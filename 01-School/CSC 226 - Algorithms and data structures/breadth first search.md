This is a method for traversing [[graphs]]

Traverses all vertexes in order of closest to furthest from the starting node
easiest to implement using a while-loop

```
Create an empty queue Q
add starting vertex to Q

while Q is not empty:
	s = Q.dequeue()
	mark s as traversed
	for all v in Neighborhood(s):
		if v is not traversed:
			add v to queue
end
```