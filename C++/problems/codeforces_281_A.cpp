#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    if(s[0]>='a' && s[0]<='z') s[0]=(char)(s[0]-'a'+'A');
    cout<<s;
    return 0;
}