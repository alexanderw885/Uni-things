here, talking just about two-tailed approach

suppose we construct a $(1-\alpha)100\%$ confidence interval for $\mu$
It is true that for any number $k$ in this interval, if we test  $H_0:\mu=k$, $H_1:\mu\neq{}k$, we would have [p-value](P-value%20Approach) greater than $\alpha$
this means if we test  $H_0:\mu=k$, $H_1:\mu\neq{}k$ at the level $\alpha$, we would reject the null hyp. if and only if $k$ were not inside the $(1-\alpha)100\%$ interval for $\mu$

1. Define parameters to be tested
2. Specify $H_0, H_1$
3. specify test statistic and identify approx. distribution, including degrees of freedom, under $H_0$
4. construct CI
5. reject $H_0$ when null hyp. outside CI


### Example
28 homes, 775,000 avg price, 4,500 standard deviation
test whether avg. price is 750,000 with $\alpha=0.05$

$H_0: \mu=775,000$
$H_1:\mu\neq775,000$

n=28
s=4,500
$\bar{x}=775,000$
small n, no $\sigma$, use t-statistic
$$t=\frac{\bar{x}-\mu}{s/\sqrt{n}}\sim{}t_{n-1}=t_{27}$$
test stat. = (estimate-parameters)/e.s.e
confidence interval = estimate+-(c.v.)(e.s.e.)
critical value comes from the t-distribution
critical value = $t_{\alpha/2,n-1}$=$t_{0.025,27}$ =2.052
estimate = $\bar{x}=775,000$
e.s.e=$s/\sqrt{n}$

$$CI(95\%)=775,000\pm2.052(\frac{4500}{\sqrt{28}})$$
$$=(773,254:775=6,745)$$
since the null. Hyp. of 750k falls outside out confidence interval of 5%, we reject our null hypothesis. We have enough evidence that the avg. home price is not 750k

