#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, res=1; cin>>n;
    string prev; cin>>prev;
    for(int i=1; i<n; i++){
    	string curr; cin>>curr;
    	if(prev[prev.size()-1]==curr[0]) res++;
    	prev=curr;
    }
    cout<<res;
    return 0;
}