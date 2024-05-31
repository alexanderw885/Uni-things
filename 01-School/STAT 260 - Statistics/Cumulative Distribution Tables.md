
continuation of [[Variance]]

Table that gives $P(X\leq{}x)$ for small values of $n$, and "nice" values of $p$
ONLY give cumulative probabilities

# Examples

25% of tablets need repairs within 2 years. suppose 12 tables
$X\sim{}bin(12,25)$
Table on Brightspace

a)no more than 6 tablets
6 or less
on table, $0.9857$

b) exactly 5 tablets
5 or less - 4 or less
$0.9456-0.8424=0.1032$

c) at least 3 repairs
1-2 or less
$1-0.3907=0.6093$

d) given at least 3 repairs, what are odds of at most five?
$\frac{P(X\leq5)-P(X\leq2)}{1-P(X\leq2)}$ 
$$\frac{0.9456-0.3907}{1-0.3907}=0.9107$$

c) if 10 departments each get 12 tables, what is prob that exactly 6 departments have at least 3 tablets to repair
Y=num. departments that need 3 repairs
prob. success was in part c
$Y\sim{}bin(10,0.6093)$
P(Y=6)
$$_{10}C_6(0.6093)^6(1-0.6093)^4\approx0.2504$$