#include <stdio.h>
#include "function.h"

/**
 * main - check the code
 * Return: 0
 */



int main(void)
{
	int num = 9;
	int fct = factorial(num);

	printf("The factorial of %d is %d\n", num, fct);
	return (0);
}
