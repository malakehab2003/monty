#include "monty.h"

/**
 * print_nodes - print all nodes in the list
 *
 * Return: void
*/

void print_nodes(void)
{
	stack_t *new;

	if (head == NULL)
		exit(EXIT_FAILURE);
	new = head;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}
