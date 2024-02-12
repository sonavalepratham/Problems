#include "server.h"
#include "ClientHandler.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

Server::Server(int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
}

void Server::start() {
    std::thread acceptThread(&Server::acceptClients, this);

    {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [this](){ return stopServer; });
    }

    acceptThread.join();
}

void Server::stop() {
    stopServer = true;
    cv.notify_all();
}

void Server::acceptClients() {
    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSocketDescriptor = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);

        if (clientSocketDescriptor == -1) {
            std::cerr << "Error accepting connection." << std::endl;
            continue;
        }

        {
            std::lock_guard<std::mutex> lock(mutex);
            clientThreads.emplace_back(&ClientHandler::handle, ClientHandler(clientSocketDescriptor));
            std::cout<<clientThreads.size()<<"\n";
        }
        cv.notify_one();
    }
}
