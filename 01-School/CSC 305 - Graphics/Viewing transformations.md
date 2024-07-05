

![[Pasted image 20240704102602.png]]

we might be modelling things around the origin, but now we want to put them together. How do we manage object coordinates, world coordinates, camera coordinates, and screen coordinates?

![[Pasted image 20240704102830.png]]

### Viewport transformation
Converts the canonical view volume, a bi-unit square/cube (-1 to 1), into screen space.
the sides of the screen are nx, ny, so in order to transform the view volume, we need the following:
![[Pasted image 20240704103207.png]]
this is both scaling, and translating away from the origin. when doing as separate steps, you need to scale first, then translate it into place

### Orthographic projection
converts camera space into the canonical view volume
Again, only uses translation and scaling. Here, we want to translate to the origin first, and then scale it.
the coordinates of the shape are bounded by $(l,b,n)$ and $(r,t,f)$
where $l,r$ = left, right
$t,b$ = top, bottom
$n,f$= near, far

so first, we move the centre of the shape to the origin, and then we scale down into bi-unit cube
![[Pasted image 20240704105408.png]]
note that the scaling is negative, since it's likely being scaled *down* by the size of the shape
### Camera transformation
converts world space into camera space
camera has 3 parameters
- eye position e
- gaze direction g
- view-up vector t
so we want to make an orthogonal vector (u,v,w) around the camera, where w points into the camera from facing direction
$w = -\frac{g}{||g||}$
$u = \frac{t\times{}w}{||t\times{}w}$ 
$v=w\times{}u$

##### Change of frame

  