#include<iostream>
#include "ProjectInfo.h"
#include "server.h"
using namespace std;

int main(){
    cout<<"Server Program started...\n"<<PROJECT_VERSION<<"\n";
    Server server(9111);
    server.start();
    return 0;
}