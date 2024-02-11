#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly-linked list.
 * @head: pointer the head of linked list
 * @number: Number to insert
 * Return: 0 If function fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *New;

	New = malloc(sizeof(listint_t));
	if (New == NULL)
		return (NULL);
	New->n = number;

	if (node == NULL || node->n >= number)
	{
		New->next = node;
		*head = New;
		return (New);
	}

	while (node && node->next && node->next->n < number)
		node = node->next;

	New->next = node->next;
	node->next = New;

	return (New);
}
