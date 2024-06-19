things are concurrent if they're happening at the same time
Remember the isolation principle of ACID, each transaction should be independent of other concurrent transaction

if two threads are running at the same time, and they both try to change the same data, some data may be lost. How can we prevent this?
### Transaction Schedules
we can plot events on a "schedule"
![[Pasted image 20240619124805.png]]

in this case, t2 is reserving the seat after T1, overwriting T1's seat

![[Pasted image 20240619125535.png]]
Here, the database will treat the transaction as a dirty write, even though the output is the same no matter the order. **The database does not look at details, only the reads and writes**
## Conflict serializability
we can simplify terminology.
replace read with R, write with W
number to indicate transaction ID (R1, W3)
in parenthesis is database element R1(A), W1(A)

a transaction is serial if each transaction ends before the next transaction begins
but serial transactions are just a queue, it will take a long time to get to each transaction. Can we execute *non-serial* schedules?

a serializable schedule is equivalent to a serial schedule if: For all possible inputs, the schedule produces the same output as some serial schedule
![[Pasted image 20240619130153.png]]
the first example is serializable, the second example is serial

how can we tell? We check for conflicts
a conflict is a pair of operations by different transactions where:
- the operations use the same database elements
- At least one operation is a write

conflicts in above examples
- R1(B), W2(B)

schedules are conflict equivalent if you can swap adjacent elements to turn the schedule into one without conflicts

## Isolation Levels

#### Read-only transactions
all read-only transactions are conflict-serializable, since there can't be any conflicts

### Serializable (snapshot isolation)
can be done with [[Mutex]]
### Repeatable read (default)
```
SET TRANSACTION READ WRITE
	ISOLATION LEVEL READ COMMITTED
```
guarantees that if you read the same row multiple times, it will always be the same
### Read committed
```
SET TRANSACTION READ WRITE
	ISOLATION LEVEL REPEATABLE READ
```
Will only read committed data, but it could change if you read it twice
### Read uncommitted
```
SET TRANSACTION READ WRITE
	ISOLATION LEVEL READ UNCOMMITTED
```
allows dirty reads

![[Pasted image 20240619131716.png]]