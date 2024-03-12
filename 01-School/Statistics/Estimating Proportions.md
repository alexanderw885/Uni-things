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
$alpha=1\%$
find $z_{0.05}$
find in normal dist, 0.05 above z
$z_{0.005}=0.57
plug into formula
did the arithmetic on board
$$CI(99\%)=0.4205\pm$$