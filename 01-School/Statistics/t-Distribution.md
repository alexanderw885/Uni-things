suppose $X_1,X_2,...,X_n$ are random sample from normal/near-normal population
$\sigma$ is **not** normal
$n$ is **not** large

the test statistic $$t=\frac{\bar{X}-\mu}{s/\sqrt{n}}$$
is **t-distributed** with n-1 degrees of freedom
as t increases, it gets closer to normal value
#### Properties
1. t-dist. is continuous on $(-\infty,\infty)$
2. symmetric, mound-shaped, centered on 0
3. as degrees of freedom increases, distribution becomes more peaked, tails thinner
4. with large number of degrees of freedom, approximates standard normal distribution

the t-dist. has mean=0 and variance $\frac{\nu}{\nu-2}$ for $\nu>2$, where nu $(\nu)$ is num. degrees of freedom

the t-tables give critical values so $t_{\nu,\alpha}$ is score in the t-dist. with $\nu$ degrees freedom, and $\alpha$ % above the value.

### how to read
$P(t_5>1.5)$
$t_5->\nu=5$
or
$t_{1.5,5}$
$\nu=5$

###  Example
find score with 10 degrees freedom and 5% of scores above
$\nu=10$
find score such that 0.05 is above it, or $\alpha=0.05$
on table

$1.812$
___
find the tightest possible bounds of the following

a) $P(t_{13}>1.64)$
$\nu=13$
find on table, to get alpha values
not exactly on table, $0.10>\alpha>0.05$ 

b) $P(T_{23}>0.14)$
$\nu=23$
find 0.14 on table, get alpha value
$0.15>\alpha>0.10$
___
**Just like normal distribution, symmetrical around $\mu=0$. You can use this to get negative values**. 
___
find $P(t_{23}<-2.300)$
$\nu=23$
less than negative means more than positive via symmetry
find 2.300 on table
$-0.015<\alpha<-0.02$ 

## Confidence interval for $\mu$ when n is small, $\sigma$ is unknown

$$\bar{x}\pm{}t_{n-1,\frac{\alpha}{2}}*\frac{s}{\sqrt{n}}$$
$\bar{x}$ is the estimate
$t_{n-1}$ is critical value
$s\sqrt{n}$ is standard value


### examples

7 mice weights
14.6, 13.2, 19.5, 10.1, 8.8, 15.5, 16.1
assume normally distributed
find 95% confidence value

__n is small, $\sigma$ unknown__
$\alpha=0.05$
need s, $\bar{x}$, $t_{n-1}$ 
$\bar{x}$ on calculator, = 13.9714
s on calculator = 3.6550
n=7
find $t_{6,0.025}$ on table = 2.447
$t\frac{s}{\sqrt{n}}$
$\frac{(2.447)(3.6550)}{\sqrt{7}}=3.3804$

$$CI(95\%)=13.9714\pm3.3804$$
