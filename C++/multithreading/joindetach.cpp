#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

/*
1. once thread started we wait for thread to finish by calling join() method on thread object.
2.double join or detach results into program termination, so use joinable() function on thread before join or detach.
3. either join or terminate should be called on thread object, otherwise at thread object destruction it will terminate program. because it checks if thread is still joinable, if yes then terminates the program.
4. detach is used to detach newly created thread from parent thread.
5. if we have detached thread & main function is returning then detached thread execution is suspended.

*/

void run(int cnt){
cout<<"Inside run()\n";
while(cnt-->0){
	cout<<cnt<<" abc\n";
}
std::this_thread::sleep_for(chrono::seconds(3));
cout<<"run after\n";
}

int main(){
cout<<"Inside main()\n";
std::thread t1(run, 10);
if(t1.joinable())
	t1.detach();

cout<<"main after\n";
return 0;
}
