two ways of making images
#### Vector images
stores something like a procedure/function on how to draw the image. You can zoom in indefinitely since it doesn't define pixel sizes.
These will not be covered in class

#### Bitmapped images
stores values of each pixel. This means as you zoom in, the image gets blurry/you can see each pixel.
Bitmapped images will be the focus of this course

Aside: Camera sensors
sensor can only sense amount of light, not colour. So a filter can be put over the sensor, with a coloured grid to let different colours at different spots. Uses three colours, RGB, and there's twice as much green as there is red or blue.


### Pixel coordinates
X- left/right, increases heading to the right.
Y- up/down, *usually* increases going up

this means in a 100x100 image:
(0,0) is the bottom left corner, 
(100,0) is bottom right
(100,100) is the top right


### Pixel Values (Framebuffer format)
1-bit greyscale -- mostly used for text
8-bit RGB (24 bits total)
8-bit RGBA (32 bits total, A for alpha channel)

we'll be using RGBA for this class

16/24/32-bit formats also exist, but won't be used in this class

### Brightness, Gamma Correction
What should be min/max light intensity?
differs from monitor to monitor, person to person. Gamma correction is the calibration for this
displayed intensity = (max intensity)\*$a^\gamma$

### Colours
2 formats:
- RGB, additive colours (start with black, add all to get white): Red, Green, Blue
- CMYK, subtractive colours (start with white, add all to get black): Cyan, Magenta, Yellow, K-stands-for-black-apparently

CMYK is used by printers/physical mediums, RGB is used for screens. We'll be using RGB format

#### Alpha Compositing
alpha, mentioned earlier, represents transparency.
$\alpha=0$, all white
$\alpha = 1$, full colour

for overlaying images:
colour $c=\alpha{}c_{new}+(1-\alpha{})c_{old}$

### Formats/Compression
Lossy:
- jpeg, introduces artifacts

Lossless:
- png - common in web applications
- ppm - simple, uncompressed
- tiff - mostly in scientific uses

