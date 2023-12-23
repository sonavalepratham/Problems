#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    string s; char d; 
	    cin>>s>>d;
	    int fp=s.size();
	    for(int i=0; i<s.size(); i++){
	        if(s[i]==d){
	            fp=i;
	            break; 
	        }
	    }
	    if(fp==s.size()){
	            cout<<"0\n";
	            continue;
	   }
	        if(d=='0'){
	            string tmp=s;
	            tmp[fp]='1';
	            for(int i=fp+1; i<tmp.size(); i++){
	                 tmp[i]='1'; 
	            }
	            cout<<stoll(tmp)-stoll(s)<<"\n";
	        }
	        else if(d=='9'){
	            string tmp=s;
	            int oc=-1;
	            bool flg=0;
	            if(fp==0){
	                tmp='1'+tmp;
	            }
	            else{
	                for(int i=fp-1; i>=0; i--){
	                    if(tmp[i]<='7'){ flg=1; fp=oc=i; tmp[i]++; break;}
	                }
	                if(!flg) tmp='1'+tmp;
	            }
	            if(flg){
	                for(int i=fp+1; i<tmp.size(); i++){
	                    tmp[i]='0';
	                }
	            }
	            else{
	                for(int i=1; i<tmp.size(); i++) tmp[i]='0';
	            }
	            cout<<stoll(tmp)-stoll(s)<<"\n";
	        }
	        else{
	            string tmp=s;
	            bool flg=0;
	            for(int i=0; i<tmp.size(); i++){
	                if(tmp[i]==d and (!flg)){ tmp[i]++; flg=1;}
	                else if(flg) tmp[i]='0';
	            }
	            cout<<stoll(tmp)-stoll(s)<<"\n";
	        }
	}
	return 0;
}
