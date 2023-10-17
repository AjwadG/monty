#include "main.h"

/**
 * validtae - cheacks base cases
 * @argc: number of args
 * @all: all struct
 *
 * Return: fs
 */
FILE *validate(int argc, all_t *all)
{
	FILE *fs;

	if (argc != 2)
	{
		handle_err(all, USAGE);
	}
	fs = fopen(all->file_name, "r");
	if (!fs)
		handle_err(all, OPEN);
	return (fs);

}


/**
 * handle_err - handles errors
 * @a: the all struct.
 * @errno: the error identifier.
 */
void handle_err(all_t *a, int errno)
{
	if (errno == USAGE)
		fprintf(stderr, "USAGE: monty file\n");
	else if (errno == OPEN)
		fprintf(stderr, "Error: Can't open file %s\n", a->file_name);
	else if (errno == COMMAND)
		fprintf(stderr, "L%d: unknown instruction %s\n", a->line,
				a->inst->opcode);
	else if (errno == PUSH)
		fprintf(stderr, "L%d: usage: push integer\n", a->line);
	else if (errno == PINT)
		fprintf(stderr, "L%d: can't pint, stack empty\n", a->line);
	else if (errno == POP)
		fprintf(stderr, "L%d: usage: can't pop an empty stack\n", a->line);
	else if (errno == SWAP)
		fprintf(stderr, "L%d: usage: can't swap, stack too short\n", a->line);
	else if (errno == ADD)
		fprintf(stderr, "L%d: usage: can't add, stack too short\n", a->line);
	else if (errno == SUB)
		fprintf(stderr, "L%d: usage: can't sub, stack too short\n", a->line);
	else if (errno == DIV)
		fprintf(stderr, "L%d: usage: can't div, stack too short\n", a->line);
	else if (errno == MUL)
		fprintf(stderr, "L%d: usage: can't mul, stack too short\n", a->line);
	else if (errno == MOD)
		fprintf(stderr, "L%d: usage: can't mod, stack too short\n", a->line);
	else if (errno == ZERO)
		fprintf(stderr, "L%d: usage: division by zero\n", a->line);

	free_all(a);
	exit(EXIT_FAILURE);
}

/**
 * free_all - frees everything inside the all struct
 * @all: the all struct.
 */
void free_all(all_t *all)
{
	if (all->fs)
		fclose(all->fs);
	if (all->inst)
	{
		free(all->inst->opcode);
		free(all->inst);
	}
	if (all->list)
		free_list(all->list);
}

/**
 * free_list -  frees all of the linked list
 * @head: head of the double linked list
 */
void free_list(stack_t *head)
{
	stack_t *tmp = head;

	while (head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
