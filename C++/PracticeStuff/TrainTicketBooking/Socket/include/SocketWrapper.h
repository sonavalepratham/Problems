#ifndef SOCKETWRAPPER_H
#define SOCKETWRAPPER_H

#include <string>
#include <future>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketWrapper {
public:
    SocketWrapper();
    SocketWrapper(const SocketWrapper& socketWrapper) = delete; // don't want copy to be created.
    SocketWrapper(SocketWrapper&& socketWrapper); // move constructor
    ~SocketWrapper();
    bool isValid() const;

    // Synchronous methods
    bool connect(const std::string& address, int port);
    bool bind(int port);
    bool listen(int backlog = 5);
    SocketWrapper accept();
    bool send(const std::string& data);
    std::string receive();
    static int getCnt() {return numSockets; }

    // Asynchronous methods
    std::future<bool> connectAsync(const std::string& address, int port);
    std::future<bool> sendAsync(const std::string& data);
    std::future<std::string> receiveAsync();

private:
    int sockfd;
    struct sockaddr_in serverAddr;
    // Static fields
    static int numSockets;
    void cleanup();
};

#endif // SOCKETWRAPPER_H
