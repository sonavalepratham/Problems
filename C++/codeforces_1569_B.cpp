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
    	vector<vector<int>> arr(n, vector<int>(n, 0));
    	vector<bool> sat(n, 0);
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			if(s[i]='1' and s[j]=='1'){
    				arr[i][j]=0;
    			}
    			else if(s[i]=='1'){
    				arr[i][j]=-1;
    			}
    			else if(s[j]=='1'){
    				arr[i][j]=1;
    			}
    			else {
    				if(sat[i]){
    					arr[i][j]=1;
    					sat[j]=1;
    				}
    				else{
    					arr[i][j]=-1;
    					sat[i]=1;
    				}
    			}
    		}
    	}
    	bool flg=1;
    	for(int i=0; i<n; i++){
    		if(s[i]=='2' and (!sat[i])){
    			flg=0;
    			break;
    		}
    	}
    	if(flg) cout<<"YES\n";
    	else cout<<"NO\n";
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			if(i==j) cout<<"X";
    			else if(arr[i][j]==-1) cout<<"+";
    			else if(arr[i][j]==0) cout<<"=";
    			else if(arr[i][j]==1) cout<<"-";
    		}
    		cout<<"\n";
    	}
    }
    return 0;
}