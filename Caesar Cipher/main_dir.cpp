#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"READ_LINE.h"
#include"secret.h"

enum{SHORT=50,MIDDLE=100,LONG=200}m;


int main(void) {
	char ch=0;
	int a;
	printf("\n\t\t______******Welcome to use Caesar encryption technique******______\n\n");
	printf("Please choose what kind length of message you would like :\n");
	printf("\t\tA:Short message       B:Middle message      C:Long message\n");
	printf("Please enter your choice:___\b\b");
	scanf("%c", &ch);
	if (ch == 'A')
		m = SHORT;
	else if (ch == 'B')
		m = MIDDLE;
	else if (ch == 'C')
		m = LONG;
	else
	{
		printf("\nError:The code you input is illegal.Input space to quit the programme.\n");
		getchar();
		return 0;
	}
	char *line = new char[m];
	memset(line,0,m*sizeof(char));
	printf("\nPlease enter your message:");
	read_line(line, m);
	printf("\nPlease determine the offset:");
	scanf("%d", &a);
	secret_f(line, a, m);
	printf("\nHere is the result message:");
	printf("%s\n", line);
	
	return 0;
}
