#include <stdio.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: Pointer to the unsigned long integer
 * @index: The index of the bit to clear (0-based)
 * Return: 1 if it worked, or -1 if an error occurs
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
