simplify conceptual designs using entity sets that are defined in terms of other entity sets
## generalisation
defines one concept as a specific type of another concept (inheritance in OOP)
represented with a black arrow in the relation line
in this example, vehicle is the generalisation, and bicycle and car are both specialisations
![[Pasted image 20240621124048.png]]
(Arrows should point to the generalisation/super class)
Why use them?
- They can allow for more precise constraints
- They can allow for more expressive relationships

### Subsets as tables
primary key in the specialisation is a foreign key to the generalisation
```sql
CREATE TABLE Worker (
    id INT PRIMARY KEY
    name VARCHAR[32]
);

CREATE TABLE PermanentWorker (
    id INT PRIMARY KEY
    pr_date DATETIME NOT NULL
    FOREIGN KEY(id) 
    REFERENCES Worker(id)
);
```
here, `PrimaryWorker` is a specialisation of `Worker`


### Ex
implement this
![[Pasted image 20240621125350.png]]

```sql
CREATE TABLE Vehicle(
	id INT PRIMARY KEY
)

CREATE TABLE Student(
	id INT PRIMARY KEY
)

CREATE TABLE Bicycle(
	id INT PRIMARY KEY
	FOREIGN KEY (id)
	 REFERENCES Vehicle(id)
)

CREATE TABLE Owns (
	
)

CREATE TABLE Competes_with(
	bicycle INT
	student INT
	FOREIGN KEY (bicycle)
	 REFERENCES Bicycle(id)
	FOREIGN KEY (student)
	 REFERENCES Student(id)
)
```

## Weak Entity Sets
a Strong Entity Set E is one in which the identifiers are a subset of the attribute E

a Weak Entity Set E has part of its identifier come from some other entity set E'
![[Pasted image 20240621130002.png]]
here, Species is a weak entity set, as it relies on Genus.name for its identifier
![[Pasted image 20240621130343.png]]

#### Examples
![[Pasted image 20240621130453.png]]
1. how could we record which students are SENG?
ideas
- is_seng attribute
- student_dept attribute
- seng subclass of student
- enum of course_id
- programmed entity set with relationship to student

