
### DML (Data Manipulation)
can create tables with other commands
```sql
CREATE TABLE Example
SELECT *
FROM OtherTable
Limit 5;
```
can do the same thing with delete
```sql
DELETE
FROM `Example`
WHERE `Id` > 10;
```

can insert with attributes in any order you want
```sql
INSERT INTO SomeTags(`Count`, TagName, `Id`)
VALUES(5, 'banana', 100)
-- or
INSERT INTO SomeTags(`Id`, TagName, `Count`)
VALUES(100, 'banana', 5)
```

### Keys and FK's
#### Keys
can add constraints retroactively
```sql
ALTER TABLE `Example`
ADD PRIMARY KEY (`attribute`);
-- Only works if the key attribute is unique!
```
Now, the database won't let you add data that violates that constraint
primary keys can be removed 
```sql
ALTER TABLE `Example`
DROP PRIMARY KEY;
-- attribute still exists, just is not key
```

you can only have one primary key, but what if you want more constraints?
say, each user can have only 1 ID
```sql
ALTER TABLE `Badges`
ADD UNIQUE(`UserId`, `Name`);
-- Also only works if pair is unique
```

#### Foreign Keys
say, table `Badges` can only have users in `Users` table
first, make sure `Users`.`Id` is a key
also make sure `Badges`.`UserId` is a primary key
and that `Badges`.`UserId` only contains keys in `Users`.`Id` already
```sql
ALTER TABLE `Badges`
ADD FOREIGN KEY(`UserId`)
REFERENCES `Users`(`Id`);
ON DELETE (CASCADE/SETNULL)
```

#### Where/ having
where applies to each tuple
having applies to whole table
`WHERE Id LIKE \%Canada%'`
versus
`HAVING COUNT(*) =5`

