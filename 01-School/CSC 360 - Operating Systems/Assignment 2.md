
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

make a convar on queue having any customers in it
make boolean `queue_closed`, set true once all customers in file are in the queue. Once `queue_closed == true && queue.isEmpty`, end thread 
### Order of Operations
global:
- queue
- mutexes
- convar

main:
initialize queue
read customers into queue + sort queue
initialize queue mutex
initialize averages mutex
initialize 5 clerk threads
initialize one arrival thread
\-\-\-
join all 5 threads
destroy mutex
destroy convar

threads:
wait for mutex+convar to unlock
lock mutex
pull from queue
- if empty, exit thread
- if not empty, pull customer
signal convar
unlock mutex
deal with customer
loop to start