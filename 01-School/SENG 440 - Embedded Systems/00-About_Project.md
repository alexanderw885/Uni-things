why use ARM?
- it's widely used in embedded systems
- large amount of free software

Goal: write C code for a specific task with fixed-point arithmetic

![[Pasted image 20250512092134.png]]

___
# Audio Compression
The goal is specifically *speech* compression.

A, E, I, O are more likely to occur, any event is less likely to be a consonant
More likely events carry less info
Less likely events carry more info

When writing, if we remove the vowels from a word, we don't lose as much info as if we were to remove consonants.
"cmptr" is understandable, "oue" is not.
So, we want to *shrink* the amplitudes of vowels, or high-probability sounds, without impacting the low-probability sounds as much.


Most sounds are low-amplitude. If we start looking at the most significant bit and work our way down, we'll waste many checks on less-likely amplitudes
We could implement a lookup table on the 6 most significant bits, we'd have $2^6$ entries, which isn't too large but smaller would be nice
A third option is if we have a machine-level instruction that looks for the number of leading zeroes. This option, if it exists, would be ideal.

Let's break these into more computery terms. There's three options:
1. chained `if-else`: looking for the most significant 1. slow, wastes many checks looking for less likely amplitudes
2. look-up table: has 128 entries, may cause cache misses
3. check instruction set for instruction/instructions to count leading zeroes (or ones)
	- `CLZ` or `CL0` are likely instruction names
	- How can we make C call these specific instructions? (Extended) assembly inlining is an option, but is it the only one?


### To-Do
Record 10-20 second speech sample, compress and decompress it. Decide if the quality is acceptable or not, this is subjective.
Present both in 

Our metric to optimize is **speed**. the ideal goal is 5 cycles

#### Progress report
1. Which processor are we using? Be specific
	1. Check instruction set manual, *specifically report* if we have `CLZ` or similar
2. Create work plan
	1. what's our approach for each for each part of the problem?

Bullet form is acceptable
hand-written is good enough