#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
int pow(int a, int n){
	if(n==0) return 1;
	if(n==1) return a;
	long long tmp = pow(a, n/2)%P;
	if(n&1) return (((tmp*tmp)%P)*a)%P;
	return (tmp*tmp)%P;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    cout<<pow(2, n);
    return 0;
}