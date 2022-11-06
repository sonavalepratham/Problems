#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    unordered_map<char, int> mp;
    for(auto it : s) mp[it]++;
    int oc=0, cnt=0;
    char c;
	for(auto it : mp) if(it.second &1) oc++, c=it.first, cnt=it.second;
	if(oc>1 or (s.size()%2==1 and oc!=1)) cout<<"NO SOLUTION";
	else{
		deque<char> q;
        while(cnt-->0) q.push_front(c);
        mp[c]=0;
        for(auto it : mp){
            while(mp[it.first]){
                q.push_back(it.first);
                q.push_front(it.first);
                mp[it.first]-=2;
            }
        }
        while(q.size()){ cout<<q.front(); q.pop_front();}
	}
    return 0;
}