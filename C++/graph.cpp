#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<pair<int, int>>> & graph, int s, int e, int w, bool dir=false){
	// add edges in adjecancy list
	graph[s].push_back({e, w});
	if(!dir) graph[e].push_back({s, w});
}

void display(vector<vector<pair<int, int>>> & graph){
	for(auto i : graph){
		if(i.empty()) cout<<"empty";
		for(auto j : i){
			cout<<"{"<<j.first<<", "<<j.second<<"} ";
		}
		cout<<"\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    time_t start, end; time(&start);

    int v, e; cin>>v>>e;
    vector<vector<pair<int, int>>> graph(v+1);
    int t=e;
    while(t--){
    	int s, e, w; cin>>s>>e>>w;
    	addedge(graph, s, e, w, false);
    }
    display(graph);
    for(int i=0; i<100000000; i++);
    time(&end);
    double time_taken = double(end - start);
    cout << "\nTime " << fixed << setprecision(5) << time_taken<<" sec";
    return 0;
}

// bool pos(vector<vector<bool>> &vis, int n, int i, int j){
//     if((i<n and i>=0) and (j<n and j>=0) and (!vis[i][j])) return 1;
//     return 0;
// }
// void dfs(vector<vector<bool>> &vis, int n, int i, int j, int ti, int tj, int &res, int len){
//     if(!pos(vis, n, i, j)) return ;
//     if(i==ti and j==tj) {
//         res=min(res, len);
//         return ;
//     } 
//     vis[i][j]=1;
//     v1={2, 2, -2, -2, -1, 1, -1, 1};
//     v2={-1, 1, -1, 1, 2, 2, -2, -2};
//     for(int k=0; k<8; k++){
//         dfs(vis, n, v1[k], v2[k], ti, tj, res, len+1);
//     }
//     vis[i][j]=0;
// }
