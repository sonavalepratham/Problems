#include<iostream>
#include "ProjectInfo.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include <unistd.h>
using namespace std;

int main(){
    cout<<"Client Program started...\n"<<PROJECT_VERSION<<"\n";
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9111);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.1.1");

    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    send(clientSocket, "Hello from client!", 18, 0);

    char buffer[1024] = {0};
    recv(clientSocket, buffer, 1024, 0);
    std::cout << "Received: " << buffer << std::endl;

    close(clientSocket);
    return 0;
}