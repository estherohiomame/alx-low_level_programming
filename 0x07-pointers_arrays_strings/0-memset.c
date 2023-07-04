#include "main.h"

/**
 * _memset - Fills a block of memory with a specified value
 * @s: Pointer to the starting address of the memory to be filled
 * @b: The desired value to be set
 * @n: Number of bytes to be filled
 *
 * Return: Pointer to the modified memory block
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}

	return (s);
}
