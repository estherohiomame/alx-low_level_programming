#include "lists.h"

/**
 * print_listint - prints all the numbers in listint
 * @h: listint_t linked list
 *
 * Return: number of numbers in the linked list
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
