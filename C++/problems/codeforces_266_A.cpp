#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, res=0; cin>>n;
    string s; cin>>s;
    int consecutive=1;
    char last=s[0];
    for(int i=1; i<n; i++){
    	if(s[i]==last){
    		consecutive++;
    	}
    	else{
    		last=s[i];
    		res+=consecutive-1;
    		consecutive=1;
        	}
    }
    res+=consecutive-1;
    cout<<res;
    return 0;
}