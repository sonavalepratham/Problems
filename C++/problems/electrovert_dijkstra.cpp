#include<bits/stdc++.h>
using namespace std;

long long INF=1e11, N=1e5+1;
#define ll long long

vector<long long> dijkstra(vector<vector<pair<long long, long long>>> &graph, long long src){
        long long n=graph.size();
        vector<ll> dist(graph.size(), INF);
        vector<bool> vis(n, 0);
        set<pair<ll, ll>> ms;
        ms.insert({0, src});
        
        dist[src]=0;
        while(!ms.empty()){
            ll wi=(*ms.begin()).first, i=(*ms.begin()).second;
            ms.erase(ms.begin());
            if(vis[i]) continue;
            vis[i]=1;
            for(auto it : graph[i]){
                if(wi+it.second < dist[it.first]){
                    dist[it.first]=wi+it.second;
                    ms.insert({dist[it.first], it.first});
                }
            }
        }
        return dist;
    }
long long solve(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<ll, ll>>> graph(n), rgraph(n);
        for(auto it : edges){
            graph[it[0]].push_back({it[1], it[2]});
            rgraph[it[1]].push_back({it[0], it[2]});
        }
        vector<ll> g1=dijkstra(graph, src1), g2=dijkstra(graph, src2), g3=dijkstra(rgraph, dest);
        ll res=INF;
        for(ll i=0; i<n; i++){
            if(g1[i]!=INF and g2[i]!=INF){
                res=min(res, g1[i]+g2[i]+g3[i]);
            }
        }
        if(res==INF) return -1;
        return res;
    }

signed main(){
    int t; 
    cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>> edges;
        for(long i=0; i<m; i++){
            int a, b, c;
            cin>>a>>b>>c;
            edges.push_back({a, b, c});
        }
        int src1, src2, dest; cin>>src1>>src2>>dest;
        cout<<solve(n, edges, src1, src2, dest)<<"\n";
    }

    return 0;
}