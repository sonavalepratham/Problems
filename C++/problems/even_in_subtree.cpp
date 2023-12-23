#include <bits/stdc++.h>
using namespace std;
/*
Given Q queries, Q<=1e5
in each query given V,
number of even numbers in subtree of V,
print subtree sum of V,
undirected graph
*/

int precompute(vector<vector<int>>&adj, vector<int>&prearr, vector<bool>&ord, vector<int>&presum, int i=1){
	ord[i]=1;
	if(i%2==0) prearr[i]=1;
	presum[i]+=i;
	for(auto it : adj[i]){
		if(!ord[it]){
		prearr[i]+=precompute(adj, prearr, ord, presum, it);
		presum[i]+=presum[it];
	}
	}
	ord[i]=0;
	return prearr[i];
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n>>q;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
    	int u, v; cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<int> prearr(n+1, 0), presum(n+1, 0);
    vector<bool> ord(n+1, 0);
    precompute(adj, prearr, ord, presum);
    // cout<<n<<q;
    while(q--){
    	int v;
    	cin>>v;
    	cout<<prearr[v]<<" "<<presum[v]<<"\n";
    }
    return 0;
}