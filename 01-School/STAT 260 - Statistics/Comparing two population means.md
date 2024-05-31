take samples from two populations to carry out comparison
state hypothesis about the difference in terms $\mu_1-\mu_2$

### Example
$\mu_1$ is lead content in Victoria
$\mu_2$ is lead content in Vancouver

if they are equal, $\mu_1-\mu_2=0$
if they are different, $\mu_1-\mu_2\neq0$
if higher in victoria, $\mu_1-\mu_2\gt0$
if lower in Victoria, $\mu_1-\mu_2\lt0$
if higher in victoria by at least 4 values, $\mu_1-\mu_2>4$
___

[point estimate](Estimating%20Proportions.md) for $\mu_1-\mu_2$ is $\bar{x_1}-\bar{x_2}$
still, confidence interval = estimate +- (crit val)(expected s.e.)
$$(\bar{x_1}-\bar{x_2})\pm{}z_{\alpha/2}($$
test statistic is still (estimate-parameter)/(est. s.e.)
$$z=\frac{(\bar{x_1}-\bar{x_2})-(\mu_1-\mu_2)}{\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}}\sim{}N(0,1)$$

**Assumptions**
independent random sample from both populations
both sample sizes are large
populations may have any distributions

### Example
A: $\bar{x_1}=197,s_1=30,n_1=45$
B: $\bar{x}_2=180,s_2=40,n_2=50$

a) can you conclude A higher than B at $\alpha=0.01$
$H_0:\mu_1=\mu_2$
$H_1:\mu_1\neq\mu_2$

$$z_{obs}=\frac{(197-180)-0}{\sqrt{things}}=2.3575$$

$z=\frac{(\bar{x_1}-\bar{x_2})-(\mu_1-\mu_2)}{\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}}\sim{}N(0,1)$

so p-value $P(z _{obs}>2.3575)$
p-val = 0.0091
below $\alpha=0.01$, so we have evidence to reject $H_0$ in favour of $H_1$
A likely has higher sales than B


b) construct 95% CI for difference between means
$$(\bar{x_1}-\bar{x_2})\pm{}z_{\alpha/2}\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}$$
$z_0.025=1.96$
$$(197-180)\pm1.96\sqrt{\frac{30^2}{45}+\frac{40^2}{50}}$$
$$CI(95\%)=(2.8662;31.1338)$$


### Both cases are small
one n n is below 30

#### Pooled Case
$$(\frac{s_1}{s_2}<1.4)$$
we assume that the variances are equal $(\sigma_1^2=\sigma_2^2)$
**Assumptions**
- samples are independand and random, from two populations
- we assume that $\sigma_1^2=\sigma_2^2$
- both populations have normal distributions
 ![[Pasted image 20240326104848.png]]
 test statistic is $\sim{}t_{n_1+n_2-2}$

### Example
distance run is normally distributed. Distance per month is on graph
![[Pasted image 20240326105148.png]]
is there enough evidence to conclude longer runs in August, $\alpha\=0.10$


small sample size
August:
$n_a=10$
$\bar{x}_a=7.548$
$s_a=1.2394$
September:
$n_s=11$
$\bar{x}_s=7.3927$
$n_s=1.263$

variance less than 1.4 apart, use pooled method

I want to test the following:
$H_0:\mu_s-\mu_a=0$
$H_1:\mu_s-\mu_a<0$

test statistic is far, far too big to type formula for regularly
$$t_{obs}=\frac{(7.3927-7.548)-0}{\sqrt{\frac{(11-1)1.263^2+(10-1)1.2394^2}{11+10-2}(\frac{1}{11}+\frac{1}{10})}}=-0.2838$$

p-value=$P({t_19}< -0.2838)=P(t_{19}>0.2838)$
p-val.=between 0.3, 0.4 (according to R, 0.3899)
alpha is 0.1
 since p-val is larger than alpha, we do not have evidence to reject $H_0$
 Or, we do not have enough evidence to reject that the runs are the same

**find 99% CI interval for the two means**

$\bar{x}_1-\bar{x}_2=-0.1553$
estimated standard error=0.2995$
$t_{19;0.005}$=2.861

$$CI(99\%)=estimate\pm{}(c.v.)(e.s.e.)$$
$$-0.1553\pm(2.861)(0.2995)$$
$$CI(99\%)=(-1.7211;1.4105)$$

### Non-Pooled case
variances are different, $s_1/s_2>1.4$
in this case, we assume $\sigma_1^2\neq\sigma_2^2$

**Assumptions**
independent random samples from two populations, and at least one sample size is small
variances are different
both have normal distributions
![[Pasted image 20240327103642.png]]

confidence interval:
$$(\bar{x}_1-\bar{x}_2)\pm{}t_{\alpha/2,\nu}\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}$$
### Example
data on hours
1. $\bar{x}_1=12, s_1=2, n_1=16$
2. $\bar{x}_2=7, s_2=8, n_2=16$
is there sufficient data to say different mean at $\alpha=0.05$?

small n, check if pooled
$s_2/s_1=4$, greater than 1.4, unpooled
$H_0: \mu_1=\mu_2$
$H_1: \mu_1\neq{}\mu_2$
or
$H_0:\mu1-\mu_2=0$
$H_1:\mu1-\mu_2\neq0$
$$\frac{(12-7)-(0)}{   \sqrt{\frac{2^2}{16}+\frac{8^2}{16}}   }\sim{}t$$

$\nu$ is very long, equals 16.86, round down to 16

$$t_{obs}=\frac{(12-7)-(0)}{   \sqrt{\frac{2^2}{16}+\frac{8^2}{16}}   }=2.4253$$

p-value = $2P(t_{16}>|2.4253|)$
$0.02<\text{p-value}<0.03$

since the p-value is smaller than $\alpha=0.05$, we do have sufficient data to reject $H_0$,
This means that there is enough evidence that the number of hours worked by two law students are different

find 99% confidence interval for difference of means
estimate $= 12-7=5$
critical value $= t_{0.005,16}=2.921$
estimated standard error = $\sqrt{\frac{4}{16}+\frac{64}{16}}=2.0615$
$$5\pm(2.921)(2.0615)$$
$$CI(99\%)=(-1.0216;11.0216)$$
based on an $\alpha$ of 1%, we could not have rejected $H_0$
not only since p-val is larger then $\alpha$, but also because
$H_0:\mu_1-\mu_2=0$, and zero is in the interval