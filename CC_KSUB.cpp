#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, k, g=0, kc=0; cin>>n>>k;
    	int arr[n];
    	for(int i=0; i<n; i++) cin>>arr[i], g=__gcd(g, arr[i]);
    	int tmpgcd=arr[0];
    	for(int i=1; i<n; i++){
    		if(tmpgcd==g){
    			kc++; tmpgcd=arr[i];
    		}
    		tmpgcd=__gcd(tmpgcd, arr[i]);
    	}
    	if(tmpgcd==g) kc++;
    	if(kc>=k) cout<<"YES\n";
    	else cout<<"NO\n";
    }
    return 0;
}