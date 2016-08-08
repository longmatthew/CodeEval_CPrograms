
#include <stdio.h>
#include <stdlib.h>

typedef enum BOOLEAN
{
	FALSE, TRUE
}BOOLEAN;

BOOLEAN isprime(int num);
BOOLEAN ispalindome(int num);

int main(int argc, char *argv[])
{
	int i, store;

	for (i = 2; i < 1000; i++)
	{
		if (isprime(i) && ispalindome(i))
		{
			store = i;
		}
	}

	printf("%d\n", store);

	return 0;
}

BOOLEAN isprime(int num)
{
	int i = 0;

	if (num <= 1)
	{
		return FALSE;
	}
	else if (num <= 3)
	{
		return TRUE;
	}
	else if ((num % 2) == 0 || (num % 3) == 0)
	{
		return FALSE;
	}

	for (i = 5; i*i <= num; i+= 6)
	{
		if ((num % i) == 0 || (num % (i + 2) == 0))
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOLEAN ispalindome(int num)
{
	int check = num, rev = 0, dig = 0;

	while (num > 0)
	{
		dig = num % 10;
		rev = (rev * 10) + dig;
		num = num / 10;
	}

	if (check != rev)
	{
		return FALSE;
	}

	return TRUE;
}
