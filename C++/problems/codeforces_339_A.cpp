#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s; cin>>s;
 	string out;
 	vector<int> hash(10, 0);
 	for(int i=0; i<s.size(); i++){
 		if(s[i]!='+'){
 			hash[s[i]-'1']++;
 		}
 	}

 	for(int i=0; i<10; i++){
 		while(hash[i]>0){
 			out+=(char)(i+'1');
 			out+="+";
 			hash[i]--;
 		}
 	} 
 	out[out.size()-1]='\n';
 	cout<<out;
    return 0;
}