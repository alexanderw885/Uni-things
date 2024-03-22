1. define parameters to be tested, using standard notation
2. specify null hypothesis $H_0$ and alternate hypothesis $H_1$
3. specify test statistic and identify distribution, including degrees of freedom
	1. is $\sigma$ known?
	2. is it normal distribution?
	3. what is $n$?
4. compute observed value of test statistic
	1. one-tailed test: 2 methods. Identified by phrases such as "the mean is more/less than 10", or "the avg. is greater than 10"
		1. $H_1$: parameter>k; and p-value = $P(z>z_{obs})$ or p-value = $P(t>t_{obs})$
		2. $H_1$: parameter\<k; and p-value = $P(z<z_{obs})$ or p-value = $P(t<t_{obs})$
	2. two-tailed test: where $H_1\neq{}k$
		1. p-val. = $2P(z>|z_{obs}|)$ or $2P(t>|t_{obs}|)$
5. compute p-value

6. if asked, report the strength evidence against $H_0$ in favour of $H_1$.
	1. Very strong evidence if $p-val\leq0.01$
	2. Strong evidence if $0.01\leq{}p-val\leq0.5$
	3. Weak/moderate if $0.05\leq{}p-val\leq0.1$
	4. no evidence otherwise
7. if asked, report the estimated value of the parameter along with the estimated standard error
8. if asked, compare p-value to alpha:
	1. if p-val $\leq\alpha$, we reject $H_0$
	2. if p-val $>\alpha$, we fail to reject $H_0$


### example
from previous set:
up to 4mg/L is safe.
60 observations have avg. of 4.2 mg/L, s.d. of 1.3mg/L
should we conclude not safe at $\alpha=0.05$ significance level?

step 1:
$\mu$ = mean chlorine levels in water

step 2:
$H_0$: the water is safe to drink          $\mu\leq4$ or $\mu=4$
$H_1$: the water is *not* safe to drink    $\mu\gt4$

step 3:
$n=60$
$\sigma$ is not known, but $s=1.3$       where s = s.d. of sample
unknown distribution, unknown sigma, n>30. By the table in [[Hypothesis Testing]], normal distribution:
$$Z_\text{observed}=\frac{\bar{X}-\mu}{s/\sqrt{n}}\sim{}N(0,1)$$
this is only true if $H_0$ is true (only under $H_0$)

step 4:
Observed val. of test statistic
$$Z_\text{observed}=\frac{4.2-4.0}{1.3/\sqrt{30}}$$  $$=1.1971$$
step 5:
p-value = $P(Z>1.1917)$ on normal dist. table
 $$=0.1170$$
 step 6:
 p-val greater than 0.1, no evidence against $H_0$

step 7:
$\bar{x}=4.2$     s.e. = $s/\sqrt{n}=0.1678$

step 8:
$\alpha=0.05$
since p-value greater than $\alpha$, we do *not* reject $H_0$
so the water is safe to drink
___

manufacturer charges $86 for each build
the mean of the prices as sampled from 25 manufacturers is $81
normal distribution
what is the strength of the evidence that $86 is not avg. price?

$\mu$=avg. market price
$H_0: \mu=86$ 
$H_1: \mu\neq86$

$n=25$
$s=12$, we do not know $\sigma$
normal, unknown $\sigma$, n<30:
$$\frac{\bar{X}-\mu}{s/\sqrt{n}}\sim{}t_{n-1}$$
$$t_{obs}=\frac{81-86}{12/\sqrt{25}}=-2.08$$
$$t_{obs}=-2.08$$

two-tailed test
$2P(t_{24}>|t_{obs}|)$ 
$2P(t_{24}>|-2.08|)$
$2P(t_{24}>2.08)$
on table, smaller than 0.025
$2(0.025)$
p-value <0.05 

P is smaller than 0.05, so the evidence against  $H_0$ is strong. there is strong evidence that the avg. price is not $86

at $\alpha=0.01$, we would not reject $H_0$
at $\alpha=0.05$, we do reject $H_0$
___
### Errors

**For ethical reasons, always set $\alpha$ before collecting data, taking into account any consequences of Type I or Type II data**

Errors:
1. Type I error: reject $H_0$ even though it is correct. call the probability of type 1 error $\alpha$. *(more serious)*
2. Type II error: not enough evidence to reject $H_0$, even though it is false. Prob. of type 2 error is $\beta$

since type I errors are more serious, we tend to fix $\alpha$ to a set level, and ensure that it doesn't increase any higher. We call this value the **significance level** of a hypothesis, while $\beta$ is the **power**
### Example
Josh is accused of stealing and selling textbooks. 4 possibilities, guilty until proven innocent

$H_0$=Josh is innocent
$H_1$ is guilty

|          | Sentenced        | not sentenced    |
| -------- | ---------------- | ---------------- |
| Innocent | Type I error     | correct desicion |
| Guilty   | correct decision | Type II error    |

### Hypothesis testing population proportions
If we want to conduct [[Hypothesis Testing]] on a population proportion, then the test statistic is: (note [[Estimating Proportions]])
$$z=\frac{\hat{p}-p}{\sqrt{\frac{p(1-p)}{n}}}$$
which is **standardly** normally distributed, if n>5, n(1-p)>5
meaning $Z\sim{}N(0,1)$
### Example
sample of 80 people, 31 wear hats
strength of evidence that less than \%50 wear hats?

p=proportion of people wearing hats 
$H_0=50$
$H_1\lt50$ 
$n = 80$
$\hat{p}=31$
let $p=0.5$, same as null hyp.

$np=40$
$n(1-p)=40$
both greater than 5, standard normally distributed

test statistic: $Z\sim{}N(0,1)$

observed test statistic: $$Z_{obs}=\frac{31/80-0.5}{\sqrt{\frac{0.5(0.5))}{80}}}=-2.01$$
P-value: one-tail approach
$=P(Z<Z_{obs})$
$=P(Z<-2.01)$ on table
p-value = $0.0222$

Strong evidence against $H_0$ between 0.01 and 0.05
meaning there's strong evidence that it's not the case that 50+% of people wear hats
