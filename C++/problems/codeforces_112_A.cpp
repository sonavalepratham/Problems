#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string a, b; cin>>a>>b;
 	int res=0;
 	for(int i=0; i<min(a.size(), b.size()); i++){
 		char ca = ('a'<=a[i] && a[i]<='z')?a[i]:(a[i]+'a'-'A');
 		char cb = ('a'<=b[i] && b[i]<='z')?b[i]:(b[i]+'a'-'A');
 		
 		if(ca<cb){
 			res=-1;
 			break;
 		}
 		else if(ca>cb){ res=1; break;}
 	}
 	cout<<res;
    return 0;
}