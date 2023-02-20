# Web Cache
---
- Web cache is a network entity that satisfies HTTP requests on the behalf of an origin web server
- Also called a proxy server
- It has its own disk storage and keeps copies of recently requested objects in this storage

1. The browser establishes a TCP connectionto the web cache and sends an HTTP request for the object to the web cache
2. The web cache checks to see if it has a copy of the object stored locally. If it does, the web cache returns the object within an HTTP response message to the client browser
3. If the web cache does not have the object, it opens a TCP connection to the origin server. The web cache then sends an HTTP request for the object into the cache-to-server TCP connection. After receiving this request, the origin server sends the object within an HTTP response to the web cache
4. When the web cache receives the object, it stores a copy in its local storage and sends a copy, within an HTTP response message, to the client browser (over the existing TCP connection between the client browser and the web cache)

 ![[proxy.png]]
 ![proxy](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/proxy.png)

- Cache is both a server and a client at the same time. When it receives requests from and sends responses to a browser, it is a server. When it sends requests to and receives responses from an origin server, it is a client

## Main Functions
- A web cache can substantially reduce the response time for a client request, particularly if the bottleneck bandwidth between the client and the origin server is much less than the bottleneck bandwidth between the client and the cache
- Web caches can substantially reduce traffic in the Interent, improving performance for all applications

Content Distribution Network (CDN) company installs many geographically distributed caches throughout the Internet, thereby localizing much of the traffic. There are shared CDNs (Akamai and Limelight) and dedicated CDNs (Google and Netflix)

## Conditional GET
- The copy of an object residing in the cache may become stale => the object housed in the web serer may have been modified since the copy was cached at the client
- An HTTP request message is called conditional GET message if 
	- the request message uses the GET method
	- the request message includes an `If-Modified-Since:` header line

1. On behalf of a requesting browser, a proxy cache sends a request message to a web server
```
GET /fruit/kiwi.gif HTTP/1.1
Host: www.exotiquecuisine.com
```
2. The web server sends a response message with the requested object to the cache
```
HTTP/1.1 200 OK
Date: Sat, 3 Oct 2015 15:39:29
Server: Apache/1.3.0 (Unix)
Last-Modified: Wed, 9 Sep 2015 09:23:24
Content-Type: image/gif
```
3. The cache forwards the object to the requesting browser, and also caches the object locally. The cache also stores the last-modified date along with the object
4. After some time, when another browser requests the same object via the cache, and the object is still in cache, the cache performs an up-to-date check by issuing a conditional GET to check whether the object has changed
```
GET /fruit/wiki.gif HTTP/1.1
Host: www.exotiquecuisine.com
If-Modified-Since: Web, 9 Sep 2015 09:23:24
```
5. The conditional GET is telling the server to send the object only if the object has been modified since the specified date. If the object has not been modified, the web server sends a response message to the cache
```
HTTTP/1.1 304 Not Modified
Date: Sat, 10 Oct 2015 15:39:29
Server: Apache/1.3.0 (Unix)

(empty entity body)
```