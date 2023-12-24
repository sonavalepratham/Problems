#include <bits/stdc++.h>
using namespace std;
/*
1. don't change order of mutex lock.
2. or use std::lock it will prevent this.
*/
std::mutex m1, m2;

void task1(){
	m1.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m2.lock();
	cout<<"Some critical section code #Task1\n";
	m1.unlock();
	m2.unlock();
}

void task2(){
	m2.lock();
	m1.lock();
	cout<<"Some critical section code #Task2\n";
	m2.unlock();
	m1.unlock();
}

int main()
{
	std::thread t1(task1);
	std::thread t2(task2);
	t1.join();
	t2.join();
    
    return 0;
}