#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2){
	if(p1.first==p2.first) return p1.second>p2.second;
	return p1.first<p2.first;
}

int query(vector<int>& segtree, int s, int e, int l, int r, int idx){
	if(e<l or s>r) return 0;
	if(s>=l and e<=r) return segtree[idx];
	int la, ra, mid=(s+e)/2;
	la=query(segtree, s, mid, l, r, 2*idx);
	ra=query(segtree, mid+1, e, l, r, 2*idx+1);
	return max(la, ra);
}

void update(vector<int>&lis, vector<int>& segtree, int s, int e, int idx, int ari, int val){
	if(s==e){
		segtree[idx]=lis[ari]=val;
		return ;
	}
	int mid=(s+e)/2;
	if(ari<mid) update(lis, segtree, s, mid, 2*idx, ari, val);
	else update(lis, segtree, mid+1, e, 2*idx+1, ari, val);
	segtree[idx]=max(segtree[2*idx],segtree[2*idx+1]);
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<pair<int, int>> arr(n);
    vector<int> segtree(4*n, 0), lis(n, 0);
    for(int i=0; i<n; i++){ cin>>arr[i].first; arr[i].second=i; }
    sort(arr.begin(), arr.end(), comp);
	int ans=0;
	for(int i=0; i<n; i++){
		int res=query(segtree, 0, n-1, 1, arr[i].second, 1);
		ans=max(ans, res+1);
		update(lis, segtree, 0, n-1, 1, arr[i].second, res+1);
	}
	cout<<ans;
    return 0;
}
