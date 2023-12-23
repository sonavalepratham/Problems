#include <iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;

/*

Timed Mutex in cpp , std::timed_mutex
try_lock_for(std::chrono::seconds(1))
try_lock_until(until_time) // returns true if able to lock in specified time.

*/

int num=0;
std::timed_mutex m;

void increment(int thread_id){
	if(m.try_lock_for(chrono::seconds(2))){
		num++;
		std::this_thread::sleep_for(chrono::seconds(1));
		cout<<"Entered Thread: "<<thread_id<<"\n";
		m.unlock();
	}
	else
		cout<<"could not enter Thread: "<<thread_id<<"\n";
}	

int main()
{
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);
    t1.join();
    t2.join();
    cout<<num<<"\n";
    return 0;
}