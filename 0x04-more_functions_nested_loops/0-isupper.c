#include "main.h"

/**
 * _isupper - checks if a letter is uppercase
 * @c: letter parameter
 * Return: 0 or 1;
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
