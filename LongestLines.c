#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE 1024
#define TOT		  128

/*int getsize(char *linep)
{
	int i = 0, sizep = 0;

	while (linep[i] != '\0')
	{
		if (isalpha(linep[i]) || (linep[i] == ' '))
		{
			sizep++;
		}
		i++;
	}
	return sizep;
}*/

int main(int argc, char *argv[])
{
	FILE *infile;
	char line[TOT][LINE_SIZE], getnum[LINE_SIZE], temp[LINE_SIZE];
	int i = 0, j = 0, k = 0, num = 0;
	infile = fopen(argv[1], "r");

	if (infile == NULL)
	{
		printf("Unable to open file\n");
		return 0;
	}

	fgets(getnum, LINE_SIZE, infile);
	num = atoi(getnum);

	while (fgets(line[i], LINE_SIZE, infile))
	{
		if (line[i][strlen(line[i]) - 1] == '\n')
		{
			line[i][strlen(line[i]) - 1] = '\0';
		}
		else
		{
			line[i][strlen(line[i])] = '\0';
		}

		i++;
	}

	for (j = 1; j < i; j++)
	{
		k = j;
		while (k > 0 && (strlen(line[k - 1])) < (strlen(line[k])))
		{
			memcpy(temp, line[k], sizeof(line[k]));
			memcpy(line[k], line[k - 1], sizeof(line[k - 1]));
			memcpy(line[k - 1], temp, sizeof(temp));
			k--;
		}
	}

	for (j = 0; j < num; j++)
	{
		printf("%s\n", line[j]);
	}

	fclose(infile);
	return 0;
}
