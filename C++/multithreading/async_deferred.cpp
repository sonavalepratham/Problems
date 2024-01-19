#include<iostream>
#include<future>

/*
std::future<int> result = std::async(std::launch::policy, function_with_return_value, params);
policy:
1. async : thread will start task as soon as this line is executed.
2. deferred : thread will start when result.get() called, will block execution.

difference with future promise :
1. future promise will unblock execution as soon as value is set.
in this case it will block until function is completed.
2. this returns value.

result.get is blocking call.
*/

int fun(int n){
    std::cout<<"thread: "<< std::hash<std::thread::id>{}(std::this_thread::get_id()) <<" started for "<< n <<"\n";
    int res=0;
    for(int i=0; i<n; i++) res+=i;
    return res;
}

int main(){
    std::future<int> result = std::async(std::launch::async, fun, 10); // will start thread after this line 
    std::future<int> result1 = std::async(std::launch::deferred, fun, 15); // will start thread after result1.get()
    // get is blocking call
    std::cout<<result.get()<<"\n";
    std::cout<<result1.get()<<"\n"; // thread will start here

}