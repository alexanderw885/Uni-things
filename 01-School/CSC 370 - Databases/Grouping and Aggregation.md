### `GROUP BY` operator ($\gamma$)
can find unique values with `DISTINCT` KEYWORD
```SQL
SELECT DISTINCT `major`
FROM  `Enrolments`;
```
but, information can be lost by using `DISTINCT`
in this example, what if multiple students have same major? you can use `GROUP BY`
```sql
SELECT `major`
FROM `Enrolments`
GROUP BY `major`;
```
in this case, they both return the exact same thing.

Group by can also return a count of the number of tuples with that attribute

##### Examples:
![[Pasted image 20240528124933.png]]
select name, group by name

| `name` |
| ------ |
| Alice  |
| Bob    |
| Carol  |
select v_number, group by v_number

| `v_number` |
| ---------- |
| V00111222  |
| V00222333  |
| V00333444  |
select class, group by class

| `class` |
| ------- |
| CSC 320 |
| CSC 370 |

### Aggregate Functions
what happens to the other attributes that are1ot part of the key used in `GROUP BY`?
we need some way to take a group of values, and return only a single value
ex. min. max, avg, sum, count, any...
```sql
SELECT MIN(`class`), `major`
FROM `Enrolments`
GROUP BY `major`;
```
now if there's a conflict on class, it will give the lowest value
```sql
select count(*), major
FROM enrolments
GROUP BY major;
```
returns the number of entries with each major

### `HAVING` clause
what if we only want 'popular' classes with at least 2 students enrolled?
```sql
SELECT `major`
FROM `Enrolments`
GROUP BY `major`
HAVING COUNT(*) > 1;
```
but make sure you have good reason to do this
