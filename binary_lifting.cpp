#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int cur, int par, vector<vector<int>> & arr, vector<vector<int>>&adj){
	arr[cur][0] = par;
	for(int i = 1; i < log2(arr.size()); i++)
    {
        if(arr[cur][i-1] != -1)
            arr[cur][i] = arr[arr[cur][i-1]][i-1];
        else arr[cur][i] = -1;
    }
    for(int child : adj[cur])
    {
        if(child != par)
            dfs(child, cur, arr, adj);
    }
}

int find(int n, int j, vector<vector<int>>&arr){
	if(j==0 or n==-1) return n;
	for(int i=19; i>=0; i--){ // try for bigger steps first
		if((1<<i)<=j){
			return find(arr[n][i], j-(1<<i), arr);
		}
	}
}

signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin>>n>>q;
    vector<vector<int>> adj(n+1);
    for(int i=2; i<=n; i++){
    	int tmp; cin>>tmp;
    	adj[tmp].push_back(i);
    }
    vector<vector<int>> arr(n+1, vector<int>(log2(n)+1));
    dfs(1, -1, arr, adj);
    
    while(q--){
    	int i, k; cin>>i>>k;
    	// cout<<i<<" "<<k<<"\n";
    	cout<<find(i, k, arr)<<"\n";
    }
    return 0;
}