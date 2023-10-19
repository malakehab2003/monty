#include "monty.h"

/**
 * add_nodes - add two nodes in list
 *
 * Return: 0 if success
 *
 * @line: the line of the node
*/

int add_nodes(int line)
{
	int i;
	stack_t *new;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		return (-1);
	}

	new = head;
	i = head->n + head->next->n;
	head = head->next;
	free(new);
	head->n = i;
	return (0);
}
