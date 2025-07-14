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

contemplate hardware. We don't need to actually implement it, but think about it, discuss if it could have significant speedup

Our metric to optimize is **speed**. the ideal goal is 5 cycles

#### Progress report
**Deadline is June 30th, send by email**
1. Which processor are we using? Be specific
	1. Check instruction set manual, *specifically report* if we have `CLZ` or similar
2. Create work plan
	1. what's our approach for each for each part of the problem?
3. Bring up any questions
	1. bullet point form is acceptable

Bullet form is acceptable
hand-written is good enough

# Final report
**Everyone should submit the project**
hand in will be opened on brightspace
Due date is the evening before the presentation

 20 pages, excluding appendices, *including* title page and references. Everything past is truncated.

**Everything here is just a framework, or a suggestion. We do not have to follow everything exactly.**

### Misc. Sections
- Title page: Name, V-numbers, emails, affiliation (Uvic, program)
- Abstract: 5-6 sentences
- Table of contents: Optional. Should only have section names, no subsections.
- Appendices: for anything you want to add, but don't want to give space to, such as UML diagrams.

### Main Sections
1. Introduction: 
	- device specs, can be in bullet form
	- environment (virtual machine, compiler ...)
	- performance achieved (cycles, instructions, whatever is important for this project)
	- self-criticism
	- contributions (design decisions?), bullet form
		- ex: "we decided to use 24-bit integers, while the specs store them as 12-bit"
	- last part: report organization. Name and (briefly) discuss each section.
		- ex: "section 2 contains (...). section 3 has (...) ..."
	- be specific, should give an idea of what was done.
	- should take about a page and a half
2. Background: 
	- 1-2 pages, lean more towards 2. It's okay to go over
	- reader should not have to research anything or read any textbooks to understand our topic.
	- motivation
3. Algorithm Design
	- 2 pages
	- which algorithm
	- make references to UML diagrams
	- how you implemented audio compression with the algorithm.
	- bit-width of intermediate variables
	- concatenation or rounding
	- number of registers used, how did you manage this
	- are we using NEON vector operations?
	- cache optimizations (including if we used NEON registers as storage to avoid cache misses)
	- ...
4. C code + Optimization
	- 1-2 pages
	- don't need to submit entire code. Could put it in appendix if wanted
	- good idea to reference UML diagrams
	- cache optimization, vectorization, software pipelining, ...
5. Compilation and assembly:
	- about 1 page
	- show compiler arguments
	- are you happy with it?
6. Results:
	- 3 pages
	- number of cycles
	- number of instructions
	- precision
	- did we use valgrind or cachegrind?
7. Improvements:
	- 2 pages
	- anything that could be done better
	- changes you'd like to make
8. Conclusions:
	- max 1 page
9. References: 
	- 1 page
	- required
	- can be in any style


# Presentation
- On zoom
- webcam required
- must log in through uvic
- 10-15 minutes. no more than 15
- Must have up to 15 slides, just one per minute
- avoid any animations
- Each person should talk, about equally
- Bullet form, slides contain important ideas
- Submit deadline is 15 minutes before presentation

- Slide 1: title. Contains same info as final report.
- Slide 2: outline/table of contents
- Slide 3: introduction
	- one slide for specs
	- one slide for environment
	- tools installed (cachegrind, valgrind, ...)
- Slide 4-5: Background
	- can be one slide
	- try to keep it to 1 minute either way
- Slide 6, 7, 8: algorithm design
	- bit width
	- number of registers
	- ...
- Slide 9, 10: C code + optimization
- Slide 11: Assembly
	- "we checked the assembly, it looks okay because (...)"
- Slide 12: results
- Slide 13: improvements
- Slide 14: conclusions

After the presentation, there will be 5-10 minutes Q&A on our work and our project. It may cover other fields