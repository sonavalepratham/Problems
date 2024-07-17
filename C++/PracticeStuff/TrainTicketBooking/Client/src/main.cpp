#include "SocketWrapper.h"
#include <iostream>

int main() {
    SocketWrapper socketWrapper;

    // Synchronous usage
    if (socketWrapper.connect("127.0.0.1", 8080)) {
        std::cout << "Connected to server!" << std::endl;
        socketWrapper.send("Hello, Server!");
        std::string response = socketWrapper.receive();
        std::cout << "Received from server: " << response << std::endl;
        std::cout << socketWrapper.getCnt()<<"\n";
    } else {
        std::cerr << "Failed to connect to server" << std::endl;
    }

    return 0;
}
