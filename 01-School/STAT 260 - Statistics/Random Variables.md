
A random variable is a function which maps each outcome of an experiment to a number.
We classify them by number of possible values it may take from the function (aka the support/support set)

Random variable is discrete is the support set is countable
Random variable is continuous if the support set contains at least one interval of real numbers

Probability mass function (pmf) of a discrete random variable $X$ is defined by $f(x)=P(X=x)$ for every $X$ in the support.

Probability distribution tables give the values and corresponding pmf for a discrete random variable

#### example
raffle sells 100 tickets
gives away one $100 prize
gives away three $20 prizes
let $X$ be the random variable representing the winnings from one ticket. find probability distribution for X

X = winnings per ticket

| x | $0 | $20 | $100 |
| ---- | ---- | ---- | ---- |
| P(X=x) | 96/100 | 3/100 | 1/100 |

EX:
probability that...
Kendall drinks wine = 0.5
Roman drinks wine = 0.95
Shiv drinks wine = 0.9
Let X be the number of bottles drunk with dinner

$P(x=0)=0.5*0.05*0.1=0.0025$
$P(x=2)=(0.05*0.95*0.1)+(0.5*0.95*0.9)+(0.5*0.05*0.9)=0.4975$
$P(x=1)=0.0725$
$P(x=3)=0.4275$

| x | 0 | 1 | 2 | 3 |
| ---- | ---- | ---- | ---- | ---- |
| f(x) | 0.0025 | 0.0725 | 0.4975 | 0.4275 |
Probability they drink at least one bottle?
$P(x \geq1)=1-P(x\lt1)= 0.9975$
or $P(x\geq1)=P(1)+P(2)+P(3)$

## Cumulative distribution function (cdf)

cdf of random variable X is defined by $F(x)=P(X\leq{x})$

for discrete rand. variable X with pmf f(x) and support set $\{x_1, x_2,...,} then the cdf is defined as:
$$F(x)=P(X\leq{x})=\sum_{X_i\leq{x}}f(x_i)$$
#### Properties
domain of F(X) is set of all real numbers
F(x) is monotone increasing
$\lim_{x\rightarrow{}- \infty}=0$, and  $clim_{x_i\rightarrow{}\infty}=1$
F(x) is right continuous, it is smooth to the right of a point but not to the left of one
if the support of X is {$x_1,x_2,...,$}, then F(x)=F(X_i)if x"i+x+...


#### examples

| x | 1 | 2 | 3 | 4 | 5 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| $f(x)$ | 0.3 | 0.15 | 0.05 | 0.2 | 0.3 |
| F(x) | 0.3 | 0.45 | 0.5 | 0.7 | 1 |
$F(1) = P(x\leq1) = f(0)=0.3$
$F(2)=P(x \leq2)=F(1)+f(2)=0.5$
...
$F(n)=P(X\leq{n})=F(n-1)+f(n)$


CDF for X, number of classes a randomly selected student is taking

| x | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| F(x) | 0.15 | 0.25 | 0.40 | 0.60 | 0.75 | 0.90 | 1 |
|  |  |  |  |  |  |  |  |

a)prob of taking no more than 3 classes
	0.4
b)F(4.5)
	=F(4)=0.6
c) P(X=4.5)
	0, not defined
d)taking at least 3 classes
	$1-P(x\leq2)=0.75$
e) taking exactly 3 classes
	$F(3)-F(2)=0.15$
f)taking at least 2, but no more than 5
	$F(5)-F(1)=0.6$
g)given they are taking at least 2 classes, what are the odds they take at most 4?
	$\frac{F(4)\cap{}F(1)}{1-F(1)}$ $$\frac{F(4)-F(1)}{1-F(1)}=0.45/0.85\approx0.529$$
