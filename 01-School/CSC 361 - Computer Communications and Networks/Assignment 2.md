# TCP Traffic Analysis
Given a sample TCP trace file, make a python script to parse and process the trace file, and track TCP state information

connection is identified by 4-tuple
- source IP
- dest. IP
- source port
- dest. port

Packets can flow in both directions, and packets from different connections may be interweaved with each other

For each connection, find:
- the state of each connection
- for complete connections with at least one SYN and ACK, find:
	- start time, end time, and total duration
	- number of packets sent in each direction and total number of packets 
	- number of bytes in each direction and total number of bytes
Finally, make summary for all connections
- number of reset TCP connections in trace
- number of connections still open when trace ended
- number of complete connections established before capture started
- number of complete connections observed in the trace
For compete connections observed:
- min, mean, max time durations
- min, mean, max RTT (round time trip)
-  min, mean, max number of packets

___
Input format:
`python3 script.py argument_trace`
Output format
```
A) Total number of connections: n
----------------------------------
B) Connection details:

Connection 1:
all:
the:
info:
for:
connection:
END
++++++++++++++++++++++++++++++++
...
++++++++++++++++++++++++++++++++
Connection N:
same as above:
--------------------------------
C) General

General:
Statistics:
--------------------------------
D) Complete TCP Connections

Statistics:
time!:
```

___
How to extract structures from the file?
Use the python package `struct`
```python
from struct import *

#Converts into bytes
# h means short int, l means long
struct.pack('hhl',1,2,3) # hhl means:
# convert first value into short
# convert second value into short
# convert third value into long

# Convert from bytes into not bytes
struct.unpack(hhl, b'binary_string')
# Again, hhl tels us the first two values are shorts, the last one is a long.
```
In the tutorial slides, it tells us how long each part of each header is, so we can unpack each packet header into values of the correct type to look at.

First 24 bytes are all for the global header
- 4 bytes magic number, to check endianness
- 2 bytes for the version major, for file format
- 2 bytes for minor version minor, for file format
- 4 bytes for time correction in seconds, difference from UTC to local time
- 4 bytes accuracy of timestamps
- 4 bytes max length of packet
- 4 bytes data link type

Then each packet has 16 bytes for the packet header
- 4 bytes for timestamp in epoch time, in seconds
- 4 bytes for microseconds in timestamp
- 4 bytes for size of the saved packet data in bytes, not including header
- 4 bytes `incl_len` for total length of packet, including the header

___
### PCAP file format
has global header, then repeats {packet header, packet data}

for us, the only important part of the global header is the magic number, though we do need to know the total length in order to find that start of  the first packet header.

### How to read PCAP file

open the file in binary mode:
`file = open(filename, 'rb')`
read first 24 bytes
`global_header = file.read(24)`
check endianness with the magic number
read packet header
`packet_header = file.read(16)`
all four packets are important for this project, but we use `incl_len` to get the number of bytes to read for the packet.

For this assignment we only care about TCP packets, we can ignore any others.