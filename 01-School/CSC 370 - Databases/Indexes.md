how to search through database in O(1) time?
```sql
SELECT *
from Users
where Id = -1;
```
looking for a very specific user, don't want to have to go through the whole list to get them.
you use indexes

### What are they
data structures in tables to help search through tables quickly. With indexes, searching for a specific item takes O(log(n)) time.

when joining, normally might take O(n\*m), since it compares every tuple of one table to every tuple in the other
we want to make this much faster
```sql
select *
from Users
join Badges
ON(Users.Id = Badges.UserId);
```
we'd want an index on one of these, which one?
We'd want it on `Users.Id`
-  want it on the larger table with more unique values
-  want it on the unique value

why not index everything possible?
- takes up a lot of space
- makes updates very slow, as it has to update every index

two types:
- clustered: similar values are closer together
- unclustered

### Creation
check indexes with `show INDEXES from USERS`

indexes are made for keys, and unique values
unique:
```sql
ALTER TABLE Tags
ADD UNIQUE (TagName);
```
key:
```sql
create index 'idx_name' on Badges(Name)
```
or explicitly

### Explain keyword
shows the methods the database is able to use for any equation

### Example
```sql
explain 
select *
from Users
join Badges
on (Users.Id < Badges.UserId);
```
in this case, `Users.Id` is a key, but that won't help very much. Don't do it like this if you don't have to