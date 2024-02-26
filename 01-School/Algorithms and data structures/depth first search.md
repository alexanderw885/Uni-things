This is a method for traversing [[graphs]]

depth first searches travel through an entire graph by looking at a vertex, travelling to an untraversed connected node if possible, and backtracking to a previous node if not

```
Choose starting node s
DepthFirst(s)

DepthFirst(vertex s):
	mark s as traversed
	 for v in Neighborhood(s):
		 if v is not traversed:
			 DepthFirst(v)
end
```