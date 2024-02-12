#include<mutex>
#include<thread>
#include<vector>
#include <sys/socket.h>
#include <condition_variable>
#include <iostream>

#ifndef SERVER_H
#define SERVER_H

class Server {
private:
    int serverSocket;
    std::vector<std::thread> clientThreads;
    std::mutex mutex;
    std::condition_variable cv;
    bool stopServer = false;
    void acceptClients();
public:
    Server(int port);
    void start();
    void stop();
};

#endif // SERVER_H