#include "function.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number tio be calculated
 * Return: the factorial
 */

int factorial(int n)
{
	if (n <= 1)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
