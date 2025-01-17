def main():
    #from socket import *
    import socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # will go over in next tutorial
    
    s.connect(("www,google.com", 80)) # server address, port number
    s.send("GET /index.html HTTP/1.0\n\n") # request to send
    data = s.recv(10000) # number of bytes to read from buffer
    s.close()
    print(data)

if __name__ == "__main__":
    main()