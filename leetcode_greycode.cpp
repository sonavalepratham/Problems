#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
 	for(int i=0; i<(1<<n); i++) cout<< (i^(i>>1)) <<" ";   
    return 0;
}