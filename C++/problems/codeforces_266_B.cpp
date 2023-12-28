#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t; cin>>n>>t;
    string s; cin>>s;
    while(t--){
    	for(int i=1; i<s.size(); i++){
    		if(s[i]=='G'&&s[i-1]=='B') { swap(s[i], s[i-1]); i++;}
    	}
    }
    cout<<s;
    return 0;
}