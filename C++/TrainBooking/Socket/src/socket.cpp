#include"../include/socket.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

PSsocket::PSsocket(std::string ip, int port) : port(port), ip(ip){
    _socket = socket(AF_INET, SOCK_STREAM, 0);
}

int PSsocket::connect(){
    struct sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(port);
    sockAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    int res = ::connect(_socket, (struct sockaddr*)&sockAddr, sizeof(sockAddr));
    if(res<0) std::cout<<"Connection failed\n";
    return res;
}

int PSsocket::close(){
    return ::close(_socket);
}

std::string PSsocket::recv(){
    char buffer[1024] = {0};
    int bytesRead;
    int res = ::recv(_socket, buffer, 1024, 0);
    if(res==0) std::cout<<"Disconnected\n";
    else if(res<0) std::cout<<"Error, socket disconnected\n";
    return buffer;
}

ssize_t PSsocket::send(std::string msg){
    return ::send(_socket, msg.c_str(), msg.size()+1, 0);
}

int PSsocket::bind(){
    struct sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(port);
    sockAddr.sin_addr.s_addr = INADDR_ANY;
    return ::bind(_socket, (struct sockaddr*)&sockAddr, sizeof(sockAddr));
}

std::string PSsocket::getIp(){
    return ip;
}

int PSsocket::getPort(){
    return port;
}

int PSsocket::getSocket(){
    return _socket;
}
