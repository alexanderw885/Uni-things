NULL is like an unknown value, in boolean logic it can be treated like it could be true or false. Any logic that depends on NULL must also be NULL
### Logic 
NOT NULL = NULL

truth table

| values |      | AND  | OR   | XOR  |
| ------ | ---- | ---- | ---- | ---- |
| 1      | NULL | NULL | 1    | NULL |
| 0      | NULL | 0    | NULL | NULL |
| NULL   | NULL | NULL | NULL | NULL |

you can treat these operators like arithmetic operators on 0 and 1
AND is like multiplication              or MIN()
OR is like addition (saturation)    or MAX()
XOR is like addition (MOD 2)
NOT is like 1-x

in this setup, you could treat NULL as 0.5 for these basic operators

More operators

| values |      | =    |
| ------ | ---- | ---- |
| 1      | NULL | NULL |
| 0      | NULL | NULL |
| NULL   | NULL | NULL |
Equal is used fairly often

What about natural joins?
Since NULL can be treated as unknown, it is not used at all in natural join

Distinct?
despite not being known, NULL is considered a distinct value and will show up only once

Same for group by
You can group by an attribute and NULL values will be grouped together.
NULL is considered less than 0 for sorting

In a left outer join, it creates a NULL value to match any unmatched input, including NULL values
also good to look into COALESCE()
### Constraints
since NULL is unknown, when comparing it to another value (<, >), it is returned as it may fulfil the constraint

can you have a null primary key?
you cannot! behaviour may vary depending on type of database/language, but you cannot have a null key
Therefore, it can't be used for a foreign key either

could it be used in a functional dependency?
remember,  an be written as:
(t.a == u.a) -> (t.b == u.b)

| left side is true | right side is true |     | Result    |
| ----------------- | ------------------ | --- | --------- |
| 0                 | NULL               |     | true      |
| 1                 | NULL               |     | NULL      |
| NULL              | NULL               |     | undefined |
since a key can never be null, the left side can never be null, meaning we never get undefined behaviour
Functional Dependencies can not be NULL values