$\Gamma(\alpha)$, for $\alpha>0$
$$\Gamma(\alpha)=\int_0^\infty{}x^{\alpha-1}e^{-x}dx$$

properties:
- $\Gamma(\alpha+1)=\alpha\Gamma(\alpha)$ for all $\alpha>0$
- $\Gamma(1)=1$
- $\Gamma(n)=(n-1)!$


random var. X has gamma distribution with parameters $\alpha,\beta>0$ if the pdf is
![[Pasted image 20240228103325.png]]
often used for waiting times, "Time until event"


### Example

$X\sim{}Gamma(\alpha=2,\beta=3)$ calculate P(X<=5)

$$\int_0^5 \frac{1}{3^2\Gamma(2)}x^{2-1}e^{-x/3}dx$$

integrate by parts
$u=(1/9)x$, $du =(1/9)dx$
$dv=e^{-x/3}$, $v=-3e^{-x/3}$
$$-(1/3)xe^{-x/3}|_0^5-\int_0^5-(1/3)e^{-x/3}dx$$
$$=-(5/3)e^{-5/3}+(e^{-x/3}|_0^5)$$
 $$=\frac{-5e^{-5/3}}{3}-(e^{-5/3}-e^0)$$
 $$=\frac{-8e^{-5/3}}{3}+1$$
 $$\approx0.4963$$
### alpha and beta
$\beta$ is the **scale parameter**
$\alpha$ is the **shape parameter**

$E(x)=\alpha\beta=\int{}xf(x)dx$ 
$V(X)=\alpha\beta^2=E(X^2)+...$
![[Pasted image 20240228104653.png]]

### Exponential distribution
exponential distribution is a member of the gamma family when $\alpha=1$. Random for. X has exponential distribution with parameter lambda > 0 if the pdf is:![[Pasted image 20240228105044.png]]

Properties
- $E(X)=1/\lambda$
- $V(X)=1/\lambda^2$
- $P(X\geq{}a+b | X\geq{}b)=P(X\geq{}a)$
### Example
find cdf for the exponential distribution

$$\int_0^xf(x)dx$$
$$\int_0^x\lambda{}e^{-\lambda{}t}$$
$$=-e^{-\lambda{}t}|_0^x$$
$$=1-e^{-\lambda{}x}$$

___
avg. wait time is 6 minutes. Suppose rand. var X measures time in minutes that waited before service is exponentially distributed

X-time before service
E(X)=6, so $\lambda=1/6$
remember: cdf $=1-e^{-\lambda{}x}$

a) prob. of waiting at least 9 minutes?
$P(X \geq9)=1-P(X\leq9)$
cdf $=1-e^{-\lambda{}x}$
$$=1-(1-e^{-9/6})$$
$$=e^{-3/2}$$

b) already waited 5 min, prob of waiting for 10 more?
remember rule $P(X\geq{}a+b | X\geq{}b)=P(X\geq{}a)$
so equals odds of $P(X\geq10)$
$=1-P(X\leq10)$
$$=1-(1-e^{-(1/6)10}$$
$$=e^{-5/3}\approx 0.19$$

### Relationship between Exponential Distribution and [[Poisson Distribution]]

Suppose Poisson process, where events occur $\lambda$ times per time/space

if X denotes number of occurrences of an event, then $X\sim{}Poisson(\lambda)$

let Y measure units of time/space until next occurrence, then $Y\sim{}Exp(\lambda)$
