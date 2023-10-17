#include "main.h"

/**
 * commands1 - handles the commands.
 * @all: the all strucut.
 * @token: comand
 * Return: 1 if fount 0 otehr wise
 */
int commands1(char *token, all_t *all)
{
	if (strcmp(token, "push") == 0)
		push(all);
	else
		return (0);
	return (1);
}
