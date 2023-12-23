#include <bits/stdc++.h>
using namespace std;
int N=1e6;
int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    int t=rand()%1000;
    cout<<t<<"\n";
    while(t--){
    	int n, m;
    	
    	string s;
    	for(char c='a'; c<='z'; c++){
    		s+=(char)(rand()%26+'a');
    		for(int i=0; i<rand()%10000; i++){
    			s+=(char)(rand()%26+'a');
    		}
    		s+=c;
    	}
    	s=s+s;
    	n=s.size(), m=190+rand()%26;
    	cout<<n<<" "<<m<<"\n";
    	cout<<s<<"\n";
    }
    return 0;
}