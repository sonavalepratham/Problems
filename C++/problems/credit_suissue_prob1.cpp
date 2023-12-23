using namespace std;
#include <string>
#include <iostream>

int solution(long long n){
    // code here
    if((n%2==0) and (n/3)%2==0){
    	if((n/3)+((n/2)-(n/6))*2!=n){ cout<<(n/3)<<" "<<(n/2)-(n/6)<<" "<<n<<"\n"; return -1;}
    	return (n/3)+(n/2)-(n/6);
    }
    else{
    	if((n/3)*2+(n-(n/3)*2)!=n) {cout<<(n/3)<<" "<<(n-(n/3)*2)<<" "<<n<<"\n"; return -1;}
    	return (n/3)+(n-(n/3)*2);
    }
}

/*  Do not edit below code */
int main() {
	long long n;
	cin >> n;
    long long answer=solution(n);
	cout << answer << endl;	
}

/*
Bank and its Cashier
A customer comes to withdraw money from a bank. Unfortunately, that day the bank only has two types of currency notes to give: 1 unit and 2 unit. The manager, being amused by the incident, tried to have some fun and decided to create a challenge for the cashier team. She asked the team to minimize the difference between the number of the two types of currency notes. The manager also asked you to give her your solution. You decided to use computational power.What would be your solution?

Constraints
Only 1 and 2 unit currency notes are used.
0 <= input integer < 109
Input Format
Integer (possibly very large): Amount customer wants to withdraw

Output Format
Single integer: Total number of notes
Do not print Debug Statements while submitting the solution.

Examples
Input            |   Output [num1+num2]
1000             |   667           Explanation : 1*334 + 2*333 = 1000
1                |   1
32               |   21
*/