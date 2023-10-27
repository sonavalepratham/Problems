#include <bits/stdc++.h>
using namespace std;
int res=0;

vector<vector<bool>> grid(7, vector<bool>(7, 0));


void fun(string &s, int i=0, int j=0, int curr=0)
{
	if(i==6 && j==0)
		res++;
	if(i<0 or i>6 or j<0 or j>6 or curr>47 or grid[i][j])
		return;
	grid[i][j]=1;
	
	for(int itr=curr; itr<48; itr++){
		if(s[itr]=='?'){
			fun(s,i-1, j, itr+1);
			fun(s, i+1, j, itr+1);
			fun(s, i, j-1, itr+1);
			fun(s, i, j+1, itr+1);
		}/*
		else if(s[itr]=='L') fun(s, i, j-1, itr+1);
		else if(s[itr]=='R') fun(s, i, j+1, itr+1);
		else if(s[itr]=='U') fun(s, i-1, j, itr+1);
		else if(s[itr]=='D') fun(s, i+1, j, itr+1);*/
	}
	cout<<i<<" "<<j<<"\n";
	grid[i][j]=0;
}


int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	string s; cin>>s;
 	fun(s);
 	cout<<res;
    return 0;
}