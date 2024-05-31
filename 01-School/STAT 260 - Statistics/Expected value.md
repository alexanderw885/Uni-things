
Let X be a discrete, random variable. The expected value or mean of X denoted  $E(X)$ or $\mu_X$, or if the context is clear, just $\mu$
$$E(X)=\mu=\sum_{all x}x*f(x)$$



#### Example
raffle of 100 tickets, one draw wins $38. You buy 3 tickets for $5
what is avg net winnings?
X=net winnings = E(X)

|  $x$ | $-5 | $33 |
| ---- | ---- | ---- |
| f(x) | $97/100$ | $3/100$ |
$$E(X)=(-5)\frac{97}{100}+(33)\frac{3}{100}=-3.86$$
if you play the raffle, you can expect to lose $3.86 each time you buy three tickets.


| x | 5 | 15 | 100 |
| ---- | ---- | ---- | ---- |
| f(x) | 1/3 | 1/4 | 5/12 |
$$E(X)=5/3+15/4+500/12=47.08\bar3$$


Insurance company wants to sell policy for $c per year.
there's a 0.02$ chance of flood, costing $75,000
what is minimum c to break even?

| x | c | -75,000+c |
| ---- | ---- | ---- |
| f(x) | 0.998 | 0.002 |

$$E(X)=0.998c+0.002(c-75,000)=0.998c+0.002c-150$$
we want E(X) to be zero, so we can say
$$0=1c-150$$
$$c=150_\blacksquare$$


Given this cdf, find E(X) (normally have used pmf)

| x | 0 | 1 | 2 | 3 |
| ---- | ---- | ---- | ---- | ---- |
| F(x) | 0.1 | 0.65 | 0.85 | 1 |
first, convert to pmf (probability mass function)

| x | 0 | 1 | 2 | 3 |
| ---- | ---- | ---- | ---- | ---- |
| f(x) | 0.10 | 0.55 | 0.20 | 0.15 |
$$E(X)=0(0.1)+1(0.55)+2(0.2)+3(0.15)$$
$$=0.55+0.4+0.45=1.4$$


### not an example
if X is random variable, Y=g(x), then Y is a random variable and:
$$E(Y)=E(g(Y))= \sum{}g(x)P(X=x)=\sum{}g(x)f(x)$$
__Note__: $E(g(X))\neq{}g(E(X))$
 
### now an example

for the last example, find $E(X+2)$ and $E(X^2)$

| $x^2$ | 0 | 1 | 4 | 9 |
| ---- | ---- | ---- | ---- | ---- |
| x+2 | 2 | 3 | 4 | 5 |
| x | 0 | 1 | 2 | 3 |
| F(x) | 0.10 | 0.55 | 0.20 | 0.15 |
$$E(X+2)=2(0.1)+2(0.55)+3(0.2)+5(0.15)=3.4$$
$$E(X^2)=0(0.1)+1(0.55)+4(0.2)+9(0.15)=2.7_\blacksquare$$

### Laws of expected values
X is rand. variable, a, b are constants

$E(b)=b$
$E(X+b)=E(X)+b$
$E(ax)=aE(x)$

$E(ax+b)$ can be notated as $\mu_{aX+b}$

### More examples

if X has expected value 3.4, what is E(5X+2)?
$5E(X)+2$
$=19_\blacksquare$


PMF of bikes sold each day

| x | 0 | 1 | 2 | 3 | 4 | 5 |  |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| f(x) | 0.1 | 0.1 | 0.15 | 0.25 | 0.2 | 0.2 |  |
fixed daily cost of $75
bike sells for $250
costs $100 to make a bike
Y=revenue-cost-expenses
Y=250-100-75
 $E(Y)=E(150x-75$)

$$E(X)=0(0.1)+1(0.1)+2(0.15)+3(0.25)+4(0.2)+5(0.2)=2.95$$
$$E(Y)=150(2.95)-75=367.5/day_\blacksquare$$