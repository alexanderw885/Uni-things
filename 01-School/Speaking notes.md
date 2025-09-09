# 1
This presentation is for SENG 440, on audio compression using mu-law.
# 2
- VM run via QEMU
- run our code on a cortex-A15 processor
- Fedora 29 linux
- 32-bit ARMv7
Implementation stats:
- use NEON SIMD for vectorization
- programmed in C with NEON intrinsics

# 4
Our contributions were to:
- develop mu law algorithm for ARMv7, with 16-bit input
- implement NEON encoding and decoding, and find a balance between latency and audio quality
- Apply a number of optimizations, such as:
	- function inlining
	- bitwise logic to replace slow multiplication. Instead of multiplying in sign values, use logical OR and addition with a sign mask
	- tested a check for NEON vectors entirely of zero or low values to exit the function early
- We implemented built in statistics to the program, and modular, iterative testing, which lead to simple, and straightforwards benchmarking
- We made a python test environment to calculate sound quality
- we made a modular API structure that supported both a portable and NEON-based version of of our compression algorithms, so we could easily perform tests both in the VM and on our actual hardware
# 8
We used NEON "single instruction multiple data" for vectorization, which brought some constraints to our algorithm:
- As we must apply operations to the entire vector of input samples, we can't use any branches or conditionals during compression or decompression.
- We can only have a maximum of eight 16x8 vectors live at any time, or 16 8x8 vectors, if we want to avoid register spilling
- That's made more difficult by the fact that for most operations, constants require dedicated vectors. Any time we add, subtract, or perform any logical operations with a constant, we need to load that constant into a vector. The only exception in this project was bitshifts.

Strategy for compression:
- store the sign of each input sample, and take the absolute value of the input.
- Get the leading zeroes using the NEON vectorized CLZ instruction, and use that to get our chord value, and how far to shift our input for compression.
- Finally, we used our shifted value, chord, and sign to construct the compressed output.
Our initial implementation was 24 instructions per cycle, or 3 cycles per sample. After optimization, this went down to 2.5 per sample

Strategy for decompression:
 - extract the chord and sign bits.
 - Apply a bias to the step value, or the actual bits we stored from the original sample
 - shift the step value using the chord
 - add back in the sign value. At first this was done via multiplication
 Our initial implementation was 34 instructions per cycle, or just over 4 instructions per sample. This was brought down to just over 2 instructions after optimization
# 9
We used a number of techniques to optimize the code, and while some worked, some didn't.
- Function inlining was the most significant speedup. Standard for NEON register use are that half of the total registers are reserved for the caller of the function, meaning we could only use 4 of the 8 128-bit registers. By inlining the function, those other registers are made available, in this case removing any register spilling.
- Multiplication can be quite slow, and we were using it in the decompression to add back in the sign bit. Instead, by logically negating all negative values and adding 1, we get the same result with a slight increase in speed.
- On optimization we tried that didn't work was ending leaving the function early if all samples were zero. While this could be a speedup in quieter recordings, it was slower in our test file. making the exit threshold more aggressive did make it faster, but audio quality suffered.
- Unrolling the loop to do 2 vectors at a time did give a speedup to compression, but not to decompression even after changing the function to use less vectors. 4 vectors per loop was much slower.
- Reordering each instruction manually to improve pipelining also gave about large speedup
# 10
Adding hardware support for compression and decompression would be possible, and likely quite fast. There are unused opcodes in ARMv7, so there would be no conflicts if we added another.
It would take in the sample to process, and a flag for either compression or decompression, and we can call it with inline assembly, as shown in the next slide.
# 11
*show inline assembly*
# 13
As shown here, the large majority of the speedup came from inlining the functions to reduce register spilling. Other optimizations managed to get about 3 milliseconds improvement in both functions. I find it interesting that decompression is consistently 10 milliseconds slower despite having less instructions. This is likely due to pipelining not being as effective.
# 18
Broadly speaking, a hardware solution would improve performance further. As few as one instruction per sample with better pipelining, as each call is independent from the others, has potential to be significantly faster. Looking at the assembly for the code also shows a 10% decrease in size.
However, The added cost of the additional hardware does make it more expensive at scale.
# 19
In conclusion mu law companding can be implemented in ARMv7 with  NEON wit acceptable latency and audio quality. Optimizations were able to further reduce compression time, and while there was a loss of sound quality, it was still acceptable.
Further work could explore some pre-processing to reduce noise, making it more efficient to check for zero vectors and leave early, or to further explore hardware support.