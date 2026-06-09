#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<cstring>
using namespace std;

int main(){
    // create client socket
    int client_fd = socket(AF_INET,SOCK_STREAM,0);

    if(client_fd==-1){
        cout<<"Client socket creation failed\n";
        return 1;
    }

    cout<<"Client Socket created successfully\n";

    // prepare server address
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    

    // Shubham Dewangan laptop's IP
    inet_pton(AF_INET,"10.42.0.1",&server_address.sin_addr);

    int result = connect(client_fd,(sockaddr*)&server_address,sizeof(server_address));

    if(result==-1){
        cout<<"Connection failed\n";
        close(client_fd);
        return 1;
    }

    else{
        cout<<"Connected to server\n";
    }

    // send message
    const char* message = "hello";
    send(client_fd,message,strlen(message),0);

    cout<<"Message sent\n";

    char buffer[4096];

    ssize_t bytes_received = recv(
        client_fd,
        buffer,
        sizeof(buffer) - 1,
        0
    );

    if (bytes_received == -1)
    {
        cout << "Receive failed\n";
    }
    else
    {
        buffer[bytes_received] = '\0';

        cout << "Server replied: "
             << buffer << "\n";
    }

    close(client_fd);

    return 0;
}