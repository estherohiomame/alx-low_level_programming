#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 * @n: a parameter
 * Return: last digit in a number
 */

int print_last_digit(int n)
{
	int digit;

	if (n < 0)
		n = -n;

	digit = n % 10;

	if (digit < 0)
		digit = -digit;

	_putchar(digit + '0');

	return (digit);

}

