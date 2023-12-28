#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, cnt=0; cin>>n;
    for(int i=0; i<n; i++){
    	int a, b, c; cin>>a>>b>>c;
    	if(a+b+c>=2) cnt++;
    }
    cout<<cnt;
    return 0;
}