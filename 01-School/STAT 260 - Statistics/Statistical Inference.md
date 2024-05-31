in general, values of population parameters aren't known due to money/time/effort
*estimation* is the inferential process of using sample statistics to approx. the value of population parameter

two kinds of parameters:
- Point estimators: use a single num as the estimate of the unknown parameter
	- ex: sample mean is a point estimator for the population mean
- Interval estimators: use a range of values as an estimate of an unknown quantity. 
	- ex: see how to construct confidence interval for parameter

## Confidence intervals for $\mu$ when $\sigma$ is known


if X is normal or n is large $(x>30)$, than $\bar{X}$ is approximately normal and $Z=\frac{\bar{x}-\mu}{\sigma/\sqrt{n}}$ is approximately normal.


let $z_{\alpha/2}$ be score with $\alpha/2$ of the population above the Z-distribution

 we can construct a confidence interval C.I estimator of $\mu$ when $\sigma$ is known, and $X$ is normal or $n\geq30$
$$\bar{x}\pm{}z_{\alpha/2}\frac{\sigma}{\sqrt{n}}$$
on formula sheet,
$$estimate\pm(c.v.)(s.e)$$
c.v.=critical value
s.e. = standard error (s.d. of $\bar{X}$)

confidence level = $1-\alpha$ or $(1-\alpha)100\%$

width of interval is upper bound-lower bound
width of confidence interval:$$2z_{\alpha/2}\frac{\sigma}{\sqrt{n}}$$
### Example
travel time has s.d. of 8 minutes.
over 10 days, avg. time of 30 minutes
compute 99% confidence interval
$\bar{X}=30$
$n=10$
$\sigma=8$
$\alpha=0.01$ or $1\%$

find $z_{\alpha/2}=z_{0.005}$
find on table of normal distribution
$z\approx2.575$

find confidence interval $z_{\frac{\alpha}{2}}\frac{\sigma}{\sqrt{n}}$
$$\bar{X}\pm2.57\frac{8}{\sqrt{10}}=6.5016$$
$$CI(99\%)=(30-6.5106; 30+6.5106$$
$$CO(99\%)=(23.4984, 36.5016)$$
### interpretation
when experiment is repeated, 99% of sample means would produce interval containing $\mu$

for a fixed $\sigma$ and a confidence level we can select a family size so the margin of error is less than or equal to $d$
$$n=ceiling((\frac{z_{\frac{\alpha}{2}}*\sigma}{d})^2)$$
### example
determine size n to obtain 95% confidence interval with $\sigma=25$, to within 5.
$\alpha=0.05$
$\sigma=25$
$CI=(95\%)$
$z=1.96$

we have $\alpha$, use to find $z_{\alpha/2}$ on table
then use with $\sigma$ and margin to find in $n$

$$n=\frac{0.96*25}{5}=96.04=97$$
## Confidence interval for $\mu$ when n is large

if we don't know $\sigma$, we can use sample s.d. $s$ as estimate

for large n, a $100(1-\alpha)$ confidence interval:
$$\bar{X}\pm$$

### Example

121 students
46 hours a week
s.d. of 12 hours
find upper limit of 94% confidence interval for mean num. hours worked

only a sample, so s.d. is sample s.d.
$n=121$
$\bar{x}=46$
$s=12$
$\alpha=0.06$

find $z_{0.03}$ by table
$z=1.88$

now use to find confidence interval
$$\bar{X}+z\frac{s}{\sqrt{n}}$$
$$=46+1.88\frac{12}{\sqrt{121}}$$


