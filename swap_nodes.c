#include "monty.h"

/**
 * swap_nodes - swap two nodes in list
 *
 * Return: 0 if success
 *
 * @line: the line of the node
*/

int swap_nodes(int line)
{
	stack_t *tmp;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		return (-1);
	}
	tmp = head;
	head = head->next;
	tmp->prev = head;
	tmp->next = head->next;
	head->next = tmp;
	head->prev = NULL;
	return (0);
}
