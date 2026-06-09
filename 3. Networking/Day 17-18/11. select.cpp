/* 1. F_GETFL means: get current flags. Maybe: readable ; writable ; append mode etc. flags | O_NONBLOCK means: keep old flags ; plus add 
non-blocking. F_SETFL means: apply new flags Done. Now socket is non-blocking.

2. EINPROGRESS means: TCP handshake started but not finished yet. This is GOOD. Not failure. This is expected.

3. Wait using select() : Now we ask OS: tell me when connect finishes. That is: select(). 
fd_set This is: set of sockets We tell OS: watch this socket.
“Create an empty set of file descriptors.” Without FD_ZERO, writefds may contain garbage values from memory, and select() may behave 
incorrectly.
FD_SET(fd, &writefds) : adds your socket into that empty set.
fd_set is an OS-defined type used to represent a set of file descriptors. On Linux/Unix it is typically implemented like a bitmask or 
fixed-size structure internally. fd_set → a collection of socket numbers.
Now writefds means: watch socket 5 and socket 9. You do not manipulate fd_set directly like an integer. You use the macros:
FD_ZERO ; FD_SET ; FD_CLR ; FD_ISSET.

int result = select(
    fd + 1,
    nullptr,
    &writefds,
    nullptr,
    &tv
);

means:

fd + 1 = highest file descriptor number to check, plus 1
first nullptr = do not watch for readability
&writefds = watch this socket for writability
second nullptr = do not watch for exceptional conditions
&tv = wait at most this long

Why does non-blocking connect use writefds and not readfds?
Answer: Because connect() is waiting for TCP handshake completion, not incoming data. A socket becomes writable when the connection is 
established and it is ready to send data. Readable indicates incoming data is available, which is not what we are waiting for during 
connect(). That is the strong answer.

so_error :  This block checks the kernel’s final verdict after a non-blocking connect(); select() tells you the socket is ready to be 
checked, and  getsockopt(... SO_ERROR ...) tells you whether the connection actually succeeded.

Why does getsockopt need socklen_t len?
Strong answer: Because the kernel writes data into user-provided memory.It must know how much space is available to avoid buffer overflow.
The length is also passed by pointer because the kernel may update it to tell how many bytes were actually written.

Is errno returned by result? Strong answer: No. The function returns success/failure through its return value, while errno is a separate 
global variable set by the OS to explain the reason for failure. Return value says WHAT happened. errno says WHY it happened.
*/

#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<cerrno>
#include<netinet/in.h>
#include<arpa/inet.h>
using namespace std;

int main(){
    int fd = socket(AF_INET,SOCK_STREAM,0);

    if(fd==-1){
        cout<<"Socket creation failed\n";
        return 1;
    }

    else {
        cout<<"Socket created successfully\n";
    }

    // 1. Make the socket as non blocking.
    int flags = fcntl(fd,F_GETFL,0);

    if(flags==-1){
        cout<<"F_GETFL failed\n";
        close(fd);
        return 1;
    }
    
    if(fcntl(fd,F_SETFL, flags | O_NONBLOCK)==-1){
        cout<<"FSET_FL failed\n";
        close(fd);
        return 1;
    }

    else{
        cout<<"Socket is now non blocking\n";
    }

    // 2. Prepare server address

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    inet_pton(AF_INET,"127.0.0.1",&server_address);

    // 3. Start connect

    int connect_fd = connect(fd,(sockaddr*)&server_address,sizeof(server_address));

    if(connect_fd==0){
        cout<<"Connect immediately\n";
    }
    else if(errno != EINPROGRESS){
        cout<<"Immediate connect failure\n";
        close(fd);
        return 1;
    }
    else{
        cout<<"Connection in progress.........\n";
    
        //4. Wait using select()
        fd_set writefds;
        FD_ZERO(&writefds);
        FD_SET(fd,&writefds);

        timeval tv;
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        connect_fd = select(fd+1,nullptr,&writefds,nullptr,&tv);

        if(connect_fd==0){
            cout<<"Coonection timeout\n";
            close(fd);
            return 1;
        }
        else if(connect_fd<0){
            cout<<"Connection failed\n";
            close(fd);
            return 1;
        }
        
        // 5. Verify 

        int so_error = 0;
        socklen_t length = sizeof(so_error);

        getsockopt(fd,SOL_SOCKET,SO_ERROR,&so_error,&length);

        if(so_error==0){
            cout<<"Connection successful\n";
        }
        else{
            cout<<"Connection failed\n";
            close(fd);
            return 1;
        }
    }

    close(fd);
    return 0;
}