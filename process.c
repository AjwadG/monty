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
		printf("%s --- line %d", all->inst->opcode, all->line);
		/* handle_comands(all); */
	}
}


/*void handle_comands(all_t *all)
*{
*
*}
*/
