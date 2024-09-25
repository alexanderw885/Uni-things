let  $X_1,X_2,...,X_n$ be independent identically distributed (iid) rand. vars with mean $\mu$ and s.d. $\sigma$

for sampling distribution of mean, $\bar{X}$, has mean $\mu$ and s.d. $\sigma/\sqrt{N}$
The sample sum, $T=\sum_{i=1}^nX_i$ has mean $n\mu$ and s.d. $\sigma\sqrt{n}$

### Example
recommended that uranium in water not exceed $2\mu{}g/L$ suppose water is has normal dist. with:
$\mu=1.9$
$\sigma=0.5$
$X\sim{}N(1.9,0.5)$
a) prob that amount exceeds recommended amount

$P(Z>\frac{1.9-2}{0.5})=P(Z>0.2)$
by table
$=0.4207$

b) prob that avg. uranium in 16 samples exceeds recommended amount

$P(\bar{X}>2)$

find $\bar{X}$
has same mean, so $\mu$=1.9
$\sigma=\sigma/n=0.5/4=0.125$
$P(\bar{X}>2)=P(Z>\frac{2-1.9}{0.125})$
$=P(Z.0.8)$
$=0.2119$

c) prob. *all* 16 samples exceed recommended amount

Y=num. samples exceeding recommended amount
prob. one is exceeding amount = 0.4207 in part a
num. tries=16
$Y\sim{}Bin(16,0.4207)$
$P(Y=16)=0.4207^{16}$
 $=9.6*10^{-7}$
 $\approx0$
### Central limit theorem
Let $X_1,X_2,...,X_n$ be $iid$ rand. vars, each with mean $\mu$, s.d. \sigma$.
Provided that n is large enough:
1. $\bar{X}$ is approximately normally distributed with mean $\mu$, s.d. $\sigma/n$ 
2. $T=\sum_{i=1}^nX_i$ is approximately normally distributed with mean $n\mu$, s.d. $\sigma\sqrt{N}$
3. above is true no matter distribution of $X_i$ (binomial, Poisson, exponential, normal...)
4. for us, $n\geq30$
5. as n increases, the closer it is to normal distribution


### Example
mass of luggage has mean of 12kg, s.d. of 3kg
prob that mass of 50 passengers exceeds 650kg?
$\mu=12$
$\sigma=3$
$n=50$

solve for $\bar{X}$
$\mu=12*50=600$
$\sigma=3\sqrt{50}=21.2132$
$T\sim{}N(600,21.2132)$
$P(T>650)=P(Z>\frac{650-600}{21.2132})$
$P(Z>2.36)$
$=0.0091$
