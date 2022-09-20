#include <bits/stdc++.h>
using namespace std;

bool soln(){
    long long N, D, C, M, cnt=0; cin>>N>>D>>C>>M;
    string s; cin>>s;
    for(int i=0; i<s.size(); i++) if(s[i]=='D') cnt++;
    if((cnt==0) or (cnt==s.size() and D>=cnt)) return 1;
    else if(cnt==s.size() and D<cnt) return 0;
    long long tmpcnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='C' and C>0) C--;
        else if(s[i]=='D' and D>0){
            tmpcnt++;
            D--;
            C+=M;
        }
        else break;
    }
    if(tmpcnt==cnt)
    return 1;
    return 0;
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    int cnt=1;
    while(t--){
    	long long res=soln();
        if(res)
    	cout<<"Case #"<<cnt++<<": "<<"YES"<<"\n";
    else cout<<"Case #"<<cnt++<<": "<<"NO"<<"\n";
    }
    return 0;
}