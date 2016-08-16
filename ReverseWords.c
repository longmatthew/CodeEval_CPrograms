#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1024

typedef struct Node
{
	char *data;
	struct Node *pNext;
}Node;

Node *pList;

Node *makeNode(char *temp);
void push(char *temp);
void pop(void);

int main(int argc, char *argv[])
{
	FILE *infile;
	char *temp, line[LINE_SIZE];

	infile = fopen(argv[1], "r");

	if (!infile)
	{
		printf("Unable to open file\n");
		exit(1);
	}

	while (fgets(line, sizeof(line), infile))
	{
		if (line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		else
		{
			line[strlen(line)] = '\0';
		}
		temp = strtok(line, " ");
		while (temp)
		{
			push(temp);
			temp = strtok(NULL, " ");
		}

		pop();
		printf("\n");
	}

	fclose(infile);
	return 0;
}

Node *makeNode(char *temp)
{
	Node *pTemp;

	pTemp = (Node *)malloc(sizeof(Node));

	if (!pTemp)
	{
		printf("Unable to create node\n");
		return NULL;
	}
	else
	{
		pTemp->data = (char *)malloc(sizeof(char) * strlen(temp));
		if (!pTemp->data)
		{
			printf("Unable to create memory in node\n");
			return NULL;
		}

		strcpy(pTemp->data, temp);
		pTemp->pNext = NULL;
	}

	return pTemp;
}

void push(char *temp)
{
	Node *pTemp = makeNode(temp);

	if (pTemp != NULL)
	{
		pTemp->pNext = pList;
		pList = pTemp;
	}
	else
	{
		printf("Exiting...\n");
	}

	return;
}

void pop(void)
{
	Node *pTemp;
	while (pList != NULL)
	{
		pTemp = pList;
		pList = pTemp->pNext;
		printf("%s ", pTemp->data);
		free(pTemp);
	}

	return;
}
