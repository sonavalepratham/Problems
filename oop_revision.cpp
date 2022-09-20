#include<bits/stdc++.h>
using namespace std;

void fun(int arr[], int n){
	int nz=0, z=0;
	for(int i=0; i<n; i++){
		while(arr[nz]==0) nz++;
		while(arr[z]==0) z++;
		if(nz>z) swap(arr[nz], arr[z]);
	}
}

int main(){
	int arr[]={1,0,0,8,3,0,7,0};
	fun(arr, 8);
	return 0;
}