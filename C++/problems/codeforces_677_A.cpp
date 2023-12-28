#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n, h, res=0; cin>>n>>h;
 	for(int i=0; i<n; i++){
 		int tmp; cin>>tmp;
 		if(tmp>h) res+=2;
 		else res+=1;
 	}   
 	cout<<res;
    return 0;
}