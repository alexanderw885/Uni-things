

by thinking of queries as compositions of operators, you can rewrite queries to be more expressive

think of arithmetic functions
$f(x) = 2x$
$g(x) = x + 3$
these can be put together in many ways to create more complex functions
$f(g(x)) = 2(x+3)$
we can do the same thing with sql operators

```sql
SELECT `course_name` FROM R;
SELECT * FROM `R` WHERE `course_name` = 'CSC 370'
```

we can make them more complex by combining them
```sql
SELECT `course_name` FROM
(
  SELECT * 
  FROM `R` 
  WHERE `course_name` = 'CSC 370'
);
```

example: 
write a query to determine from which majors are the students studying in 'CSC 370'
Student(sid, name, major)
Enrolments(sid, course_name)

useful operators
```sql
SELECT DISTINCE * FROM `R`

natural join query

SELECT `major` FROM R;

SELECT *
FROM `Enrolments`
WHERE `class_name` LIKE 'CSC 370';
```
by combining them all, you could make one large query to make what we want
But it would be really ugly

### Associativity
operator is associative if repeated application of operator can be permuted without changing results
$(x+y)+z = x+(y+z)$
some operators are associative, so the order will not matter. You also can often simplify and merge repeated operations together
![[Pasted image 20240712130444.png]]

can we simplify this? ![[Pasted image 20240712130545.png]]

there's 2 where clauses, $\sigma\sigma(x)$
we can merge these together into one where clause
since we now only have one selection operator, we can remove the subquery
```sql
SELECT *
FROM `Student`
WHERE `name` = 'Alice'
  AND `major` = 'SENG';
```

### Examples
$2(x+y) = 2x + 2y$
![[Pasted image 20240712131407.png]]
there's two selection operators, but they're separated by the join. we can factor out the natural join
```sql
SELECT *
FROM Student
WHERE `name` = 'Alice'
  AND `major` = 'SENG'
NATURAL JOIN `Student`
```
and then we can remove the join in this case
```sql
SELECT *
FROM Student
WHERE `name` = 'Alice'
  AND `major` = 'SENG'
```
___
Can we simplify this?
![[Pasted image 20240712131656.png]]

group by is not associative or distributive, so we cannot simplify this query anymore than it already is
___
what about this?
![[Pasted image 20240716123904.png]]
we could factor out the join just like before
```sql
SELECT *
FROM `Students`
NATURAL JOIN `Enrollments`
WHERE `name` = 'Alice'
  AND `course_name` = 'CSC 370';
```

___
![[Pasted image 20240716125133.png]]
```sql
SELECT DISTINCT Student.*
FROM Student
LEFT OUTER JOIN Enrollment
  On (Student.sid = Enrollment.sid)
  ..... out of time
```

___
![[Pasted image 20240716125328.png]]the `NATURAL JOIN (SELECT sid...)`
is identical to
```sql
select * from student
join enrollment on (sid = sid)
 where ...
```
___
![[Pasted image 20240716125805.png]]
nothing is duplicated, so it's not immediately obvious how to group them
```sql
SELECT DISTINCT major
FROM Student
WHERE major LIKE 'science'
```
this is because we didn't actually aggregate anything with the group by operator

### Note
```sql
select *
from table
where attr in
(
  select attr
  from table
  where restrictions...
);

-- IS THE SAME AS
select distinct t1.*
from table as t1
natural join table as t2
where t2. restrictions
```
replace the subquery with a self-join, and put all restrictions on the second table
However, sometimes this might be harder to understand, it may not be quite as expressive

