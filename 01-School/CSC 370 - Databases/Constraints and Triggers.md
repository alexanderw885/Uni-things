users can obtain and purchase tickets
users have unique username and must report their age
artist can only play one concert a day

Triggers are code specified to run on an event

make 3 entities
- users
	- username primary key
	- age
- shows
	- date
	- artist
		- date and artist as identifiers
- tickets
	- ticket_id

relation table connecting all 3
many users, many shows, to one tickets
- ticketedTo

Tickets(**ticket_id**)
Users(**username**, age)
Shows(**date**, **artist**)
TicketedTo(**username, date, artist** ticket_id)

## more constraints
#### age cannot be negative
$\sigma_{age\ is\ null\ \lor\ age<0}(Users)=\emptyset$ 
```sql
ALTER TABLE `Users`
  MODIFY COLUMN `age` INT NOT NULL
    CHECK(`age` >= 0);
```
#### shows cannot be booked over capacity
(this method will de-normalise database)

Shows(**date**, **artist**, capacity, tickets_sold)
$\sigma_{sold\gt{}capacity}(Shows)=\emptyset$
```sql
ALTER TABLE `Shows`
  ADD COLUMN `sold` INT
  ADD COLUMN `capacity` INT 
    NOT NULL DEFAULT 100;

ALTER TABLE `Shows`
  ADD CHECK(`capacity` >= `sold`);
```
This is a bad way of doing it, but it was to get across an idea
#### some shows are adult only (19+)

Shows(**date**, **artist**, capacity, tickets_sold, adult_only)
$\sigma_{age < 19 \land{}adult\_only=TRUE}(Users\bowtie{}TicketedTo\bowtie{}Shows)=\emptyset$
```sql
ALTER TABLE `Shows`
  ADD COLUMN adult_only BOOLEAN;

CREATE ASSERTION
(
  -- not in mysql, very expensive
  -- need different design, or to push to application layer
);
```

- when ticket is purchased, increment sold counter
```sql
DELIMITER $$

CREATE TRIGGER `inc_sold`
BEFORE INSERT ON `TicketedTo`
FOR EACH ROW
  BEGIN
	UPDATE `Shows`
	SET `sold` = `sold`+1
	WHERE `artist` = NEW.`artist`
	  AND `date` = NEW.`date`;
  END
$$

DELIMITER ;
```
OLD refers to tuple iterating through, just for updates
NEW refers to tuple after the trigger, always use in insertions