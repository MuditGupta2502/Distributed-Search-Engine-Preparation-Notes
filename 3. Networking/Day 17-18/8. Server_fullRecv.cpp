#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>
#include<string>
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

bool recv_all(int client_fd, string &out){
    out.clear();
    const size_t BUF_SIZE = 4096;
    char buffer[BUF_SIZE];

    while(true){
        ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
        if(bytes_received < 0){
            return false;
        }
        if(bytes_received == 0){
            // peer closed connection
            break;
        }
        out.append(buffer, bytes_received);
        // If we read less than the buffer, assume there's no more data right now.
        if (static_cast<size_t>(bytes_received) < sizeof(buffer)) {
            break;
        }
    }
    return true;
}


int main(){
    int server_fd = socket(AF_INET,SOCK_STREAM,0);

    if(server_fd==-1){
        cout<<"Socket creation has failed\n";
        return 1;
    }
    else{
        cout<<"Socket created successfully\n";
    }

    // prepare server address
    sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    int bind_result = bind(server_fd,(sockaddr*)&server_address,sizeof(server_address));

    if(bind_result==-1){
        cout<<"Bind has failed\n";
        close(server_fd);
        return 1;
    }

    else{
        cout<<"Bind has been done successfully\n";
    }

    // Step 3 : listen
    int listen_result = listen(server_fd,10);

    if(listen_result == -1){
        cout<<"Listen failed\n";
        close(server_fd);
        return 1;
    }

    else{
        cout<<"Server is listening on port 8080\n";
    }

    // Step 5:  accept one client

    int client_fd = accept(server_fd,nullptr,nullptr);

    if(client_fd==-1){
        cout<<"Accept failed\n";
        close(server_fd);
        return 1;
    }

    else{
        cout<<"Client connected\n";
        cout<<"Client FD = "<<client_fd<<"\n";
    }

    string full_message;
    if(!recv_all(client_fd, full_message)){
        cout<<"Receive failed\n";
    } else {
        cout<<"Message received from client\n";
        cout<<full_message<<"\n";
        if(!send_all(client_fd, full_message.c_str(), full_message.size())){
            cout<<"Send failed\n";
        } else {
            cout<<"Echoed message back to client\n";
        }
    }

    close(client_fd);
    close(server_fd);

    return 0;
}