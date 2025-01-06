## Header
`t=x-y` or `to=x-y`
- x,y both floats
- x = min tempo
- y = max tempo
`level=x`
- x = level, 0-20
`ver=x`
- should not matter?
___
## Body
`--`
- bar line, signifies the end of the header and the beginning of each bar
- must have bar line after the last measure
`beat=x/y`
- time signature, likely 4/4
- if not specified, continue from last known value
`t=x`
- tempo for the bar, should be within `to` range
- if not specified, continue from last known value
### `0000|00|--`
gonna break this into parts
`bt-notes|fx-notes|lasers`

##### bt-notes
0000, each value represents a bt-button
- 0 means no note
- 1 means a tap note
- 2 means a hold note. the first 2 is the start, and each following 2 continues holding. On 0, you release
##### fx-notes
00, each value represents one of the fx-buttons
- 0 means no note
- 1 means **hold note**. the first 1 is when you start holding, each following 1 means continue holding. release on 0
- 2 means **tap note**
**1 and 2 are swapped between the BT and FX keys, keep this in mind**
##### lasers
--, each symbol represents a laser
- `-` means no laser
- `0` means far left position
- `o` means far right position
- `:` connects the position before and after it. 
	- This means `0` to `:` to `0` is "Hold at position `0`, fat left".
	- `0` to `:` to `o` means "start at `0`, go to `o`"
- from left to right, all positions are: `0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmno`
if a laser is less than 1/32, they're treated as slams

___
# Measurement Metrics
- average notes/second
	- peak notes/second, highest average over 8 measures
- laser time
	- non-stationary
	- number of direction changes
	- peak direction change rate, average over 8 measures
- average notes/second while a laser is active
- number of notes being played on the same side of the controller as an active laser