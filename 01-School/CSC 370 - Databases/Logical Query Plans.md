transform SQL query into logical query, apply basic algebraic transforms

recall:
joins and selections are associative
joins are selections distributive
joins are commutative, can swap loft/right target
## Expression trees
you can represent any arithmetic expression with binary trees
![[Pasted image 20240726124053.png]]
you could traverse this tree recursively to evaluate expressions.
You can do the same thing for relational algebra
![[Pasted image 20240726124227.png]]
tables are always on leaves, branches are operators

this tree is called a logical query plan, it gives us a plan on how to execute a query. This type of thing is often an intermediary stage in compilers

Naive approach to converting queries into a logical query plan:
- do all cross products and joins
- then apply WHERE
- then grouping
- then Having
- then order by
- then LIMIT
- then projections
- then remove any duplicates
### Tree transformations

this naive approach will give us *a* logical query plan, but that doesn't mean it's a good one. There may be multiple plans for the same query, but not all are equal

##### Commutativity
you can swap left and right children of a commutative operator
##### Associativity
you can rotate nodes with the same associative operator
![[Pasted image 20240726125226.png]]

