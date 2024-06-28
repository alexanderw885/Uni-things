correctly project set of functional dependencies onto sub-relation, and produce a minimal basis
![[Pasted image 20240626124340.png]]
in top left, B defines C, but not on the left. Not in BCNF
same for bottom right
bottom left is good

What about top right?

### Bases
closure of a set of functional dependencies is: The closure of all possible subsets of attributes
![[Pasted image 20240626124909.png]]

basis of a set of functional dependencies
two sets of functional dependencies are equivalent iff: They have same closure set
if two sets are equivalent, they are a basis for each other
![[Pasted image 20240626125209.png]]
so if all three sets of functional dependencies have the same closure, they would be basis for each other.
ex: ![[Pasted image 20240626125637.png]]
```
F
{A}+ = {A,B,C}
{B}+ = {A,B,C}
{C}+ = {A,B,C}
{A,B}+ = {A,B,C}
{A,C}+ = {A,B,C}
{B,C}+ = {A,B,C}
{A,B,C}+ = {A,B,C}

F'
{A}+ = {A,B,C}
{B}+ = {A,B,C}
{C}+ = {A,B,C}
{A,B}+ = {A,B,C}
{A,C}+ = {A,B,C}
{B,C}+ = {A,B,C}
{A,B,C}+ = {A,B,C}
```
in this case, we could have stopped once we saw every attribute was a super key. Since both sets of FDs have the same closure, they are equivalent, therefore are basis of each other.

### Minimal Bases
A set of functional dependencies form a minimal basis iff:
- every FD has single value on right hand side
- if any FD is removed, we no longer have a basis
- if we remove any attribute from the left hand side of any FD, we no longer have a basis

so the image in the previous example is a minimal basis.
the first rule is optional, depending on the source
ex: which of these are minimal?
![[Pasted image 20240626130248.png]]
F is not minimal, has multiple values on right hand side in a FD
F' is not minimal, we can remove A from AB->A and still have a basis
F'' is not minimal, we can remove D->A and still have a basis
So **none** are a minimal basis


calculating a minimal basis:
if we have a set of functional dependencies, how do we produce a minimal basis?

TODO

### Projecting FDs
lets project R(A,B,C,D) onto S(A,B,C), then project following FDs onto S as well:
A->B
B->D
CD->E

![[Pasted image 20240626131213.png]]
first, remove all trivial and semi-trivial cases
![[Pasted image 20240626131241.png]]
Now remove everything not in S (remove every D,E)
![[Pasted image 20240626131330.png]]
this leaves us with:
A->B
AC->B
which we can reduce by removing the redundant FD into:
A->B

Example 2:
project R(A,B,C,D,E) onto S(A,C,E)
A->B
B->D
CD->E

calculate closure of all non-empty subset
A->A
C->C
E-->E
AC->ACE
AE->AE
CE->CE
ACE->ACE

remove all trivial/semi-trivial
~~A->A~~
~~C->C~~
~~E-->E~~
AC->~~AC~~E
~~AE->AE~~
~~CE->CE~~
~~ACE->ACE~~
this leaves us with just:
AC->E