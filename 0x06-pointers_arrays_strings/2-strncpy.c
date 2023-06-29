#include "main.h"

/**
 * _strncpy - copies a given string
 * @dest: parameter
 * @n: parameter
 * @src: parameter
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copy characters from source to destination up to n bytes*/
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
