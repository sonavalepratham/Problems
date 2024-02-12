#include <string>

#ifndef CLIENT_H
#define CLIENT_H

class Client{
private:
    int port;
    std::string ip;
    int clientSocket;
public:
    Client(std::string _ip, int _port);
    void Send(std::string data);
    void StartRxTx();
};

#endif