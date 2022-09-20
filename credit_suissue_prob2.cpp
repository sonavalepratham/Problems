#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z,int security_value[])
{
    int no_of_stocks=0;
   // participants code here
 	int remaining=z, i=0;
 	vector<pair<int, int>> v;
 	int n=sizeof(security_value)/sizeof(security_value[0]);
 	for(i=0; i<n; i++) v.push_back({security_value[i], i+1});
 	sort(v.begin(), v.end());
 	i=0;
 	while(remaining>0 and i<n){
 		if(min(v[i].second, remaining/v[i].first)<=remaining){
 		no_of_stocks+=min(v[i].second, remaining/v[i].first);
 		remaining-=min(v[i].second, remaining/v[i].first)*v[i].first;
 	}
 		i++;
 	}
    return no_of_stocks;
}
 
int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z,security_value);
cout << no_of_stocks_purchased;
 
 
 
}
/*
Securities buying
Harry has just started investing in stock markets. There are a variety of securities that he can buy, but he is a bit confused about buying the securities because he has a limited amount of money. The prices of the various securities are given for N days and security_value[k] denotes the price of the security on the kth day. There is one more rule, Harry can buy at most k number of securities on the kth day. As mentioned earlier, Harry has a limited amount of money with him to buy these securities and this amount is denoted by z. Can you guide Harry in finding the maximum number of securities that he can buy?

Constraints:
All the security prices given in the security_value array are positive integers.

Input Format:
The first line contains an integer z denoting the limited amount which Harry has with him.
The second line contains an array named security_value consisting of the prices of various securities on N different days.
Output Format:
An integer denoting maximum number of securities which Harry can buy with that limited amount(which is denoted by z).
Do not print Debug Statements while submitting the solution.

Examples:
Example 1:
Input:

45
10 7 19
Output:

4
Explanation:

Harry can buy: 
1 security of $10 + 2 securities of $7 + 1 security of $19, which would cost him $43 in total. And $43 < $45(z value).
Hence total no. of securities he can purchase = 4
Example 2:
Input:

64
17 24 7 45 15 14 37 40 8 23 27 17
Output:

8
*/