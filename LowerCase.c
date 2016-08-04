#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINE_SIZE 1024

int main(int argc, char *argv[])
{
	FILE *infile;
	int i;
	char line[LINE_SIZE];

	infile = fopen(argv[1], "r");

	if (!infile)
	{
		printf("Unable to open file\n");
		return 0;
	}

	while (fgets(line, LINE_SIZE, infile))
	{
		line[strlen(line)] = '\0';

		i = 0;
		while (line[i] != '\0')
		{
			if (isupper(line[i]))
			{
				printf("%c", tolower(line[i]));
			}
			else
			{
				printf("%c", line[i]);
			}
			i++;
		}
	}

	printf("\n");
	return 0;
}
