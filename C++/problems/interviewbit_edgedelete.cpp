#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
void calcSubarrSum(vector<int>&A, vector<vector<int>>&B, vector<int>&subarrsum, int i, int par=0){
	subarrsum[i]+=A[i];
	for(auto it : B[i]){
		if(it==par) continue;
		calcSubarrSum(A,B,subarrsum, it, i);
		subarrsum[i]+=subarrsum[it];
	}
}

int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
	int n=A.size();
	vector<int> subarrsum(n+1, 0);
	calcSubarrSum(A, B, subarrsum, 1);
	long long ans=0;
	for(int i=2; i<=n; i++){
		ans=max(ans, (1ll*subarrsum[i]*(subarrsum[1]-subarrsum[i]))%M);
	}
	return ans;
}


int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n; cin>>n;
    vector<int> A(n+1);
    vector<vector<int>> B(n+1);
    for(int i=1; i<=n; i++) cin>> A[i];
    for(int i=0; i<n-1; i++){
    	int u, v; cin>>u>>v;
    	B[u].push_back(v);
    	B[v].push_back(u);
    }

    cout<<deleteEdge(A, B);
    return 0;
}