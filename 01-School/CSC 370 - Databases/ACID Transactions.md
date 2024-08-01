batch SQL queries into transactions to achieve appropriate level of atomicity

A- Atomicity
C - Consistency
I - Isolation
D - Durability

# [[Atomicity]]
Transactions should occur atomically, i.e. be indivisible
each query is atomic, and cannot be broken down.

sometimes, we want multiple queries to execute, but only *all or *none*. Bundling queries together as a single transaction is how we specify atomic units of logic, which would otherwise be taken as an individual query

### example:
which is an atomicity failure?
![[Pasted image 20240612125410.png]]
the bottom right is the atomicity failure in the database
# Consistency
transactions should never leave the database in an inconsistent state, or *inconsistent with design intent*

after every transaction, every requirement for the database is met. At no point is the database in an inconsistent/wrong state
### Examples
which have consistency failure?![[Pasted image 20240612130100.png]]
Bottom left *could be* a consistency failure, deleting a tuple referenced by a foreign key puts the table containing the foreign key into an inconsistent state, depending on the policy
cascade would allow it, 
reject would prevent it
setNULL would imply this is an intended action

bottom right would be a violation, ages would not be supposed to be negative
# [Isolation](Concurrency) (serializability)
results of a transaction should be viewed as independent of other concurrent transactions

users should not be able to tell that other users are accessing the database

### Example
which is isolation failure?
![[Pasted image 20240612130726.png]]
top right is the isolation failure, along with a durability failure. Your actions were dependent on someone else's current activity in the database, which was then reversed
# [[Durability]]
once a transaction is committed, it is permanent
In a database, you want to prevent data loss

### Examples
which is durability failure?
![[Pasted image 20240612131538.png]]
top left is the durability failure, there was data loss in that a transaction that did occur is not shown

