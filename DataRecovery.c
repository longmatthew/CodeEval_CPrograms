#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE 1024

int main(int argc, char *argv[])
{
	FILE *infile;
	char line[LINE_SIZE], *temp = NULL, **arr = NULL, **newarr = NULL;
	int i = 0, words = 0, num = 0;

	infile = fopen(argv[1], "r");

	if (!infile)
	{
		fprintf(stderr, "Unable to open file:");
		exit(1);
	}

	while (fgets(line, 1024, infile))
	{
		i = words = 0;
		if (line[strlen(line) - 1] == '\n')
		{
			line[strlen(line) - 1] = '\0';
		}
		else
		{
			line[strlen(line)] = '\0';
		}

		while (line[i++] != ';')
		{
			if (isspace(line[i]))
			{
				words++;
			}
		}
		words++;

		arr = (char **)malloc((words) * sizeof(char*));
		for (i = 0; i < words; i++)
		{
			arr[i] = (char *)malloc(sizeof(char) * 1);
			arr[i] = '\0';
		}

		i = 0;
		temp = strtok(line, " ;");
		arr[i] = (char *)malloc(sizeof(char) * (strlen(temp)));
		strcpy(arr[i], temp);
		i++;

		// Store words in array.
		while (temp && (i < words))
		{
			temp = strtok(NULL, " ;");
			arr[i] = (char *)malloc(sizeof(char) * (strlen(temp)));
			strcpy(arr[i], temp);
			i++;
		}

		i = 0;
		newarr = (char **)malloc((words)* sizeof(char*));
		for (i = 0; i < words; i++)
		{
			newarr[i] = (char *)malloc(sizeof(char) * 1);
			newarr[i] = '\0';
		}

		i = 0;
		temp = strtok(NULL, " ");
		while (temp)
		{
			num = atoi(temp);
			newarr[num - 1] = (char *)malloc(sizeof(char) * (strlen(arr[i])));
			strcpy(newarr[num - 1], arr[i]);
			temp = strtok(NULL, " ");
			i++;
		}

		i = 0;
		while (newarr[i]){
			i++;
		}

		newarr[i] = (char *)malloc(sizeof(char) * (strlen(arr[words - 1])));
		strcpy(newarr[i], arr[words - 1]);
		
		for (i = 0; i < words; i++)
		{
			printf("%s ", newarr[i]);
		}
		printf("\n");
	}

	free(arr);
	free(newarr);

	fclose(infile);
	return 0;
}
