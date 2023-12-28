#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2; cin>>s1>>s2;
    if(s1.size()!=s2.size()){
    	cout<<"NO";
    	return 0;
    }
    bool flg=true;
    for(int i=0; i<s1.size(); i++){
    	if(s1[i]!=s2[s1.size()-i-1]){
    		flg = false;
    		break;
    	}
    }
    if(flg) cout<<"YES";
    else cout<<"NO";
    return 0;
}