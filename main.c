#include "monty.h"

/**
 * main - entry level
 * @argc: number of args
 * @argv: the args
 *
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	all_t all = {NULL, 0, NULL, NULL, NULL, 0, 1};

	all.file_name = argc == 2 ? argv[1] : NULL;

	all.fs = validate(argc, &all);

	process(&all);

	free_all(&all);

	return (EXIT_SUCCESS);
}
