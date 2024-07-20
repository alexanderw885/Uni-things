Queues are a type of [list](01%20Types%20of%20lists.md).

can be implemented with [[arrays]] or [[linked lists]].

in a queue, you can only remove the first-added item (FIFO). It can be compared to the lines for a till in a grocery store, you enter at the back and wait for everyone in front of you to check out before you.

operations
- enqueue(n)
	- O(1), adds n to back of queue
- dequeue()
	- O(1), removes front element of queue
- isEmpty()
	- O(1), returns true if queue is empty
- size()
	- O(n), returns integer length of queue