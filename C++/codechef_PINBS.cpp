#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	string s; cin>>s;
    	bool flg=0;
    	int n=s.size();
    	for(int i=0; i<n-1; i++){
    		if((s[i]=='1' and s[i+1]=='0') or (s[i]=='1' and s[i+1]=='1')){
    			flg=1; break;
    		}
    	}
    	if(flg) cout<<"Yes\n";
    	else cout<<"No\n";
    }
    return 0;
}