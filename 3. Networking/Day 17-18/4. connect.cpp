#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;

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

    //  accept one client

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

    close(client_fd);
    close(server_fd);

    return 0;
}