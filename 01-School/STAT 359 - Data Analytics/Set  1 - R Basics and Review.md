this class is about using R to analyse data
`worms<-read.table(file="FILEPATH", sep="", header=TRUE, na.strings="NA")`
<- is the assignment operator
`sep` is separator between values
`header` is if there's names for columns
`na.strings` is what should be treated as a null value

`names(worms)` shows names of all variables

```R
library(knitr)
kable(worms, caption='Caption name')` shows the full data table
```
`?kable` will show function description

`summary(worms)` gives a summary of each variable. Mean, median, min, max, 1st/3rd quartile


when working with a dataset, you can attach it
`attach(worms)`
lets say worms has a variable `density`
normally you access it with `worms$density`, but after attaching worms you can access it just by typing `density`
you can then `detach(worms)`

```R
attach(worms)
# now density is a vector, you can treat it like an array
density[2] # gives 2nd index
density[density<3] # returns all density values < 3

# worms can be treated as a 2d array
worms[1,2] # value in row 1, column 2
worms[area<3 & density > 2,] # note single &
worms[order(density),] #shows in ascending order
worms[rev(order(density))]
```
___
here's a sample function in R to find the median
```R
sample.median<-function(y)
{
  n<-length(y)
  y.ordered<-sort(y)
  if(n%%2 == 0)
  {
    low<-floor(n/2)
    return.value<-(y.ordered[low]+y.ordered[low+1])/2
  }
  else
  {
    mid<-n/2
    return.value<-(y.ordered[mid])
  }
  return.value
}
```
note things like `sample.median` and `return.value`, these aren't functions. sample does not exist before this.
the period in the names is the convention in R

code to remove null values
`Placebo<-Placebo[!is.na(Placebo)]`
# Stats things
use [mean or median](Mean,%20Median,%20Mode)?
median can do much better at filtering outliers
if we generate a distribution 
`y<-rnorm(n=20,    plt.show()
mean=2,sd=1)`, and then create `y2`
`y2<-y; y[20] <-1000`
the median will be nearly unchanged, but the mean of `y2` will be very far off

using the ginkgo/placebo data set
we have the sample means `sum(Ginkgo)/length(Ginkgo)`
or just `mean(Ginkgo)`
and this is the sample mean, but we want to know about the population mean
![[Pasted image 20240906140552.png]]
the distributions look very similar for placebo and ginkgo
`mean(Placebo)=5.222` $= \bar{y}_1$
`median(Placebo)=6`
`length(Placebo)=99` $=n$

`mean(Ginkgo)=4.231` $=\bar{y}_2$
`median(Ginkgo)=4
`length(Ginkgo)=104`$=m$

to compare them, we let each value in both sets be an independent random variable, and infer interval estimations for each

we have over 30 in each set, so we're using a large sample size

we have the means of the samples, we want the means of the populations. we can use the [[Central Limit Theorem]]
**Note that we do not need to assume the data is normal**
[[Comparing two population means]]

$$\bar{Y}_j\sim{}N(\mu_j,\frac{\sigma_j^2}{m}), j=1,2$$

to get the test statistic:
$$\frac{\text{estimate}-\text{parameters}}{\text{estimated standard error}}$$
we don't have the actual standard deviation, so we need to estimate it
$$\frac{(\bar{y}_1-\bar{y}_2)-(\mu_1-\mu_2)}{\sqrt{\frac{s_1^2}{m}+\frac{s_2^2}{n}}}$$
```R
var(ginkgo) = 25.23
var(Placebo) = 16.95
# var(vector) = s^2 in above examples
```

[[Confidence Interval Approach]]
$$\bar{y}_1-\bar{y}_2\pm{}Z_{\alpha/2}\sqrt{\frac{s_1^2}{m}+\frac{s_2^2}{n}}$$
to get the upper and lower bounds in R:
```R

alpha<-0.05
lower<-mean(ginkgo) - mean(Placebo) - qnorm(1-(alpha/2))*
sqrt( (var(ginkgo)/length(ginkgo)) +  (var(Placebo)/length(Placebo)))

upper<-mean(ginkgo) - mean(Placebo) + qnorm(1-(alpha/2))*
sqrt( (var(ginkgo)/length(ginkgo)) +  (var(Placebo)/length(Placebo)))

c(lower,upper)

## returns -2.2536479  0.2707419

# Since 0 is in our confidence interval, it is possible that the actual averages of ginkgo and placebo are the same
```

we want to see if ginkgo does affect memory
$H_0: \mu_1 = \mu_2$
$H_1: \mu_1 > \mu_2$, or $\mu_1-\mu_2 > \Delta_\mu$
where $\Delta_\mu$ is whatever value we want to test for, this value replaces the parameters $\mu_1-\mu_2$

[[P-value Approach]]
lets get the observed test statistic
```R
T.obs<-(mean(ginkgo) - mean(Placebo))/sqrt( (var(ginkgo)/length(ginkgo)) +  (var(Placebo)/length(Placebo)))
T.obs
## -1.53955
```
the p-val is the probability that, assuming $H_0$ is true, that the test statistic as at least as extreme as observed
$$p-val=P(T_{real}>T_{obs})\sim{}N(0,1)$$
$$=P(T>-1.53955)$$
we can use a table or a program for this, or use `pnorm(value)` and get the value
$$0.938165$$
since the p-value is greater than the previously used alpha value of 0.05, we do not have evidence to reject $H_0$, we do not have evidence that Ginkgo improves memory.
If $H_0$ is true, about 93% of the time we would observe a similar or more extreme result as this one

Note that this isn't evidence *for* $H_0$, it's just *not against* it

### Types of error
two types of error:
1. $H_0$ is true, and we reject it: Type 1 error
2. $H_0$ is false, and we do not reject it: Type 2 error

we're most concerned about Type 1 errors, the alpha value controls the chance of a type 1 error.
we only reject the null hypothesis if the p-value $\leq\alpha$, so smaller alpha values reduce the chance of type 1 errors. However, it increases the chance of a type 2 error
this is referred to statistical significance at level $\alpha$

### More on p-values
if we collect test statistics and p-values repeatedly, each one can be treated as a random variable. If the null hypothesis is true, the p-value should be a $uniform(0,1)$ variable, uniform dist from 0 to 1.
The test statistic should form a $N(0,1)$ distribution