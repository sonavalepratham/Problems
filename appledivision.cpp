#include <bits/stdc++.h>
using namespace std;
#define int long long

int res = INT_MAX, sum=0;
int cnt=0;
void fun(vector<int>&arr, int i, int s)
{
	res=min(abs(sum-2*s), res);
	if(i<0)
	return;
	fun(arr, i-1, s);
	fun(arr, i-1, s+arr[i]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) cin>>arr[i], sum+=arr[i];

    fun(arr, n-1, 0);

    cout<<res;
    return 0;
}