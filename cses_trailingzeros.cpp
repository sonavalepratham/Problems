#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, ans=0; cin>>n;
    for(long long i=5; n/i>0; i*=5) ans+=n/i;
    	cout<<ans;
    return 0;
}