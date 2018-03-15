#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<ctype.h>

int read_line(char str[], int n) {
	int ch, i = 0;
	while (isspace(ch = getchar()))
		;
	while (ch != '\n'&&ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

void main() {
	char *strFile= (char*)malloc(100 * sizeof(char));
	memset(strFile, 0, 100 * sizeof(char));
	read_line(strFile, 100);

	FILE* fp = fopen(strFile, "wt");
	printf("\n______******Welcome to use central file control system******______\n\n");
	if (!fp) {
		printf("Error: can not open file %s!\n", strFile); 
			return;
	}
	printf("Please input a string: \n\n"); 
		char ch = getchar();
	while (ch != '\n'){
			fputc(ch, fp);
	ch = getchar();
}

fclose(fp);

}