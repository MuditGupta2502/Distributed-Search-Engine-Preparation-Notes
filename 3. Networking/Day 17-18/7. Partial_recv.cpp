#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<cstring>
using namespace std;

bool send_all(int client_fd, const char* message, size_t length){
    size_t total_sent = 0;

    while(total_sent<length){
        ssize_t bytes_sent = send(client_fd,message+total_sent,length-total_sent,0);

    if(bytes_sent<=0){
        return false;
    }

    total_sent += bytes_sent;
   }

   return true;
}

bool recv_all(int client_fd){
    char buffer[4096];

    string full_response = "";

    while(true){
        ssize_t bytes_received = recv(client_fd,buffer,sizeof(buffer),0);

        if(bytes_received<0){
            return false;
        }

        if(bytes_received==0){
            break;
        }
        full_response.append(buffer,bytes_received);
    }
    cout<<"Message received from server successfully\n";
    cout<<full_response<<"\n";
    return true;
}

int main(){
    int client_fd = socket(AF_INET,SOCK_STREAM,0);

    if(client_fd==-1){
        cout<<"Socket creation failed\n";
        return 1;
    }

    else{
        cout<<"Client Socket created successfully\n";
    }

    // Step 2: connect() --> establish connection to server.
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    inet_pton(AF_INET,"10.42.0.1",&server_address.sin_addr);

    int connect_fd = connect(client_fd,(sockaddr*)&server_address,sizeof(server_address));

    if(connect_fd==-1){
        cout<<"Connection failed\n";
        close(client_fd);
        return 1;
    }

    else{
        cout<<"Connected to server\n";
    }

    const char* message = "Hi I am Mudit! Your project partner.";

    if(send_all(client_fd,message,strlen(message))==false){
        close(client_fd);
        return 1;
    }

    else{
        cout<<"Message sent\n";
    }

    if(recv_all(client_fd)==false){
        close(client_fd);
        return 1;
    }

    close(client_fd);
    return 0;
}