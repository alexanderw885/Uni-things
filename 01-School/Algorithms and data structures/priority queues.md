Priority queues are a type of [list](01%20types%20of%20lists).

along with working like [[queues]] (FIFO), priority queues also require a weight value, which takes precedence over the time in the queue. For example, if everything in the queue has a priority of 1 and you add something with a priority of 5, the new element will be the next thing out of the queue.

This can be implemented efficiently with [[heaps]].

when inserting into the heap, each element has its value and a priority value.
the heap is then sorted by priority.
