
Let X, Y be discrete rand. vars. defined on sample space S

Joint probability function f(X, Y) is defined as:
$$f(x,y)=P(X=x \text{ and }Y=y)$$
![[Pasted image 20240228110834.png]]

### Example

consider *joint probability table* of f(x,y)

| f(x,y) |       | y    |      |      |       |
| ------ | ----- | ---- | ---- | ---- | ----- |
|        |       | 1    | 2    | 3    | total |
| x      | 1     | 0.06 | 0.24 | 0.1  | 0.4   |
|        | 2     | 0.06 | 0.36 | 0.18 | 0.6   |
|        | total | 0.12 | 0.6  | 0.18 | 1     |

a) Find  $f_x(x)$
$$=\sum_\text{all y}f(x,y)$$
$$f_x(1)=0.06+0.24+0.1=0.4$$
 $$f_x(2)=0.06+0.36+0.18=0.6$$

b) find $f_Y(y)$
$$f_Y(1)=0.12$$
$$f_Y(2)=0.6$$
$$f_Y(3)=0.0.18$$

c) $P(X=1\cap{}Y\leq2)$
$f(1,1)+f(1,2)$
$=0.3$
### expected val
$$E(h(x,y))=\sum_x\sum_yh(x,y)f(x,y)$$
___
Let X, Y be jointly distributed variables with pmf:

|     |       | y   |     |       |
| --- | ----- | --- | --- | ----- |
|     |       | 2   | 3   | total |
| x   | 5     | 0.4 | 0.2 | 0.6   |
|     | 7     | 0.3 | 0.1 | 0.4   |
|     | total | 0.7 | 0.3 | 1.0   |
calculate $E(X^2-Y)$ 
so $h=X^2-Y$
$$\sum_x\sum_y(X^2-Y)f(x,y)$$
 $$=\sum_x(X^2-2)f(x,2)+(X^2-3)f(x,3)$$
 $$=(5^2-2)f(5,2)+(5^2-3)f(5,3)+(7^2-2)f(7,2)+(7^2-3)f(7,3)$$
 =(23)(0.3)+(22)(0.2)+(47)(0.3)+(26)(0.1)
 $6.9+4.4+14.1+2.6$
 $=28$
### Covariance
Cov(X,Y):
$$Cov(X,Y)=\sum_x\sum_y(x-\mu_x)(y-\mu_y)$$
an easier way to calculate is:
$$Cov(X,Y)=E(X,Y)-\mu_x\mu_y$$
Note: unlike [[Variance]], Covariance can be negative

if positive, then large X values correlate with large Y values
if negative, large X values correlate with small Y values
magnitude is difficult to interpret

[[Correlation Coefficient]] of X, Y, written rho($\rho$) is:
$$\rho=Corr(X,Y)=\frac{cov(X,Y)}{\sigma_x\sigma_y}$$

### example
find Cov(x,y)

|     |       | y   |      |       |
| --- | ----- | --- | ---- | ----- |
|     |       | 1   | 2    | total |
| x   | 5     | 0.3 | 0.15 | 0.45  |
|     | 10    | 0.2 | 0.35 | 0.55  |
|     | total | 0.5 | 0.5  | 1.0   |
$\mu_x=E(X)=(0.45)(5)+(0.55)(10)$
$\mu_x=7.75$ 

$\mu_y=E(Y)=(0.5)(1)+(0.5)(2)$
$\mu_y=1.5$

$E(X,Y)=\sum_x\sum_y(xy)f(x,y)$
$=(5)(1)(0.3)+(5)(2)(0.15)+(10)(1)(0.2)+(10)(2)(0.35)$
$=12$
$$Cov(x,y)=12-(7.75)(1.5)=0.375$$
___
find $\rho$ of previous equation

we need std. dev, so calculate [[Variance]]
$v(y)=E(y^2)-(E(y))^2$
$E(y^2)=1(0.5)+4(0.5)=2.5$
$\sigma_y^2=v(y)=2.5-1.5^2=0.25$
$\sigma_y=\sqrt{0.25}=0.5$

$E(X^2)=66.25$
$\sigma_x=\sqrt{66.25-(7.75^2)}$
$\sigma_x=6.1875$
$$\rho=\frac{cov(X,Y)}{\sigma_x\sigma_y}$$
$$=\frac{0.375}{(0.5)(6.1875)}$$
$$=0.4743$$
there's a positive relationship. as X increases, Y increases

### about $\rho$
1. $-1\leq\rho\leq1$
2. $Corr(aX+b,cY+d)=Corr(X,Y)$
3. if X, Y are independent, $\rho=0$
4. if $\rho=0$, then X and Y are uncorrelated, but possible dependent
5. if$\rho=1,-1$ then X and Y have strict linear relation

### example

let X take values $-2, -1, 1, 2$ with o.25 prob. of each.
Let $Y=X^2$
Since Y is defined by X, Y is dependent.
However, these variables are uncorrelated
### more properties and things

$$E(a_1X_1+...+a_nX_n)=a_1E(X_1)+...+a_nE(x_n)$$

$$V(a_1x_1+..+a_nX_n+b)=\sum_i^n\sum_j^na_ia_jCov(X_i,X_j)$$

$$Cov(aX,aX)=a^2V(X)$$
___
for independent, random variables, covariance is 0. so:

$$V(a_1X_1+..+a_nX_n+b)=a_1^2V(X_1)+..+a_n^2V(X_n)$$

if we let $\bar{X}=\frac{X_1+...+X_n}{n}$, then we can show
- $E(\bar{X})=\mu$
- $V(\bar{X}=\frac{\sigma^2}{n}$
- $\sigma_\overline{X}=\frac{\sigma}{\sqrt{n}}$

