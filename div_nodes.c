#include "monty.h"

/**
 * div_nodes - div two nodes in list
 *
 * Return: 0 if success
 *
 * @line: the line of the node
*/

int div_nodes(int line)
{
	int i;
	stack_t *new;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		return (-1);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		return (-1);
	}

	new = head;
	i = head->next->n / head->n;
	head = head->next;
	free(new);
	head->n = i;
	return (0);
}
