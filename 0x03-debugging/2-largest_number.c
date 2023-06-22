#include "main.h"

/**
 * largest_number - Prints the largest of three numbers
 * @a: Parameter
 * @b: Parameter
 * @c: Parameter
 * Return: the largest number
 */

int largest_number(int a, int b, int c)
{
	int largest;

	if (a >= b && a >= c)
	{
		largest = a;
	}
	else if (b >= a && b >= c)
	{
		largest = b;
	}
	else
	{
		largest = c;
	}

	return (largest);
}
