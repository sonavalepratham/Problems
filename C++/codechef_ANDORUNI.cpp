#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n; cin>>n;
    	int arr[n];
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}
    	int ans=0;
    	for(int i=0; i<32; i++){
    		int cnt=0;
    		for(int j=0; j<n; j++){
    			if(arr[j]&(1<<i)) cnt++;
    		}
    		if(cnt>=2) ans=ans|(1<<i);
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}