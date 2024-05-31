
Events A and B are independent if knowing one does not effect the odds of the other.

example, rolling two dice. the result of one does not change the chances for the other dice.
$$P(A|B)=P(B), and P(B|A)=P(A)$$
$$P(A\cap{B})=P(A)P(B)$$

proof by multiplication rule:
$$P(A\cap{B})=P(B\cap{A})=P(A)P(B|A)=P(A)P(B)$$

Events are mutually exclusive if $$P(A\cup{B})=0$$

#### examples

take a deck of cards, draw one card

a) are the events (card is 10), and (card is a jack) independent?
$P(is10)*P(is10)=(4/52)^2$
$P(is10\cap{}isJ)=0$
not the same, not independent

b) are (is diamond) and (is queen) independent?
$P(isDiamond\cap{}isQueen)=1/52$
$P(Queen)*P(diamond)=4/52$
same, events are independent



at a university, first year students...
60% take calculus
70% take history
80% take calculus *and/or* history

are they independent/mutually exclusive?
$P(calc)*P(history)=0.42$

$P(calc\cap{}hist)=P(calc)+P(hist)-P(calc\cup{}hist)$
$=0.6+0.7-0.8=0.5$
0.43 != 0.5, **not** independent

if they were mutually exclusive, the intersection would = 0
**not** mutually exclusive

### More then two things!

Mutual independent:
$$P(A_1\cap{}A_2\cap{}... \cap{}A_k)=P(A_1)P(A_2)...P(A_k)$$

pairwise independent:
for all $i\neq{}j$ 
$$P(A_i\cap{}A_j)=P(A_i)P(A_j)$$

#### examples
At this store, everyone who enters buys one laptop and one printer

|  | Printer 1 | Printer 2 | Total |
| ---- | ---- | ---- | ---- |
| Laptop A | 0.12 | 0.28 | 0.40 |
| Laptop B | 0.12 | 0.22 | 0.34 |
| Laptop C | 0.06 | 0.20 | 0.26 |
| Total | 0.30 | 0.70 |  |
Let:
D be "customer buys Printer 1"
A be "customer buys Laptop A"
B be "customer buys Laptop B"

True or false:

a) A and D are independent
	$P(A)P(D)=0.4*0.3=0.12$
	$P(A\cup{}D)=0.12$
	True - independent
b) B and D are mutually exclusive
	$P(B\cap{}D)=0.12$
	False - not mutually exclusive
c) D and B are independent
	$P(D)P(B)=0.3*0.34=0.102$
	 $P(D\cap{}B)=0.12$
d) A and B are mutually exclusive
	True - nobody buys two laptops



Quality control is done separately, by 2 inspectors
inspector 1 correctly identifies 0.95 of defects
inspector 2 correctly identifies 0.85 of defects

**Given the item is correctly identified**, what are the odds the 2nd inspector identifies a defect but not the first?
A=first inspector identifies = 0.95
$P(A)=0.95$
$P(\bar{A}) = 0.05$
B=second inspector identifies = 0.85
$P(B)=0.85$
$P(\overline{B})=1.15$
C=A or B or both (item was identified)
$P(C)=P(A\cup{B})=P(A)+P(B)-P(A\cap{B})$ 
$=0.95+0.85-0.95(0.85)$

Method 1
$$P(\bar{A}\cap{B}|C)=\frac{P((\bar{A}\cap{B})\cap{B})}{P(C)}$$
the answer we want is $\frac{P(B)-P(A\cap{B})}{P(C)}$
$$ \frac{0.85-(0.95)(0.85)}{0.95+0.85-(0.95)(0.85)}$$
$$ \approx0.0428$$

method 2
$$\frac{B*\bar{A}}{P(C)}=\frac{0.85*0.05}{0.9925
}\approx0.0428$$ 

