#include <bits/stdc++.h>
using namespace std;

int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mtrx[5][5], res=0;
    for(int i=0; i<5; i++)
    	for(int j=0; j<5; j++) cin>>mtrx[i][j];

 	for(int i=0; i<5; i++)
 	for(int j=0; j<5; j++)
 		if(mtrx[i][j]==1){
 			res=abs(2-i)+abs(2-j);
 			break;
 		}   
 		cout<<res;
    return 0;
}