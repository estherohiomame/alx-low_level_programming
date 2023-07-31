#include "lists.h"

/**
 * reverse_listint - returns a linked list in reverse
 * @head: pointer to the first element
 *
 * Return: pointer to the first element in the returned listint
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}
