#include <stdio.h>
#include "main.h"

/**
 * print_binary - it prints out the binary representation of a number
 * @n: the denary number
 * Return: 0
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = (unsigned long int)1 << (sizeof(unsigned long int) * 8 - 1);
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}

	while (mask >= 1)
	{

		if (n & mask)
		{
			_putchar('1');
			count = 1;
		} else if (count || mask == 1)
		{
			_putchar('0');
		}

		mask = mask >> 1;
	}

	_putchar('\n');
}
