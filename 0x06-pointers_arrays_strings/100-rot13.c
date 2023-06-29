#include "main.h"

/**
 * rot13 - encode text into rot13
 * @s: pointer to string params
 * Return: *s
 */

char *rot13(char *s)
{
	char *ptr = s;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j;

	for (; *ptr != '\0'; ptr++)
	{
		for (i = 0; alphabet[i] != '\0'; i++)
		{
			if (*ptr == alphabet[i])
			{
				*ptr = rot13[i];
				break;
			}
		}
	}

	return (s);
}
