#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pos ={ {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

bool ispos(int a, int b, int c, int d){
	return a>=0 and b>=0 and a<c and b<d;
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, m; cin>>n>>m;
    	int arr[n][m];
    	vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    	int mx=0;
    	queue<pair<int, int>> q;
    	vector<vector<bool>> vis(n, vector<bool>(m, 0));
    	for(int i=0; i<n; i++)
    		for(int j=0; j<m; j++) cin>>arr[i][j], mx=max(mx, arr[i][j]);

    	for(int i=0; i<n; i++)
    		for(int j=0; j<m; j++)
    			if(arr[i][j]==mx) q.push({i, j}), dis[i][j]=0, vis[i][j]=1;
    		
    	int res=0;

    	while(!q.empty()){
    		int i=q.front().first, j=q.front().second;
    		q.pop();
    		for(auto it : pos){
    			if(ispos(i+it.first, j+it.second, n, m) and !vis[i+it.first][j+it.second]){
    				dis[i+it.first][j+it.second]=dis[i][j]+1;
    				vis[i+it.first][j+it.second]=1;
    				q.push({i+it.first, j+it.second});
    				res=max(res, dis[i+it.first][j+it.second]);
    			}
    		}
    	}
    	cout<<res<<"\n";
    }
    return 0;
}