#include "main.h"

/**
 * _isalpha - Does something
 * @c: is a parameter
 * Return: Always 0
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
