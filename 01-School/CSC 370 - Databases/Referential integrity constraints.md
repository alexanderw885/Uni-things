also called foreign keys
and cover relational algebra

after splitting data into multiple tables, how do we know which attributes are the same between tables?
what if we forget to change all related tables when adding/removing something?

linking these attributes are what's called "foreign keys".

### Relational algebra
Relational Algebra is used to formally express constraints

#### Rename operator $\rho$
rho
given R(A,B,C,D)
$\rho_{S(B,C,D,E)}(R)$ renames everything in R, and R to S

#### Projection operator $\pi$
given R(A,B,C,D)
$\pi_{(B,C)}(R)$ shows only B and C
`SELECT` in MySQL

#### Selection operator $\sigma$  
given R(A,B,C,D)
$\sigma_{A=a1}(R)$ only shows results where A=a1

#### Union $\cup$ 
just like set theory, shows all tuples in 2 sets

#### Difference -
R-S shows everything in R, not in S

#### Cross product x
RxS merges R and S, making one tables with all attributes from both

#### Natural join $\bowtie$
merges tables, removes duplicate attributes

#### Theta join
joins only tuples where condition is true

#### express in Relational algebra
Enrolments(v_number, crn, grade)
	IDs of all students with grade >=8.0 in this course
v_number is key

SQL
```sqql
SELECT  `v_number`
FROM `Enrolments`
WHERE `grade >= 8.0`
AND (`crn` = 'CSC 270');
```

ALGEBRAs
$\pi_{v\_number}\sigma_{(grade >=8.0 AND (crn = 'CSC370'))}(Enrollments)$

### How to express constraint
state the result of an expression is the empty set
$\sigma_{age >=16}(Employees)=\varnothing$
no employees can be less that 16

ex: all tuples must come from another table
every flight must depart to an airport from our table of airports
```
Airports(code, city, country, name)
flights(depart_from, arrive_at, departure_time)
```

Airports$\bowtie_{df=code}$Flights=$\varnothing$ || not quite correct

$\pi_{df}$Flights / $\pi_{ac}$Airports = $\varnothing$  || more accurate

