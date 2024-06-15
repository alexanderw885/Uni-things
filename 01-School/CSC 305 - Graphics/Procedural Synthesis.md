Making things is too much effort, what if we could make a thing that makes things for us?
# Noise 
Goal: create realistic textures at inexpensive costs
this starts with noise functions

what makes a good noise function? use white-noise + smooth-function
This could be controllable, to give potions like vertical lines, or larger grain, or cloud-like appearance
other properties to have
- continuous
- controllable
- compact
- fast
- non-periodic

### Why use procedural textures?
- don't take up much memory, since you don't need to store them
- fast to use
- can be evaluated at any point, fully continuous (infinite resolution)
- computation-bound, not memory-bound
## Perlin noise
Standard method of noise creation. Unless specified otherwise, most noise is generated this way

based on a regular lattice, with a random vector vat each corner/vertex
given a point p, find the four lattice corners
compute $v*(p-v)$ for every corner
return bilinear interpolation of the dot product at each p
#### finding point p
Let vertices on the lattice be (0,1),(1,0),(1,1)...
given point p(x,y), take the floor and ceiling of $p_x,p_y$ to get the four nearest vertices to p

let lower left vector be $v_0$, incrementing counter-clockwise
#### Dot products
$v_0*(p-v_0)=a$
$v_1*(p-v_1)=b$
$v_2*(p-v_2)=c$
$v_3*(p-v_3)=d$
#### Bilinear interpolation
$e = \frac{a_x+b_x}{2}$
$f=\frac{a_y+b_y}{2}$
$x_1=lerp(e,f, sx)$
do same with c and d for $x_2$
return $lerp(x_1,x_2,sy)$

sx, sy are interpolation weights
sx = decimal part of $p_x$
sy = decimal part of $p_y$ 


### Changeability
by changing the density of the lattice, you can change how quickly the resulting noise change
you can also combine results to make even less regular-looking maps

## Side note: Colour maps
human's suck at colour perception. be careful about where you choose to map your noise to, they might see very little change or very large changes where there shouldn't be.
There exists "Perceptually uniform colourmaps" to get around this.
*or*, you could use carefully chosen colour schemes to manipulate data!

# Implicit Modelling



## Turning implicit into explicit
can use marching squares/cubes
- create grid
- find if each vertex is inside-outside the shape
- program result for each case
- there's 16 cases, but thanks to symmetry there's only 4 unique cases
![[Pasted image 20240610101138.png]]
how do you decide where the boundary of inside-outside is?
You can just choose the middle, but that's unlikely to be accurate. Instead, linear interpolation is more likely to be accurate. However, it's even more of a pain, just don't.

it's a pain to implement, if you must do it then use triangles instead
#### 3d
can go up to 3d with marching squares, but then there's $2^8$ possible states, with is way too many. Just use a library. If you *really* need to, still just do it with triangles instead of cubes

