# Cookies
---
- HTTP server is stateless
- It is often desirable for a web server to identify users when it serves content as a function of the user identity
- Cookies allow sites to keep track of users
- Has 4 components:
	1. cookie header line in the HTTP response message
	2. cookie header line in the HTTP request message
	3. cookie file kept on the user's end system and managed by the user's browser
	4. back-end database at the web site

![[cookie.png]]
![cookie](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/cookie.png)

- The `Set-cookie` header in the HTTP response contains the identification number
- The browser appends a line containing the hostname of the server and the identification number to the special cookie file 
- The web server gets to know exactly which pages the user visits, the particular order and also the time at which the page was visited
- If a user registers themselves in the web page with their details, their account details will also be added along with the identification number in the web server's database
- Amazon uses cookies to provide its shopping cart service and also its product recommendation system