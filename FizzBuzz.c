#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *infile = fopen(argv[1], "r");

	char line[1024];

	while ((fgets(line, 1024, infile) != NULL))
	{
		line[strlen(line)] = '\0';
		char *temp = (char *)malloc(sizeof(char) *strlen(line) + 1);
		strcpy(temp, line);

		char *str = strtok(temp, " ");
		int x = atoi(str);

		str = strtok(NULL, " ");
		int y = atoi(str);

		str = strtok(NULL, " ");
		int n = atoi(str);

		int i = 0;
		for (i = 1; i <= n; i++)
		{
			if (((i % x) == 0) && ((i % y) == 0))
			{
				printf("FB ");
			}
			else if ((i % x) == 0)
			{
				printf("F ");
			}
			else if ((i % y) == 0)
			{
				printf("B ");
			}
			else
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}

	return 0;
}
