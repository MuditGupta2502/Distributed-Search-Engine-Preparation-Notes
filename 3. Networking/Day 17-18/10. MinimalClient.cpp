#include <iostream>
#include <string>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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

string recv_all_until_close(int fd)
{
    string result;
    char buffer[4096];

    while (true)
    {
        ssize_t n = recv(fd, buffer, sizeof(buffer), 0);

        if (n == 0)
        {
            break; // server closed connection
        }

        if (n < 0)
        {
            cerr << "recv failed\n";
            break;
        }

        result.append(buffer, static_cast<size_t>(n));
    }

    return result;
}

int main()
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        cout << "Socket creation failed\n";
        return 1;
    }

    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) != 1)
    {
        cout << "Invalid server IP\n";
        close(client_fd);
        return 1;
    }

    if (connect(client_fd, (sockaddr*)&server, sizeof(server)) == -1)
    {
        cout << "Connect failed\n";
        close(client_fd);
        return 1;
    }

    string request =
        "GET / HTTP/1.1\r\n"
        "Host: localhost\r\n"
        "User-Agent: IndiaBot/1.0\r\n"
        "Connection: close\r\n"
        "\r\n";

    if (!send_all(client_fd, request.c_str(), request.size()))
    {
        cout << "send failed\n";
        close(client_fd);
        return 1;
    }

    cout << "Request sent successfully.\n";

    string response = recv_all_until_close(client_fd);

    cout << "Full response:\n";
    cout << response << "\n";

    close(client_fd);
    return 0;
}