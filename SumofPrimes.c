#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef enum BOOLEAN
{
	FALSE, TRUE
}BOOLEAN;

BOOLEAN isprime(int num);

int main(int argc, char *argv[])
{
	BOOLEAN prime = FALSE;
	int sum = 0, i = 1, count = 0;

	while (count < 1000)
	{
		prime = isprime(i);
		if (prime == TRUE)
		{
			sum += i;
			count++;
		}
		i++;
	}

	printf("%d\n", sum);

	return 0;
}

BOOLEAN isprime(int num)
{
	int i;

	if (num <= 1)
	{
		return FALSE;
	}
	else if (num <= 3)
	{
		return TRUE;
	}
	else if (((num % 2) == 0) || ((num % 3) == 0))
	{
		return FALSE;
	}

	for (i = 5; i*i <= num; i += 6)
	{
		if (((num % i) == 0) || ((num % (i + 2)) == 0))
		{
			return FALSE;
		}
	}

	return TRUE;
}
