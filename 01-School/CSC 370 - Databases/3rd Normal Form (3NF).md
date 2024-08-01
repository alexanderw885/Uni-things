#### Review
Closure of a set of attributes are all attributes that can be determined from that set
two sets of functional dependencies are equivalent iff they have same closing set
	This means the two sets are basis for each other

a set of FDs form minimal basis iff
- every FD has singleton on right hand side
- if any FD is removed, no longer a basis
- if we remove any attribute from left hand side, no longer a basis
to project functional dependencies make power set of all FDs, remove trivial/semi-trivial FDs, then reduce to minimal basis
- this makes all dependencies for a subset

### Dependency preservation
with [BCNF](BCNF%20Decomposition), it's possible to lose constraints when performing the decomposition

### Prime Attributes
an attribute is prime iff it is part of a [key](Functional%20Dependencies%20and%20Keys) (Not a superkey)
example:
```
CinemaShowings(city, theatre, title)
theatre -> city
city, title -> title
```
in this, {theatre, city} is only key. Thus, theatre and city are prime
BCNF will usually lose constraints if some FD has antecedent involving prime attr that is not a key


example:
```
R(A,B,C,D)
A -> BC
AC -> D
C -> A
```
in this example, A, C are prime and keys

# 3NF
a relation R over attributes C with functional dependencies F is 3NF iff
- Every FD in F is in 3NF

and FD d:X -> Y is in 3NF iff:
- X is superkey
- OR
- every attribute in Y is prime

lets revisit theatre example:
```
CinemaShowings(city, theatre, title)
theatre -> city
city, title -> title
```
in first FD, city is prime, so it is in 3NF
in second FD, {city, title} is superkey, so it is in 3NF

### to make 3NF:
1. Let G be minimal basis for F
2. create functional dependency X->Y in G
	- create sub-relation by projecting R onto X union Y
3. if no sub relation has superkey for R, create sub relation with some key
4. return all sub relations

#### Example
![[Pasted image 20240703125750.png]]
1. turn each FD into relation
R(city, title, theatre)
S(theatre, city)
T(title, genre)
2. create functional dependency X->Y
U(theatre, city, start_time)