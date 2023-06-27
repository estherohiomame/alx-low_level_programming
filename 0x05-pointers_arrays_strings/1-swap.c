#include "main.h"

/**
 * swap_int - swaps the values of two numbers
 * @a: parameter
 * @b: parameter
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
