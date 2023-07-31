#include "lists.h"

/**
 * free_listint - unallocates space previously allocated to a linked list
 * @head: pointer listint_t list
 */
void free_listint(listint_t *head)
{
	listint_t *swap;

	while (head)
	{
		swap = head->next;
		free(head);
		head = swap;
	}
}
