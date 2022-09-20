#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int a, b; cin>>a>>b;
    	int arr[9][9];
    	for(int i=1; i<=8; i++)
    		for(int j=1; j<=8; j++) arr[i][j]=0;
    	arr[a][b]=1;
    	if(a+2<=8 and b+1<=8) arr[a+2][b+1]=2;
    	if(a+2<=8 and b-1<=8) arr[a+2][b+1]=2;
    	if(a-2<=8 and b+1<=8) arr[a+2][b+1]=2;

    	for(int i=1; i<=8; i++){
    		for(int j=1; j<=8; j++)
    			{ cout<<arr[i][j]<<" ";}
    		cout<<"\n";
    	}
    	}
    
    return 0;
}