#include "main.h"

/**
 * factorial - Returns the factorial of a given number i.e 5!
 * @n: the number to be calculated
 * Return: -1 if there's an error, or the factorial result
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	} else if (n <= 1)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
