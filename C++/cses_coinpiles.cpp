#include <iostream>
using namespace std;

bool fun(int a, int b){
    if(a>2*b or b>2*a) return 0;
    if((a+b)%3==0) return 1;
    return 0;
}

signed main()
{
    int t; cin>>t;
    while(t--){
        int a,b; cin>>a>>b;
        string res=fun(a,b)?"YES\n":"NO\n";
        cout<<res;
    }
    return 0;
}