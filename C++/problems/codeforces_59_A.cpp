#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    int small =0, big=0;
    for(char c : s){
    	if(c>='a' && c<='z') 
    		small++;
    	else 
    		big++;
    }
    for(int i=0; i<s.size(); i++){
    	if((small>big || small==big) && s[i]>='A' && s[i]<='Z') s[i] = s[i]-'A'+'a';
    	else if(small<big && s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';

    }
    cout<<s;
    return 0;
}