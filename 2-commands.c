#include "monty.h"

/**
 * pint - prints the value at the top of the stack.
 * @all: the all struct.
 */
void pint(all_t *all)
{
	if (!all->list)
		handle_err(all, PINT);
	else
		printf("%d\n", all->list->n);
}

/**
 * swap - swaps the top two elements of the stack.
 * @all: the all struct.
 */
void swap(all_t *all)
{
	stack_t *h = all->list;
	int len = get_len(h), tmp;

	if (len < 2)
		handle_err(all, SWAP);

	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}

/**
 * pop - removes the first node of the linked list.
 * @all: the all strucut.
 */
void pop(all_t *all)
{
	if (!all->list)
		handle_err(all, POP);
	del_first(&all->list);
}

/**
 * pchar - prints the first node->n's ascii represintation.
 * @all: the all strucut.
 */
void pchar(all_t *all)
{
	int n;

	if (!all->list)
		handle_err(all, PCHEMP);

	n = all->list->n;

	if (n >= 0 && n <= 127)
		printf("%c\n", n);
	else
		handle_err(all, PCHAR);
}

/**
 * pstr - prints the stack elements as a string
 * @all: the all struct.
 */
void pstr(all_t *all)
{
	int n;
	stack_t *tmp;

	tmp = all->list;
	while (tmp)
	{
		n = tmp->n;
		if (n > 0 && n <= 127)
			printf("%c", n);
		else
			break;
		tmp = tmp->next;
	}
	putchar(10);
}
