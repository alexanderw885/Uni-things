# User Authorization
 Goal: determine effects of queries that modify authorization controls

what if you want to share database with someone, but don't trust them to damage the database? Use privileges to allow them access to certain commands
### Some Privileges
###### SELECT
Can be done  on projection, only allowing users to view certain aspects of a table
```sql
SELECT ON Movies;

SELECT ON Movies(title, year);
```
###### INSERT
can also be on a projection
```sql
INSERT ON Movies;

INSERT ON Movies(title, year);
```
note that inserting into a projection only works if other attributes have default values. generally you don't limit insert
###### DELETE
Cannot be on a projection
Also needs select privileges to delete chosen tuples
```sql
DELETE ON Movies
SELECT ON Movies
```
###### UPDATE
Can be done on projection
```sql
UPDATE ON Movies
```
###### REFERENCES
Allows you to add constraints such as foreign keys
```sql
REFERENCES ON Movies
```

#### Example
what privileges do you need for this command?
![[Pasted image 20240607124842.png]]
```sql
INSERT ON `Studio`;
SELECT ON `Studio`(`name`);
SELECT ON `Movies`(`studioName`);
```


### GRANT clause
```sql
GRANT <privilege>
ON <database(element)>
TO <user_list>
WITH GRANT OPTION;
```
the line `WITH GRANT OPTION` allows them to grant those privileges to other users

can grant multiple privileges at once
```sql
GRANT SELECT, INSERT
ON Studio
TO kirk, picard
WITH GRANT OPTION;

GRANT SELECT
ON Movies
TO kirk, picard
WITH GRANT OPTION;
```
Now Kirk and Picard can select and insert into Studio, but only select on Movies

instead of writing out each privilege
```swl
GRANT ALL PRIVILEGES
ON *
TO <user_list>;
```
note that all privileges is just all privileges you can grant
Still have to specify `WITH GRANT OPTION`

##### Example
who can do what?
```sql
GRANT SELECT, INSERT
ON Studio
TO kirk, picard
WITH GRANT OPTION;

GRANT SELECT
ON Movies
TO kirk, picard
WITH GRANT OPTION;

GRANT SELECT(name), INSERT
ON Studio
TO sisko;

GRANT SELECT 
ON Movies
TO sisko;
```
kirk: 
- select on studio
- insert on studio
- select on movies
- all with grant privilege
picard;
- select on studio
- insert on studio
- select on movies
- all with grant privilege
sisko:
- select on studio, only on name
- insert on studio
- select on movies
- no grant privilege
so everyone has the same privileges, but sisko cannot grant them while the others can.

### Revoking Privileges
```sql
REVOKE <privilege>
ON <database_element>
FROM <user_list>;

REVOKE GRANT OPTION <privilege>
ON <database_element>
FROM <user_list>;
```

but what about every privilege that was granted by that user?
there's two options

RESTRICT: if this privilege was granted to other by this user and nobody else granted that privilege to them, blocks the query
```sql
REVOKE <privilege>
ON <database_element>
FROM <user_list>
RESTRICT;
```

CASCADE: if this privilege was granted to others by this user and nobody else granted that privilege to them, revoke their privilege too
```sql
REVOKE <privilege>
ON <database_element>
FROM <user_list>
CASCADE;
```

this is kept track if with a directed acyclic graph
![[Pasted image 20240607131100.png]]
in this example, Janeway is the owner of the database, with each of her privileges being a "root note"

# Database Views
create views to control user access
know effect of `INSERT, UPDATE, DELETE` queries on those views

### Creating views
what if we don't want the user 'schester' from seeing grades?
Students(**v_number**, name, major);
Enrollments(**course, v_number, semester**, grade)
Course(**course_id**, name, instructor)

```
REVOKE SELECT
ON Enrollments(grade)
FROM schester
CASCADE;
```
but what if we just want to stop him from seeing grades outside of CSC370? Then that method won't work, since he still needs to be able to see some grades 
or what about only let him see grades for classes he teaches?
This is what you use views for!

### view as a query
```sql
CREATE VIEW viewname(column names) AS
  SELECT <rest of query>;
```

**lets go back to the previous example:**
what if we don't want the user 'schester' from seeing grades not from CSC370?

Students(**v_number**, name, major);
Enrollments(**course, v_number, semester**, grade)
Course(**course_id**, name, instructor)
```sql
CREATE VIEW `DBStudents` AS
  SELECT *
  FROM `Enrollments`
  WHERE `course` LIKE 'CSC370';

GRANT SELECTON
ON `DBStudents`
TO `schester`;
```

all courses he teaches?

```sql
CREATE VIEW `DBStudents` AS
  SELECT *
  FROM `Enrollments`
  JOIN `Course`
  ON (`course`=`course_id`)
  WHERE `instructor` = `schester`;

GRANT SELECTON
ON `DBStudents`
TO `schester`;
```

### Selecting from Views
what happens when we execute a query against a view instead of a table?
```sql
CREATE VIEW `DBStudents` AS
  SELECT *
  FROM `Enrollments`
  WHERE `course` = 1234;

SELECT * FROM `DBStudents`;
```
this is just like using the view as a subquery on the `ON` statement
```sql
SELECT *
FROM
(
  SELECT *
  FROM `Enrollments`
  WHERE `course` = 1234;
)
AS `DBStudents`;
```

Views can be used exactly like any other regular table
```sql
SELECT *
FROM `DBStudents`
NATURAL JOIN `Students`;
```

what happens in this case?
![[Pasted image 20240611130321.png]]
note that now `DBStudents` does not have `grade`
so in this case, we'll get an error message.
to substitute in the subquery instead of a view:
```sql
SELECT *
FROM
(
  SELECT `course`, `v_number`,
    `semester` 
  FROM `Enrollments`
  WHERE `course`=1234
)
NATURAL JOIN `Students`
WHERE `grade` = 7.0;
```
you can see here that grade is nowhere in this table
### Dropping
can drop view
`DROP VIEW DBStudents`
or whole table
`DROP TABLE Enrollments`


### Inserting into views
Inserting into a view is the same as inserting into a table, since they always query the base table.
```sql
INSERT INTO `DBStudents`
VALUES (...);
```
this inserts into the table `Enrollments`

what if attributes outside of the view don't have default values?
```sql
CREATE VIEW `DBStudents` AS
	SELECT `course , `student`
	FROM `Enrollments`
	WHERE `course` = 1234;

INSERT INTO `DBStudents`
VALUES ( ... );
```
since semester is an identifier, you cannot add into Enrollments without it
Meaning you cannot add to the view in this case
Note that if the user does not have insert permission on the base table, they cannot insert on the view.
### Deleting into views
what if we try to delete from a view?
```sql
DELETE FROM `DBStudents`
WHERE `grade` > 9.0;
```
this is also executed against the base table. Note they can only delete from tuples they can see, and if they have permission on the base table

### Materialized views
instead of always referencing the table, this creates a new copy of the data

this is faster to read than regular views since it doesn't reference the base table every time.
can be approximated as:
```sql
CREATE TABLE `DBStudents` AS
  SELECT *
  FROM Enrollments
  WHERE course = 1234;
```
however, now when Enrollments is updated, `DBStudents` is not. 
Now, `DBStudents` is a snapshot of that moment in `Enrollments`


### Example

ensure Alice can only view `movieExecs` who are presidents
```
create view pres as
  select *
  from MovieExec
  join Studio
  on (MovieExec.certNo = Studio.presC#);

Grant select
on pres
to alice
```