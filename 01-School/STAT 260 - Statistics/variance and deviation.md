 
### Sample variance $s^2$ and population variance $\sigma^2$ (sigma squared)

how "spread out" data is, variance is a measure of how much dispersion is in the data set.
The lower the variance means data is more spread out.

the i deviation is $x_i - \bar{x}$ $$\sum_{i=1}^{n}(x_i - \bar{x}) = 0$$
sample variance, $s^2$ is given by 

$$s^2 = \frac{\sum(x_i-\bar{x})^2}{n-1}$$

or  $$s^2 = \frac{\sum (x_i^2)-n(\bar{x}^2)}{n-1}$$

### Standard deviation

Standard deviation is just the square root of variance, either $s$ for sample or $\sigma$ for population

with calculator:
enter stats mode
enter data
hit RCL + $x$ 


#### example

data set is ${40, 23, 28, 26, 33}$. find variance and std. deviation
$\bar{x}$ is given as $32$ 

| $x_i$ | $x_i-\bar{x}$ | $(x_i-\bar{x})^2$ |
| ---- | ---- | ---- |
| 40 | 8 | 64 |
| 23 | -9 | 81 |
| 28 | 6 | 36 |
| 26 | -6 | 36 |
| 33 | 1 | 1 |

$$s^2 = \frac{\sum_{i=1}^{n}(x_i-\bar{x})^2}{n-1}$$
$$s^2 =\frac{64+81+36+36+1}{5-1}$$
$$s^2=\frac{218}{4} = 54.5$$

$s^2 = 54.5$ 
$s = \sqrt{54.5} \approx 7.3824$

### practice 
consider the sample $$10, 11, 14, 17, 18, 20$$
using calculator, find mean
$\bar{x} = 15$
find standard deviation
$s = 4$

what if we add 10 to every score?
$20, 21, 24, 27, 28, 30$
$\bar{x} = 25$
$s = 4$

what if we multiply all scores by $10$?

$\bar{x}=150$
$s=40$

Given standard deviation s, find an expression for the new standard  deviation after each score is multiplied by a and b is added.  $a > 0$
	Mean $\bar{x}$  is multiplied by $a$, and then increased by $b$ 
	Standard deviation $s$ is multiplied by $a$, but unaffected by $b$ 

$S_{ax+b}=a*S_x$ 



