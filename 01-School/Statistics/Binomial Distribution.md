
*Bernoulli Process*: An experiment consisting of one or more trials that
- only succeed or fail
- are independent of each other
- for all trials, probability of success $p$ is constant

A **Binomial experiment** is a Bernoulli process where the number of trials $n$ is fixed.

a **Binomial random variable**  X counts num. successes in Binomial experiment.
$X\sim{}BIN(n,p)$

### example
coin lands heads 60% of time. flip coin 3 times. construct prob. dist. for X, number of heads

|  | 0 | 1 | 2 | 3 |
| ---- | ---- | ---- | ---- | ---- |
|  | $(1)(0.4^3)$ | $(3)(0.4^2)(0.6)$ | $(3)(0.4)(0.6^2)$ | $(1)(0.6^3)$ |
|  | 0.064 | 0.288 | 0.432 | 0.216 |
### Other things
if $X\sim{}BIN(n,p)$, then
$$f(x)=P(X=x)=(_nC_x)p^x(1-p)^{n-x}$$
$$xxxxx$$