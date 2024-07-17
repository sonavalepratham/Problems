#include "SocketWrapper.h"

// Static field initialization

int SocketWrapper::numSockets = 0;

// Constructor
SocketWrapper::SocketWrapper() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket" << std::endl;
    }
    numSockets++;
    std::memset(&serverAddr, 0, sizeof(serverAddr));
}

SocketWrapper::SocketWrapper(SocketWrapper&& in){
    this->sockfd = in.sockfd;
    this->serverAddr = in.serverAddr;
    in.sockfd = -1;
    numSockets++;
}

// Destructor
SocketWrapper::~SocketWrapper() {
    numSockets--;
    cleanup();
}

// Check if socket is valid
bool SocketWrapper::isValid() const {
    return sockfd >= 0;
}

// Cleanup resources
void SocketWrapper::cleanup() {
    if (isValid()) {
        close(sockfd);
    }
}

// Synchronous connect
bool SocketWrapper::connect(const std::string& address, int port) {
    if (!isValid()) return false;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    if (inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return false;
    }

    if (::connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return false;
    }

    return true;
}

// Synchronous bind
bool SocketWrapper::bind(int port) {
    if (!isValid()) return false;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (::bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind Failed" << std::endl;
        return false;
    }

    return true;
}

// Synchronous listen
bool SocketWrapper::listen(int backlog) {
    if (!isValid()) return false;

    if (::listen(sockfd, backlog) < 0) {
        std::cerr << "Listen Failed" << std::endl;
        return false;
    }

    return true;
}

// Synchronous accept
SocketWrapper SocketWrapper::accept() {
    SocketWrapper clientSocket;
    socklen_t addrLen = sizeof(clientSocket.serverAddr);
    clientSocket.sockfd = ::accept(sockfd, (struct sockaddr*)&clientSocket.serverAddr, &addrLen);
    if (clientSocket.sockfd < 0) {
        std::cerr << "Accept Failed" << std::endl;
    }
    return clientSocket;
}

// Synchronous send
bool SocketWrapper::send(const std::string& data) {
    if (!isValid()) return false;

    if (::send(sockfd, data.c_str(), data.size(), 0) < 0) {
        std::cerr << "Send Failed" << std::endl;
        return false;
    }

    return true;
}

// Synchronous receive
std::string SocketWrapper::receive() {
    if (!isValid()) return "";

    char buffer[1024] = {0};
    int received = ::recv(sockfd, buffer, sizeof(buffer), 0);
    if (received < 0) {
        std::cerr << "Receive Failed" << std::endl;
        return "";
    }

    return std::string(buffer, received);
}

// Asynchronous connect
std::future<bool> SocketWrapper::connectAsync(const std::string& address, int port) {
    return std::async(std::launch::async, &SocketWrapper::connect, this, address, port);
}

// Asynchronous send
std::future<bool> SocketWrapper::sendAsync(const std::string& data) {
    return std::async(std::launch::async, &SocketWrapper::send, this, data);
}

// Asynchronous receive
std::future<std::string> SocketWrapper::receiveAsync() {
    return std::async(std::launch::async, &SocketWrapper::receive, this);
}
