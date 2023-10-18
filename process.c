#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * process - main program process
 * @all: all struct
 */
void process(all_t *all)
{
	size_t size;
	ssize_t l;

	while (++all->line)
	{
		size = 0;
		if (all->opcode)
			free(all->opcode);
		l = getline(&all->opcode, &size, all->fs);
		if (l < 0)
			break;
		handle_commands(all);
	}
}

/**
 * handle_commands - handles the commands.
 * @all: the all strucut.
 */
void handle_commands(all_t *all)
{
	int i;
	char *token = all->opcode;
	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"div", divi},
		{"mod", mod},
		{"pop", pop},
		{"add", add},
		{"rotl", rotl},
		{"rotr", rotr},
		{"sub", sub},
		{"mul", mul},
		{"pchar", pchar},
		{"pstr", pstr},
		{"stack", mode},
		{"queue", mode},
		{NULL, NULL}
	};


	token = strtok(token, " \n");

	if (!token || token[0] == '#' || strcmp(token, "nop") == 0)
		return;

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(token, commands[i].opcode) == 0)
		{
			commands[i].f(all);
			return;
		}
	}

	handle_err(all, COMMAND);
}

/**
 * push - handles the push commands.
 * @all: the all struct.
 */
void push(all_t *all)
{
	char *token = strtok(NULL, " \n");
	int n = atoi(token ? token : "0"), i;

	if (!token)
		handle_err(all, PUSH);
	else
	{
		for (i = 0; token[i] && !n; i++)
		{
			if (token[i] != '0' && token[i] != '-')
				handle_err(all, PUSH);
		}
		if (all->stack)
		{
			if (!push_start(&all->list, n))
				handle_err(all, MEMORY);
		}
		else
		{
			if (!push_end(&all->list, n))
				handle_err(all, MEMORY);
		}
	}
}

/**
 * pall - handles the pall command.
 * @all: the all struct.
 */
void pall(all_t *all)
{
	plist(all->list);
}
