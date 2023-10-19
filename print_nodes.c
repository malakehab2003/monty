#include "monty.h"

/**
 * print_nodes - print all nodes in the list
 *
 * Return: void
*/

int print_nodes(void)
{
	stack_t *new;

	if (head == NULL)
	{
		return (-1);
	}
	new = head;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
	return (0);
}
