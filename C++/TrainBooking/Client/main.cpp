#include<iostream>
#include "ProjectInfo.h"
#include "client.h"

using namespace std;

int main(){
    cout<<"Client Program started...\n"<<PROJECT_VERSION<<"\n";
    Client client("127.0.1.1", 9111);
    client.Send("First Msg");
    client.StartRxTx();
    return 0;
}