
Poisson process:
1) number of successes that occur in any interval of space/time is independent of the number of successes in any other non-overlapping interval NO REPETITION OF INTERVALS
2) the probability of one success in a small interval is proportional to the size of the interval. prob of more than one success in this small interval is negligible
3) if two non-overlapping intervals have the same size, then the probabilities of successes are the same for both intervals


Poisson Random variable X counts num. successes that occur in one interval in Poisson process

 $X\sim{}Poisson(\lambda)$, where lambda $(\lambda)$ is avg. successes per interval
 some books use $\mu$ instead
 
pmf for Poisson Random Variables
$$P(X=k)=\frac{e^{-\lambda}\lambda^k}{k!},k=0,1,2,...$$

If  $X \sim{}Poisson(\lambda)$, then:
$$E(X)=V(X)=\lambda$$
### examples
suppose average of 2 accidents per day
$\lambda=2$
$X\sim{}poisson(2)$
a) prob of 3 accidents in a day
$$P(X=3)=\frac{e^{-2}2^3}{3!} \approx0.180$$

b)odds of at least 1 accident
1-P(X=0)

$$1-\frac{e^{-2}2^0}{0!}=1-e^{-2}=0.865$$

c)prob that at most 2 days in the week have at least 1 accident
Y=num. days that have at least 1 accident
$Y\sim{}bin(7,0.865)$
0.865 calculated in B
$$P(Y\leq2)=P(0)+P(1)+P(2)\approx0.000742$$

**Sometimes you need to scale $\lambda$ according to length of interval**

Josh used to get about 1.5 calls per hour

a) prob of getting exactly 10 calls in 8 hours?
X= # calls in 8 hour shift
$\lambda = 1.5*8=12$
$X\sim{}Poisson(12)$

$P(X=10)$, so $k=10$
$$P(X=10)=\frac{e^{-12}12^10}{10!}\approx0.1048$$

b) expected number of calls in a 12 hour shift
X = num. calls in 12 hours
$\ lambda = 12*1.5=18$
$X \sim{}Poisson(18)$
$E(X)=18$

c) what is standard deviation of calls in 12 hour shift?
$X \sim{}Poisson(18)$
$V(X)=18$
$$S_X=\sigma_X=\sqrt{V(X)}\approx4.2426$$


also have [[Cumulative Distribution Tables]] for Poisson variables
$(P(X\leq{}k))$
page 7 on table sheets

### Example:
road has average of 3 potholes per square kilometer of road
X = num potholes
$X\sim{}Poisson(3)$
$P(X=0)=P(X\leq0)$

a) odds of no potholes?
 $$P(X=0)=\frac{e^{-3}e^0}{0!}=0.0498$$
b) at most 5 potholes?
$$P(X\leq5)=0.9161$$

c) exactly 3?
from tables
$$P(X=3)=P(x\leq3)-P(\leq2)=0.2240$$

d) at least 10 potholes?
$P(X\geq{}10)=1-P(X\leq9)$ By table
$$1-0.9989= 0.0011$$

e) if crew plans to repair 1 square kilometer, how many potholes should they expect so that they're at least 90% sure they have enough material?

$P(X\leq{}k)\geq0.9$ by table
if $k=4, P = 0.8153$
if $k=5, P=0.9161$
so $k=5$


Poisson approximation to [[Binomial Distribution]]:
if X is a binomial rand. variable where:
n is large
p is small
X can be approximated with a Poisson dist. where
$\lambda=np$
 lets say $n\geq20,p\leq0.05$


### example

odds of defective page is 0.04
if 50 copies are made, what are odds of 3 pages at most defective?
X = num. defective pages
$X\sim{}bin(50,0.04)$
Using the binomial
$$P(X=0)+P(X=1)+P(X=2)+P(X=3)$$
$$ _{50}C_0(0.04)^0(1-0.04)^{50}+_{49}C_1(0.04)^0(1-0.04)^{49}+...=0.8609$$
way too long
Estimate $X=np$ for Poisson
$X=(500)(0.04)=2=\lambda$
by table
$P(X\leq3)=0.8571$

## Use binomial when:
have a fixed number of trials $n$ with common probability $p$ of success

## Use Poisson when:
have average number of successes over an interval of time/space