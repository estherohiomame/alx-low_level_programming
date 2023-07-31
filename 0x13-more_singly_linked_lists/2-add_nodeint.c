#include "lists.h"

/**
 * add_nodeint - prepends a new node to a linked list
 * @head: pointer to the first node
 * @n: new node to be added
 *
 * Return: pointer to the new node that was added
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
