
Let X be a discrete random variable. the variance of X V(X), or $\sigma^2_X$, or $\sigma^2$
$$\sigma^2=V(X)=E((X-\mu)^2)$$
$$\sigma^2=V(X)=E(X^2)-\mu^2$$

Standard deviation $\sigma$ is square root of variance.

### Example

probability distribution table, find $\sigma$

| $x^2) | 0 | 1 | 4 | 9 | 16 | 25 |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| x | 0 | 1 | 2 | 3 | 4 | 5 |
| f(x) | 0.1 | 0.1 | 0.15 | 0.25 | 0.2 | 0.2 |
we found that $E(X)=2.95$
Find $\sigma_X$
$$V(X)=E(X^2)-2.95^2$$
$$E(X^2)=1(0.15)+4(0.15)+9(0.25)+16(0.2)+25(0.2)=11.15$$
$$V(X)=11.15-2.95^2=2.4475$$
$$ \sigma= \sqrt{2.4475}=1.5644$$



### Laws of Variance

$V(b)=0$
$V(X+b)=V(X)$
$V(aX)=a^2V(X)$

so, $V(aX+b)=\sigma_{aX+b}=a^2V(X)$

#### Example
suppose $E(X^2)=23$, $E(X)=4$, $\sigma_Y=5$

a) V(X)
$$E(X^2)-(E(X))^2=25-4^2=7$$
b) V(-2X-3)
$$(-2)^2V(X)=487=28$$
c) $\sigma_{-2x-3}$
$$V(-2X-3)=28$$
d) $\sigma_{-2Y+1}$
$$(-2)^2V(Y)=4\sqrt{\sigma_Y}=10$$


goalie had a .915 save percent. suppose other team shoots 30 times

a) prob of 27 saves
X = num. saves. $X\sim{}bin(30, 0.915)$
$$P(X=27)=_{30}C_{27}(0.915)^{27}(1-0.915)^{3}\approx0.226$$

b) prob of all 30 saves
$$0.915^{30}\approx0.696$$

c) prob he saves fewer than 29 shots
1-29 saves - 30 saves ~= 0.7364
$P(X=29)=_{30}C{1}(0.915)^{29}(1-0.915)$

d) expected number of saves
$$\mu=30*0.915=27.45$$

e) standard deviation $\sigma$ of saves

$$V(X)=\sigma^2=np(1-p)=30(0.915)(1-0.915)$$
$$\sigma=\sqrt{\sigma^2}\approx1.5275$$

