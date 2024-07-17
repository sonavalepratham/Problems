#include "SocketWrapper.h"
#include <iostream>

int main() {
    SocketWrapper serverSocket;

    if (serverSocket.bind(8080)) {
        std::cout << "Server is listening on port 8080..." << std::endl;
        if (serverSocket.listen()) {
            SocketWrapper clientSocket = serverSocket.accept();
            if (clientSocket.isValid()) {
                std::cout << "Client connected!" << std::endl;
                std::string message = clientSocket.receive();
                std::cout << "Received from client: " << message << std::endl;
                clientSocket.send("Hello, Client!");
            } else {
                std::cerr << "Failed to accept client connection" << std::endl;
            }
        } else {
            std::cerr << "Failed to listen" << std::endl;
        }
    } else {
        std::cerr << "Failed to bind to port 8080" << std::endl;
    }

    return 0;
}
