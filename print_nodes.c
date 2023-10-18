#include "monty.h"

/**
 * print_nodes - print all nodes in the list
 *
 * Return: void
*/

void print_nodes(FILE *fp)
{
	stack_t *new;

	if (head == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	new = head;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
