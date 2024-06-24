# Linear Transformations
linear 2d transformation can be represented by a unique 2d matrix

### Scaling
s(x,y) is scaling factor
$$ \begin{array}{cc} s_x &0 \\ 0 &s_y \end{array} $$
with this formula, the origin does not move
### Rotation
where alpha is degree to rotate
$$ \begin{array}{cc} 
cos\alpha &-sin\alpha \\ 
sin\alpha &cos\alpha \end{array} $$
again, the origin does not move
### Shearing
to shear along x-axis
$$ \begin{array}{cc} 
x & a \\ 
0 & y \end{array} $$
to shear along y axis
$$ \begin{array}{cc} 
x & 0 \\ 
b & y \end{array} $$
in these examples, the sheared axis does not move
### Translation
![[Pasted image 20240624105215.png]]
arguably the most useful transformation

# Affine Transformations
origin is no longer always a fixed point
Affine map = linear map + translation
![[Pasted image 20240624105612.png]]
but can we represent it is just a matrix transformation?
we can, with homogenous coordinates
### Homogenous Coordinates
adds a third coordinate, making a 3x3 matrix for 2d space
![[Pasted image 20240624105750.png]]
with this, the transformations can be represented as: 
![[Pasted image 20240624110041.png]]
