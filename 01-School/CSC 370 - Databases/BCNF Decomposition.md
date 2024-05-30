Boyce-Cott Normal Form

prevent anomalies by reducing to BCNF



### Keys and Superkeys
let C be set of attributes of relation $R$ and $A\subseteq{C}$ be a subset of C
A is superkey iff $\{A\}^+=C$ (every attribute in R can be determined by A)

the closure of a superkey is the entire set

A is a key iff
1. A is a superkey
2. there is no set $A'\subset{A}$ where A' is a superkey

A is minimal set that determines every attribute

![[Pasted image 20240522125545.png]]
{B} is key
{A,B,C,D}, {A,B,C}, {B,C} are superkeys

### BCNF
A relation R with attribute set C is BCNF iff:

For every non-trivial functional dependency on R, $\{a_1,A_2,...,A_n\}\rightarrow\{B_1,B_2,...,B_n\}$, $\{A_1,A_2,...,A_n\}$ is a superkey of R
so when writing out dependencies, left hand side is always key

![[Pasted image 20240522130616.png]]
```
member_id -> sin date_joined
account_id -> balance date_joined member_id
```
account_id is not a key, so not in BCNF

#### Decomposition
a decomposition split R into two relations
S with attributes $B=\{B_1,B_2.,,,B_n\}$
T with attributes $C=\{C_1,C_2,...C_n\}$
s.t.:
$A=B\cup{C}$
$S=\pi_{(B_1,B_2,...,B_m)}(R)$
$T=\pi_{(C_1,C_2,...,C_m)}(R)$

Do it recursively
if $R_0$ is BCNF form, return $R_0$
select BCNF violation with X on the left
split into 2 sets, R1 = $X^+$ (closure of X), R2 is everything else+X

ex: Schema R(A,B,C)
A->B
B->C

B is not a key, split
R1(B,C)
R2(B,A)

ex 2:
R(A,B,C,D,E)
A,B->C
C->D
D->E

R1(C,D,E)
R2(C,A,B)

R1(D,E)
R2(D,C)
R3(A,B,C)


### Lossless Decompressions
how to get original table back?
use natural join, which joins them by matching values

```sql
SELECT *
FROM `Members`
NATURAL JOIN `Accounts`;
```