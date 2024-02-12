#include "ClientHandler.h"
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

ClientHandler::ClientHandler(int socket) : clientSocket(socket) {}

void ClientHandler::handle() {
    char buffer[1024] = {0};
    recv(clientSocket, buffer, 1024, 0);
    std::cout << "Received from client: " << buffer << std::endl;

    send(clientSocket, "Hello from server!", 18, 0);

    close(clientSocket);
}
