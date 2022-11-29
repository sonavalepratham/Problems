#include <bits/stdc++.h>
using namespace std;

set<string> res;

void fun(string &s, int n){
	if(n==-1) return;
	res.insert(s);
	for(int i=n; i>=0; i--){
		if(s[i]==s[n]) continue;
		fun(s, n-1);
		swap(s[i], s[n]);
		fun(s, n-1);
		swap(s[i], s[n]);
	}
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s; cin>>s;
 	sort(s.begin(), s.end());
 	fun(s, s.size()-1);
 	cout<<res.size()<<"\n";
 	for(auto it : res) cout<<it<<"\n"; 
    return 0;
}