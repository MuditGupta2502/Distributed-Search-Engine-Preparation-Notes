#include <iostream>
#include <string>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

bool send_all(int fd, const char* data, size_t length)
{
    size_t total_sent = 0;
    while (total_sent < length)
    {
        ssize_t sent = send(fd, data + total_sent, length - total_sent, 0);
        if (sent <= 0) return false;
        total_sent += static_cast<size_t>(sent);
    }
    return true;
}

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        cout << "Socket creation failed\n";
        return 1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) == -1)
    {
        cout << "Bind failed\n";
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 10) == -1)
    {
        cout << "Listen failed\n";
        close(server_fd);
        return 1;
    }

    cout << "HTTP server listening on port 8080...\n";

    int client_fd = accept(server_fd, nullptr, nullptr);
    if (client_fd == -1)
    {
        cout << "Accept failed\n";
        close(server_fd);
        return 1;
    }

    char buffer[8192];
    ssize_t n = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (n > 0)
    {
        buffer[n] = '\0';
        cout << "Received request:\n";
        cout << buffer << "\n";
    }

    string body = "Hello from raw C++ HTTP server!";
    string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: " + to_string(body.size()) + "\r\n"
        "Connection: close\r\n"
        "\r\n" +
        body;

    send_all(client_fd, response.c_str(), response.size());

    close(client_fd);
    close(server_fd);
    return 0;
}