intro example
20% of residents own homes
survey 20 people
odds of at most 6 people own the home?

let p denote population proportion -> proportion of the time an outcome occurs in the population
sample proportion $\hat{p}$:
$$\hat{p}=\frac{x}{n}$$
is a point estimate for $p$

in example at top, $\hat{p}=6/20$

### sampling distribution of the proportion
1. $\hat{p}$ is approx. normal for $np\geq5$ and $n(1-p)\geq5$
2. the mean of the proportion is $E(\hat{p})=p$
3. std. error of proportion/ std. dev. of $\hat{p}$ is: $$\sigma_\hat{p}=\sqrt{\frac{p(1-p)}{n}}$$

### confidence interval for $p$

provided it follows property one in above list:
$$\hat{p}\pm{}z_{\alpha/2}\sqrt{\frac{\hat{p}(1-\hat{p})}{n}}$$
$\hat{p}$ is estimate
$z_{\alpha/2}$ is critical value
rest is standard error

### Example
in 88 students, 37 could do thing
based on that, find 99% confidence interval of uvic pop. that can do thing

n=88
$\hat{p}$=37/88=0.4205
$\alpha=1\%$
find $z_{0.005}$
find in normal dist, 0.005 above z
$z_{0.005}=0.57$
plug into formula
did the arithmetic on board
$$CI(99\%)=0.4205\pm0.1352$$
$$0.2853\leq{}CI(99\%)\leq0.5557$$
___
54 residents
12 to newfoundland
find 94% interval

n=54
p=0.2222
$\alpha$=0.06
find $z_{0.03}$
$z=1.88$
formula:
$$0.2222\pm{}0.06\sqrt{\frac{0.2222(0.7778)}{54}}$$

___
### Selecting the sample size to estimate a proportion
based on confidence interval from before, margin for error for an estimate is:
$$d=z_{\alpha/2}\sqrt{\frac{\hat{p}(1-\hat{p})}{n}}$$
$$\sqrt{n}=z_{\alpha/2}\sqrt{\frac{\hat{p}(1-\hat{p})}{d}}$$
$$n=\lceil(z_{\alpha/2}\sqrt{\frac{\hat{p}(1-\hat{p})}{d}})^2\rceil$$

to solve n we need $\hat{p}$, but we haven't taken the sample yet
2 methods:
1. just guess, set $\hat{p}=0.5$
2. use result of a pilot study or a guess to set it. 

### Example
what size needed to estimate p to within 0.07 with 96% confidence

d= 0.07
$\alpha=0.04$
don't know $\hat{p}$, guess 0.5
find $z_{0.02}$ on normal dist. table
$z=2.05$
$$n=2.05^2\frac{0.5(0.5)}{0.07}$$
$$=214.41$$
$$=215$$
___
given:
n=215
$\hat{p}$=0.18
d=0.03
$z_{0.02}=2.05$

find new n

$$n=2.05^2\frac{0.18(0.82)}{0.03}$$
$$n=690$$
