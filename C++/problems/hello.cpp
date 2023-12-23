#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++){
    	int n, x, y; cin>>n>>x>>y;
    	int sum=n*(n+1)/2;
    	int X=(sum*x)/(x+y), Y=(sum*y)/(x+y);
    	if(X+Y==sum){
    		vector<int> res;
    		int ans=X;
    		for(int i=n; i>0; i--){
    			if(i<=ans) ans-=i, res.push_back(i);
    			if(ans==0) break;
    		}
    		if(ans==0){
    		cout<<"Case #"<<tc<<": "<<"POSSIBLE"<<"\n";
    		cout<<res.size()<<"\n";
    		for(auto i : res) cout<<i<<" ";
    		cout<<"\n";
    		}
    		else
    	cout<<"Case #"<<tc<<": "<<"IMPOSSIBLE"<<"\n";
    	}
    	else
    	cout<<"Case #"<<tc<<": "<<"IMPOSSIBLE"<<"\n";
    }
    return 0;
}