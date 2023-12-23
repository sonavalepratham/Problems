#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    int cnt=1;
    while(t--){
    	int n; cin>>n;
    	int res=0, ls=-1, rs=-1;
    	string s; cin>>s;
    	int arr1[n], arr2[n];
    	for(int i=0, j=n-1; i<n; i++, j--){
    		if(s[i]=='1') ls=i;
    		if(s[j]=='1') rs=j;
    		arr1[i]=ls; arr2[j]=rs;
    	}
    	for(int i=0; i<n; i++){
    		if(arr1[i]!=-1 and arr2[i]!=-1){
    			res+=min(abs(arr1[i]-i), abs(arr2[i]-i));
    		}
    		else if(arr1[i]!=-1){
    			res+=abs(arr1[i]-i);
    		}
    		else res+=abs(arr2[i]-i);
    	}
    	cout<<"Case #"<<cnt++<<": "<<res<<"\n";
    }
    return 0;
}