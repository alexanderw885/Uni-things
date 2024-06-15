Logging and Recovery
in unused content, info in Parity and RAID schemes

completed changes in a database, that should not be lost

Correctness principle: If a transaction begins in a consistent state, then it ends in a consistent state

## Is just flushing to disk enough?
physically what happens in a transaction?
- read data from disk into memory
- load into registers
- perform calculations
- store back to memory
- write back to disk
at what point, is data committed?

### Operations
INPUT(X) - copy from disk into memory
READ(X, t) - transaction reads from memory into variable t
WRITE(X, t,) - store variable t into memory
OUTPUT(X) - copies from memory to disk

let there be constraint that A = 2b
Transaction T1:
A:= A\*2
B:= B\*2 
![[Pasted image 20240614131549.png]]
What if we lost power between OUTPUT(A) and OUTPUT(B)? Then our transaction was saved only partially, violating the constraint