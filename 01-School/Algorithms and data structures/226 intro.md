
CSC 226 is about better analyzing problems to find more optimal solutions

### Problem:

given an integer array A\[n\], find largest and 2nd largest elements in array

First idea (Trivial solution):
```
largest <-A[0]
second <-A[0]
for i <- 1 to n do
	if A[i] > largest then
		second <- largest
		largest <- A[i]
	else if A[i] > second then
		second  <- A[i]
	end
end
```
num. comparisons = $2n$ 

Solution 2: 
sort array, return last two elements
works, but comparison algorithms are no better then $O(nlogn)$



A{45, 9, 12, 1, 17, -5, 20, 52}
divide into pairs of two
{45, 9},{12,1},{17,-5},{20,52}
sort pairs                  $n/2$ comparisons
{9,45},{1,12},{-5,17},{20,52}
compare largest of each pair  $n/2$ comparisons
largest number = 52
Compare largest of every other pair and element paired with largest in whole array           $n/2$ comparisons
second largest = 45

Largest, second = 52, 45
num. comparisons = $3n\over2$ 