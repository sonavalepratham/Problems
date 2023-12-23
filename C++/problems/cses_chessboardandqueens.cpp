#include <bits/stdc++.h>
using namespace std;
int res=0;

bool canplace(vector<vector<char>> &grid, int r, int c)
{
	int i, j;
	if(grid[r][c]=='*' or grid[r][c]=='P')
	return false;
	for(i=r; i>=0; i--){
		if(grid[i][c]=='P') return false;
	}
	for(j=c; j>=0; j--){
	if(grid[r][j]=='P') return false;}

	for(i=r,j=c; i>=0 && j>=0; i--, j--){
		if(grid[i][j]=='P') return false;
	}

	for(i=r, j=c; i>=0 && j<8; i--, j++){
		if(grid[i][j]=='P') return false;
	}

	return true;
}
void fun(vector<vector<char>> &grid, int r, int cnt){
	if(cnt==8){
		res++; return;
	}
	if(r>=8) return;
	for(int i=0; i<8; i++){
		if(canplace(grid, r, i)){
			grid[r][i] = 'P';
			fun(grid, r+1, cnt+1);
			grid[r][i]='.';
		}
	}
}
int main()
{
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> grid(8, vector<char>(8));
    for(int i=0; i<8; i++)
    	for(int j=0; j<8; j++) cin>>grid[i][j];

    fun(grid, 0, 0);
	cout<<res;
    return 0;
}