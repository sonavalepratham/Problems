#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n; cin>>n;
    	cout<<max(1+n-(1<<(int)log2(n)), (1<<(int)log2(n)-1))<<"\n";
    }
    return 0;
}