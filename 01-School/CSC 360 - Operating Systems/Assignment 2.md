
check-in with 2 queues and 5 clerks
Queue 0 is economy
Queue 1 is business

FIFO, but business has priority. All business are served before any economy

#### Customers
Class type: business or economy
Arrival time
Service time: time required to serve, 10th of a second


create queue outside of any function and you won't need to share it in pthread creation
then you have to deal with synchronization
make pulling from queue a critical section?