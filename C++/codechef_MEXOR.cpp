#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, i; cin>>n;
    	for(i=0; i<31; i++){
    		if(((int)pow(2, i)-1)>n) break;
    	}
    	cout<<(int)pow(2, i-1)<<"\n";
    }
    return 0;
}