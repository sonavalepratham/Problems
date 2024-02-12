#include"client.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include <string>
#include <iostream>

Client::Client(std::string _ip, int _port) : ip(_ip), port(_port){
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9111);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.1.1");

    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

void Client::Send(std::string data){
    send(clientSocket, data.c_str(), data.length(), 0);
}

void Client::StartRxTx(){
    std::string input;
    std::cin>>input;
    while(input!="#"){
        Send(input);
        std::cin>>input;
    }
}