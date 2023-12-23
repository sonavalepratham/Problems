#include<stdio.h>
#include<string.h>
int main(){

	char c[10];
	int i;
	scanf("%s", c);
	for(i=0; i<strlen(c)-i-1; i++){
		char tmp=c[i];
		c[i]=c[strlen(c)-i-1];
		c[strlen(c)-i-1]=tmp;
	}
	printf("%s", c);
	return 0;
}