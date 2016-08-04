#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_SIZE 1024

int main(int argc, char *argv[])
{
	FILE *infile;
	char line[LINE_SIZE];
	int i, j, flag;

	infile = fopen(argv[1], "r");

	if (!infile)
	{
		printf("Unable to open file\n");
		return 0;
	}

	while (fgets(line, LINE_SIZE, infile))
	{
		i = j = flag = 0;
		while (line[i] != '\0')
		{
			if (isalpha(line[i]))
			{
				printf("%c", tolower(line[i]));
				i++; flag = 1;
			}

			if (!isalpha(line[i]))
			{
				if (flag != 0)
				{
					printf(" ");
				}

				while ((!isalpha(line[i])) && (line[i] != '\0'))
				{
					i++;
				}
			}
		}
		printf("\n");
	}

	return 0;
}
