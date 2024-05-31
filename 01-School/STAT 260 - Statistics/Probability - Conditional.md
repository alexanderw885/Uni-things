
bag has 5 red marbles, 5 blue marbles. Draw two from bag without replacement
if...
first is red, odds that 2nd red will be red, prob. is $5/9$
first is blue, prob 2nd will be blue is $5/9$

Conditional Probabilities are probabilities that are affected by some information in the experiment. (The condition or conditioning event)

**Notation** $P(B|A)$ denotes probability of $B$ given that $A$ occurs

**Definition** provided that $P(A)>0)$
$$P(B|A) =\frac {P(B\cap{A})}{P(A)}$$
or if the sample space is uniform: 
$$P(B|A) =\frac {n(B\cap{A})}{n(A)}$$
In general, $P(A|B)\neq{}P(B|A)$


### Examples

|  | Wheat | Corn | Soy | Total |
| ---- | ---- | ---- | ---- | ---- |
| Alberta | 69 | 15 | 16 | 100 |
| Saskatchewan | 61 | 65 | 24 | 150 |
| Total | 130 | 80 | 40 | 250 |

$A$=Alberta
$P(A)=2/5$
$B$=Soy
$P(B)=4/25$

a)
Suppose that a single-crop farm is selected at random. If the farm is in  Alberta, what is the probability the farm grows soy?
$$P(A|B)=\frac{16/250}{100/250}=\frac{16}{100}=0.16$$

b)
If a farm which grows soy is selected, what is the probability that the farm  is in Alberta?
$$P(B|A)= \frac{16/250}{40/250}= \frac{16}{40}=0.4$$


Say 80% of Canadians exercise 1+ days a week $(A)$ 
say 20% of Canadians exercise 5+ days a week $(B)$
if we select a Canadian that exercises at least 1 day a week, what are the odds they exercise 5+ days?

is you exercise 5 days, you always exercise at least one day, so $P(A\cup{B})=B$ 
$$P(A|B)=\frac{0.2}{0.8}=0.25$$



### Law of Total Probability

**Multiplication rule**
$$P(B|A) =\frac {P(B\cap{A})}{P(A)}$$
is the same as
$$P(B\cap{A})=P(A)P(B|A) $$



events $A_1,A_2,...,A_k$ are exhaustive if $A_1\cup{}A_2\cup{}...\cup{}A_k=S$ 

events $A_1,A_2,...,A_k$ are mutually exclusive if $A_i\cap{}A_j=\varnothing$  for $i\neq{j}$ 


**Law of Total Probability**

if $A_1,A_2,...,A_k$ are exhaustive and mutually exclusive for any event B we have:
$$P(B)=P(B\cap{A_1})+P(B\cap{A_2})+...+P(B\cap{A_k})$$
$$=P(B|A_1)P(A_1)+P(B|A_2)P(A_2)+...+P(B|A_k)P(A_k)$$


#### Examples

$A=($
$A_1$ 30% drive
$A_2$ 50% bus
$A_3$ 20% walk
$)$

$B=$$($
of those who drive, 20% are late
of those who bus, 10% are late
of those who walk, 15% are late
$)$

what the the odds a random student is late?
these events
- cannot intersect (mutually exclusive)
- all possibilities in the sample space (exhaustive)
This means we can use law of total probability
$$P(B)=(0.2*0.3)+(0.1*0.5)+(0.15*0.2)=0.14$$


Probability of an item on production line being defective is 0.1
if it is defective, odds of it being removed is 0.9
if it is not defective, odds of it being removed is 0.2
what are the odds a random item will be removed?
$A=$ defective
$B=$ removed
$$P(B)=(0.1*0.9)+(0.9*0.2)=0.27$$



### Bayes' Formula/Rule
if$A_1,A_2,...,A_k$ are mutually exclusive and exhaustive, then for any event $B, P(B)\neq{0}$, and for $1\leq{i}\leq{k}$
$$P(A_i|B)=\frac{P(A_i\cap{B})}{P(B)}$$

#### Examples

$A_1$ 30% drive
$A_2$ 50% bus
$A_3$ 20% walk

$B$
Of those who drive, 20% are late
Of those who bus, 10% are late
Of those who walk, 15% are late

if a random late student is picked, what are the odds they walked?
$P(A_3)$
$P(A_3|B)=0.15*0.2=0.03$ 
$P(B)=0.45$

$$P(B)=\frac{ 0.15*0.2}{0.45} \approx0.2143$$



odds of defective = 0.1
odds defective is removed = 0.9
odds non-defective is removed = 0.2
if an item is removed, what are the odds it is not defective?
$P(removed)=0.27$

$P(removed|defective)=0.1*0.9=0.18$ 

$$P(B)=\frac{0.18}{0.27}=2/3$$

what are the odds product is defective, but not removed?
$\frac{P(defective|\overline{removed})}{P(\overline{removed})}$
=$\frac{P(\overline{defective}|removed)(P(defective))}{P(\overline{removed})}$

 
 $$=\frac{(0.1)(0.1)}{0.27}=0.0137$$
#### Try it yourself

at a factory, 
80% need minor repairs
20% need minor repairs

of those needing minor repairs,
90% of minor repairs are sold
50% of major repairs sold
the rest are destroyed.
Given a randomly selected item, what are the odds it will be destroyed?

closest is A) 0.2