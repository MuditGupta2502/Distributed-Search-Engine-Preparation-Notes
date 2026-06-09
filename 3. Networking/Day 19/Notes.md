Every machine on network needs an address. google.com → mapped to → IP . This mapping system is:DNS.
Full chain : 
Root (.)
↓
.com
↓
google.com
↓
www.google.com
↓
IP address

Real process --> Your machine asks: “Who knows .com?” . Root server replies. Then asks: “Who knows google.com?” TLD server replies. Then asks: “Who knows www.google.com?” Authoritative server replies. Then gets IP.

This is why first DNS can be slower because multiple lookups happen. Later: cache hit → fast.

DNS record types : Not all DNS records are same. Important ones:
A Record : IPv4 addres. Example: google.com → 142.250.xxx.xxx
AAAA Record : IPv6 address. Example: google.com → 2607:f8b0:4005:805::200e
CNAME : alias. Example: www.google.com → actually points to google.com
MX : Mail server. Used for: gmail mail delivery (not crawler important)
For crawler mostly: A + AAAA

What is TTL? Time To Live. Example: google.com → IP valid for 300 seconds means: after 300 sec: re-check DNS because IP may change.
Why? Servers change. Load balancing changes. CDN changes. Cloud infra changes. So DNS cannot be permanent.

getaddrinfo() --> Thread-safe. Supports IPv4 + IPv6. Production standard 
getaddrinfo() is the standard C/C++ function that converts: "google.com" into one or more network addresses you can connect to.
It hides a lot of DNS work for you. Instead of you manually asking root servers, TLD servers, authoritative servers, and then parsing records, the OS resolver does it and gives you ready-to-use results.
The result is not a single address. This is important.
A hostname can map to: multiple IPv4 addresses, multiple IPv6 addresses, both IPv4 and IPv6, different answers over time.
So getaddrinfo() returns a linked list of results. That is why the output parameter is: struct addrinfo* result = nullptr; not a single IP.