Binary trees are a type of [[trees]], they are connected, directed, and acyclic

each vertex in the binary tree has one incoming edge from a "parent" vertex, and up to two outgoing edges to "children" vertexes
every tree starts with one root node with no parent
any vertex with a parent and at least one child is called a branch
any vertex with no children is called a leaf

#### Balanced trees
in a balanced tree, the greatest depth of the left and right branches of any node are no more than one apart. 
In other words, all leaf vertexes are either on the same level, or one level apart

#### Complete trees
in a balanced tree, all leaf nodes are on the same level. This is the most optimal tree, but must have specifically $2^{n-1}$  nodes, where $n$ is the depth of the tree.