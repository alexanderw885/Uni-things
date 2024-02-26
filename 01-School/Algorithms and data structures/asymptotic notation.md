
asymptotic notation is a method of analyzing the runtime of algorithms

### Big O notation
$f(n)\in{}O(g(n))$ if there exists a $c$ such that: 
$$f(n)\leq{}c*g(n) \text{ for all } n>n_0$$
Big O notation is often used in analyzing running times for algorithms


### Little o notation
$f(n)\in{}o(g(n))$ if for all c,
$$f(n)<c*g(n)\text{ for all }n>n_0$$
note that this is a strict less than, not less or equal to
little o is a more strict category of big O
if $f(n)\in{}o(g(n))$, then $f(n)\in{}O(g(n))$


### Big omega notation
$f(n)\in\Omega(g(n))$ if there exists a $c$ such that:
$$f(n)\geq{}c*g(n) \text{ for all } n>n_0$$
This is the opposite of Big O, so:
if $f(n)\in{}O(g(n))$, then $g(n)\in\Omega(f(n))$ 


### Little omega notation
$f(n)\in\omega(g(n))$ if there  for all c, 
$$f(n)<c*g(n)\text{ for all }n>n_0$$
This is the opposite of little o, and a more strict version of big $\Omega$
if $f(n)\in{}\omega(g(n))$, then $f(n)\in{} \Omega(g(n))$
if $f(n)\in{}o(g(n))$, then $g(n)\in\omega(f(n))$ 


### Big Theta notation
$f(n)\in\Theta(g(n))$ if:

$f(n)\in{}O(g(n))$
**and**
$f(n)\in\Omega(g(n))$

This also means that:
if $f(n)\in\Theta(g(n))$, then $g(n)\in\Theta(f(n))$
