
### Three-tier Architectures
how users interact with databases:
- Web servers: processes that connects users to the system
- Application servers: processes that embed the "business logic" and prepare data
- Database servers: processes that run the DBMS and executes queries

![[Pasted image 20240730125324.png]]
These days it's slightly different, as work can be done on cloud
#### Web server tier
manages all front end interactions
#### Application tier
implements logic to transform user interactions into appropriate responses to database server
usually high level, like C#
often split into sub-tiers
#### Database tier
executes queries
does not process the results

### SQL Environment
A database server may host multiple different databases, from different clients
- schema: a specific database in the server
- catalogue: collection of schemata
- cluster: collection of catalogues accessible to a given user

### Call-lever Interfaces
Combining host and SQL code
there's two options
- embed SQL code into host code, use shared variables. This approach is not used often
- Use a library to interact with the database through

##### Impedance mismatch
well designed databases are normalised, but well-designed classes in object-oriented classes are not. There can be challenges trying to mix the two languages

##### Interactions
- Single-line select: when the query is guaranteed to only return a single tuple, the attributes can map directly to variables
- Cursors: uses iterator pattern with `.next()` and `.isEnd()`, can return multiple tuples, one at a time

When connecting via library, you need to open a connection first.
Then, create a statement object with a query and a cursor.
This is done in different ways, depending on the programming language used