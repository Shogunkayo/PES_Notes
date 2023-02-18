# DNS Records
---
- The DNS servers that together implement the DNS distributed database store resource records (RR), including RRs that provide hostname-to-IP address mappings
- Each DNS reply message carries one or more resource records

Resource Recods format: `{name, value, type, ttl}`
- `ttl` is the time to live of the resource record -> determines when a resource should be removed from cache
- `name` and `value` fields depend on `type`

| Type  | Description                                                                    |
| ----- | ------------------------------------------------------------------------------ |
| A     | name is hostname, value is IP address                                          |
| NS    | name is domain, value is hostname of authoritative name server for this domain |
| CNAME | name is alias for some 'canonical' name, value is canonical name               |
| MX    | value is canonical name of a mailserver, associated with alias hostname name                                                                               |

- If a DNS server is authoritative for a particular hostname, then the DNS server will contain a Type A record
- If a server is not authoritative for a hostname, then the server will contain a Type NS record as well as a Type A record

# DNS Messages
---
- Both query and reply messages have the same format
- `nslookup` program can be used to send a DNS query message directly from your host to some DNS server

![[dnsmsg.png]]
 ![dnsmsg](https://github.com/Shogunkayo/PES_Notes/blob/main/Computer%20Networks/Images/dnsmsg.png)

### Header Section
- The first 12 bytes is the header section. 
- The first field is a 16bit number that identifies the query. This identifier is copied into the reply message to a query, allowing the client to match received replies with sent queries
- A 1 bit query/reply flag indicated whether the message is a query(0) or a reply(1)
- A 1 bit authoritative flag is set in a reply message when a DNS server is an authoritative server for a queried name
- A 1 bit recursion-desired flag is set when a client desires that the DNS server perform recursion when it doesn't have the record. It is 
- A 1 bit recursion-available flag is set in a reply if the DNS server supports recursion
- There are also four number of fields which indicate the number of occurences of the four types of data sections that follow the header

### Question Section
- Contains information about the query that is being made
- Has a name field that contains the name that is being queried
- A type field that indicates the type of question being asked about the name

### Answer Section
- Contains the resource records the name that was originally queried
- A reply can return multiple RRs in the answer

### Authority Section
- Contains records of other authoritative servers

### Additional Section
- Contains other helpful records
- For example, the answer field in a reply to an MX query contains a resource record providing the canonical hostname of a mail server. The additional section contains a Type A record providing the IP address for the canonical hostname of the mail server

## Inserting Records
- A registrar is a commerical entity that verifies the uniqueness of the domain name and enters the domain name into the DNS database 
- Prior to 1999, Network Solutions had a monopoly on domain name registrations for `com`, `net` and `org` domains

When registering a domain name, you need to provide the registrar with the names and IP addresses of your primary and secondary authoritative DNS servers. For each of the authoritative DNS servers, the registrar makes sure that a Type NS and a type A record are entered into the TLD servers