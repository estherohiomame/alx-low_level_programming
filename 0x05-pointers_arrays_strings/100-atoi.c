#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: parameter
 *
 * Return: the int converted from the string
 */


int _atoi(char *s)
{
	int index, count, num, length, flag, digit;

	index = 0;
	count = 0;
	num = 0;
	length = 0;
	flag = 0;
	digit = 0;

	while (s[length] != '\0')
		length++;

	while (index < length && flag == 0)
	{
		if (s[index] == '-')
			++count;

		if (s[index] >= '0' && s[index] <= '9')
		{
			digit = s[index] - '0';
			if (count % 2)
				digit = -digit;
			num = num * 10 + digit;
			flag = 1;
			if (s[index + 1] < '0' || s[index + 1] > '9')
				break;
			flag = 0;
		}
		index++;
	}

	if (flag == 0)
		return (0);

	return (num);
}
