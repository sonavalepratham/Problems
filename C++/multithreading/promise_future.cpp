#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
/*
std::promise std::future
value set by promise in other thread we can retrive in another thread by using future

*/

void fun(std::promise<ull>&& prom, ull start, ull end){
	ull cnt=0;
	for(ull i=start; i<end; i++){
		if(i&1) cnt++;
	}
	prom.set_value(cnt);
}

int main()
{
 	ull start =0, end=1900000000;
 	std::promise<ull> prom;
 	std::future<ull> fut = prom.get_future();
 	cout<<"Thread created\n";
 	std::thread t1(fun, std::move(prom), start, end);
 	
 	cout<<"waiting for result\n";
 	cout<<fut.get()<<"\n";
	cout<<"first value occured\n";
	cout<<fut.get()<<"\n"; // error will occur here, use shared_future in case of multiple retrivel of value
	cout<<"Completed!!";
 	t1.join();
    return 0;
}
