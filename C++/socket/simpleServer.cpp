#include<iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<cstring>

int portNum = 1500;

int main(){
        int serverFd = socket(AF_INET, SOCK_STREAM, 0);
        if(serverFd<=0)
        {
                std::cerr << "ERROR while creating socket fd\n";
                exit(1);
        }

        struct sockaddr_in server_addr;

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(portNum);

        if(bind(serverFd, (struct sockaddr*)&server_addr, sizeof(server_addr))<0){
                std::cerr << "ERROR while binding socket fd\n";
                exit(1);
        }
        if (listen(serverFd, 3) < 0) { perror("listen"); exit(EXIT_FAILURE); }

        auto addrlen = sizeof(server_addr);
        // Accepting a connection
        int new_socket;
        if ((new_socket = accept(serverFd, (struct sockaddr*)&server_addr, (socklen_t*)&addrlen)) < -1)
        {
                perror("accept");
                exit(EXIT_FAILURE);
        }
        // Reading and sending data
        char buffer[1024] = {0};
        read(new_socket, buffer, 1024);
        std::cout << "Message from client: " << buffer << std::endl;
        char* hello = "Hello from server...";
        send(new_socket, hello, strlen(hello), 0);
        std::cout << "Hello message sent\n";

        close(new_socket);
        close(serverFd);
}
