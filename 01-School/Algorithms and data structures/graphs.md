Graphs are a type of [list](01%20Types%20of%20lists.md).

Made of vertices connected by edges. e(s,t), where s,t are vertexes connected by the edge
Edges can be directed, pointing from one vertex to the other, or undirected.

#### Connected
in a connected graph, there exists a path between any two vertexes. all vertexes are "connected"

#### Directed
in a directed graph, each edge has a starting vertex $s$ and an ending vertex $t$. edges can only be traversed from start to end, and are represented as $e(s,t)$ 
note that $e(s,t)\neq{}e(t,s)$ 

#### Cyclic/Acyclic
in an acyclic graph, there is no more than one path between any two vertexes. Also known as [[trees]].
note that in a directed graph, path$(s,t)$ likely will not be the same as path$(t,s)$, if both exist. Both can exist, as long as each is unique


### subgraph
subset of edges and vertices of a graph. This can include all vertices and edges, and even if the parent graph is connected, a subgraph may not be connected.