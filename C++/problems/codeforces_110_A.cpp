#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n; cin>>n;
 	int tmp=n, lucky=0;
 	bool flg=true;
 	while(tmp){
 		if(tmp%10==7 || tmp%10==4) lucky++;
 		tmp/=10;
 	}  
 	if(lucky==4 || lucky==7)
 	cout<<"YES";
 	else cout<<"NO"; 
    return 0;
}