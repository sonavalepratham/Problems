#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, q; cin>>n>>q;
    	int arr[n+1], prefgcd[n+2]={0}, postfgcd[n+2]={0};
    	for(int i=1; i<=n; i++){
    		cin>>arr[i];
    		prefgcd[i]=__gcd(prefgcd[i-1], arr[i]);
    	}
    	for(int i=n; i>=0; i--){
    		postfgcd[i]=__gcd(postfgcd[i+1], arr[i]);
    	}
    	while(q--){
    		int l, r; cin>>l>>r;
    		cout<<__gcd(prefgcd[l-1], postfgcd[r+1])<<"\n";
    	}
    }
    return 0;
}