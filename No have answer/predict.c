#include <stdio.h>

int main()
{
	double a = 14.1;
	double b = 15.1;

	printf("%s: %f, %f\n", a == --b ? "Hello" : "World", a, b);

	a = 15.1;
	b = 16.1;

	printf("%s: %f, %f\n", a == --b ? "Hello" : "World", a, b);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//예시답안
//Hello: 14.100000, 14.100000
//World: 15.100000, 15.100000
