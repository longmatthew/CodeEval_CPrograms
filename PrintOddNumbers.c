#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int oddnum = 0, i = 0;

	for (i = 1; i <= 50; i++)
	{
		oddnum = ((2 * i) - 1);
		printf("%d\n", oddnum);
	}

	return 0;
}
