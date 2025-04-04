# Analysis of IP Protocol
continuation of assignment 2.

Aside
`Traceroute`: shows possible route to a destination across IP network
it sends a series of packets. First has time to live (TTL) of 1, then one of 2, and so on until it gets to the max hops for traceroute (default 30) or reaches the destination.
once a packet reaches the end of its TTL without reaching the goal, the router it expired at sends back a `time exceeded` packet to the source.

Fragmentation is when one large datagram is split into 3 smaller datagrams. These need to be reassembled at the destination
### Assignment 3
write python program to analyze trace created by `traceroute`
- list source IP
- list dest IP
- list intermediate node IPs
- protocols used
- number of fragments from original datagram 
- offset of last fragment
- calculate mean RTT and it's standard deviation from source to each other node
You must also:
from a set of 5 given traceroute files:
- determine number of probes per TTL 
This can be done manually with wire shark, or you could take the time to write a script to analyse it for you.


You can reuse your assignment 2 code, don't use a python package to analyse the file.
some intermediate routers may only send back one packet for multiple fragments. Use this ICMP message to get RTT

All fragments should have same identification in the IP header if they belong to the same datagram. Fragment offset determines starting position in the datagram in bytes. if the flag is set to 1, that means there's more fragments in the pack.
