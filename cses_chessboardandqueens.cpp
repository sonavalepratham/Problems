#include <bits/stdc++.h>
using namespace std;

#define int long long

bool canplace(int r, int c, vector<vector<char>> &arr){

	if(arr[r][c]!='.') return false;

	for(int i=r; i>=0; i--)
	if(arr[i][c]=='P') return false;

	for(int i=c; i>=0; i--)
	if(arr[r][i]=='P') return false;

	for(int i=r, j=c; i>=0 && j>=0; i--, j--)
	if(arr[i][j]=='P') return false;

	for(int i=r, j=c; i>=0 && j<8; i--, j++)
	if(arr[i][j]=='P') return false;
	//cout<<r<<" "<<c<<"}";
	return true;
}

void fun(vector<vector<char>> &grid, int r, int c, int&res, int cnt)
{
	if(cnt==8) res++;
	if(cnt>8 or r>7 or c>7) return;
	for(int i=r; i<8; i++){
		for(int j=c; j<8; j++){
			cout<<i<<" "<<j<<"}";
			if(canplace(i, j, grid)){
				char tmp='P';
				swap(grid[i][j], tmp);
				fun(grid, i+1, j+1, res, cnt+1);
				swap(grid[i][j], tmp);
			}
			fun(grid, i+1, j+1, res, cnt);
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> grid(8,vector<char>(8));
    for(int i=0; i<8; i++)
    for(int j=0; j<8; j++)
    cin>>grid[i][j];


	int res=0;
	fun(grid, 0, 0, res, 0);
	cout<<res;

    return 0;
}