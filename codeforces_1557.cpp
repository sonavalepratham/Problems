#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, mx=INT_MIN; cin>>n;
    	int arr[n];
    	double sum=0;
    	for(int i=0; i<n; i++) {
    		cin>>arr[i];
    		mx=max(arr[i], mx);
    		sum+=arr[i];
    	}
    	cout<< fixed << setprecision(9) << mx+(double) (sum - mx)/(n-1)<<"\n";
    }
    return 0;
}