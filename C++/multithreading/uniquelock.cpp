#include <bits/stdc++.h>
using namespace std;

/*
1. std::unique_lock it's mutext ownership wrapper.
2. It allows:
	a. can have different locking strategies.
	b. time constrained locking on mutex(try_lock_for, until).
	c. recursive locking.
	d. transfer of lock ownership(move, not copy).
	e. condition variables.
// Locking Strategies
	TYPE			EFFECTS
1.  defer_lock		do not aquire ownership of mutex
2.  try_to_lock		try to aquire ownership of mutex without blocking
3.  adopt_lock		assume the calling thread already own mutex
*/


std::mutex m;
int buffer=0;

void task(const char* threadId, int num){
	std::unique_lock<mutex> lock(m); // immediatly lock mutex
	for(int i=0; i<num; i++){
		buffer++;
		cout<<"Thread id: "<<threadId<<"\n";
	}
	// unlock automatically on destruction of unique lock.
}

void task1(const char* threadId, int num){
	std::unique_lock<mutex> lock(m, std::defer_lock); // does not lock, we have to do that manually
	lock.lock();
	for(int i=0; i<num; i++){
		buffer++;
		cout<<"Thread id: "<<threadId<<"\n";
	}
	
	// automatically unlock in destruction of unique lock/
}

int main()
{
   	std::thread t1(task1, "1", 5);
    std::thread t2(task1, "2", 5);
    t1.join();
    cout<<"t1 completed\n";
    t2.join();
    return 0;
}