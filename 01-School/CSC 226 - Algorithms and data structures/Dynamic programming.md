  
A good thing to do to make programs faster. One of the **Most important** parts of this course. To use Dynamic programming, the problem must have the following attributes

### Memoization

If a "sub-problem" is reused at anytime, compute it only once and store the result (memoize it)
Solve the small problems first, then solve the large problem after.
for this to work, the problem must have the following properties:

#### No Cyclic Dependencies
Subproblems must have an order, **cannot** by cyclic

#### Optimal substructure property
Optimal solutions to subproblems can be combined to get an optimal solution to the original problem

### Overview of steps to do
by using the following steps, one can create a dynamic algorithm
1. Define subproblems
	1. find structure
	2. ensure they fit the requirements
2. Guess
	1. guess brute force solution
	2. ensure it works
3. Combine subproblem solution
	1. write the brute force solution
4. Recursive (brute force alg.) + memoization
	1. add memoization the the algorithm in part 3
	2. ensure you didn't add any cyclic dependencies
6. Final solution
## Computing Fibonacci Numbers

$F_n = F_{n-1}+F_{n-2}$;      $F_1=1; F_2=1$

```
if(n<=2):
	return 1
else:
	return fib(n-1)+fib(n-2)
```
T(n)=time to compute nth term
$T(n)=T(n-1)+T(n-2)+O(1)$
$\geq$ $2T(n-2)+O(1)$
$\geq$ $2(2T(n-4)+O(1))$
...
$\geq$ $2^k(T(n-2k)+O(1))$
$\geq n^{n/2}$ <- [Exponential time](asymptotic%20notation), not great
if only there was a better way!

### Better way with Dynamic Programming

The issue with this method is the amount of repetition of sub-problems. F(n-2) is calculated twice, F(n-3) is done thrice, and so on. Not efficient!
This is a perfect case for memoization
	Store the result of a sub-problem for later use, to only do it once.
Caveat: This assumes some ordering of the sub-problems.


Fibonacci subproblems:
F(n), F(n-1), F(n-2), ... , F(1)
Observations:
1) only polynomial num. of subproblems
2) no cyclic dependencies

```
Global array val[n] // initialized to NULL
fib(n)
	if val[n] != NULL, return //has it been computed before
	if n<=2
		val[n]=1
	else
		//note that these next calls return right away if
		//they've already been calculated
		fib(n-1)
		fib (n-2)
		val[n] = val[n-1]+val[n-2]
	end
end
```

Note that this algorithm does not return the value, just puts it in the array.
all the memoization is done/saved by the global array "val"

#### Correctness
Whenever val\[j\] is accessed in recursion for computing val\[k], k>j,
it is already calculated.
F(n) has n subproblems, each taking O(1) time.
$O(n)*O(1) = O(n)$
thus, $F(n)\in{O}(n)$
## Shortest Path Problem 

Given directed [graph](graphs.md) $G(V,E)$ with edge weight,
find the shortest path from vertex $u$ to vertex  $v$


#### Greedy algorithm is bad
The optimal short-term solution is **not** the optimal long-term solution.

[[depth first search]]  going down edges of least weight.
Very slow, can go down every single path before finding a path to the destination $v$.
Also not guaranteed to work, some paths are not the shortest path possible.
ex: this algorithm would choose a path with weights $(1,100)$ instead of $(2)$

#### Recursive brute force solution

```
S(u,v):
	if u = v:
		return 0
	
	min=infty
	currentU=u
	for all w in Neighborhood(u): //aka N(u)
		recursively compute shortest path on (w,v)
		cost=w(u,v)+ shortest path (w,v)
		if cost < min
		min = cost
	return min
```
very slow, $O(2^n)$

Problem: what if there are cycles?
the algorithm would be stuck in the cycle, and wouldn't move on
also, some paths would be calculated multiple times, good problem for dynamic programming 


#### Dynamic program method
"Brute force plus memorization"

what are our sub-problems?
```
S(s,t)
	if(s=t) return 0
	spLen=infty
	for every u in N(s):
		splen<-min(splen, w(s->u)+S(u,t))
	return spLen
```

with dynamic programming becomes:
```
Make a global array D[v][v] initialized to NULL
S(s,t)
	ifD[s][t] != Null: return D[s][t]
	if(s=t) return 0
	spLen=infty
	for every u in N(s):
		splen<-min(splen, w(s->u)+S(u,t))
	D[s][t]=spLen
	return spLen
```
This algorithm depends on there **not** being a cycle with a net negative weight. That would make the "shortest path" infinitely long, to get the weight to $-\infty$

what if there is a positive weight cycle between s and t? it will get stuck in an infinite loop
**this algorithm only works for directed acyclic graphs (DAGs)**

### interlude

gotta talk about dynamic programming in general a bit more. 

#### Optimal Substructure
Optimal solutions to subproblems can be combined to get an optimal solution to the original problem

#### formalism to explain Dynamic Programming : Subproblem DAG

List every subproblem $S_i$ needed to solve the original problem as a vertex

Vertex $S_i$ is connected by a directed edge to vertex $S_j$ if we need solution $S_i$ to solve $S_j$

### Back to SPP
#### How do we break dependencies?
we can assume our graphs do not have negative weight cycles, but they still might have cycles

##### With a Subproblem DAG
lets define our problem as a subproblem DAG
![[Pasted image 20240129124103.png]]

we want to get from 1 to 4
so our subproblem DAG is:
![[Pasted image 20240129124207.png]]
notice the red arrow makes a loop, so we should remove it to keep the graph acyclic.
since there are no net negative cycles, removing this cycle can only make the path shorter.
we can do this in the SPP, we can make sure we use each vertex only once.

TODO: change this code to reflect what we were talking about
HAVE NOT DONE THAT YET
DO NOT TRUST THIS CODE
IT STILL BREAKS WITH CYCLES
BIG ISSUE
```
Make a global array D[v][v] initialized to NULL
S(s,t)
	ifD[s][t] != Null: return D[s][t]
	if(s=t) return 0
	spLen=infty
	for every u in N(s): // Neighborhood(s)
		splen<-min(splen, w(s->u)+S(u,t))
	D[s][t]=spLen
	return spLen
```

##### With a path length limit
we can solve this problem by trying to find the lightest path using at most $k$ edges
guess and verify good values of  $k$

$\delta_k(a,b)$: shortest path from $a\rightarrow{}b$ using  $k$ edges

$$\delta_k(s,t)=\delta_{k-1}(s,node\_before\_t),w(node\_before\_t\rightarrow{}t)$$  
$$\delta_k(s,t)=min(u\in{}v),u\rightarrow{}t\in{}E(u)$$
$$=S_{k-1}(s,u)+w(u\rightarrow{}t)$$
so the shortest path S(s,t)
$$S(s,t)=min(\delta_k(s,t)),0\leq{}k\leq{}E(G)$$

```
make global array for dynamic programming
FindPathAtMostK(s,t,k):
	if k=1:
		if a==b:
			return 0
		elif edge(s,t) exists:
			return weight(s,t)
		else:
			return infty
		end
	end
	else
		minWeight <-infty
		for all u s.t. vertex u->t exists
			minWeight = min(minWeight,
			FindPathAtMostK(s,u,k-1))
		end
			
		return minWeight

```

```
FindShortestPath(s,t)
	optPath<-infty
	for k=0 to |E(u)|
		if optPath > FindPathAtMostK(s,t,k)
			optPath=FindPathAtMostK(s,t,k)
		end
	end
	return optPath
```
### Big Idea
To break cycles, introduce some parameter with respect to the subproblems