#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    int t=rand()%50;
    cout<<t<<"\n";
    while(t--){
    	int n=rand()%1000, m=rand()%n;
    	cout<<n<<" "<<m<<"\n";
    	for(int i=0; i<n; i++) cout<<rand()%100<<" ";
    	cout<<"\n";
    }
    return 0;
}