#include <stdio.h>

/**
 * flip_bits - Calculates the number of bits to flip to get from n to m
 * @n: The first unsigned long integer
 * @m: The second unsigned long integer
 * Return: The number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
