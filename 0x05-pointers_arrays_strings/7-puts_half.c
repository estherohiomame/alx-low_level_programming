#include "main.h"
/**
 * puts_half - a function that prints half
 * @str: input
 * Return: half of input
 */

void puts_half(char *str)
{
	int length = 0;
	int i;
	int start;

	for (i = 0; str[i] != '\0'; i++)
	{
		length++;
	}

	start = (length + 1) / 2;

	for (i = start; i < length; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
