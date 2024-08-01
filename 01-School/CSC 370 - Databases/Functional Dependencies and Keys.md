#### Review
data model: notation for describing information. three parts
fixed type of structure
set of permitted operators
language for expressing constraints


### What is a relation?
a relation is a definition of a two-dimensional table
a relation instance is a two dimensional table with information in it
could be described with notation:
Movies(title, year, length, genre)
each row in a table is a "tuple"

Instance equivalence:
same information in the table, but maybe in a different order. tuples are unordered, like sets 

#### Domains
each attribute has a fixed domain/datatype
domain must be an elementary type
all tuples must have a value from that attribute's domain

### Data Anomolies
what's wrong here? ![[Pasted image 20240521124640.png]]
in this, we're giving Bob Alices' v_number
this won't cause an error message, creates a data anomaly. This is due to an issue in design
this is an **insertion anomaly**

there are also  **update anomalies** where you don't update everything you intended,
and **Deletion anomalies**, where you delete more than intended

all of these come about due to redundancy in the table
this could have been solved by splitting the data into two tables, one for students and one for classes

what can go wrong here? ![[Pasted image 20240521125241.png]]
memberId, sin, date_joined are all repeated for each account they hold, creating redundancy.
fix this by splitting into two tables, `Member` and `Account`, where `Member` is constrained by `Account`

if we deleted account 10331, we would entirely lose member 000222
we could insert a new account but input member id wrong, creating insertion anomaly
we could update a member id in only some places, creating update anomaly

### Functional Dependency
in the above table, given the sin, we could find member_id or date_joined, even though it isn't an identifier. This means the sin number is a key

consider schema $R(C_1,C_2,...,C_k)$ and let $C=\{C_1,C_2,...C_k\}$ be set of attributes
Let $A=\{A_1,A_2,...A_n\}\subseteq{C}$ and $B=\{B_1,B_2,...B_m\} \subseteq{C}$.
A functionally determines B iff:
for every two tuples R, if they have same values for all attributes in A, they must have all same attributes in B

![[Pasted image 20240521130516.png]]

`title -> year length genre studioName`

but it is possible that a movie has same title, but different year. If we make this a functional dependency, that means no other movies could have the same title

`title year -> length genre studioName`

**From a relation instance, we can narrow down potential functional dependencies, but can't definitively declare them**

###  Computing a closure

#### Rules

Combining rule:
```
album ->label
album->artistName
----
album -> label artistName
```

splitting rule 
```
album -> label artistName
___
album ->label
album->artistName
```

transitivity
```
album->artistId
artistId->artistName
___
album->artistName
```

triviality
```
album songName -> album writer
___
album songName -> writer
```

### Closure
given some information, how much can we know
consider:
```
A->C
BC->D
C->B
```
what is the closure of {A}?
A defines C which defines B
now we have BC which defines D
{A} += {A, B, C, D}

what is the closure of {B}?
no functional dependencies on just B
{B}* = {B}

## Keys
if from a subset you can define all attributes, that subset is a key