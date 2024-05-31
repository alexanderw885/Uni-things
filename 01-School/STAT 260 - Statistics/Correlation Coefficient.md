
The correlation coefficient $r$ is used to assess linearity of bivariate data
![[Pasted image 20240117104525.png|300]]

sample covariance $S_{xy}$ is defined as ![[Pasted image 20240117104746.png]]


$r$ can also be defined as $r=\frac{S_{xy}}{S_xS_y}$ 

$r$ has a range from -1 to 1
if $r=-1$, there is a perfect negative linear relation
if $r=1$, there is a perfect positive linear relation
if $r=0$, there is no linear relation
	note that does not mean there isn't any relation, it just isn't linear
#### example 

given this set, calculate $r$ 
![[Pasted image 20240117105211.png]]
$\sum_{i=1}^nx_iy_y=(19.5)(3900)+(20)(4205)+...=778165$
$\bar{x} = 21.0625$
$\bar{y}= 4591.875$ 

$$S_{xy}=\frac{778165-(8)(21.0625)(4591.875)}{8-1}$$
$$S_{xy}=633.4375$$
$S_x = 1.147591$
$S_y=567.3493$ 
$$r=\frac{S_{xy}}{S_xs_y}$$
$$r=\frac{633.4375}{(1.147591)(567.3493)}$$
$$r\approx0.973$$
This means there is a strong positive linear relation between $x$ and $y$
