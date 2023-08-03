#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to a string of 0 and 1 chars
 *
 * Return: The converted number, or 0 if:
 *         - There is one or more chars in the string b that is not 0 or 1
 *         - b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		dec_val = (dec_val << 1) | (b[i] - '0');
	}

	return (dec_val);
}
