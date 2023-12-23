#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, x, xr=0; cin>>n>>x;
    	for(int i=1; i<n; i++){
    		xr=xr^(x+i);
    		cout<<x+i<<" ";
    	}
    	cout<<(x^xr)<<"\n";
    }
    
    return 0;
}