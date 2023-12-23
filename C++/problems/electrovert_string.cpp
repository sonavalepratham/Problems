#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10, INF = INT_MAX;
int ans;
int lvl_indx[N];
string s;
int m;
void dfs(int n, vector<vector<int>>&adj, int l=0){
    lvl_indx[l] = n;
    if(s[n] == 'a' and l>=m){
        int ind = lvl_indx[l-(m-1)];
        int len=ind-n+1-m;
        ans=min(ans, len);
    }
    for(auto it : adj[n]){
        dfs(it, adj, l+1);
    }
}

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    cin>>m;
	    cin>>s;
	    s+='$';
	    
	    vector<vector<int>> adj(n+2);
	    vector<int> ni(257, n);
	    for(int i=n-1; i>=0; i--){
	        int nxtchr = s[i]+1;
	        if(s[i]=='z') nxtchr='a';
	        adj[ni[nxtchr]].push_back(i);
	        ni[s[i]]=i;
	    }
	    ans=INF;
	    dfs(n, adj);
	    if(ans==INF) ans=-1;
	    cout<<ans<<"\n";
	}
	return 0;
}