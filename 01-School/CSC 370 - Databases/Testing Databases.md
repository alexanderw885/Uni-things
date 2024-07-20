A unit test is a test of the program itself, not connected to other programs
should be fast, want to run many of them
### Input domain partitioning
in partitioning, we have the set S
we partition this into $S_1, S_2, ..., S_k$ such that:
$S_1\cup{}s_2\cup...\cup{}S_k = S$
$S_i\cap{}S_j =\emptyset$
each partition is determined by some characteristic

example problem: add a one-digit non-negative integer to itself
input domain is 0-9
how could we partition this?
- values >= 5 return 2 digit values
- values 1-4 return positive single-digit integer
- zero returns itself
So we might want to make tests for each of these cases, but we don't really need multiple tests for each case
it's good to check boundaries, so we might choose 0, 1, and 5

Example problem: add two one-digit non-negative integers
input domain: 2 values, both 0-9
how to partition?
- add zero to anything, returns itself
- some pairs return two-digit values
note that for the last partition, you can't test each digit individually, you need to take both values into comparison


#### In MySQL
what might the input be in a select statement?
- The current state of the 


Student(**id**, name, gpa)
problem: retrieve all information about students who's gpa is at least 7
inputs: all names, all id, all gpas 0-9
how would we partition?
- all that matters is gpa, partition at gpa=7
you might pick test cases at 6.9, and 7
so we could make a table with two tuples, random names and ids, one tuple with gpa=7, one with gpa=6.9

example:
we're given query:
```sql
SELECT *
FROM `Student`
WHERE `gpa` >= 7;
```
since we have the exact query, we can test each operator, in this case the `WHERE` clause
in this case, we would test the same way as the previous example

more complex example:
```sql
SELECT *
FROM `Users`
NATURAL JOIN `Badges`
```
what should we check for?
- value joined on isn't displayed twice
- tuples joined on the intended attribute
- tuple matched that shouldn't have

