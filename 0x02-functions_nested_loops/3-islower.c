#include "main.h"

/**
 * _islower - check if the letter is lowercase
 * @c: parameter for function
 * Return: 1 or 0, depending on character case
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);

}
