#include <bits/stdc++.h>
using namespace std;

/*
0. lockguard lightweight wrapper to lock mutex on scope basis.
1. you cannot unlock it mannually/
2. cannot copy.
3. when lock_gurard object is created, it will lock object.
*/

std::mutex m1;
int buffer = 0;

void fun(int loofFor){
	std::lock_guard<mutex> lock1(m1);
	for(int i=0; i<loofFor; i++){
		buffer++;
		cout<<"Thread: "<< std::this_thread::get_id() <<" \n";
	}
}

int main()
{
 	std::thread t1(fun, 5);
 	std::thread t2(fun, 5);
 	t1.join();
 	t2.join();
    return 0;
}
