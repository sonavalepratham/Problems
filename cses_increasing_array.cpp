#include <bits/stdc++.h>
using namespace std;

template <typename T> T mmax(T a, T b){
    return a>b?a:b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	long long n, sum=0, prev_mx; cin>>n>>prev_mx;
 	for(int i=0; i<n-1; i++){
 		long long curr; cin>>curr;
 		sum += mmax(prev_mx-curr, (long long int)0);
 		prev_mx = mmax(curr, prev_mx);
 	}
 	cout<<sum;
    return 0;
}