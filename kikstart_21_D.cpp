#include<bits/stdc++.h>
using namespace std;

void sol(){
	int arr[3][3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(i==1&&j==1) continue;
			cin>>arr[i][j];
		}
	}
	int pv[4];
	pv[0]=(arr[0][0]+arr[2][2])/2;
	pv[1]=(arr[0][2]+arr[2][0])/2;
	pv[2]=(arr[0][1]+arr[2][1])/2;
	pv[3]=(arr[1][0]+arr[1][2])/2;
	int cnt=0;
	for(int i=0; i<4; i++){
		arr[1][1]=pv[i];
		int tmp=0;
		if(arr[0][1]-arr[0][0]==arr[0][2]-arr[0][1]) tmp++;
		if(arr[1][1]-arr[1][0]==arr[1][2]-arr[1][1]) tmp++;
		if(arr[2][1]-arr[2][0]==arr[2][2]-arr[2][1]) tmp++;
		if(arr[1][0]-arr[0][0]==arr[2][0]-arr[1][0]) tmp++;
		if(arr[1][1]-arr[0][1]==arr[2][1]-arr[1][1]) tmp++;
		if(arr[1][2]-arr[0][2]==arr[2][2]-arr[1][2]) tmp++;
		if(arr[1][1]-arr[0][0]==arr[2][2]-arr[1][1]) tmp++;
		if(arr[0][2]-arr[1][1]==arr[1][1]-arr[2][0]) tmp++;
		cnt=max(cnt, tmp);
	}
	cout<<cnt<<"\n";
}

int main(){

	int t; cin>>t;
	int n=1;
	while(t--){
		cout<<"Case #"<<n<<": ";
		n++;
		sol();
	}
	return 0;
}