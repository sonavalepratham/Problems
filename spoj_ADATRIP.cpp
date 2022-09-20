#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i=0; i<m; i++){
    	int u, v, l; cin>>u>>v>>l;
    	adj[u].push_back({v, l});
    	adj[v].push_back({u, l});
    }
    while(q--){
    	
    }
    return 0;
}