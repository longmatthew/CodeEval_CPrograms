#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
	struct stat st;
	// FILE *input;
	int size = 0;
	// int line;

	// input = fopen(argv[1], "r");

	stat(argv[1], &st);
	printf("%d\n", size = st.st_size);

	/*while (1)
	{
		line = fgetc(input);
		if (feof(input))
		{
			break;
		}
		size++;
	}*/

	//printf("%d\n", size);
	//fclose(input);

	return 0;
}
