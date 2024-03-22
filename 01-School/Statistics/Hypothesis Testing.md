 chlorine up to 4mg/L is safe
 60 observations have average of 4.2mg/L with s.d. 1.3mg/L
 should we conclude the water is not safe?
 avg. is higher than safe level, but was that just due to chance?

**Hypothesis testing** uses sample data to evaluate a hypothesis

null hypothesis $H_0$ is statement about the value of a parameter
alternate hypothesis/research hypothesis $H_1$ or $H_a$ is a statement we are trying to gather evidence for, about the value of a parameter

### Null hypothesis
default assumption or conventional wisdom
begin by assuming is true.
once evidence is summarized, only 2 outcomes
1. There is enough evidence to reject $H_0$ for $H_1$
2. There is not enough evidence to reject $H_0$. This does **not** mean it's true, just that we can't prove it false

in earlier example, we assume water is fine, so $H_0$ is the water is safe, and $H_1$ is the water is unsafe
$p$ is the prob that sample is at least as extreme as what we observed.
so $p$ is the probability a sample size of 60 has avg of 4.2, given that population mean is 4

if $p$ is **small**, that sample was unlucky and unlikely to be true. This means it is evidence **against** $H_0$

is $p$ is **large**, we expect many samples to have similar results, this is also evidence **against** $H_0$

we compute $p$ using a test statistic: numerical summary of data allowing us to draw a conclusion about chance of our sample, given $H_0$ is true.
$$\frac{\text{estimate}-\text{null hyp. of parameter}}{\text{estimated standard error}}$$

![[Pasted image 20240315111251.png]]
