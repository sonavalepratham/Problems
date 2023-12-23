#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int l, r, k; cin>>l>>r>>k;
    	int oe;
    	if(l%2==1 and r%2==1){
    		oe=(r-l+1)/2+1;
    	}
    	else oe=(r-l+1)/2;

    	int minnum=oe;

    	if(k>=minnum or (l==r and l!=1)) cout<<"YES\n";
    	else cout<<"NO\n";
    }
    return 0;
}