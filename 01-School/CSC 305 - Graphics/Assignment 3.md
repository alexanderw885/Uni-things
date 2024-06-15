
### Part 1
need to make generic implementation of camera
you are given point origin of the camera, and angle of opening (aperture). You need to find the width and height to get ray direction
### Part 2
implement shading shadow rays
when sending ray from intersection to light source, make sure the ray starts slightly above the intersection. Otherwise floating point error will cause issues
### Part 3
implement reflection
### Part 4
implement perlin noise for a texture on a sphere
both with linear and cubic interpolation
### Bonus 0
implement depth of field. 
Shoot several rays per pixel, each one from a very slightly different spot
each ray will point to the same spot on the focal plane.
### Bonus 1
implement refraction **hard**
derive formula for refracted day
implement refraction color