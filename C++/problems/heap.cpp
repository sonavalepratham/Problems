#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
bool less(T&a, T&b){
	return a<b;
}
template<typename T>
class mxheap{
	vector<T> arr;
public:
	void push(int e){
		arr.push_back(e);
		int i=arr.size()-1;
		while(i&&arr[i]>arr[(i-1)/2]){
			swap(arr[i], arr[(i-1)/2]);
			i=(i-1)/2;
		}
	}
	T top(){
		return arr[0];
	}
	void pop(){
		int  i=0;
		arr[0]=arr[arr.size()-1];
		arr.pop_back();
		while(2*i+1<arr.size()){
			int child=arr[2*i+1]>arr[2*i+2]?(2*i+1):(2*i+2);
			if(arr[i]<arr[child]){
				swap(arr[i], arr[child]);
			}
			else break;
			i=child;
		}
	}
	void print(){
		for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
	}
};

int main(){

	mxheap<int> h;
	int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	for(int i=0; i<11;  i++) {h.push(a[i]);	}
	h.print();
	return 0;
}