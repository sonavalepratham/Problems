#include "ClientHandler.h"
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

ClientHandler::ClientHandler(int socket) : clientSocket(socket) {}

void ClientHandler::handle() {
    char buffer[1024] = {0};
    int bytesRead;

    while ((bytesRead = recv(clientSocket, buffer, 1024, 0)) > 0) {
        std::cout << "Received from client: " << buffer << std::endl;

        send(clientSocket, "Hello from server!", 18, 0);

        // Clear buffer for the next iteration
        memset(buffer, 0, sizeof(buffer));
    }

    if (bytesRead == 0) {
        std::cout << "Client disconnected." << std::endl;
    } else {
        std::cerr << "Error receiving data from client." << std::endl;
    }

    close(clientSocket);
}
