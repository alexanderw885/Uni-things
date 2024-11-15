how to choose which [[Logical Query Plans]] is best, turn into physical query plan

remember the [external memory model](Evaluating%20Query%20Performance) and [[B+ Tree index]]

### Stats review
remember [[Expected value]], [independent events](Probability-independent%20events%20+%20Mutual%20exclusive.md) 

### Cost estimation
T(R) number of tuples in R
B(R) number of blocks in R
V(R,x) number of unique x values in R

treat x as random variable
$P(x) = 1/V(R,x)$
other attributes are considered independent, so $P(x,y) = (1/V(R,x)) * (1/V(R,y))$

for more accurate estimations, we can make an approximate density function, and compare each equal range in R and S
![[Pasted image 20240730124247.png]]
so we'd compare $(-\infty, 25)$ in R.x and S.x get 0 expected results
or for $[50, 75)$, we'd get $\frac{7*7}{25}$ expected results

### Ordering joins

which plan is the best plan for joins?
![[Pasted image 20240730124625.png]]
left hand argument would be outer loop
right hand argument would be inner loop

The best is generally the one of the left, with the size of each smallest on the left and increasing as it goes to the right.
We want a small inner loop, and a large inner loop
we can build a good left-deep tree with [[Greedy algorithms]], always doing the smallest possible cross-products at every step