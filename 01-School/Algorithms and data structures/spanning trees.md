 a type of [list](01%20Types%20of%20lists.md), and a sub-category of [[graphs]].

Spanning trees are subgraphs that connect every vertex in the parent graph into one tree, with no loops or two-way links. There can be many spanning trees for any given graphs

## Minimum spanning tree (MST) problem
given a connected, undirected [[weighted graph]], find a spanning tree of minimum weight.

- must return a spanning tree
- must have minimum weight
- must be provable to return optimal solution
### Brute force solution
```
//looks at every spanning tree in the graph G, returns 
//smallest weight

//num higher then weight of tree G
minWeight <- \infty

minTree <- NULL
For every spanning tree T in graph G do
	if minWeight > weight(T) then
		minWeight <- weight
		minTree <- T
	end
end
```
this method is O(n!), but it does meet all requirements
terrible idea, do better.


### [Greedy](greedy%20algorithms) solution (Prim's algorithm) 
uses [[Vertex cut]]
with a graph $G(V,E)$, take vertex cut of $(S,T)$ where $S$ is all but one vertex and $T$ contains the remaining vertex

look at the $(S,T)$-cut, and remove all edges but the one with the minimum weight

$S={1}$
$T={2, 3, ..., n}$ 
look at all edges in $(S,T)$-cut, find edge $e$ of minimum weight.
let node $v$ be in the set $T$ connected to edge $e$. 
add vertex $v$ to $S$ 

now $S = 1, $v$
$T = V/S$, so it no longer contains $v$
repeat previous step until $S=V$ 

```
S <- {1}, 
//T is the output spanning tree
T <- NULL

while V/S != 0
	let (u,v) where u is in the set S
		&& v is in the set V/S
		be the lightest edge crossing the cut
	S <- S+v
	T <- T+{u,v}
end
return T
```

#### Proving correctness of Prim's algorithm
###### Idea 1: induction
Hypothesis:
	at any iteration of the loop, the spanning tree built at that point is a MST.
This might be doable, but isn't the easiest way. this is a greedy algorithm, we can use that to make a better hypothesis.


Hypothesis:
	At any iteration of the while loop, the spanning tree that we have built so far is part of some MST for the input graph G

Base Case:   Tree so far:
	$s=\{1\}$, no edges.
	this vertex is part of an MST, as every MST $T$ of $G$ must include every vertex

claim:
	should you cut any edge of the spanning tree and paste in a different edge to complete the tree, the spanning tree will no longer be a MST. Otherwise, Prim' algorithm would have chosen that branch.

let $T$ be the spanning tree made by the algorithm, $T'$ be the tree after cut/pasting a new edge


Induction step:
	The tree built so far on $S$ is part of some MST $T$ of $G$, and this invariant is maintained when we add the lightest edge $(u,v), u\in{S}, u\in(V/S)$, crossing the $(S,V/S)$-cut. 
	$T'\leftarrow T\cup{( u,v)}$ 


#### Optimizing

How to use priority queue to find lightest edge crossing the cut?
	way too inefficient to make a new one for every cut, it would be better to just brute force the problem
Better way:
	Give each vertex the weight of the lightest edge connecting it to $S$. If the vertex is not connected to $S$, assign the weight to be infinity.
	When you add a vertex to $S$, update the weights of all vertices connecting to $S$.
What this means:
	Start with $S=\{1\}$. set weights for every vertex. anything connected to 1 has a normal weight, everything else weighs infinity.
	Make priority queue of all the vertices by weight.
	when you add a vertex $v$ to $S$, update all vertices connected to $v$

```
Initialize priority queue PQ on vertices V of G
	weight(1)=0
	for all v in V, v!=1, weight(v)=infty

S <- NULL

while(!PQ.isEmpty()):
	u<-ExtractMin(PQ)
	S <- S+u
	for every v in neighborhood of u N(u):
		if (PQ.getWeight(v) > Weight(u,v)):
		//if it changed, we know the best way to connect
		//v into S is through u, so we can change it to
		//the weight of (u,v)
			PQ.adjustWeight(v, w(u,v))
	
	
	
```


Operations:
	isEmpty
	ExtractMin
	AdjustWeight


### Optimal Substructure property
#### Edge Contraction
Edge contraction is treating two separate vertexes as one single "super" vertex. if  other vertexes were connected to both edges, now they only have one edge connecting to the super vertex. in a weighted tree, choose the edge with the minimum weight of the two.

In relation to Prim's algorithm, consider $S$ as one single super vertex, removing all high value edges if a lower value edge can replace it.



Subproblem structure:
Let  $(u,v)$ be an edge in some MST $T$ of $G$, 
then $G'$ by obtained by doing edge contraction $(u,v)$ in $G$, 
and $T'$ be obtained by doing edge contraction $(u,v)$ in T,
Then $T'$ is an MST of $G'$ 

in englisher:
	if you take a spanning tree $T$ of $G$, look at one edge and edge contract it.
	if you make a new spanning tree using Prim's algorithm in this new graph $G'$, called $T'$, it will be a MST
	But, how can we be sure it's a MST of all of G?
	We can only be sure if the edge we contract is the smallest edge in $G$



### Kruskal's algorithm

**Algorithm**: Pick edges in order of increasing weight until you get a spanning tree
if you pick an edge that creates a loop, delete that edge

```
T<- NULL

while numEdges(T) < n-1:
	pick edge of least weight still unpicked.
	let this edge be (u,v)
	
	if (u,v) creates a cycle in T:
		continue
	else:
		T <- T+(u,v)
	end
end
```
can prove with edge contraction

#### Runtime
while loop is $O(n)$
use a priority queue to make a list of edges, just pick from queue
use [[Union-find Data Structure]] to check for cycles by looking for both $u$ and $v$ in the spanning tree $T$:
```
at the start, every vertex is in its own set.
let $(u,v)$ be endpoints of next edge to add
if(Find(u) != Find(v)):
	Merge(Find(u), Find(v))
end
```

#### implementation
 
```

Initialize Union-Find data structure on the set of vertices v of G(v,e)
Each vertex will be considered it's own subset

T <- NULL

while numEdges(T) < n-1:
	use priority queue to find edge of least weight
	call this edge (u,v)
	
	if(Find(u) != Find(v)):
		T <- Merge(Find(u), Find(v))
	end
end
```