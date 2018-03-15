#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include"READ.h"

#define NAME_LEN 250

struct part {
	char name[NAME_LEN+1];
	int number;
	int age, aver;
	struct part *next;
};

struct part *student=NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {
	char code;
	printf("******______The User's Operation Guidence______******\n");
	printf("      	 i:insert   s:search   u:update   p:print   q:quit\n\n");
	for (;;) {
		printf("Enter your operation code:_____.\b\b\b\b");
		scanf(" %c", &code);
		while (getchar() != '\n');
		switch (code)
		{
		case'i':insert(); break;
		case's':search(); break;
		case'u':update(); break;
		case'p':print(); break;
		case'q':return 0;
		default:printf("Illegal code\n");
			
		}
		printf("\n");
	}
}

struct part *find_part(int number) {
	struct part *p;
	for (p = student; p != NULL&&number > p->number; p = p->next);
	if (p != NULL&&number == p->number)
		return p;
	return NULL;
}

void insert(void) {
	struct  part *cur,*prev, *new_node;
	new_node = (part*)malloc(sizeof(struct part));
	if (new_node == NULL) {
		printf("Database is full;cannont add more parts.\n");
		return;
	}

	printf("Enter student number:  ");
	scanf("%d", &new_node->number);

	for (cur = student, prev =NULL; cur != NULL&&new_node->number > cur->number; prev = cur, cur = cur->next);
	if (cur != NULL&&new_node->number == cur->number) {
		printf("Part already exists.\n");
		free(new_node);
		return;
	}

	printf("Enter student name:  ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter the student's average score:  ");
	scanf("%d", &new_node->aver);
	printf("Enter the student's age:  ");
	scanf("%d", &new_node->age);
	new_node->next = cur;
	if (prev == NULL)
		student = new_node;
	else
		prev->next = new_node;
}

void search(void) {
	int number;
	struct part*p;
	printf("Enter part number:   ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Student name: %s\n", p->name);
		printf("Student average score: %d\n", p->aver);
		printf("Student age:  %d\n", p->age);
	}
	else
		printf("Student not found 404.\n");
}

void update(void)
{
	int number, change,change2;
	struct part*p;
	printf("Enter part number:  ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Enter change in student's average score: ");
		scanf("%d", &change);
		printf("Enter change in student's age: ");
		scanf("%d", &change2);
		p->aver = change;
		p->age = change2;
	}
	else
		printf("Student not found 404.\n");
}

void print(void) {
	struct part*p;
	printf("Student number     Part Name        Average Score       Age   \n");
	for (p = student; p != NULL; p = p->next)
		printf("%7d            %-20s%6d %12d\n", p->number, p->name, p->aver,p->age);
}