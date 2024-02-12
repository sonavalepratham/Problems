#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

class ClientHandler {
private:
    int clientSocket;
public:
    ClientHandler(int socket);
    void handle();
};

#endif // CLIENTHANDLER_H