#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1024

typedef struct Node
{
	int data;
	struct Node *pNext;
}Node;

Node *pList;

void push(int num);
int pop(void);
Node *makeNode(int num);

int main(int argc, char *argv[])
{
	FILE *infile;
	char *temp, line[1024];
	int num = 0;

	infile = fopen(argv[1], "r");

	if (!infile)
	{
		printf("Unable to open file\n");
		exit(1);
	}

	while (fgets(line, LINE_SIZE, infile))
	{
		temp = strtok(line, " ");
		while (temp)
		{
			num = atoi(temp);
			push(num);
			temp = strtok(NULL, " ");
		}

		while (pList != NULL)
		{
			printf("%d ", pop());
			pop();
		}

		printf("\n");
	}

	return 0;
}

Node *makeNode(int num)
{
	Node *pTemp;

	pTemp = (Node *)malloc(sizeof(Node));

	if (!pTemp)
	{
		printf("Unable to allocate memory\n");
		return NULL;
	}
	else
	{
		pTemp->data = num;
		pTemp->pNext = NULL;
	}

	return pTemp;
}

void push(int num)
{
	Node *pTemp = makeNode(num);

	if (!pTemp)
	{
		printf("Unable to create node\n");
	}
	else
	{
		pTemp->pNext = pList;
		pList = pTemp;
	}

	return;
}

int pop(void)
{
	Node *pTemp = pList;
	int hold = 0;

	if (pTemp)
	{
		hold = pTemp->data;
		pList = pTemp->pNext;
		free(pTemp);
	}

	return hold;
}
