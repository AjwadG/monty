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
 * @all: the all struct.
 * @errno: the error identifier.
 */
void handle_err(all_t *all, int errno)
{
	if (errno == USAGE)
		fprintf(stderr, "USAGE: monty file\n");
	else if (errno == OPEN)
		fprintf(stderr, "Error: Can't open file %s\n", all->file_name);
	else if (errno == COMMAND)
		fprintf(stderr, "L%d: unknown instruction %s\n", all->line,
				all->inst->opcode);
	else if (errno == PUSH)
		fprintf(stderr, "L%d: usage: push integer\n", all->line);

	free_all(all);
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
