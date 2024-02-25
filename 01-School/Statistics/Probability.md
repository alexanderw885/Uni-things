
Probability of even $A$ occurring is $P(A)$



#### Axioms
$P(S)=1$
$P(A)\geq0$
$P(A_1\cup{}A_2\cup{}...)=\sum{P(A_i)}$ 

$P( \varnothing)=0$
$P(A)=1-P(\bar{A})$ for any $A$
$P(A)\leq1$ for any $A$

Principle of Inclusion-Exclusion (PIE) $$P(A\cup{B}) = P(A)+P(B)-P(A\cap{B})$$
for three sets: $P(A\cup{B}\cup{C})=$
$$P(A)+P(B)+P(C)-P(A\cap{B})-P(A\cap{C})-P(B\cap{C})+P(A\cap{B}\cap{C})$$

Uniform Sample space means every outcome is equally likely to occur.
Let $n(S)$ be size of sample space. Let $n(A)$ be size of event $A$
For any event in the uniform space $n$, the probability is $P(A)=\frac{n(A)}{n(S)}$ 


#### Examples

80 students, 7 in the front row. what are the odds a student in the front row is selected? $$P(A)=\frac{7}{80} =0.0875$$

Consider this table of 250 single crop farms

|  | Wheat | Corn | Soy | Total |
| ---- | ---- | ---- | ---- | ---- |
| Alberta | 69 | 15 | 16 | 100 |
| Saskatchewan | 61 | 65 | 24 | 150 |
| Total | 130 | 80 | 40 | 250 |

if we select one farm... 
a) What is the probably it is wheat in Alberta?
$$P(A)=\frac{69}{250}=0.276$$
b) what is the probability it is corn **or** in Saskatchewan?
$$P(A)=\frac{80+150-65}{250}=\frac{165}{250}=0.66$$
c) what is the probability it does not grow soy?
$$P(A)=\frac{250-40}{250}=\frac{210}{250}=0.84$$


Suppose $P(A)=0.6, P(B)=0.8, P(A\cup{B})=0.95$

find...
a) $P(A\cap{B})$
$$P(A\cap{B})=0.6+0.8-0.95=0.45$$
b) $P(\overline{A\cap{B}})$
$$P(\overline{A\cap{B}})=1-0.45=0.55$$
c) $P(\overline{A\cup{B}})$
$$P(\overline{A\cup{B}})=1-0.95=0.05$$


Suppose $P(E)=0.4, P(F)=0.8$
answer true of false

if we carry out the experiment ten times, we are guaranteed that F will  occur twice as often as E does.  
	False

If we carry out the experiment ten times, we are guaranteed that F will  occur exactly 8 times.  
	False

If we carry out the experiment ten times, we are guaranteed that E will  occur less often than F .  
	False

We would expect that in a long-term average, E will occur about 40% of  the time.  
	True

We would expect that in a long-term average, F will occur approximately  twice as often as E does.  
	True


Consider a 6-sided die,
4 occurs thrice as often as 6
2 occurs twice as often as 4
1,3,5 occurs 5 times as often as 2
how often do you roll a 6?

let $n(6)=1$
$n(4)=3$
$n(2)=6$
$n(1,3,5)=30$

$$P(6)=\frac{1}{1+3+6+30}$$
