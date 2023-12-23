#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
    	int n, ir; cin>>n>>ir;
    	vector<vector<int>> arr;
    	for(int i=0; i<n; i++){
    		int tmp; cin>>tmp;
    		arr.push_back({tmp, 0});
    	}
    	    	for(int i=0; i<n; i++){
    		int tmp; cin>>tmp;
    		arr[i][1]=tmp;
    	}
    	sort(arr.begin(), arr.end());
    	for(int i=0; i<n; i++){
    		if(ir<arr[i][0]) break;
    		else ir+=arr[i][1];
    	}
    	cout<<ir<<"\n";
    }
    return 0;
}