#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	if (s1.size()>s2.size()){
		cout<<"No"; return 0;
	}
	map<char,int> m;
	for(int i=0; i<s1.size(); i++)
		m[s1[i]]++;
	map<char,int> m1=m;
	int cnt=0;
	for(int i=0; i<s1.size(); i++)
		if(m[s2[i]]) {
			cnt++;
			m[s2[i]]--;
		}
	if(cnt==s1.size()){
		cout<<"Yes"; return 0;
	}
	for(int i=1; i<s2.size()-s1.size()+1; i++){
		if(m1[s2[i-1]]) {
			cnt--;
			m[s2[i-1]]++;
		}
		if(m[s2[i+s1.size()-1]]){
			cnt++;
			m[s2[i+s1.size()-1]]--;
		}
		if(cnt==s1.size()){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}