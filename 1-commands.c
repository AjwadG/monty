#include "monty.h"

/**
 * add - adds the first two node->n and put the result in one node.
 * @all: the all strucut.
 */
void add(all_t *all)
{
	int n1;

	if (get_len(all->list) < 2)
		handle_err(all, ADD);
	n1 = del_first(&all->list);
	all->list->n += n1;
}

/**
 * sub - substracts the first two node->n and put the result in one node.
 * @all: the all strucut.
 */
void sub(all_t *all)
{
	int n1;

	if (get_len(all->list) < 2)
		handle_err(all, SUB);
	n1 = del_first(&all->list);
	all->list->n -= n1;
}

/**
 * mul - multeblies the first two node->n and put the result in one node.
 * @all: the all strucut.
 */
void mul(all_t *all)
{
	int n1;

	if (get_len(all->list) < 2)
		handle_err(all, MUL);
	n1 = del_first(&all->list);
	all->list->n *= n1;
}

/**
 * divi - divides the second top element by the top element of stack stack.
 * @all: the all strucut.
 */
void divi(all_t *all)
{
	int n1;

	if (get_len(all->list) < 2)
		handle_err(all, DIV);

	n1 = del_first(&all->list);

	if (!n1)
		handle_err(all, ZERO);

	all->list->n /= n1;
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @all: the all strucut.
 */
void mod(all_t *all)
{
	int n1;

	if (get_len(all->list) < 2)
		handle_err(all, MOD);

	n1 = del_first(&all->list);

	if (!n1)
		handle_err(all, ZERO);

	all->list->n %= n1;
}
