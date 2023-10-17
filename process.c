#define  _POSIX_C_SOURCE 200809L
#include "main.h"

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
		if (all->inst->opcode)
			free(all->inst->opcode);
		l = getline(&all->inst->opcode, &size, all->fs);
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
	char *token = strtok(all->inst->opcode, " \n");

	if (!token || strcmp(token, "nop") == 0)
		return;
	else if (strcmp(token, "push") == 0)
		push(all);
	else if (commands1(token, all) || commands2(token, all))
		return;
	else if (strcmp(token, "pall") == 0)
		pall(all);
	else
		handle_err(all, COMMAND);
}

/**
 * push - handles the push commands.
 * @all: the all struct.
 */
void push(all_t *all)
{
	char *token = strtok(NULL, " \n");
	int n = atoi(token ? token : "0");

	if (!n && token && token[0] != '0')
		handle_err(all, PUSH);
	else
		push_start(&all->list, n);
}

/**
 * pall - handles the pall command.
 * @all: the all struct.
 */
void pall(all_t *all)
{
	plist(all->list);
}
