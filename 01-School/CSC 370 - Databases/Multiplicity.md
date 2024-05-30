sometimes there are constraints on relationships. For example, a studio could make many movies, but each movie can only be made by a single studio
this constraint can be represented as an arrow in the ERD

ex: ![[Pasted image 20240517124724.png]]
each person can use each building, and each building can be used by multiple people. But, each building can have only 1 owner.
So, if there was an ERD with `building` and `people` connected by relationships `uses` and `owns`. So you draw an arrow from building to person when related to `owns`, as the building can identify the relationship.

### Many-Many and Many-One relationships
a relationship is many-many if there are no arrows in the ERD. in the above example, the person-uses-building is many-many, as people can use many buildings, and building have many users

Many-One is like the above example with users-own-buildings. People own many buildings, but buildings have only one user

One-One relations are more uncommon, but would have the constraint arrow going in both directions

#### Many-Many
how would this be represented as a table in SQL? ![[Pasted image 20240517130043.png]]
along with the student and table classes, we use a mapping table to show the relation between the two
in this mapping table, we include the identifiers of each entity set
note that the identifiers still appear in the `student` and `class` entities

```SQL
CREATE TABLE  `Student`(
	`name` VARCHAR(64),
	`v_number` INT,
);
CREATE TABLE `Class`(
	`CRN` INT,
);
CREATE TABLE `EnrolledIn`(
	`v_number` INT,
	`CRN` INT,
	`grade` FLOAT,
);
```
grades are part of the relation between `students` and `class`, so they're also included in the mapping table

ex: ![[Pasted image 20240517130753.png]]
```SQL
CREATE TABLE `Movie`(
	`movie_id` INT PRIMARY KEY,
	`title` VARCHAR(64),
	`releaseYear` INT,
);
CREATE TABLE `User`(
	`user_id` INT PRIMARY KEY,
	`is_admin` BOOLEAN
);
CREATE TABLE `Rates`(
`movie_id` INT,
`user_id` INT,
`score` FLOAT,
);
```

#### Many-One
how do we represent this as a set of tables? ![[Pasted image 20240517131145.png]]
given a class, we know the unique instructor
so instead of making a teacher entity, we can include it in class
```SQL
CREATE TABLE `Class`(
	`crn` INT PRIMARY KEY,
	`instructor` VARCHAR(64),
);
```
it's implied that the teacher teaches the class, so we don't need the `teaches` attribute


### Take home activity
implement this in SQL ![[Pasted image 20240517132243.png]]
done in database `class-ex`