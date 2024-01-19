#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    for(int i=1; i<=n; i++){
    	cout<<(i*i*(i*i-1))/2-4*(i-1)*(i-2)<<"\n";
    }
    return 0;
}