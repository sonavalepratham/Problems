#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n, rem=0; cin>>n;
 	int res = n/5;
 	rem=n%5;
 	res+=rem/4;
 	rem=rem%4;
 	res+=rem/3;
 	rem=rem%3;
 	res+=rem/2;
 	rem=rem%2;
 	res+=rem;
 	cout<<res; 
    return 0;
}