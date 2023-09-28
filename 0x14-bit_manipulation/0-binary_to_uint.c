#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned integer
 * @b: A binary number
 * Return: An integer
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	int i = 0;

	while (b[i] != '\0')
	{
		if (b[i] != 0 && b[i] != 1)
		{
			return (0);
		}

		result = (result << 1) | (b[i] - '0');
		i++;
	}

	return (result);
}
