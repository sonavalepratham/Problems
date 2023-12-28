#include <bits/stdc++.h>
using namespace std;

bool isDistinct(int i){
	vector<bool> hash(10, false);
	while(i){
		if(hash[i%10])
			return false;
		hash[i%10]=true;
		i/=10;
	}
	return true;
}

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n; cin>>n;
 	for(int i=n+1; i<=9999; i++)
 	if(isDistinct(i)){
 		cout<<i;
 		return 0;
 	}   
    return 0;
}