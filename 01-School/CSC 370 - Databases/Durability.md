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

# Undo Logging
a log file is an append-only record of important events. If the log file is in non-volatile storage, then we can use it to restore database to previous state.

operations:
```
<START T>
- transaction T has commenced
<COMMIT T>
- transaction T has completed
<ABORT T>
- transaction T has been reverted
<T,X,v>
- transaction T changed value X, which used to be value v
```
Note that you do not save value X, just that it used to be v
## Undo logging
1. If transaction T modifies X, the log record must show `<T,X,v>` *before* X is outputted to disk
2. If transaction T commits, then it's `<COMMIT>` log record is output *after* database elements were outputted
![[Pasted image 20240618124756.png]]
in this case, we can read the LOG file backwards.
look at `<T,B,84>` and change B back to 84
look at `<T,A,42>` and change A back to 42
now that we're back at `<START T>`, we know we've undone the transaction

### Checkpointing
what if we don't want to have to undo the entire log file?
we can make checkpoint marks in the log file whenever the database is in a consistent state
`<CKPT>`
when undo logging, you only have to go back until finding a `<CKPT>`, at which point we know the database is consistent and can stop

How do we make one?
- first, stop accepting any new transaction
- wait for all transactions to complete
- flush log to disk
- write log record `<CKPT>`
- flush to disk again
- resume accepting transactions

The trouble with this is that you need to halt *all* checkpoints, which can be very disrupting to the database

instead, you can use
#### Nonquiescent Checkpointing
- Write `<START CKPT(T1, T2, T...)>`
- flush log
- wait for T1, T2, ... to finish, but don't prevent new transactions
- write `<END CKPT>`
- flush log again

lets say this is our log after a crash:![[Pasted image 20240618125757.png]]
here, T3 started but was not completed
- return E back to 30
- see the checkpoint has ended, so we may need to skip some transactions
- see T1, T2 are committed, so we do not need to change any of their transactions
- see `<T1, D, 20>`, ignore it since we saw T1 commit
- see START(T3), note it has been aborted
- end, since all transactions after `END CKPT>` have been reversed

## Redo Logging
instead of undoing all transactions since last commit, we use the log to reapply incomplete transactions
 Before writing X to disk:
- all log records `<T,X,v>` must be output to disk
- `<COMMIT T>` must be flushed to disk. 

![[Pasted image 20240618130535.png]]
Note that this time v is what X changed *into*
___

![[Pasted image 20240618130345.png]]

### Undo/Redo Logging
combines both methods together
this means you record both what X was, and what X was changed to
`<T,X,prior,new>`