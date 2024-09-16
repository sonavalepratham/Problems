#include <bits/stdc++.h>
using namespace std;

vector<string> fun(int n){
	if(n<1) return {};
	if(n==1) return {"0", "1"};
	vector<string> res=fun(n-1), res2=res;
	for(int i=0; i<res.size(); i++) res[i]= '0'+res[i];
	for(int i=0; i<res2.size(); i++) res2[i]= '1'+res2[i];
	for(int i=res2.size()-1; i>=0; i--) res.push_back(res2[i]);
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n; cin>>n;
 	vector<string> res = fun(n);
 	for(auto it : res){
 		cout << it <<"\n";
 	}   
    return 0;
}