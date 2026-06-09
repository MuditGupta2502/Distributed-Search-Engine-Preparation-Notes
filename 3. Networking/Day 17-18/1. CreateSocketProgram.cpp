/* Can C++ ask the OS to create a socket? If yes → we move forward. If no → nothing else works.
PART 1 — First Understand What a Socket Is --> Think like this: File Example
When you open a file: int fd = open("data.txt", ...);
OS gives you: fd = 3
This means: “Here is handle number 3 for that file.”
You use:read() write() close() on that handle.
Socket Example : When you create a socket:
int sockfd = socket(...);
OS gives: sockfd = 4
This means: “Here is handle number 4 for network communication.”
You use: send() recv() close() on that handle.
VERY IMPORTANT : Socket = File Descriptor. This is why blueprint says: Everything is a file descriptor
because: files ; sockets ; pipes ; terminals all are represented by integers.
Example: 0 → stdin 1 → stdout 2 → stderr 3 → file 4 → socket
This is UNIX philosophy.

socket(domain, type, protocol)
AF_INET     → IPv4 
SOCK_STREAM → TCP
0           → default protocol for TCP

If socket creation fails, socket() returns -1.

Header 1
#include <sys/socket.h>
Contains: socket() bind() listen() accept() connect() send() recv()

#include <netinet/in.h> Contains: sockaddr_in AF_INET  htons()
Used for IPv4 addressing.

#include <unistd.h> Contains: close() . Used to close socket.

AF_INET means: Address Family = IPv4
Examples: IPv4 ; 142.250.183.206
IPv6 : 2404:6800:4009:80b::200e
If we wanted IPv6: AF_INET6
For now: we use IPv4.

Argument 2 : SOCK_STREAM means: TCP Reliable connection. Ordered delivery.
Examples: websites login systems banking file transfer
If we wanted UDP: SOCK_DGRAM
For crawler:we need TCP. because HTTP uses TCP.

Argument 3 : 0
means: default protocol, OS automatically chooses: TCP protocol. Usually always 0.

Dear OS, please give me a TCP phone connection using IPv4. OS replies: Here is phone number 3. Socket created successfully
Socket FD = 3 or maybe 4, 5, etc. That number changes.
*/

#include<iostream>
#include<sys/socket.h>   // socket()
#include<netinet/in.h>   // sockaddr_in
#include<unistd.h>      // close()
using namespace std;

int main(){
    
    int sockfd = socket(AF_INET,SOCK_STREAM,0);

    /*
    If socket creation fails,
    socket() returns -1
    */

    if(sockfd==-1){
        cout<<"Socket creation has failed\n";
        return 1;
    }

    else{
        cout<<"Socket created successfully\n";
        cout<<"SOCKET FD = "<<sockfd<<"\n";
    }

    // Always close file descriptors
    close(sockfd);

    return 0;
}