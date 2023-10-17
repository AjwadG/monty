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
		handle_err(all, 0);
	}
	fs = fopen(all->file_name, "r");
	if (!fs)
		handle_err(all, 1);
	return (fs);

}


void handle_err(all_t *all, int errno)
{
	if (errno == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (errno == 1)
		fprintf(stderr, "Error: Can't open file %s\n", all->file_name);
	else if (errno == 2)
		fprintf(stderr, "L%d: unknown instruction %s\n", all->line,
				all->inst->opcode);

	if (errno > 1)
		free_all(all);
	exit(EXIT_FAILURE);
}

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
		free(all->list);
}
