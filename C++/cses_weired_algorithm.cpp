#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n; cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2){
            n=n*3+1;
        }
        else n=n/2;
    }
    cout<<1;
    return 0;
}