/*Subproblem: socket() + bind() Right now we can only create a socket. That is like buying a phone.
But no one can call us yet. Why? Because we have not assigned a phone number. That is what bind() does.

After bind() : bind(...) means: Attach this phone to number 8080
Now clients can call: 127.0.0.1:8080
Very important difference: socket() → create phone ; bind() → assign address + port.

What is IP + Port? A machine is identified by: IP address + Port number
Example: 192.168.1.10:8080 or 127.0.0.1:8080
IP Address Tells: Which machine?
Example: 127.0.0.1 means: localhost = this same machine
Port Number Tells: Which program on that machine?
Example: 80   → HTTP    443  → HTTPS     5432 → PostgreSQL    6379 → Redis   8080 → our test server
Same machine can run many servers. Ports separate them.

Create socket + bind it to port 8080
*/

#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;

int main(){
    // create a socket
    int server_fd = socket(AF_INET,SOCK_STREAM,0);

    if(server_fd==-1){
        cout<<"Socket creation has failed\n";
        return 1;
    }

    else{
        cout<<"Socket created successfully\n";
    }

    // create address structure
    sockaddr_in server_address;

    //always initialize zero first
    server_address.sin_family = AF_INET;

    server_address.sin_addr.s_addr = INADDR_ANY;

    // Port must be converted to network byte order using htons()
    server_address.sin_port = htons(8080);

    // Bind socket to ip + port
    int bind_result = bind(server_fd,(sockaddr*)&server_address,sizeof(server_address));

    if(bind_result == -1){
        cout<<"Bind failed\n";
        close(server_fd);
        return 1;
    }

    else{
        cout<<"Bind successful. Server is attached to port 8080\n";
    }

    close(server_fd);
    return 0;
}