#include <string>

#ifndef SOCKET_H
#define SOCKET_H

class PSsocket{
    private:
        int _socket;
        int port;
        std::string ip;
    public:
        PSsocket(std::string ip, int port=0);
        int getSocket();
        int getPort();
        std::string getIp();
        int bind();
        ssize_t send(std::string msg);
        std::string recv();
        int close();
        int connect();
};

#endif SOCKET_H