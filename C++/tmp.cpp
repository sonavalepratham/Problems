#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s="([{}])([{}]){}";
   stack<char> st;
   st.push('*');
   for(int i=0; i<s.size(); i++){
   	char tmp_c=st.top();
   	if(s[i]=='(' or s[i]=='[' or s[i]=='{'){
   		st.push(s[i]);
   	}
   	else if((tmp_c=='(' and s[i]==')') or (tmp_c=='[' and s[i]==']') or (tmp_c=='{' and s[i]=='}'))
   	{
   		st.pop();
   	}
   	else st.push(s[i]);
   }
   if(st.top()=='*'){
   	cout<<"balanced";
   }
   else cout<<"inbalanced";
   
   return 0;
}