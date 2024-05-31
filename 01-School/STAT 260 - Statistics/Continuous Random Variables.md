
[[Random Variables]]


A Continuous random variable is a random variable which can assume any real value, not just integers
 $x\in\mathbb{R}$


we can describe a continuous random variable with a probability density function (pdf) $f(x)$

1. $f(x)\geq0$ for all real numbers $x$
2. $\int_{-\infty}^\infty{}f(x)dx=1$  
3. it's the area under a curve!



some consequences of valid pdf

$P(X=a)=0$ for any a
$P(X\leq{}a)=P(P\lt{}a)$ 
$P(X\leq{}a)=1- p(X\geq{}a)$
$P(a\leq{}X\leq{}b)=P(X\leq{}b)-P(X\leq{}a)$ for all $a\leq{}b$


for a uniform probability distribution, $f(x)=\frac{1}{b-a}, a\leq{}x\leq{}b$
if $a\leq{}x\leq{}b$ is not true, f(x)=0

### example

suppose if $1\leq{}x\leq5$, then $f(x)=\frac{5}{3124}x^4$
otherwise, $f(x)=0$

a)Find $P(2\leq{}x\leq{}4)$
$$\int_2^4\frac{5}{3124}x^4dx$$
$$=\frac{1}{3124}x^5|_2^4$$
$$\frac{256}{3124}-\frac{16}{3124}$$
$$\approx0.318$$

Find $P(X\leq{}b)$ where $b\in[1,5]$

$$\int_1^b\frac{5}{3124}x^4dx$$
$$=\frac{1}{3124}x^5|_1^b$$
$$...=\frac{b^5-1}{3124}$$

Find [cdf](Cumulative%20Distribution%20Tables.md) $F(x)$ for X

$F(x)=P(X\leq{}x)$ 


$0$, if  $x\lt1$
$\frac{x^5-1}{3124}$, if $1\leq{}x\leq{}5$
$0$, is $x\gt5$

$$\cases{0\text{}\\\frac{x^5-1}{3124}\\0}$$


Random var. X has following cdf

this is the cdf, cumulative. we want pdf
$$\cases{0,\text{ when }x\lt0 \\\frac{x}{x+1} \text{when}x\geq0}$$
if cdf if the integral, take the derivative to get the pdf
$f'(x)=\frac{1}{(x+1)^2}$
$$\cases{0,\text{ when }x\lt0 \\\frac{1}{(x+1)^2} \text{when}x\geq0}$$

Example 66
find median of the distribution $\mu$
since the area under this curve=1, the middle/median is when the integral = 1/2
find the value of $\alpha$ such that $$F(\alpha)=\int_0^ \alpha2e^{-2x}dx=1/2$$
$$F(\alpha)=-e^{-2x}|_0^\alpha=1/2$$
$$=-e^{-2\alpha}+e^0=1/2$$
$$e^{-2\alpha}=1/2$$
$$-2\alpha=ln(1/2)$$
$$\alpha=-\frac{ln(1/2)}{2}$$
$$\approx{0.347}$$
the [[Expected value]] or mean of a continuous random variable X with pdf f(x) is$$E(X)= \mu=\int_{-\infty}^{\infty}xf(x)dx$$

the [[Variance]] is $$V(X)= \sigma^2=\int_{-\infty}^{\infty}(x-\mu)^2f(x)dx$$

$V(X)=E(X^2)-\mu^2$
$E(aX+b)=aE(X)+b$
$V(aX+b)=a^2V(X)$



### Example
find mean and variance of ex 67

integrate by parts
 $$\int_0^\infty{}xf(x)dx$$
  $$2\int_0^\infty{}xe^{-2x}dx$$
  let $u=x$, $dv=e^{-2x}$
$$=2(-\frac{1}{2}xe^{-2x}+\frac{1}{2}\int_0^\infty{}e^{-2x}dx)$$
$$=-xe^{-2x}+\int_0^\infty{}e^{-2x}dx)$$
$$2lim_{b\rightarrow\infty}x(\frac{1}{2}e^{-2x})$$
Not gonna bother with this on laptop, I'm switching back to notebook next class