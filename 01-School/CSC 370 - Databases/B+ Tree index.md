All indexes should support 4 types of queries

1. lookup query
```sql
SELECT *
FROM Student
WHERE id = 123456;
```
has a search 'key' it needs to find
2. range query
```sql
SELECT *
FROM Students
WHERE age < 18;
```
looks for all with value in upper/lower bounds
3. Insertions
4. Deletions

### Good solutions for RAM model
##### Binary-search trees
- lookup is log(n)
- range query is log(n), two lookups, one for upper and one for lower bound
- insertion is log(n)
the problem is that they're not always balanced, so we can't guarantee proper log(n) times
also does not take memory blocks into account
You can rotate to balance them, but that's not good in the EM model
##### 2-4 trees

a 2-4 tree can guarantee logarithmic height
(each node has 2 to 4 children)
this ensures every leaf node is at the same depth
insert values to the bottom of the tree, grow the tree up. Send value from child to parent if child grows too big

generalised to a-b trees
tree where each node has between a and b children

### B Trees
every node has a at least d/2 children, and at most d, where d = depth
since each node can have so many values, you can load a larger amount of data at a time, making it far more efficient in the EM model

##### B+ tree
each node takes up exactly one block
All of the keys are stored in leaves, and form a linked list pointing to the next. To do a range query, you lookup the lower bound, then traverse the leaves until you get to the upper bound, no need to traverse the tree more than once
![[Pasted image 20240723131245.png]]
so if we were to look for the range 7-40 in this tree:
- search for the lower bound 7
- traverse the linked list of leaves until you reach value > 40
Note that all keys are duplicated in the leaf nodes

### Index-Loop Joins
