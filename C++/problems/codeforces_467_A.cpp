#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n, cnt=0; cin>>n;
 	for(int i=0; i<n; i++){
 		int p, q; cin>>p>>q;
 		if(q-p>=2) cnt++;
 	}   
 	cout<<cnt;
    return 0;
}