#include <stdio.h>

/**
 * get_bit - Retrieves the value of a bit at a given index
 * @n: The unsigned long integer
 * @index: The index of the bit to retrieve (0-based)
 * Return: The value of the bit at the given index or -1 if an error occurs
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index > 63)
		return (-1);

	bit = (n >> index) & 1;

	return (bit);
}
