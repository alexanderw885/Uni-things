consider scenario:
samples from 2 independent populations
let  $p_1,p_2$ pop. proportion of each population
since there are 2 things, we only need to examine $p_1-p_2$

we can use $\hat{p_1}-\hat{p_2}$ as point estimate, where $p_1=x_1/n_1$ (num. successes over num. trials)

when at least 5 success and 5 failures in each group, it is approximately normally distributed:
$$Z=\frac{(\hat{p}_1-\hat{p}_2)-(p_1-p_2)} { \sqrt{\frac{p_1(1-p_1)}{n_1}+\frac{p_2(1-p_2)}{n_2}} }$$
**that square root is the estimated standard error, but with hats**
I don't want to write it again

this means the **Confidence Interval** is:
$$(\hat{p}_1-\hat{p}_2)\pm{}z_{\alpha/2}(e.s.e)$$
