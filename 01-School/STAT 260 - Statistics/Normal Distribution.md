
$$f(x,\mu,\sigma)=\frac{1}{\sigma\sqrt{2\pi}}e^{\frac{1}{2}(\frac{x-\mu}{\sigma})^2}$$ 

peak at x = $\mu$
mean, median, variance = $\mu$
points of inflection at $\mu \pm\sigma$


**Percentile**
 $z_\alpha$ is the number such that $P(Z-z\alpha)=\alpha$
 also equals $100(1-\alpha)$
it's the percentile!

#### Example
a) find 97.5th percentile of the standard normal distribution

this means point where 97.5% of area below curve is *left* of this point
$P(Z<z_p)=0.975$

look on table for 0.975, then find z values.
$P=0.975$, $z_p=1.96$

b) find $z_{0.05}$

 look at inverse, find P= 0.95
 value is right between z=1.64, 1.65
 so $z=1.645$
 

c) find $z_{0.10}$
Table doesn't go that low, inverse is P=0.9
z between 1.28,1.29
so $z=0.1285$

d) Find $z_{0.005}$
P=0.005
find inverse on table, p = 0.995
$z$ between 2.57, 2.58
so $z=0.2575$


### Standardizing a normal distribution
is C is normally distributed with mean $\mu$ and standard deviation $\sigma$, i.e, $X\sim{}N(\mu,\sigma$
$$Z=\frac{X-\mu}{\sigma}$$
this standardizes X

#### Example

technician works over a weekend, normally distributed as (num hours)
$\mu=18$
$\sigma=4$

a) odds of less than 24 hours?
$$P(X<24)=P(\frac{X-\mu}{\sigma}<\frac{24-\mu}{\sigma})$$
 $$=P(Z<\frac{25-18}{4})$$
$$=P(Z<1.5)$$
find on table, z=1.50, so
$P=0.9332$

b) odds of less than 18?

$$P(X<24)=P(\frac{X-\mu}{\sigma}<\frac{18-\mu}{\sigma})$$$$=P(Z<\frac{18-18}{4})$$
$P(Z<0)$
$P=0.5$

c)prob between fifteen and 23?

$P(15<X<23)$
$P(X<23)-P(X<15)$
$P(Z<1.25)-P(Z<-0.75)$
$0.8944-0.2266$
$=0.6678$

d) Largest num. hours $k$ such that the technician works well than $k$ hours 10% of the time
find z such that $P(X<k)=0.1$

$P(Z<\frac{k-18}{4})=0.1$
$z=-1.28=\frac{k-18}{4}$
$k=12.88$


e) prob that over 50 weekends, there are exactly 41 weekends of less than 24 hours
first, find $P(X<24$)
then, random variable Y counting num weekends s.t. technician works less than 24 hours.

$P(Z<1.5)=0.9332$

$Y\sim{}Bin(50, 0.9332)$

$P(Y=41)=_{50}C_{41}(0.9332)^{41}(1-0.9332)^9$
 $=0.0039$

### Approximating Binomial Dist. with Normal Dist.

Suppose $X\sim{}Bin(n,p)$ where $np$ and $n(1-p) are both at least 5, then:
 
 $$X\approx{}N(\mu=np,\sqrt{np(1-p)})$$

better with a continuity correction
$$P(X\leq{}x)\approx{}P(X\leq{}x+0.05)$$
$$\approx{}P(Z\leq\frac{x-np+0.5}{\sqrt{np(1-p)}})$$

## Example
suppose 15% batteries have shorter lifespan then advertised.
suppose 200 batteries are selected at random.
What is prob. at least 20 have shorter lifespan?
X= num. batteries with short lifespan
$X\sim{}Bin(200,0.15)$
want $P(X\geq20)$

$np=30, n(1-p)=170$
both pass test, can approx. with normal dist.
$$X\approx{}N(\,u=30, \sqrt{0.15(170)})$$
$$X\approx{}N(30,\sqrt{25.5})$$
$P(X\geq20)=1-P(X\leq19)$
$$=1-P(Z<\frac{19.5-30}{\sqrt{25.5}})$$
