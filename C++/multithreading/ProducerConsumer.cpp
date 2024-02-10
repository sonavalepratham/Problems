#include<iostream>
#include<thread>
#include <mutex>
#include <condition_variable>
#include <queue>

#define cap 30;

using namespace std;

std::mutex mu;
std::condition_variable cv;
queue<int> q;
void producer(int val){
    while(val--){
        std::unique_lock locker(mu);
        cv.wait(locker, [](){return q.size()<cap;});
        q.push(val);
        cout<<"value produced: "<<val<<"\n";
        locker.unlock();
        cv.notify_one();
    }
}

void consumer(){
    while(true){
        std::unique_lock locker(mu);
        cv.wait(locker, [](){return q.size()>0;});
        cout<<"consumed value: "<<q.front()<<"\n";
        q.pop();
        locker.unlock();
        cv.notify_one();
    }
}

int main(){
    std::thread t1(producer, 50);
    std::thread t2(consumer);
    t1.detach();
    t2.join();
    return 0;
}