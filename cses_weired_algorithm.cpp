#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s; cin>>s;
 	int cnt=1, ans=1;
 	char cur=s[0];
 	for(int i=1; i<s.size(); i++){
 		if(s[i]==cur) cnt++;
 		else cnt=1, cur=s[i];
 		ans=max(ans, cnt);
 	}
 	cout<<ans;
    return 0;
}