#include<bits/stdc++.h>
using namespace std;

void sol(){
	int c, n, mx=0; cin>>c>>n;
	vector<vector<int>> p;
	for(int i=0; i<n; i++){
		int p1, p2; cin>>p1>>p2;
		mx=max(mx, max(p1, p2));
		p.push_back({p1, p2});
	}
	vector<int> arr(mx+2, 0);
	for(int i=0; i<n; i++){
		arr[p[i][0]+1]++;
		arr[p[i][1]]--;
	}
	int ps=0;
	priority_queue<pair<int, int>> pq;
	for(int i=0; i<arr.size(); i++) {
		arr[i]+=ps;
		// cout<<arr[i]<<" ";
		ps=arr[i];
		pq.push({ps, i});
	}
	int res=n;
	while(c--&&pq.top().first){
		res+=pq.top().first;
		pq.pop();
	}
	cout<<res<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin>>t;
	int n=1;
	while(t--){
		cout<<"Case #"<<n<<": ";
		n++;
		sol();
	}
	return 0;
}
