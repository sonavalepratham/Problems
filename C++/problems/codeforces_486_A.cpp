#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
  	int t=n/2;
    cout<<t*(t+1)-(t*t)-(n&1?n:0);
    return 0;
}