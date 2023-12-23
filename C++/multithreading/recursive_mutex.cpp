#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

/*
std::recursive_mutex
0. one thread can lock mutex multiple times.
1. if thread T1 is locked mutex m1 then T1 can lock or try_lock any number of times.
   but if T1 locked mutex 10 times, then it should unlock it 10 times other wise no othre thread will be able to lock mutex.
2. how many time we can lock recursive mutex is not defined, but if we exceed that number (based on stack space) & 
do lock() then we get std::system_error in case of try_lock get false.

*/

std::recursive_mutex m;

void recursive(int num){
	if(num<=0) return;
	if(m.try_lock()){
		recursive(num-1);
		std::cout<<num<<"\n";
		m.unlock();
	}
}

int main()
{
	std::thread t1(recursive, 5);
	t1.detach();
	t1.join();
	//std::this_thread::sleep_for(std::chrono::microseconds(1));
	return 0;
}