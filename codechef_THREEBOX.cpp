#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int a[3], d;
    	cin>>a[0]>>a[1]>>a[2]>>d;
    	sort(a, a+3);
    	int res=1, rl=d-a[0];
    	if(rl>=a[1]) rl=rl-a[1];
    	else {res++; rl=d-a[1];}
    	if(rl>=a[2]) rl=rl-a[2];
    	else {res++; rl=d-a[2];}
    	cout<<res<<"\n";
    }
    return 0;
}