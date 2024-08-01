the EM model (External Memory model)

### What is modelling?
an abstraction of the subject
We can construct a model of computation to determine how to analyse computation
different models have different focuses on what they prioritise

### Random Access Machine (RAM)
This was covered in [CSC 226](asymptotic%20notation)

Why not just run and measure algorithms?
- Experiments can only be done on a limited set of inputs
- don't need to worry about hardware
- need to know how to code to make the algorithm

tracks following operations:
- assigning value to variable
- calling  method
- arithmetic operations
- comparing numbers
- indexing into array
- following object reference
- returning from method

This model completely ignores the effects of the cache, and the programming language

### Asymptotic analysis
worst-case analysis O(n)
best-case analysis 
average-case analysis (harder to do)

### Why use other models?
in the RAM model, all memory accesses have the same cost, it doesn't take into account the cache. The cache has a very substantial impact. It also only takes into account one CPU, no parallel processing

For us, we want to make sure we capture the number of times we read/write to a disk, and the amount of data that can be transferred in one operation
### External Memory model
AKA block I/O model

since reading and writing data is by far the most expensive operation, that's all we count

operations in memory are free
each access to 4kb block has same cost, regarless of size read
cost of algorithm is therefore based on blocks read and written

example:
![[Pasted image 20240717125856.png]]
lets join 2nd value of R with 1st value of S
so (2,12) would join (12, 5)
we have to read whole blocks at a time

so step 1 is reading in from R (2,12), (7,2)
then read in from S (2,2), (1,17)
we read in both at once, so we don't need to read again
each loop of S reads 3 blocks
R reads 5 times total

each join outputs one block

Asymptotic analysis gives us $O(mn)$
in this case, the EM model gives us $O(\frac{mn}{B})$, where B is block size

##### Block Nested Loop Join (BLNJ)

![[Pasted image 20240717130924.png]]
in this case, we read in 2 blocks of R and 1 blocks of S, then compare everything
we can use the remaining block as a buffer for outputs.
Since we're taking advantage of blocks, this is significantly faster

In BLNJ, it's given a smaller and larger thing to loop over, it's better for the smaller item to be the outer loop

notation:
B(X) = number of blocks of X
B(M) = blocks in memory
B(O) = blocks you can output???

##### Naive Linked List
has 3 operations
- `InsertAfter()`
- `Find()`
- `Delete()`
in RAM model, `InsertAfter` and `Delete` are O(1), but `Find` is O(n)