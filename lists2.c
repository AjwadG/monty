#include "monty.h"
#include <stdlib.h>

/**
 * del_last -  deletes the last node
 * @head: head of the double linked list
 * Return: 1 if succeeded 0 other wise
 */
int del_last(stack_t **head)
{
	stack_t *ptr = *head;
	int n;

	for (; ptr->next; ptr = ptr->next)
		;

	n = ptr->n;
	if (ptr->prev)
		ptr->prev->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	if (!ptr->prev)
		*head = ptr->next;

	free(ptr);
	return (n);
}
