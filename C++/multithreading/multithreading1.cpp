#include<iostream>
#include<thread>
#include<chrono> // Library to deal with Date & Time
#include<algorithm>
using namespace std;


/*
NOTE:
	1. Creating multiple threads dosen't guaranted which one will start at first.
	
Creation of Threads:
	1. Function pointer.
	2. Lambda function.
	3. Functor or function object.
	4. Non static member function.
	5. Static member function.
	
*/

class Base{
public:
void operator ()(int x){
	while(x-->0){
	cout<<x<<"\n";
	}
}
};

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum=0;

void findEven(ull start, ull end){
	for(ull i=start; i<=end; i++){
		if((i&1)==0){
			EvenSum+=i;
		}
	}
}

void findOdd(ull start, ull end){
	 for(ull i=start; i<=end; i++){
		if((i&1)!=0){
			OddSum+=i;
		}					
	}	
}

void findOddEven(){

ull start=0, end = 19000000000;

auto startTime = chrono::high_resolution_clock::now();

std::thread t1(findEven, start, end), t2(findOdd, start, end); // created two threads t1 & t2 by passing function pointer & arguments

t1.join(); // wait until t1 is completed
t2.join(); // wait until t2 is completed


//findOdd(start, end);
//findEven(start, end);

auto stopTime=chrono::high_resolution_clock::now();

auto duration = chrono::duration_cast<chrono::microseconds>(stopTime-startTime);

cout<<"OddSum"<<OddSum<<"\n";
cout<<"EvenSum"<<EvenSum<<"\n";

cout<<"Execution Time: "<<duration.count()/1000000;
}

void printNums(){
auto fun = [](int x){
	while(x--){
		cout<<x<<"\n";
	}
};

std::thread t(fun, 10); // we can directly write lamda expression as first argument.
t.join();

}

void FunctorThreadCreation(){
cout<<"Inside FunctorThreadCreation()\n";
std::thread t(Base(), 10);
t.join();
return ;
}

void NonStaticMemberFunction(){
cout<<"Inside NonStaticMemberFunction()\n";

class Base{
public:
void run(int x){
	while(x-->0){
	cout<<x<<"\n";
	}
}
};

Base b;
std::thread t(&Base::run, &b, 10); // for non static member fn we need to pass object to call method as 2nd argument.
t.join();
}

void StaticMemberFunction(){
cout<<"Inside StaticMemberFunction()\n";

class Base{
public:
static void run(int x){
	while(x-->0){
	cout<<x<<"\n";
	}
}
};

std::thread t(&Base::run, 10); // in case of static member fn we don't need to pass object to call method.
t.join();
}

int main(){

// findOddEven(); // threads created by function pointer.
//printNums();
//FunctorThreadCreation();
//NonStaticMemberFunction();
StaticMemberFunction();
return 0;

}
