#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
 	string s; cin>>s;
 	int a=0, d=0;
 	for(char c : s){
 		if(c=='D') d++;
 		else a++;
 	}   
 	if(a>d) cout<<"Anton";
 	else if(d>a) cout<<"Danik";
 	else cout<<"Friendship";
    return 0;
}