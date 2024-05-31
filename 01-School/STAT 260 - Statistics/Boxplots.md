also box-and-whisker plots
allows viewer to quickly identify median, and upper/lower quartile.
![[Pasted image 20240116104711.png]]
top of box is upper quartile, which means 25% is above the box.
bottom of box is lower quartile, which means 25% is below the box.
inside the box is the interquartile range (IQR), it contains 50% of the data points.

The line in the middle of the box is the median.
the lines above and below the box show the maximum and minimum values, excluding the outliers
the outliers are still shown as the dots outside of this range. note that in this example, all outliers are below the range, none are above. __outliers are still used in any calculations.__


Outliers are often determined with the IQR, anything outside of:
\[lower quartile  - 1.5\*IQR,   upper quartile +1.5\*IQR\]
