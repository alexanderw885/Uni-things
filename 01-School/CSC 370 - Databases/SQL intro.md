### What is a relational Database?
we store data in tables

| Name    | Age |
| ------- | --- |
| 'Alice' | 22  |
| 'Bob'   | 21  |
Rows are "tuples"
Columns are called "attributes", and have fixed types (each column only carries one data type)

the structure is a "relation"
the data is a "relation instance"

SQL has many base data types, but some notable changes
CHAR(n) is fixed-length string
VARCHAR(n) is variable length up to n
DATE: YYYY-MM-DD
TIME: HH:MM:SS. milliseconds
ENUM: can define custom behavior

a database often has many tables, that can be linked together. An example of a table that can go with the table at the top of the file:

| Name    | Course   |
| ------- | -------- |
| 'Alice' | 'CSC370' |
| 'Bob'   | 'CSC360' |

### SQL and Declarative Programming

Procedural programming is like C
- define functions, call functions from main
OOP is like java/C++
- Define classes with functions, create instances from main

**Declarative doesn't focus on how, only what to do**

this code receives everything from a table called Table

```
SELECT *
FROM 'Table';
```
This isn't saying *how* to return everything from Table, just to do it however the computer thinks is best.

Other languages can have declarative statements, like python's list comprehensions.

#### Why Declarative?
more layers of abstraction increases efficiency by:
- letting you focus on getting the correct results
- letting the compiler do what it thinks is best

### SQL CREATE TABLE Statements

there are three components of a database language

 *Data Definition Language*: declare what schemata should exist in database
*Data Manipulation Language*: 



```
CREATE TABLE Trees(latinName VARCHAR(20)
			, englishName VARCHAR(20)
			, type ENUM('deciduous', 'evergreen))
```
to Delete: DROP TABLE Trees
to alter and preserve contents: ALTER TABLE Trees \<change\>

to make example table at top of page:
```
CREATE TABLE `Student`(
   `Name` VARCHAR(32)
   ,`Age` INT
);
INSERT INTO `Student`
VALUES('Alice', 22);
INSERT INTO `Student`
VALUES('Bob', 21);
```
and the other example table:
```
CREATE TABLE Enrolments(
   name VARCHAR(32)
   ,Class CHAR(7)
);
```
note that you can use backticks around keywords, but do not have to. Strings require single apostrophes

