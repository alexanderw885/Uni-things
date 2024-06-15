graphics often require spatial queries
- find k points closest to point p
- does X intersect with Y?
- what is the volume of this intersection?
brute forcing is expensive, so application-specific models are used

One thing to keep in mind with this subject, big O notation doesn't always apply for every 

#### The main ideas
1. You can index the space itself (spatial index)
2. you can "sort" the primitives in the scene which implicitly induces a partition of the space (Bounding Volume Hierarchies)


# Spatial Indexing Structures
these accelerate the kind of queries "what is near this object?"
tasks:
- construction+updating
	- preprocess static objects
	- update for moving objects
- access/usage
	- must be as fast as possible

the most common structures are:
- regular grid (easiest)
- kD-tree
- Oct-Tree/Quad-Tree
- BSP Tree

### Regular grid
![[Pasted image 20240610104936.png]]
an array of 3d cells, each cell is a list of pointers to colliding objects

Constant time indexing
construction:
	- for each object, find cells that touch it
	- add pointer to each cell found 
queries
- given a point, find cell that contains it
- return pointers in cell

problems;
- if cells are small, takes up a lot of memory
- if cells are large, too many objects in each cell
- as teacher says: "it's kinda sketchy"

### kD-Tree
![[Pasted image 20240610105527.png]]
uses a tree structure
each node is a space in 3d
root: the whole world
each child node splits into subpart of the space

kD-tree
- binary tree
- each node only splits over one dimension
	- there are variants that don't follow this. They're harder to implement, but potentially more optimal
- split until each leaf only has one object
- note that each object may be in multiple leaves

### Oct/Quad-tree
![[Pasted image 20240610110146.png]]
same as kD-tree, but not binary:
each node is a space
root is whole scene
child is subspace of parent

split each space evenly into 4 if 2d, 8 if 4d
continue splitting until either the limit is reached, or there's few enough objects in each space

they fit very nicely in memory, space gets divided faster, but it's messy to implement

### BSP-tree (Binary Spatial Partition)
![[Pasted image 20240610110556.png]]
most complicated system, even more complicated for shapes instead of points
don't bother trying to implement it

instead of partitioning along an axis, partition in an arbitrary direction to make the tree as even as possible

They are useful for checking if points are in a polygon

# Primitive sorting structures

### Bounding Volume Hierarchy (BVH)
![[Pasted image 20240613105939.png]]
each leaf node is volume around an object
then pair together closest together objects, parent will be the space containing both
recursively apply that until everything is in one node
that node is the root

it's constructed bottom-up, but is visited top-down

it's relatively easy to update, but sometimes there can be overlap in the tree. in this picture, there's overlap between K and J
