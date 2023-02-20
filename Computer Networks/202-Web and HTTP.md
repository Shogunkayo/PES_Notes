# HTTP
---
- Lies at the heart of the Web
- Implemented in two programs: client program (implemented by web browsers) and server program (implemented by web servers)
- Webpages are made up of objects (files)
- Each URL has two components => hostname of the server that houses the object and the object's path name

`https://www.somesite.com/somedirectory/somefile.txt`
`www.somesite.com` is the host name and `/somedirectory/somefile.txt` is the object's path name

- HTTP defines how web clients request web pages from web servers and how servers transfer web pages to clients
- HTTP uses TCP as its underlying transport protocol. The HTTP client first initiates a TCP connection with the server. Once the connection is established, the browser and the server processes access TCP through their socket interfaces
- HTTP is a stateless protocol => does not store any state information about the client
- A web server is always on, with a fixed IP address, and it services requests from potentially millions of different browsers
- HTTP has nothing to do with how a web page is interpreted by a client. The HTTP specifications define only the communication protocol between the client and server HTTP programs

## Non-Persistent Connections
1. The HTTP client process initiates a TCP connection to the server on port 80 (default for HTTP). Associated with the TCP connection, there will be a socket at the client and a socket at the server
2. The HTTP client sends a HTTP request message to the server via its socket. The request message includes the path name
3. The HTTP server process receives the request message via its socket, retrieves the object from its storage, encapsulates the object in an HTTP response message, and sends the response message to the client via its socket
4. The HTTP server process tells TCP to close the TCP connection (but TCP will not be terminated untill it knows for sure that the client has received the response message intact)
5. The HTTP client receives the response message. The TCP connection terminates
6. The first four steps are then repeated for each subsequent request from the client

- Each TCP connection transports exactly one request message and one response message
- Most browsers open 5 to 10 parallel TCP connections, and each of these connections handles one request-response transaction
- Round trip time RTT => time it takes for a small packet to travel from client to server and then back to the client. It includes the all the end to end delays

### TCP 3-way handshake
1. Client sends a small TCP segment to the server => SYN packet
2. The server acknowledges and responds with a small TCP segment => SYN-ACK packet
3. Client acknowledges back to the server => ACK packet

- After completing the first two parts of the handshake, the client sends the HTTP request message combined with the third part into the TCP connection
- Roughly, the total response time is two RTTs (first two parts take one RTT, the third part and server response take another RTT) plus the transmission time at the server of the HTML file for a non persistent connection

### Disadvantages
- A brand new connection must be established and maintained for each requested object
- For each of these connections, TCP buffers must be allocated and TCP variables must be kept in both the client and the server => burden on the web server
- Each object suffers a delivery delay of two RTTs

## Persistent Connection
- The server leaves the TCP connection open after sending a response
- Subsequent requests and responses between the same client and server can be sent over the same connection
- Multiple web pages residing on the same server can be sent from the server to the same client over a single persistent TCP connection
- The HTTP server closes a connection when it isn't used for a certain time (configurable)
- The default mode of HTTP uses persistent connections with pipelining

## HTTP Message Format
- There are two types of HTTP messages: request messages and response messages

### Request Message

```
GET /somedir/page.html HTTP/1.1
Host: www.someschool.edu
Connection: close
User-agent: Mozilla/5.0
Accept-language: fr
```

- Message is written in ordinary ASCII text
- Each line is followed by a carriage return (control character or mechanism used to reset a device's position to the beginning of a line of text) and line feed (newline)
- There is an additional carriage return and line feed after the last header line
- If the HTTP method is POST, there will also be an entity body section (it will be empty for a GET method)

> *Carriage return vs Newline*
> The separation comes from typewriter times, when you turned the wheel to move the paper to change the line and moved the carriage to restart typing on the beginning of a line. This was two steps

- The first line of an HTTP request message is called the request line and subsequent lines are called the header lines
- The request line has three fields: method, URL and the HTTP version fields
- HEAD method is usually used for debugging, PUT method is for editing an object, DELETE method to delete an object

| Headers         | Purpose                                                                |
| --------------- | ---------------------------------------------------------------------- |
| Host            | specifies the host on which the object resides                         |
| Connection      | 'close' indicates non-persistent connection                           |
| User-agent      | the user agent (browser type) that is making the request to the server |
| Accept-language | indicates the language in which the user prefers to receive the object, if such an object exists on the server, else server will send the default version                                                                       |

### Reponse Message
```
HTTP/1.1 200 OK
Connection: close
Date: Tue, 18 Aug 2015 15:44:04 GMT
Server: Apache/2.2.3 (CentOS)
Last-Modified: Tue, 18 Aug 2015 15:11:03 GMT
Content-Length: 6821
Content-Type: text/html

(data)
```

- Three sections: status line, header lines and the entity body
- Status line has three fields: protocol version, status code and a corresponding status message
- Entity body contains the requested object itself

| Headers        | Purpose                                                                     |
| -------------- | --------------------------------------------------------------------------- |
| Date           | the time and date when the HTTP response was created and sent by the server |
| Server         | details about the web server, analogous to User-agent                       |
| Last-Modified  | the time and date when the object was created or last modified              |
| Content-Length | the number of bytes in the object being sent                                |
| Content-Type   | the type of the object being sent                                                                            |
- The object type is officially indicated by the `Content-Type` header and not by the file extension

| Status Code | Status Message             | Description                                                                                                                                                  |
| ----------- | -------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 200         | OK                         | request succeeded and the information is returned in the response                                                                                            |
| 301         | Moved Permanently          | requested object has been permanently moved and the new URL is specified in the Location header. The client software will automatically retrieve the new URL |
| 400         | Bad Request                | request could not be understood by the server                                                                                                                |
| 404         | Not Found                  | the requested document does not exist on this server                                                                                                         |
| 505         | HTTP Version Not Supported | the requested HTTP protocol version is not supported by the server                                                                                                                                                             |

