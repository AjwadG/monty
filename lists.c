#include "monty.h"
#include <stdlib.h>

/**
 * push_start -  adds a new node to the start of list
 * @head: head of the double linked list
 * @n: the value of the new node
 * Return: address of the new element, or NULL if it failed
 */
stack_t *push_start(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new || !head)
		return (new);

	new->next = *head;
	new->prev = NULL;
	new->n = n;
	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * push_end - adds a new node at the end of a stack_t list.
 * @head: the head of the list.
 * @n: the new node's value.
 *
 * Return: the address of the new node, or NULL if it failed.
 **/
stack_t *push_end(stack_t **head, const int n)
{
	stack_t *tmp, *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		return (NULL);
	newNode->n = n;
	newNode->next = NULL;

	if (!*head)
	{
		newNode->prev = NULL;
		*head = newNode;
		return (newNode);
	}

	for (tmp = *head; tmp->next; tmp = tmp->next)
		;
	tmp->next = newNode;
	newNode->prev = tmp;

	return (newNode);
}

/**
 * plist - prints all elements of a stack_t list
 * @h: head of the double linked list
 */
void plist(stack_t *h)
{
	for (; h; h = h->next)
		printf("%d\n", h->n);
}

/**
 * get_len - cal the elemnts in a stack_t list
 * @h: head of the double linked list
 * Return: the number of nudes
 */
int get_len(stack_t *h)
{
	int i;

	for (i = 0; h; i++, h = h->next)
		;
	return (i);
}

/**
 * del_first -  deletes node at a given index
 * @head: head of the double linked list
 * Return: 1 if succeeded 0 other wise
 */
int del_first(stack_t **head)
{
	stack_t *ptr = *head;
	int n;

	if (ptr)
	{
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
	else
		return (0);
}
