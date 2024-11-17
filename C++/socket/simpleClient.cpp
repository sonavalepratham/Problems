#include<iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<cstring>

int portNum = 1500;

int main(){
        int sock = 0;
        struct sockaddr_in serv_addr;
        char buffer[1024] = {0};
        const char* hello = "Hello from client";
        // Creating socket file descriptor
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                std::cerr << "Socket creation error\n";
                return -1;
        }
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(portNum);
        // Converting IP addresses from text to binary form
        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        {
                std::cerr << "Invalid address/ Address not supported\n";
                return -1;
        }
        // Connecting to the server
        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        {
                std::cerr << "Connection Failed\n";
                return -1;
        } // Sending and reading data
        send(sock, hello, strlen(hello), 0);
        std::cout << "Hello message sent\n";
        read(sock, buffer, 1024);
        std::cout << "Message from server: " << buffer << std::endl;
        // Closing the socket
        close(sock);
}
