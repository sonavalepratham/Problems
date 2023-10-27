#include <bits/stdc++.h>
using namespace std;

vector<int> dsuf;

int find(int v){
	if(dsuf[v]==-1) return v;
	return dsuf[v]=find(dsuf[v]);
}

bool iscyclic(vector<pair<int, int>> &edgelist){
	for(auto p : edgelist){
		int fp, tp;
		fp=find(p.first);
		tp=find(p.second);
		if(fp==tp) return 1;
		dsuf[fp]=tp;
	}
	return 0;
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e; cin>>v>>e;
    dsuf.resize(v, -1);
    vector<pair<int, int>> edgelist(e);
    for(int i=0; i<e; i++){
    	cin>>edgelist[i].first;
    	cin>>edgelist[i].second;
    }
    if(iscyclic(edgelist)) cout<<"Cycle Detected";
    else cout<<"Cycle Not Detected";
    return 0;
}