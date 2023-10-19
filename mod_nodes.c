#include "monty.h"

/**
 * mod_nodes - mod two nodes in list
 *
 * Return: 0 if success
 *
 * @line: the line of the node
*/

int mod_nodes(int line)
{
	int i;
	stack_t *new;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		return (-1);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		return (-1);
	}

	new = head;
	i = head->next->n % head->n;
	head = head->next;
	free(new);
	head->n = i;
	return (0);
}
