#include <bits/stdc++.h>
using namespace std;

/*
condition variables are used for 2 purpose
	a. notify other threads
	b. waiting for some condition

1. condition variable allows running threads to wait on some conditions and once those conditions are met the waiting thread is notified using
	a. notify_one()
	b. notify_all()
2. you need mutex variable to use condion variable.
3. If some thread want to wait on some condition then it has to do these things
	a. acquire the mutex lock using std::unique_lock<std::mutex> lock(m);
	b. execute wait, wait_for or wait_wait_until. the wait operations automatically release the mutex and suspend the execution of thread
	c. when the condition variable is notified, the thread is awakened, and the mutex is automatically reqacquired.
	the thread should check condition and resume waiting if the wake up was spurious.

NOTE:
1. CV are used to sync 2 or more threads.
2. best use case of CV is producer/consumer problem.

*/


std::mutex m;
std::condition_variable cv;
int balance  = 0;

void addMoney(int Rs){
	std::unique_lock<mutex> lock(m);
	cout << "Adding Rs "<<Rs<<" to acct\n";
	balance+=Rs;
	cv.notify_one();
	cout<<"after notify\n";
	std::this_thread::sleep_for(chrono::seconds(2));
}

void withdrawMoney(int Rs){
	std::unique_lock<mutex> lock(m);
	cv.wait(lock,[]{return balance!=0;});
	if(balance<Rs){
		cout<<"less than requested money\n";
		return;
	}
	balance-=Rs;
	cout<<"Withdrawing money\n";
}

int main()
{
   	std::thread t1(withdrawMoney, 500);
   	std::this_thread::sleep_for(chrono::seconds(1));
   	std::thread t2(addMoney, 500);
    t1.join();
    t2.join();
    return 0;
}