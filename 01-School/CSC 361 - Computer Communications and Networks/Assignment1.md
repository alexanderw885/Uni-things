Goal: build tool to collect info on web server
[HTTP request](01.14-Application_Layer):
- header with:
	- method field
	- URL field
	- HTTP version field
- body with information
HTTP response:
- header contains if info was found or not, and info about server
	- HTTP version field
	- status code
		- 200: request succeeded
		- 404: info does not exist
		- 505: HTTP version not supported
		- 302: URL redirection
		- 401: password protected, do not have right credential
	- if content was found
	- 
	- content type
	- content length
	- if connection is closed
	- ...
- body contains requested packet


### Uniform resource identifiers URI
combination of uniform resource locator (path to file) and uniform resource name (name of file).

by default: HTTP uses port 80, HTTPS uses port 443

### cookies
data sent by server to browser. browser stores cookie and sends it back to the server in later requests. 

Sent in the header section of the response, with field Set-Cookie: \<cookie-name\> = \<cookie_value\>

___
# Project
implement WebTester
- find out if server supports HTTP2
- name of every cookie
- expire time of cookie (if exists)
- domain name in cookie (if exists)
- if web page is password protected

run the program with:
`python WebTester.py www.uvic.ca`

OPTIONAL: print response from website

Expected response format:
website: www.uvic.ca
Supports http2: no
List of Cookies: 108 
cookie name: SESSID_UV_128004, domain name: www.uvic.ca
cookie name: uvic_bar, expires time: Thu, 04-Jan-2018 00:00:01 GMT; domain name: .uvic.ca
cookie name: www_def,
cookie name: TS01a564a5
cookie name: TS01c8da3c, domain name: www.uvic.ca 
cookie name: TS014bf86f, domain name: .uvic.ca
\3. Password-protected: no


Test code in `ssh netlinkID@linux.csc.uvic.ca`
use ftp tools to upload to server
___
### Python socket programming
socket: abstraction for network code
like a function that takes port number (80 for HTTP), and IP address

```python
from socket import *
s = socket(AF_INET, SOCK_STREAM) # will go over in next tutorial
s.connect(("www,google.ca", 80)) # server address, port number
s.send("GET /index.html HTTP/1.0\n\n") # request to send
data = s.recv(10000) # number of bytes to read from buffer
s.close()
```
always close the connection once you're done
### HTTP2 detection
for HTTP server: common way to check for HTTP/2 is to issue an OPTIONS request instead of GET, then inspect the HTTP2-Settings header. 

for HTTPS server: often used over TLS, requires SSL/TLS handshake. you can check the negotiated protocol once the TLS handshake is negotiated. 
## Design idea
for HTTP:
```python
request = f'OPTIONS / HTTP/1.1\r\n"
```
do things????

HTTPS:
check TLS-ALPT (application-layer protocol negotiation)
1. create SSL-wrapped socket
```
sock = socket.create_connection((host,port))
context =
context.set_alpm_protocols(['h2','http/1.1\])
sock = context.wrap_socket(sock, server_hostname=host)
```
2. Get negotiated protocol from handshake```

```
negotiated_protocol = ssock.selected_alpn_protocol()
```

3. check if `h2` is in supported protocols