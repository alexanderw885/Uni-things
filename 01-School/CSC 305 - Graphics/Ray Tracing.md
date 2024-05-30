steps
1. Generation of rays (one per pixel)
2. Intersection with objects in the scene
3. Shading (compute colour of pixel)

### Generation
2 projection methods, orthographic and perspective


### Intersections
expensive operation
often done to either spheres or triangles.
there may be multiple intersections, only count the closest one to the camera
#### spheres
compute closest point to center of sphere. if distance <= radius, there is an intersection. Need to find point of intersection, and the normal of the intersection point

### triangles


### Shading
Also expensive
3 parts
- Diffuse shading (Lambertarian)
- Specular shading (Blinnn-Phong)
- Ambient shading

#### Shadows
in order to implement shadows, look for intersections between intersection point and light source
if there is an intersection, the light should not contribute.
these rays are called shadow rays
##### Cases
1. No intersection, so no shadow
2. Intersection, shadow
3. intersect after light source, so no shadow

to differentiate case 2, 3, calculate distance from intersection and light. if distance->light greater than distance->light, there is a shadow

NOTE: sometimes due to floating point error, shadow ray will intersect with p, where ray hit the surface.
one way to fix that is to set the starting point of the ray as slightly further down the shadow ray.

#### Ideal Reflections
Ideal Reflections (mirror reflections)
at intersections reflection colour can be found by:
reflect ray around normal of surface, find colour where that ray lands.
This can be called recursively

how to reflect around normal?
incoming ray: d
normal vector: n
outgoing vector: v
decompose d into parallel to n, and orthogonal to n
$$v=-(d-proj_nd)+proj_nd$$
$$=-d+2proj_nd$$
$$v=-d+2\frac{n*d}{n*n}n$$
