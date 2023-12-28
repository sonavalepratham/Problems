#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s; cin>>s;
 	vector<bool> v(27, true);
 	int cnt =0;
 	for(int i=0; i<s.size(); i++){
 		if(v[s[i]-'a']){
 			v[s[i]-'a']=false;
 			cnt++;
 		}
 	}   
 	if(cnt&1) cout<<"IGNORE HIM!";
 	else cout<<"CHAT WITH HER!";
    return 0;
}