#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, curr=0, ans=0; cin>>n;
    while(n--){
    	int a, b; cin>>a>>b;
    	curr+=b-a;
    	ans=max(ans, curr);
    }
    cout<<ans;
    return 0;
}