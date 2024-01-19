#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int q; cin>>q;
 	while(q--){
 		int r, c; cin>>r>>c;
 		if(r==c){
 			cout<<(r-1)*(r-1)+r<<"\n";
 			continue;
 		}
 		int mx=max(r, c)-1;
 		mx*=mx;
 		if((max(r, c)&1 and max(r, c)==c) or (max(r, c)%2==0 and max(r, c)==r)){
 			cout<<mx+2*max(r,c)-min(r, c)<<"\n";	
 		}
 		else{
 			cout<<mx+min(r,c)<<"\n";
 		}
 	}   
    return 0;
}