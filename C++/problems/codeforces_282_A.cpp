#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n, res=0; cin>>n;
 	while(n--){
 		string s; cin>>s;
 		bool inc=false, dec=false;
 		for(char c : s) 
 			{
 				if(c=='+') inc=1;
 				else if(c=='-') dec=1;
 				else continue;
 				break;
 			}
 		if(inc) res++;
 		else res--;
 	}   
 	cout<<res;
    return 0;
}