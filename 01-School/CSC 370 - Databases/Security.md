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