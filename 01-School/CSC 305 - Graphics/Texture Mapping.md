we don't want to be limited to one colour per pixel. Instead, we map an image (a texture) onto the model

### Bump mapping
Instead of encoding textures, you can encode normals to use for lighting. This allows you to add bumps and texture to a flat image
But, you cannot change the the outline\silhouette. A sphere, no matter the bump map, will always be a perfect sphere. 
### Displacement mapping
along with encoding normals, you can displace the placement of different points on the object, allowing you to adjust the shape and silhouette of an object
### Texture mapping
Texture mapping
most often combining:
- colour mapping
- bump mapping
- displacement mapping

# How to do it
we add one additional property for each vertex, the UV coordinate
We need an image/2d texture
we can interpolate the UV value for each triangle, and then find the corresponding value in the texture

