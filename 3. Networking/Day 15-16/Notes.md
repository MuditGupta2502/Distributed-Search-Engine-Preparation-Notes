HTTP : Hyper Text Transfer Protocol. It is the protocol used for communication between web browsers and web servers. It is a request-response protocol, where the client (browser) sends a request to the server, and the server responds with the requested resource.
It is the foundational application layer protocol for data communication on the World Wide Web designed for transferring hypermedia documents like HTML between web browsers and servers. HTTP is a stateless protocol, meaning that each request from a client to a server is independent and does not retain any information about previous requests. This allows for scalability and simplicity in web communication.
HTTP operates on a client-server model, where the client initiates a request and the server processes the request and returns a response. The client can be a web browser, mobile app, or any other software that can send HTTP requests. The server is typically a web server that hosts the website or web application.
HTTP uses a set of methods to indicate the desired action to be performed on the resource. The most common HTTP methods are:
- GET: Used to retrieve data from the server. It is a read-only operation and should not have any side effects on the server.
- POST: Used to submit data to the server. It is typically used for creating new resources or submitting form data.                 - PUT: Used to update an existing resource on the server. It is idempotent, meaning that multiple identical requests will have the same effect as a single request.
- DELETE: Used to delete a resource from the server. It is also idempotent.
- HEAD: Similar to GET, but it only retrieves the headers of the response without the body. It is often used to check if a resource exists or to get metadata about the resource.
- OPTIONS: Used to describe the communication options for the target resource. It allows the client to determine which HTTP methods are supported by the server for a specific resource.
HTTP also supports status codes to indicate the outcome of a request. Some common status codes include:
- 200 OK: The request was successful and the server returned the requested resource.
- 201 Created: The request was successful and a new resource was created as a result.
- 400 Bad Request: The server could not understand the request due to invalid syntax.
- 401 Unauthorized: The client must authenticate itself to get the requested response.
- 403 Forbidden: The client does not have access rights to the content.
- 404 Not Found: The server could not find the requested resource.
- 500 Internal Server Error: The server encountered an unexpected condition that prevented it from fulfilling the request.

----------------------------------------------------------------------------------------------------------------------------------------

1) What happens when your crawler fetches a page?

Suppose your crawler fetches a page from a website. The following steps occur:
1. The crawler sends an HTTP GET request to the server hosting the website, requesting the specific page.
2. The server receives the request and processes it. It checks if the requested page exists and if the crawler has permission to access it.
3. If the page exists and the crawler has permission, the server generates an HTTP response with a status code of 200 OK and includes the content of the page in the response body.
4. The crawler receives the response and processes it. It may parse the HTML content to extract links, images, and other resources for further crawling.
5. The crawler may also check the response headers for information such as caching directives, content type, and other metadata that can help it decide how to handle the response.
6. If the page does not exist or the crawler does not have permission, the server may respond with an appropriate status code (e.g., 404 Not Found or 403 Forbidden) and an error message in the response body.
7. The crawler may log the response and decide whether to retry the request or move on to other pages based on the status code and the content of the response. Overall, the process involves a series of interactions between the crawler and the server, with the crawler sending requests and the server responding with the requested content or appropriate status codes.  

In terms of OS Level for the above, 
1. The crawler initiates a network connection to the server using the TCP/IP protocol stack. This involves creating a socket and establishing a connection to the server's IP address and port number (usually port 80 for HTTP).
2. The crawler sends the HTTP GET request over the established connection. This involves writing the request data to the socket, which is then transmitted over the network to the server.
3. The server receives the request and processes it. This may involve reading the request data from the socket, parsing the HTTP headers, and generating a response based on the requested resource.
4. The server sends the HTTP response back to the crawler over the same connection. This involves writing the response data to the socket,which is then transmitted back over the network to the crawler.
5. The crawler receives the response and processes it. This may involve reading the response data from the socket, parsing the HTTP headers, and extracting the content of the page for further processing.
6. Finally, the crawler may close the connection    after receiving the response, or it may keep the connection open for future requests to the same server (using HTTP keep-alive). This involves closing the socket or keeping it open for reuse.     Overall, the process involves a series of interactions between the crawler and the server at both the application level (HTTP) and the transport level (TCP/IP), with the crawler sending requests and the server responding with the requested content or appropriate status codes.

-----------------------------------------------------------------------------------------------------------------------------------

2) Prerequisite : bare minimum ideas :

- Bit, Byte, Data, Information, Protocol, Network, Internet, IP Address, Port Number, Socket, TCP/IP, HTTP, Status Codes, Crawler.
- Bit: The smallest unit of data in computing, representing a binary value of 0 or 1.   
- Byte: A group of 8 bits, used to represent a single character or a small piece of data.
- Data: Raw facts and figures that can be processed to generate information.
- Information: Processed data that is meaningful and useful for decision-making.
- Protocol: A set of rules and conventions that govern the communication between devices in a network. It defines how machines talk to 
each other and exchange data. TCP, IP, and HTTP are examples of protocols.
- Network: A collection of interconnected devices that can communicate with each other to share resources and information.
- Internet: A global network of networks that allows devices to communicate and share information across the world.
- IP Address: A unique numerical identifier assigned to each device on a network, used to identify and locate devices for communication.
- Port Number: A numerical identifier used to specify a particular service or application on a device. It helps to direct network traffic to the correct destination.
- Socket: An endpoint for communication between two devices in a network. It is a combination of an IP address and a port number, used to establish a connection for data exchange.
- TCP/IP: A suite of protocols  used for communication over the internet. TCP (Transmission Control Protocol) is responsible for ensuring reliable data transmission, while IP (Internet Protocol) is responsible for addressing and routing data packets across the network.
- Packet : A unit of data that is transmitted over a network. It contains the source and destination IP addresses, as well as the data being transmitted. Large messages are broken down into smaller packets for efficient transmission.
- Client and Server: In a network, a client is a device or software that initiates a request for a service or resource, while a server is a device or software that provides the requested service or resource to the client.
- Crawler : A software program that automatically browses the web and collects information from websites. It is commonly used for indexing web pages for search engines or for data mining purposes. A crawler sends HTTP requests to web servers, retrieves the content of web pages, and processes the information for various applications.

----------------------------------------------------------------------------------------------------------------------------------------

3) Why layers exist in networking?
Layers exist in networking to provide a structured and modular approach to designing and implementing communication protocols. Each layer is responsible for specific functions and interacts with the layers above and below it, allowing for separation of concerns and easier management of complex systems. The main reasons for the existence of layers in networking are:
1. Abstraction: Layers provide a level of abstraction, allowing developers to focus on specific functionalities without worrying about the details of other layers. This makes it easier to design and implement protocols, as each layer can be developed independently.
2. Modularity: Layers allow for modular design, where different protocols can be implemented at each layer without affecting the others. This promotes flexibility and allows for the use   of different protocols for different purposes, such as using TCP for reliable communication and UDP for faster, connectionless communication.
3. Interoperability: Layers enable interoperability between different systems and technologies. By adhering to standardized protocols at each layer, devices from different manufacturers can communicate with each other seamlessly, as long as they follow the same protocol specifications.
4. Scalability: Layers allow for scalability in network design. As networks grow in size and complexity, layers help manage the increasing number of devices and connections by providing a structured framework for communication.
5. Troubleshooting: Layers make it easier to troubleshoot network issues. By isolating problems to specific layers, network administrators can identify and resolve issues more efficiently, as they can focus on the relevant layer rather than trying to diagnose the entire network stack at once.
Overall, layers in networking provide a systematic way to design, implement, and manage communication protocols, promoting abstraction, modularity, interoperability, scalability, and easier troubleshooting in complex network environments.

--------------------------------------------------------------------------------------------------------------------------------------

4) Different layers in networking and their functions:

### The Higher Layers (Host Layers)
These layers focus on applications and how data is presented.

- **Layer 7 — Application**
    - Provides network services to applications (web browsers, email clients).
    - Examples: HTTP/HTTPS, FTP, DNS, SMTP.

- **Layer 6 — Presentation**
    - Data formatting, encryption, compression, character encoding.
    - Examples: SSL/TLS, MIME, character sets.

- **Layer 5 — Session**
    - Manages sessions: setup, maintenance, teardown, checkpoints and synchronization.

### The Heart: Layer 4 (Transport)
Responsible for end-to-end communication and segmentation.

- **TCP** — reliable, connection-oriented: ACKs, retransmission, ordering, flow control.  
- **UDP** — connectionless, low-latency, no reliability guarantees (useful for streaming/gaming).

### The Lower Layers (Media Layers)
These layers move data across the physical network.

- **Layer 3 — Network**
    - Routing and logical addressing using IP; handles packet forwarding and path selection.
    - Examples: IP, ICMP, routers.

- **Layer 2 — Data Link**
    - Frame delivery on a single link, MAC addressing, switching, error detection (CRC).
    - Examples: Ethernet, switches.

- **Layer 1 — Physical**
    - Transmits raw bits as physical signals (electrical, optical, radio).
    - Hardware: cables, fiber, NICs, transceivers.

### Physical layer — single-transfer (bit-level) process
1. Bit → signal conversion (line coding / modulation) by NIC/transceiver.  
     - Copper: voltage levels; Fiber: light pulses; Wi‑Fi: amplitude/frequency/phase changes.  
2. Propagation across the medium.  
3. Receiver samples signal at clock intervals.  
4. Decoding maps sampled signal back to bits.  
5. Synchronization (preambles, clock recovery) ensures correct timing.

### Summary
| Layer | Data Unit | Primary Function | Examples / Hardware |
|---|---:|---|---|
| 7 Application | Data | User-facing services | HTTP, FTP, DNS |
| 6 Presentation | Data | Formatting, encryption, compression | SSL/TLS, MIME |
| 5 Session | Data | Session management, checkpoints | RPC, session APIs |
| 4 Transport | Segment | End-to-end reliability/flow control | TCP, UDP |
| 3 Network | Packet | Routing / logical addressing | IP, ICMP, routers |
| 2 Data Link | Frame | MAC addressing / switching, error detection | Ethernet, switches |
| 1 Physical | Bit | Physical signaling | Cables, fiber, NICs, hubs |

---------------------------------------------------------------------------------------------------------------------------------------

5) OSI vs TCP/IP Model:

We hear both names. The practical model used in real-world networking is the TCP/IP model, which is a simplified version of the OSI model. The OSI (Open Systems Interconnection) model is a theoretical framework that defines seven layers of network communication, while the TCP/IP model is a more practical and widely used model that consists of four layers. The OSI model already discussed above, while the TCP/IP model consists of the following layers:
1. Application Layer: This layer corresponds to the OSI model's Application, Presentation, and Session layers. It provides network services to applications and defines protocols for specific applications, such as HTTP,              FTP, DNS, and SMTP.
2. Transport Layer: This layer corresponds to the OSI model's Transport layer. It is responsible for end-to-end communication and provides reliable (TCP) or unreliable (UDP) data transfer between hosts.
3. Internet Layer: This layer corresponds to the OSI model's Network layer. It is responsible for routing and logical addressing using the Internet Protocol (IP). It handles packet forwarding and path selection across the network.
4. Link Layer: This layer corresponds to the OSI model's Data Link and Physical layers. It is responsible for the physical transmission of data over the network, including framing, MAC addressing, and error detection. It includes protocols such as Ethernet for wired connections and Wi-Fi for wireless connections.
In summary, the OSI model is a theoretical framework that defines seven layers of network communication, while the TCP/IP model is a practical model that consists of four layers. The TCP/IP model is widely used in real-world networking and is the basis for the protocols that govern communication on the internet.

------------------------------------------------------------------------------------------------------------------------------------

6) TCP/IP in terms of crawlers:

When a crawler fetches a page, it uses the TCP/IP protocol suite to establish a connection and communicate with the web server.

Overall, the TCP/IP protocol suite plays a crucial role in enabling communication between the crawler and the web server, allowing the crawler to fetch pages and retrieve content from the internet. The TCP layer ensures reliable data transmission, while the IP layer handles addressing and routing of packets across the network. The HTTP protocol operates at the application layer, allowing the crawler to request and receive web pages from the server.

-----------------------------------------------------------------------------------------------------------------------------------

7) IP Addressing : An IP address is like a network address for a device on the internet. It is a unique identifier that allows devices to communicate with each other over the network. There are two main types of IP addresses: IPv4 and IPv6.
- IPv4 (Internet Protocol version 4) uses a 32-bit address format, which allows for approximately 4.3 billion unique addresses. It is the most widely used version of IP addressing. An IPv4 address is typically represented in dotted decimal notation, such as 192.168.0.1.
- IPv6 (Internet Protocol version 6) uses a 128-bit address format, which allows for a much larger number of unique addresses (approximately 3.4 x 10^38). It was developed to address the limitations of IPv4 and is gradually being adopted. An IPv6 address is typically represented in hexadecimal notation, such as 2001:0db8:85a3:0000:0000:8a2e:0370:7334.
IP addresses are used to identify devices on a network and facilitate communication between them. When a crawler fetches a page, it uses the IP address of the web server to establish a connection and retrieve the requested content. The IP address is essential for routing packets across the internet and ensuring that data reaches the correct destination. 

---------------------------------------------------------------------------------------------------------------------------------

8) Routing : Routing is the process of determining the path that data packets take from the source to the destination across a network. It involves the use of routing algorithms and protocols to make decisions about how to forward packets based on factors such as network topology, traffic load, and link costs. Routers are devices that perform routing functions by examining the destination IP address of incoming packets and forwarding them to the appropriate next hop based on their routing tables. Routing is essential for enabling communication between devices on different networks and ensuring that data reaches its intended destination efficiently.

---------------------------------------------------------------------------------------------------------------------------------

9) Packet travels ip address remains same : When a packet travels across the network, its source and destination IP addresses remain the same. The IP address is used to identify the source and destination devices, and it is included in the header of the packet. As the packet traverses through routers and switches, the IP address is used to determine the next hop for forwarding the packet towards its destination. However, the IP address itself does not change during transit; it remains constant from the source to the destination. This allows for proper routing and delivery of packets across the network.

MAC Address is a unique identifier assigned to network interfaces for communication at the data link layer. It is used for local network communication and is not visible to devices outside the local network. When a packet travels across the network, the MAC address of the source and destination devices may change as the packet is forwarded through different network segments, but the IP address remains constant for end-to-end communication.

----------------------------------------------------------------------------------------------------------------------------------

10) TTL (Time To Live) : TTL is a field in the IP header that specifies the maximum number of hops (routers) that a packet can traverse before it is discarded. It is used to prevent packets from circulating indefinitely in the network in case of routing loops. Each time a packet passes through a router, the TTL value is decremented by one. If the TTL value reaches zero before reaching its destination, the packet is discarded and an ICMP "Time Exceeded" message is sent back to the source. This mechanism helps to ensure that packets do not get stuck in routing loops and allows for efficient use of network resources. TTL is also widely used in traceroute tools to determine the path that packets take from the source to the destination by sending packets with increasing TTL values and observing the responses from intermediate routers.

----------------------------------------------------------------------------------------------------------------------------------

11) IP Header : The IP header is a part of the IP packet that contains important information about the packet, such as the source and destination IP addresses, the protocol being used, and other control information. The IP header is typically 20 bytes long for IPv4 and 40 bytes long for IPv6. It includes fields such as:
- Version: Indicates the version of IP being used (IPv4 or IPv6).
- Header Length: Specifies the length of the IP header in 32-bit words.
- Total Length: Specifies the total length of the IP packet, including the header and data.
- Identification: A unique identifier for the packet, used for fragmentation and reassembly.
- Flags: Control flags for fragmentation and other purposes.
- Fragment Offset: Indicates the position of a fragment in the original packet if fragmentation occurs.     
- TTL (Time To Live): Specifies the maximum number of hops (routers) that a packet can traverse before it is discarded.

Where is ttl located in the IP header? The TTL (Time To Live) field is located in the IP header, specifically in the IPv4 header. It is an 8-bit field that is used to specify the maximum number of hops (routers) that a packet can traverse before it is discarded. The TTL field is located after the Identification, Flags, and Fragment Offset fields in the IPv4 header. In the IPv6 header, there is a similar field called "Hop Limit" that serves the same purpose as TTL in IPv4.

----------------------------------------------------------------------------------------------------------------------------------

12) Fragmentation and Reassembly : Fragmentation is the process of breaking down a large IP packet into smaller fragments to fit within the maximum transmission unit (MTU) of the network. This is necessary because different networks may have different MTU sizes, and if a packet exceeds the MTU, it cannot be transmitted without fragmentation. The IP header contains fields such as Identification, Flags, and Fragment Offset that are used to manage fragmentation and reassembly.

When a packet is fragmented, each fragment is treated as a separate packet with its own IP header. The Identification field is used to identify all fragments that belong to the same original packet. The Flags field contains control flags that indicate whether more fragments are coming (MF flag) and whether the fragment is the last one (DF flag). The Fragment Offset field indicates the position of the fragment in the original packet.

----------------------------------------------------------------------------------------------------------------------------------

13) ICMP : ICMP (Internet Control Message Protocol) is a network protocol used for error reporting and diagnostic purposes in IP networks. It is a part of the Internet Protocol suite and operates at the network layer. ICMP messages are used to communicate information about network conditions, such as unreachable hosts, time exceeded, and echo requests/replies (used in ping). When a router or host encounters an error while processing a packet, it can generate an ICMP message to inform the sender about the issue. ICMP is essential for network troubleshooting and management, allowing administrators to diagnose connectivity problems and monitor network performance.

-----------------------------------------------------------------------------------------------------------------------------------

14) TCP is a stream not packets to your program : TCP (Transmission Control Protocol) is a connection-oriented protocol that provides reliable, ordered, and error-checked delivery of data between applications. When a program sends data over a TCP connection, it is treated as a continuous stream of bytes rather than discrete packets. TCP takes care of breaking the data into segments, adding headers for sequencing and error checking, and ensuring that the data is delivered in the correct order. The receiving application can read from the TCP stream without needing to worry about packet boundaries, as TCP handles the segmentation and reassembly of data behind the scenes. This allows for a seamless and reliable communication experience for applications using TCP.

TCP gives congestion control : TCP includes built-in congestion control mechanisms to prevent network congestion and ensure fair use of network resources. Congestion control algorithms, such as TCP Reno and TCP Cubic, adjust the rate at which data is sent based on network conditions. If the network becomes congested (e.g., due to packet loss or increased latency), TCP will reduce the sending rate to alleviate congestion and avoid overwhelming the network. Conversely, if the network is performing well, TCP can increase the sending rate to maximize throughput. This dynamic adjustment helps maintain efficient data transmission while minimizing the impact of congestion on overall network performance.

-----------------------------------------------------------------------------------------------------------------------------------

15) 3 way handshake : The three-way handshake is a process used in TCP to establish a reliable connection between a client and a server. It involves three steps:
1. SYN: The client sends a TCP segment with the SYN (synchronize) flag set to the server, indicating that it wants to establish a connection. The segment includes an initial sequence number chosen by the client.
2. SYN-ACK: The server responds with a TCP segment that has both the SYN and ACK (acknowledgment) flags set. The server acknowledges the client's SYN by including the client's initial sequence number plus one in the ACK field, and it also includes its own initial sequence number in the SYN field.
3. ACK: The client sends a final TCP segment with the ACK flag set, acknowledging the server's SYN-ACK by including the server's initial sequence number plus one in the ACK field. At this point, the connection is established, and both the client and server can start exchanging data over the TCP connection. The three-way handshake ensures that both parties are ready to communicate and that the connection is established reliably before any data is transmitted.        

------------------------------------------------------------------------------------------------------------------------------------

16) Sequence number and ACK number : In TCP, the sequence number is a unique identifier assigned to each byte of data sent over a TCP connection. It is used to keep track of the order of bytes and ensure that data is delivered reliably. The ACK (acknowledgment) number is used by the receiving party to acknowledge the receipt of data. It indicates the next expected sequence number that the sender should send. For example, if a sender sends a segment with a sequence number of 100 and a length of 50 bytes, the receiver will acknowledge it with an ACK number of 150, indicating that it has received all bytes up to sequence number 149 and is expecting the next byte to be sequence number 150. This mechanism allows TCP to provide reliable, ordered delivery of data between applications.

------------------------------------------------------------------------------------------------------------------------------------

17) Sliding Window Protocol : The sliding window protocol is a flow control mechanism used in TCP to manage the amount of data that can be sent before receiving an acknowledgment from the receiver. It allows for efficient use of network resources and helps prevent congestion. The sender maintains a window of unacknowledged data that can be sent, and the receiver maintains a window of data that it is willing to receive. As the sender transmits data, it slides the window forward, allowing for new data to be sent while waiting for acknowledgments for previously sent data. This protocol helps to ensure that the sender does not overwhelm the receiver with too much data at once and allows for efficient utilization of the network connection.

----------------------------------------------------------------------------------------------------------------------------------

18) TCP vs UDP : TCP (Transmission Control Protocol) and UDP (User Datagram Protocol) are both transport layer protocols used for communication over the internet, but they have different characteristics and use cases.
- TCP is a connection-oriented protocol that provides reliable, ordered, and error-checked delivery of data between applications. It establishes a connection between the sender and receiver before transmitting data and ensures that all data is received correctly. TCP is suitable for applications that require reliability, such as web browsing, email, and file transfers.
- UDP is a connectionless protocol that does not provide reliability or ordering guarantees. It allows for faster transmission of data but does not ensure that all data is received or that it is received in the correct order. UDP is suitable for applications that require low latency and can tolerate some loss of data, such as streaming media, online gaming, and voice over IP (VoIP).   

-----------------------------------------------------------------------------------------------------------------------------------

19) Ports : A port is a numerical identifier used in networking to specify a particular service or application on a device. It helps to direct network traffic to the correct destination. Ports are associated with IP addresses to create a unique endpoint for communication. For example, when a client wants to connect to a web server, it typically uses port 80 for HTTP or port 443 for HTTPS. The combination of an IP address and a port number is known as a socket, which allows for communication between devices over the network. Ports are essential for enabling multiple services to run on the same device without conflicts, as each service can be assigned a different port number.

-----------------------------------------------------------------------------------------------------------------------------------

20) Socket : A socket is an endpoint for communication between two devices in a network. It is a combination of an IP address and a port number, used to establish a connection for data exchange. Sockets are used in network programming to enable communication between applications running on different devices. A socket can be created using various programming languages and libraries, such as the socket module in Python or the Socket API in C. Sockets allow applications to send and receive data over the network, enabling functionalities such as web browsing, email, and file transfers.

In our crawler example, the crawler would create a socket to connect to the web server's IP address and port number (e.g., port 80 for HTTP). The crawler would then use this socket to send an HTTP GET request to the server and receive the response containing the requested web page. The socket provides a communication channel between the crawler and the server, allowing them to exchange data over the network.
-------------------------------------------------------------------------------------------------------------------------------------

21) Ephemeral Port : An ephemeral port is a temporary, short-lived port number that is automatically assigned by the operating system to a client application when it initiates a connection to a server. Ephemeral ports are typically used for outgoing connections and are assigned from a predefined range of port numbers (usually between 1024 and 65535). When a client application creates a socket and connects to a server, the operating system assigns an ephemeral port number to the client's socket, which is used as the source port for the communication. Once the connection is closed, the ephemeral port is released and can be reused for future connections. Ephemeral ports are essential for enabling multiple client applications to establish connections with servers without conflicts, as each client can be assigned a unique ephemeral port number for its communication.

----------------------------------------------------------------------------------------------------------------------------------

22) Port Scanning : Port scanning is a technique used to identify open ports on a target device or network. It involves sending requests to a range of port numbers and analyzing the responses to determine which ports are open, closed, or filtered. Port scanning is commonly used by network administrators for security assessments and by attackers for reconnaissance purposes. Tools such as Nmap are often used for port scanning, allowing users to perform various types of scans (e.g., TCP SYN scan, UDP scan) to gather information about the target's network services and potential vulnerabilities. Port scanning can help identify potential entry points for unauthorized access or attacks on a network.

-----------------------------------------------------------------------------------------------------------------------------------

23) NAT (Network Address Translation) : NAT is a technique used in networking to allow multiple devices on a local network to share a single public IP address when accessing the internet. It works by translating the private IP addresses of devices on the local network to a single public IP address for outgoing traffic, and vice versa for incoming traffic. This allows for efficient use of limited public IP addresses and provides an additional layer of security by hiding the internal network structure from external entities. NAT is commonly used in home and small business networks, where multiple devices need to access the internet through a single connection provided by an Internet Service Provider (ISP).

Crawlers and NAT: When a crawler is behind a NAT, it can still access the internet and fetch web pages, but it may face challenges in receiving incoming connections from external servers. Since the crawler's private IP address is not directly accessible from the internet, it relies on the NAT device to manage the translation of IP addresses and ports for outgoing requests. The crawler can initiate connections to web servers and receive responses, but if the crawler needs to accept incoming connections (e.g., for callbacks or peer-to-peer communication), it may require additional configuration such as port forwarding or using techniques like UPnP (Universal Plug and Play) to allow external devices to reach the crawler through the NAT.

-----------------------------------------------------------------------------------------------------------------------------------

24) How an HTTP request travels from a crawler to a web server and back:
1. The crawler prepares an HTTP GET request (URL + headers such as User‑Agent, Accept).  
2. Domain name resolution: resolve the server hostname to an IP via DNS (if needed).  
3. Create socket and perform TCP three‑way handshake to establish a transport connection to the server IP/port (usually port 80):
    - SYN: crawler → server (initial sequence).  
    - SYN‑ACK: server → crawler (acknowledges SYN, advertises its sequence).  
    - ACK: crawler → server (acknowledges server SYN) — TCP connection established.  
    (For HTTPS, a TLS handshake occurs after TCP is established.)
4. The crawler sends the HTTP GET over the established TCP connection.  
5. The server receives and processes the request (parse headers, locate resource, generate response).  
6. The server sends the HTTP response (status line, headers, body) back over TCP; TCP segments are acknowledged and retransmitted as needed.  
7. The crawler reads and parses the response, extracts links/resources, and processes/indexes the content.  
8. Connection teardown or reuse: the crawler may close the TCP connection (TCP four‑way FIN/ACK or RST) or keep it open for further requests using HTTP keep‑alive (avoids repeating the three‑way handshake).

-------------------------------------------------------------------------------------------------------------------------------------

25) What can fail at each TCP/IP layer in web crawler : 
1. Application Layer (HTTP):
    - Malformed HTTP request (e.g., missing headers, invalid syntax/bad URL).
    - Unsupported HTTP method (e.g., using POST instead of GET).
    - Server returns an error status code (e.g., 404 Not Found, 500 Internal Server Error).

2. Transport Layer (TCP):
    - TCP connection failure (e.g., SYN timeout, no response from server).
    - Connection reset by server (e.g., RST received).
    - Packet loss leading to retransmissions and delays.
    - Congestion control reducing throughput.   
    - Handshake failure (e.g., SYN-ACK not received).
3. Network Layer (IP):
    - Routing issues (e.g., no route to host, network unreachable).
    - TTL expiration (packet discarded if it exceeds max hops).
    - IP fragmentation issues (e.g., fragments lost or not reassembled correctly).
    - Destination unreachable (e.g., ICMP error from intermediate router).
4. Data Link Layer:
    - Physical layer issues (e.g., cable unplugged, wireless interference).
    - MAC address resolution failure (e.g., ARP failure).
    - Frame errors (e.g., CRC errors, collisions on Ethernet).
5. Physical Layer:
    - Hardware failure (e.g., NIC malfunction).
    - Signal degradation (e.g., noise, attenuation).
    - Power issues (e.g., device not powered on).
Overall, a web crawler can encounter various failures at each layer of the TCP/IP stack, ranging from application-level errors to physical connectivity issues. Proper error handling and retry mechanisms are essential for building a robust crawler that can handle these potential failures gracefully.

----------------------------------------------------------------------------------------------------------------------------------------

26) How to handle failures at each TCP/IP layer in web crawler: 
1. Application Layer (HTTP):
    - Implement error handling for HTTP status codes (e.g., retry on 5xx errors, skip on 4xx errors).
    - Validate and sanitize URLs before making requests to avoid malformed requests.
    - Use timeouts for HTTP requests to prevent hanging on unresponsive servers.
2. Transport Layer (TCP):
    - Implement retry logic for connection failures (e.g., exponential backoff).
    - Handle connection resets gracefully (e.g., by re-establishing the connection).
    - Monitor for packet loss and adjust sending rate accordingly (e.g., using TCP congestion control mechanisms).
    - Use keep-alive connections to reduce the overhead of establishing new connections.
3. Network Layer (IP):
    - Implement fallback mechanisms for routing issues (e.g., try alternative routes or servers).
    - Handle TTL expiration by adjusting the TTL value or using traceroute to diagnose routing problems.
    - Implement logic to handle ICMP errors (e.g., retry with a different server if destination is unreachable).
4. Data Link Layer:
    - Monitor physical connectivity and implement reconnection logic if a link is lost (e.g., detect cable unplugged or wireless disconnection).
    - Implement ARP caching and retries to handle MAC address resolution failures.
    - Use error detection and correction mechanisms to handle frame errors (e.g., CRC checks).
5. Physical Layer:
    - Implement hardware monitoring to detect and handle NIC failures (e.g., switch to a backup NIC).
    - Use signal strength monitoring for wireless connections to detect and mitigate signal degradation.
    - Ensure proper power management to prevent issues related to device power.
Overall, handling failures at each layer of the TCP/IP stack requires a combination of error detection, retry mechanisms, and fallback strategies to ensure that the web crawler can continue functioning even in the face of various network issues. Implementing robust error handling and monitoring can help improve the reliability and resilience of the crawler in real-world network conditions.

--------------------------------------------------------------------------------------------------------------------------------------

27) Packets tracing with tcpdump and Wireshark:
- **tcpdump**: A command-line packet analyzer that allows you to capture and display network traffic. You can use tcpdump to filter packets based on various criteria (e.g., source/destination IP, port, protocol) and save the captured packets to a file for later analysis. For example, to capture HTTP traffic on port 80, you can use the command: `tcpdump -i eth0 port 80 -w capture.pcap`.
sudo tcpdump -i eth0 port 80 -w capture.pcap
sudo : packet capture requires root privileges, so we use sudo to run tcpdump with elevated permissions.
-i eth0 : specifies the network interface to capture traffic from (replace eth0 with the appropriate interface name).
port 80 : filters the captured traffic to only include packets that are sent to or received from port 80 (HTTP traffic).
-w capture.pcap : saves the captured packets to a file named capture.pcap for later analysis.

Then trigger traffic by running the crawler to fetch a page, and tcpdump will capture the relevant packets. You can then analyze the captured packets using tcpdump's command-line options or by opening the capture file in Wireshark.
curl http://example.com and stop the tcpdump (ctrl+C) after the request is complete to analyze the captured packets.


- **Wireshark**: A graphical packet analyzer that provides a user-friendly interface for capturing and analyzing network traffic. Wireshark allows you to view detailed information about each packet, including the headers and payload. You can apply filters to focus on specific traffic and use various analysis tools to understand the communication between devices. For example, you can open the capture file created by tcpdump in Wireshark to analyze the HTTP requests and responses in detail, including the sequence of packets, timing, and any errors that may have occurred during the communication.
Overall, both tcpdump and Wireshark are powerful tools for tracing packets and analyzing network traffic, allowing you to gain insights into the communication between a web crawler and a web server, as well as diagnose any issues that may arise during the process.  

---------------------------------------------------------------------------------------------------------------------------------------

28) WireShark Inspection : open the pcap in wireshark. Look for these packets : SYN, SYN-ACK, ACK (TCP handshake), HTTP GET request, HTTP response. Analyze the headers and payload of each packet to understand the communication flow between the crawler and the server. Look for any anomalies or errors in the packets that may indicate issues with the connection or data transfer. Use Wireshark's filtering capabilities to focus on specific packets of interest and gain insights into the network communication process.

HTTP Request : A packet containing an HTTP GET request will have the following characteristics:
- The packet will be part of a TCP stream, typically on port 80 (HTTP) or port 443 (HTTPS).
- The payload of the packet will contain the HTTP request line (e.g., "GET /index.html HTTP/1.1") and may include additional headers (e.g., "Host: example.com", "User-Agent: MyCrawler/1.0").
- The packet may also include a payload if the request contains data (e.g., in a POST request), but for a GET request, the payload is usually empty or minimal.
By inspecting the packet in Wireshark, you can verify that the HTTP request is correctly formed and contains the expected headers, which can help diagnose any issues with the request being sent from the crawler to the server.

HTTP Response : A packet containing an HTTP response will have the following characteristics:
- The packet will be part of the same TCP stream as the corresponding HTTP request, typically on port 80 (HTTP) or port 443 (HTTPS).
- The payload of the packet will contain the HTTP status line (e.g., "HTTP/1.1 200 OK") followed by response headers (e.g., "Content-Type: text/html", "Content-Length: 1024") and the response body (e.g., the HTML content of the requested page).
- The status line will indicate the result of the request (e.g., 200 for success, 404 for not found, 500 for server error), and the headers will provide additional information about the response.
By inspecting the packet in Wireshark, you can verify that the HTTP response is correctly formed and contains the expected status code and headers, which can help diagnose any issues with the response being received by the crawler from the server. You can also analyze the response body to ensure that the content is as expected and that there are no errors in the data being returned by the server. 

------------------------------------------------------------------------------------------------------------------------------------------

29) Sequence numbers in wireshark : In Wireshark, you can view the sequence numbers of TCP packets by expanding the TCP layer in the packet details pane. The sequence number is displayed in the "Sequence Number" field, which indicates the position of the first byte of data in the TCP segment relative to the initial sequence number established during the TCP handshake. By analyzing the sequence numbers, you can track the flow of data between the crawler and the server, identify any retransmissions or out-of-order packets, and understand how TCP manages reliable data transfer. Sequence numbers are crucial for ensuring that data is delivered in order and that any lost packets are retransmitted correctly.

-----------------------------------------------------------------------------------------------------------------------------------------

30) Mental model for crawler : Our crawler --> HTTP request --> TCP connection (three-way handshake) --> IP routing --> Network transmission --> Server receives request --> Server processes request --> Server sends HTTP response --> TCP connection (acknowledgments, retransmissions) --> Our crawler receives response --> Crawler processes response (parses HTML, extracts links) --> Crawler continues crawling based on extracted links.

--------------------------------------------------------------------------------------------------------------------------------

31) Give c++ coding and coding conceptualization for the complete process of a crawler fetching a page using TCP/IP:
Here is a simplified C++ code example that demonstrates the process of a crawler fetching a page using TCP/IP. This example uses the Boost.Asio library for network programming, which provides a convenient interface for handling TCP connections and HTTP requests.  
```cpp
#include <boost/asio.hpp>
#include <iostream> 
#include <string>
using boost::asio::ip::tcp;
void fetch_page(const std::string& host, const std::string& path) {
    try {
        boost::asio::io_context io_context;

        // Resolve the host name to an IP address
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(host, "http");

        // Create a socket and connect to the server
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // Form the HTTP GET request
        std::string request = "GET " + path + " HTTP/1.1\r\n";
        request += "Host: " + host + "\r\n";
        request += "User-Agent: MyCrawler/1.0\r\n";
        request += "Accept: */*\r\n";
        request += "Connection: close\r\n\r\n";

        // Send the HTTP request
        boost::asio::write(socket, boost::asio::buffer(request));

        // Read the response
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        // Check the response status code
        std::istream response_stream(&response);
        std::string http_version;
        unsigned int status_code;
        std::string status_message;
        response_stream >> http_version >> status_code;
        std::getline(response_stream, status_message);

        if (!response_stream || http_version.substr(0, 5) != "HTTP/") {
            std::cout << "Invalid response\n";
            return;
        }

        if (status_code != 200) {
            std::cout << "Response returned with status code " << status_code << "\n";
            return;
        }

        // Read the response headers
        boost::asio::read_until(socket, response, "\r\n\r\n");
        
        // Process the response body (for simplicity, we just print it)
        std::string body((std::istreambuf_iterator<char>(&response)), std::istreambuf_iterator<char>());
        std::cout << body << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}
int main() {
    std::string host = "example.com";
    std::string path = "/index.html";
    fetch_page(host, path);
    return 0;
}

In the code, `host` refers to the domain name of the web server that the crawler is trying to access (e.g., "example.com"), while `path` refers to the specific resource on the server that the crawler wants to fetch (e.g., "/index.html"). The `host` is used in the HTTP request to specify the target server, and the `path` is used to specify the particular page or resource that the crawler is requesting from the server. Together, they form the URL that the crawler is trying to access (e.g., "http://example.com/index.html").

explain fetch_page function line by line:
1. `void fetch_page(const std::string& host, const std::string& path) {` - This line defines a function named `fetch_page` that takes two parameters: `host` (the domain name of the web server) and `path` (the specific resource on the server). The function is responsible for fetching the specified page from the server.
2. `try {` - This line starts a try block to catch any exceptions that may occur during the execution of the function.
3. `boost::asio::io_context io_context;` - This line creates an `io_context` object, which is required for using Boost.Asio's asynchronous operations. It provides the core I/O functionality needed for network communication.
4. `tcp::resolver resolver(io_context);` - This line creates a `resolver` object that will be used to resolve the host name to an IP address. It takes the `io_context` as a parameter to manage asynchronous operations.
5. `auto endpoints = resolver.resolve(host, "http");` - This line resolves the specified `host` and service ("http") to a list of endpoints (IP addresses and port numbers) that can be used to connect to the server.
6. `tcp::socket socket(io_context);` - This line creates a `socket` object that will be used to establish a connection to the server. It takes the `io_context` as a parameter to manage asynchronous operations.   
7. `boost::asio::connect(socket, endpoints);` - This line attempts to connect the socket to one of the resolved endpoints. It will try each endpoint until a successful connection is established.
endpoints not there in code ?? The `endpoints` variable is defined in line 5 as the result of the `resolver.resolve(host, "http")` call. It contains a list of resolved endpoints (IP addresses and port numbers) for the specified host and service. The `boost::asio::connect(socket, endpoints)` function uses this list of endpoints to attempt to establish a connection to the server. If the connection is successful, the socket will be connected to one of the endpoints from the list. If there are multiple endpoints, it will try each one until it successfully connects or exhausts the list.    
8. `std::string request = "GET " + path + " HTTP/1. 1\r\n";` - This line constructs the HTTP GET request line by concatenating the "GET" method, the specified `path`, and the HTTP version ("HTTP/1.1"). It also adds a carriage return and line feed (`\r\n`) at the end of the request line to indicate the end of the line in the HTTP protocol.
9. `request += "Host: " + host + "\r\n";` - This line adds the "Host" header to the HTTP request, specifying the target server's domain name. It also adds a carriage return and line feed at the end of the header line.
what is carriage return and line feed? In the context of HTTP requests, a carriage return (`\r`) and line feed (`\n`) are used to indicate the end of a line. The combination of `\r\n` is commonly used in HTTP to separate lines in the request and response messages. The carriage return moves the cursor back to the beginning of the line, while the line feed moves the cursor down to the next line. This is important for properly formatting HTTP messages, as it allows the server to correctly parse the headers and body of the request or response.
10. `request += "User-Agent: MyCrawler/1.0\r\n";` - This line adds the "User-Agent" header to the HTTP request, identifying the crawler software making the request. It also adds a carriage return and line feed at the end of the header line.
11. `request += "Accept: */*\r\n";` - This line adds the "Accept" header to the HTTP request, indicating that the crawler can accept any type of content in the response. It also adds a carriage return and line feed at the end of the header line.
12. `request += "Connection: close\r\n\r\n";` - This line adds the "Connection" header to the HTTP request, indicating that the crawler wants to close the connection after receiving the response. It also adds two carriage return and line feed sequences (`\r\n\r\n`) to indicate the end of the headers and the start of the body in the HTTP protocol.
13. `boost::asio::write(socket, boost::asio::buffer(request));` - This line sends the constructed HTTP request to the server using the socket. The `boost::asio::write` function writes the entire request buffer to the socket, ensuring that the request is transmitted to the server.    
14. `boost::asio::streambuf response;` - This line creates a `streambuf` object to hold the incoming response from the server. It will be used to read the response data from the socket.
15. `boost::asio::read_until(socket, response, "\r\n");` - This line reads data from the socket into the `response` buffer until it encounters a carriage return and line feed sequence (`\r\n`), which indicates the end of the HTTP status line. This allows the crawler to read the status line of the HTTP response, which contains the HTTP version, status code, and status message.
16. `std::istream response_stream(&response);` - This line creates an input stream (`response_stream`) that is associated with the `response` buffer. This allows the crawler to read the response data using standard stream operations.
17. `std::string http_version;` - This line declares a string variable to hold the HTTP version extracted from the response status line.
18. `unsigned int status_code;` - This line declares an unsigned integer variable to hold the HTTP status code extracted from the response status line.
19. `std::string status_message;` - This line declares a string variable to hold the HTTP status message extracted from the response status line.
20. `response_stream >> http_version >> status_code;` - This line reads the HTTP version and status code from the response stream. It uses the stream extraction operator (`>>`) to parse the status line of the HTTP response and store the values in the respective variables.
21. `std::getline(response_stream, status_message);` - This line reads the remaining part of the status line (the status message) from the response stream using `std::getline`, which reads until the  end of the line. The status message is stored in the `status_message` variable. 
22. `if (!response_stream || http_version.substr(0, 5) != "HTTP/") {` - This line checks if the response stream is in a valid state and if the HTTP version starts with "HTTP/". If either condition is false, it indicates that the response is invalid.
23. `std::cout << "Invalid response\n";` - If the response is invalid, this line prints an error message to the console.
24. `return;` - This line exits the function early if the response is invalid, preventing further processing of the response data.
25. `if (status_code != 200) {` - This line checks if the HTTP status code is not equal to 200 (which indicates a successful response). If the status code is not 200, it indicates that there was an error with the request.
26. `std::cout << "Response returned with status code " << status_code << "\n";` - If the status code is not 200, this line prints an error message to the console, including the actual status code returned by the server.
27. `return;` - This line exits the function early if   the status code indicates an error, preventing further processing of the response data.
28. `boost::asio::read_until(socket, response, "\r\n\r\n");` - This line reads data from the socket into the `response` buffer until it encounters a double carriage return and line feed sequence (`\r\n\r\n`), which indicates the end of the HTTP headers and the start of the body. This allows the crawler to read the headers of the HTTP response before processing the body.
29. `std::string body((std::istreambuf_iterator<char>(&response)), std::istreambuf_iterator<char>());` - This line reads the remaining data from the `response` buffer (which contains the body of the HTTP response) into a string variable named `body`. It uses an input stream iterator to read all characters from the buffer until the end of the stream.
30. `std::cout << body << std::endl;` - This line prints the body of the HTTP response to the console. In a real crawler, you would typically parse the body to extract links and other relevant information rather than just printing it.
31. `} catch (std::exception& e) {` - This line starts a catch block to handle any exceptions that may have been thrown during the execution of the function. If an exception occurs, it will be caught and handled in this block.
32. `std::cerr << "Exception: " << e.what() << "\n";` - If an exception is caught, this line prints the exception message to the standard error stream, providing information about what went wrong during the execution of the function.
33. `}` - This line closes the catch block.
34. `int main() {` - This line defines the main function, which is the entry point of the program.
35. `std::string host = "example.com";` - This line declares a string variable named `host` and initializes it with the value "example.com", which is the domain name of the web server that    the crawler will attempt to fetch a page from.
36. `std::string path = "/index.html";` - This line declares a string variable named `path` and initializes it with the value "/index.html", which is the specific resource on the server that the crawler will attempt to fetch.
37. `fetch_page(host, path);` - This line calls the `fetch_page` function, passing the `host` and `path` variables as arguments. This initiates the process of fetching the specified page from the server.
38. `return 0;` - This line returns 0 from the main function, indicating that the program has completed successfully.
39. `}` - This line closes the main function.   