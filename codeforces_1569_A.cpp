#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
 
    while(t--){
    	int n; cin>>n;
    	string s; cin>>s;
    	vector<int>cnta(n, 0), cntb(n, 0);
    	for(int i=0; i<n; i++){
    		if(s[i]=='a') cnta[i]++;
    		else cntb[i]++;
    	}
    	bool flg=0;
    	for(int i=1; i<n; i++){
    		cnta[i]+=cnta[i-1];
    		cntb[i]+=cntb[i-1];
    	}
    	
    	// for(int i=0; i<n; i++){
    	// 	cout<<cnta[i]<<" "<<cntb[i]<<"\n";
    	// }
    	// cout<<"\n";
    	for(int i=0; i<n; i++){
    		for(int j=i; j<n; j++){
    			if(i==0){
    				if(cnta[j]==cntb[j]){
    					flg=1;
    				cout<<i+1<<" "<<j+1<<"\n";
    				break;
    				}
    			}
    			else if((cnta[j]-cnta[i-1])==(cntb[j]-cntb[i-1])){
    				flg=1;
    				cout<<i+1<<" "<<j+1<<"\n";
    				break;
    			}
    		}
    		if(flg) break;
    	}
    	if(!flg)
    	cout<<-1<<" "<<-1<<"\n";
    }
    return 0;
}