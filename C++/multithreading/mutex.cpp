#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

/*
Mutex: Mutual Exclusion(accessing something mutually) karar in marathi.
RACE condition: 2 or more threads happened to change common data.
if try_lock is called again by the same thread which owns the mutex, the behaviour is undefined.
it is deadlock situation with undefined behaviour. if we want to lock same mutex by same thread more than one time, go for recursive mutex.


m.lock(); block this code, wait until it's unlocked
m.try_lock() it will return false if mutex is unavailable (non blocking)

*/

int myCnt = 0;
std::mutex m;

void fun(){
m.try_lock();
myCnt++;
m.unlock();
}

void fun_try(){
for(int i=0; i<10000; i++)
{
	if(m.try_lock()){
	myCnt++;
	m.unlock();
	}
}
}

int main(){
std::thread t1(fun_try);
std::thread t2(fun_try);
t1.join();
t2.join();

cout <<myCnt<<"\n";

return 0;
}
