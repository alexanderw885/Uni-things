![[Pasted image 20240708104955.png]]
#### Review: implicit geometric representation
define shapes as functions
F(x,y) = 0 -> on surface
F(x,y) < 0 -> inside surface
F(x,y) > 0 -> outside surface

# Rasterization
for all pixels (i,j)
map (x,y) to (i,j)
if F(x,y) < 0:
  colour pixel(i,j)

### Barycentric Interpolation
method to determine if point is in triangle or not
![[Pasted image 20240708105424.png]]
we have the point p, and we have the triangle, but we need $\alpha,\beta,\gamma$ to see if the point is in the triangle or not. 
if all three are >0, you can tell the point is inside the triangle
![[Pasted image 20240708105921.png]]
### Triangle rasterization
this lets us make simple algorithm for rasterizing a triangle
```
given triangle made of points a,b,c

for all x do:
    for all y do:
        compute (alpha, beta, gamma)
	    if(0 < alpha < 1) &&
          (0 < beta < 1) &&
          (0 < gamma < 1) then:
		    set_pixel(x,y)
		fi
	done
done
```
### Object depth sorting
you can sort be depth, but not only is that inefficient, it also doesn't work all the time. So how do we figure out which objects are behind other?
#### z-buffering
render both the image and the depth buffer, which only stores distance to the camera
when new fragment comes in, only draw if it is closer to you
does not work for transparency, but it's a very cheap operation

