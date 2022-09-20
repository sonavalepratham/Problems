#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=325;
    while(n){
        cout<<n%6;
        n=n/6;
    }
    return 0;
}
