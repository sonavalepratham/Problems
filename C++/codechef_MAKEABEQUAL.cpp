#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, sum1=0, sum2=0, ans=0; cin>>n;
    	int arr1[n], arr2[n];
    	for(int i=0; i<n; i++) cin>>arr1[i], sum1+=arr1[i];
    	for(int i=0; i<n; i++) cin>>arr2[i], sum2+=arr2[i];

    		if(sum1!=sum2){
    		 cout<<"-1\n";
    		 continue;
    		}
    	for(int i=0; i<n; i++) ans+=abs(arr1[i]-arr2[i]);
    	cout<<ans/2<<"\n";
    }
    return 0;
}