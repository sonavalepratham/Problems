#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main(int argc, char* argv[]){
        // arguments handeling part
        int tmpArgscnt = argc;
        cout << "received: " << argc <<"arguments\n";
        while(tmpArgscnt--){
                cout << argv[tmpArgscnt] <<" ";
        }
        cout << "\n";
        // handeling stdin until receive eof
        std::stringstream inputBuffer; // storing input
        cout << "printing from stdin\n";
        std::string line;
        while (std::getline(std::cin, line))
        {
          std::cout << line << std::endl;
          inputBuffer << line <<"\n";
        }
        // printing error msg to see if get writes to 2> file
        cerr << "printing TEST error message\n";

        // handling file io operations
        if(argc < 2){
                cerr << "file name not provided to read and write. argc: " << argc <<"\n";
                return 1;
        }

        std::ifstream inFile(argv[1]); // reading file
        if(inFile.is_open()){
                while(std::getline(inFile, line)){
                        std::cout << line << "\n";
                }
                inFile.close();
        }
        else{
                std::cerr << "Not able to open file for reading\n";
        }

        std::ofstream oFile(argv[1]); // opening file to write content from stdin until receive eof
        if(oFile.is_open())
        {
                oFile<<inputBuffer.str();
                oFile.close();
        }
        else{
                std::cerr << "Not able to open file for writing\n";
        }
        return 0;
}
