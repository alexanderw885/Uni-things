Orthographic and perspective projections change the [camera transformation](Viewing%20transformations).

An orthographic projection just changes the position and rotation of an object, and can be represented with a matrix
![[Pasted image 20240722100347.png]]

In a perspective projection, the size of objects changes as they get further from the camera origin.

What we want to do is convert the perspective camera into an orthographic one. We want to use a matrix transform to turn this:
![[Pasted image 20240725095831.png]]
into this:
![[Pasted image 20240725095856.png]]

if the height of an object is  $y$, 
and it's at distance $z$, 
and you project everything to the image plane at distance $d$:
the projected height $y_s$ =
$$y_s = \frac{d*y}{z}$$
![[Pasted image 20240722110330.png]]


What was our [transformation matrix](2D%20Transformations) before this? 
![[Pasted image 20240722110534.png]]
a and b were for scaling and rotating, c was for translation
we still have two empty values we can use for perspective
![[Pasted image 20240722110649.png]]
But, now we don't have that 1 in the last slot
So we divide everything by $ex+fy+g$
![[Pasted image 20240725100740.png]]

here's a matrix for 3d perspective transform
![[Pasted image 20240725101340.png]]this is in camera space, so we know the camera is at the origin and that z faces opposite the camera direction

### Parameters
$l,r$ are left, right
$b,t$ are bottom, top
$n, f$ are nearest and furthest planes
You do need to specify the furthest plane you can see.