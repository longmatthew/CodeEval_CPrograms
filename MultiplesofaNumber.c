#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1024

int main(int argc, char *argv[])
{
	FILE *infile;
	char *temp, line[LINE_SIZE];
	infile = fopen(argv[1], "r");
	int mul = 0, comp = 0, total, i = 2;

	if (!infile)
	{
		printf("Unable to open file\n");
		exit(1);
	}

	while (fgets(line, sizeof(line), infile))
	{
		if (line[strlen(line)] == '\n')
		{
			line[strlen(line)] = '\0';
		}
		else
		{
			line[strlen(line) - 1] = '\0';
		}

		temp = strtok(line, ",");
		while (temp)
		{
			total = mul = atoi(temp);
			temp = strtok(NULL, ",");
		}
		comp = atoi(line);

		while (comp > total)
		{
			total = mul * i;
			i++;
		}

		printf("%d\n", total);
		i = 2;
	}

	fclose(infile);
	return 0;
}
