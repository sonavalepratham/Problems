#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n, k; cin>>n>>k;
 	while(k>0) {
 		if(n%10==0){
 			n=n/10; k--;
 		}
 		else{
 			int tmp = n%10;
 			if(k>tmp){ k-=tmp; n=(n/10)*10; }
 			else {
 				tmp-=k;
 				k=0;
 				n=(n/10)*10+tmp;
 			}
 		}
 	} 
 	cout<<n; 
    return 0;
}