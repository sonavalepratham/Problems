#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int t; cin>>t;
 	while(t--){
 		int n, k; cin>>n>>k;
 		string s; cin>>s;
 		int cnt=0, x=0, cnto=0, xo=0;

 		for(int i=0; i<n; i++){
 			x^=(s[i]=='1');
 			xo^=(s[i]=='1');
 			if(cnt<k-1 and i!=n-1 and (!x)) cnt++;
 			if(xo and cnto<k-1 and i!=n-1) cnto++, xo=0;
 		}

 		if(cnt==k-1 and !x) cout<<"YES\n";
 		else if(xo and (cnto==k-1)) cout<<"YES\n";
 		else cout<<"NO\n";
 	}   
    return 0;
}