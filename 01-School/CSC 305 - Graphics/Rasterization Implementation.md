is normally done on the GPU, but in this course, we'll do it in software

##### raster.h/raster.cpp
mimics the API of modern rasterizers
readable, under 200 lines

## Rasterization Pipeline
![[Pasted image 20240711103228.png]]
## Vertex input
you have to send:
- World coordinates
- Colour
- Normal
You can send more, but should only send what is required
## Shaders
general purpose functions executed in parallel on the GPU
often in a custom programming language, but here will be done in C++

The vertex shader process each input vertex, and outputs the final vertex position in the canonical bi-unit cube, and to output any data required by the fragment shader

the Fragment shader outputs final colour of a fragment

the Blending shader blends the colours'attributes in the pixel
### Uniforms
values that are constant for the entire scene
essentially global variables

### How to prevent viewport distortion?
if you're not rendering a square image, you need to adjust for that in order to not stretch the image
need to adapt view depending on framebuffer size
create a transformation that maps a box with the same aspect ratio as the viewport to the unit cube
```
aspect_ratio = framebuffer.rows() / framebuffer.cols();

if (aspect_ratio >= 1)
{
	uniform.view(0,0) = 1 / aspect;
}
else
{
	uniform.view(1,1) = aspect;
}
```

