#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n; cin>>n;
 	if(((n*(n+1))/2) &1)
 	{
 		cout<<"NO";
 		return 0;
 	}
 	cout<<"YES\n";
 	int ans=(n*(n+1))/4;
 	vector<int> s1, s2;
 	for(int i=n; i>0; i--){
 		if(i<=ans){
 			s1.push_back(i);
 			ans-=i;
 		}
 		else s2.push_back(i);
 	}
 	cout<<s1.size()<<"\n";
 	for(auto it : s1) cout<<it<<" ";

 	cout<<"\n"<<s2.size()<<"\n";
 	for(auto it : s2) cout<<it<<" ";
    return 0;
}