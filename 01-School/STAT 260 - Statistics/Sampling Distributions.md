a statistic is any function of random variables

for observed values, we use lower case. When talking about random var, use upper case

### Example
let $X_1,X_2,...,X_n$ be $n$ rand. vars. Some common statistics include:
$$\bar{X}=\frac{X_1+X_2+...+X_n}{n}$$
$$T=X_1+X_2+...+X_n$$
$$S^2=\frac{\sum(X_i-\bar{X})^2}{n-1}$$
for observed values, we use lower case. When talking about random var, use upper case
___
Biased coin shows heads 0.6 of time. Let $\bar{X}$ be avg. num. heads when coin is flipped 3 times

a) find pdf for $\bar{X}$

|           | 0              | 1                   | 2                   | 3              |
| --------- | -------------- | ------------------- | ------------------- | -------------- |
|           | $_3C_0(0.4)^3$ | $_3C_1(0.6)(0.4)^2$ | $_3C_2(0.6)^2(0.4)$ | $_3C_3(0.6)^3$ |
| $\bar{X}$ | $0.064$        | $0.288$             | $0.432$             | $0.216$        |
b) find $E(\bar{X})$
$1(0.288)+2(0.432)+3(0.216)$
$=0.288+0.864+0.648$
$=1.8$
___

**Any linear combination of independent normal random variables is normally distributed**
$X_i\sim{}N(\mu_i,\sigma_i)$, $i=1,...,n$
$$\sum_{i=1}^na_iX_i\sim{}N(\sum{}a_i\mu_i,\sum{}a_i\sigma_i)$$
if T is sum of $X_1,X_2,...,X_n$
$T\sim{}N(\mu_1+\mu_2+...+\mu_n, \sqrt{V(X_1)+V(X_2)+...+V(X_3)})$ 
***ERROR ERROR ERROR MAYBE BUT MAYBE FIXED***


Mass of Male flamingo is normally distributed.
$\mu=4.5$ kg, $\sigma=0.3$ kg.
Mass of Female flamingo is normally distributed.
$\mu=2$ kg, $\sigma=0.1$ kg.
suppose a male and female are randomly selected, what are odds of total mass exceeding 7kg?

due to above statement, we know this has lin. distribution as well. we need to find new distribution

Let $T$ be total mass of the flamingoes.
$X_1$=mass of male flamingo $X_1\sim{}N(4.5, 0.3)$
$X_2$=mass of female flamingo $X_2\sim{}N(2,0.1)$
$T=(X_1+X_2)$
$T\sim{}N(4.5+2,\sqrt{V(X_1)+V(X_2)})$
$T\sim{}N(6.5, \sqrt{0.3^2+0.1^2})$

$$P(T>7)=P(Z>\frac{7-6.5}{\sqrt{0.1}})=P(Z>1.58)$$
use table
$P(Z>1.58)=0.571$
___
machining requires 4 different machining operations. each operation is normally distributed 
$\mu=15$
$\sigma^2=9$
all operation times are independent.
$X_i=$ operation of $i^{th}$ machining
$X_i\sim{}N(9,sqrt{15})$

a) what is prob. the average of four operation times is >13?
$\bar{X}=\frac{X_1+X_2+X_3+X_4}{4}$
$=(1/4)X_1+...+(1/4)X_4$
$\bar{X}\sim{}N(15/4+15/4+15/4+15/4, \sqrt{1/16*9*4})$
$\bar{X}\sim{}N(15,\sqrt(9/4))$

$$P(\bar{X}>13)=P(Z>\frac{13-15}{9/4})=P(Z>-1.33)=0.9082$$

b) suppose cost for operations are $1, $2, $3, $4 respectively per minute. What is probability that total cost for next component is more than $250?
Y= cost of next component
$Y=f(X_1,X_2,X_3,X_4)$
$Y=X_1+2X_2+3X_3+4X_4$
$Y\sim{}N(1*15+2*15+3*15+4*15,\sqrt{1^2*9+s^2*9+3^2*9+4^2*9})$
