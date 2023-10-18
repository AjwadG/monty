#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @all: the all strucut.
 */
void rotl(all_t *all)
{
	int n;

	if (!all->list)
		return;

	n = del_first(&all->list);
	push_end(&all->list, n);
}


/**
 * rotr - rotates the stack to the bottom.
 * @all: the all strucut.
 */
void rotr(all_t *all)
{
	int n;

	if (!all->list)
		return;

	n = del_last(&all->list);
	push_start(&all->list, n);
}


/**
 * mode - sets memory mode
 * @all: the all strucut.
 */
void mode(all_t *all)
{
	all->stack = strcmp(all->opcode, "stack") ? 0 : 1;
}
