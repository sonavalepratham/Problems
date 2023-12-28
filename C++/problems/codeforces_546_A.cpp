#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int k, n, w; cin>>k>>n>>w;
 	if(w*k*(w+1)/2 > n)
 		cout<<w*k*(w+1)/2-n;   
 	else cout <<0;
    return 0;
}