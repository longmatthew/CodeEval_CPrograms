#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) 
{
	int oddnum = 0, i = 0;

	for (i = 1; i <= 50; i++)
	{
		oddnum = ((2 * i) - 1);
		cout << oddnum << endl;
	}

	return 0;
}