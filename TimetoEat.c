#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char line[1024];

	while (fgets(line, 1024, file) != NULL) 
	{
		int size = strlen(line) - 1;
		if (line[size] == '\n') { line[size] = '\0'; }

		char *strtemp = (char *)malloc(sizeof(char) *strlen(line) + 1);
		strcpy(strtemp, line);

		int x = 0, n = 0;
		while (line[x] != '\0')
		{
			if (isspace(line[x]))
			{
				n++;
			}
			x++;
		}
		n++;

		char **args = (char **)malloc(sizeof(char*) *n + 1);

		int p = 0;
		for (p = 0; p < n; p++)
		{
			if (p == 0)
			{
				char *str = strtok(strtemp, " ");
				args[p] = (char *)malloc(sizeof(char) * strlen(str) + 1);
				strcpy(args[p], str);
			}
			else
			{
				char *str = strtok(NULL, " ");
				args[p] = (char *)malloc(sizeof(char) * strlen(str) + 1);
				strcpy(args[p], str);
			}
		}

		args[n] = NULL;

		int i = 0, j = 0;

		for (i = 0; i < n; i++)
		{
			j = i;
			while (j > 0 && strcmp(args[j - 1], args[j]) < 0)
			{
				char *temp = args[j];
				args[j] = args[j - 1];
				args[j - 1] = temp;
				j--;
			}
		}

		int d = 0;
		while (args[d] != NULL)
		{
			printf("%s ", args[d]);
			d++;
		}
		printf("\n");
	}
	
	return 0;
}
