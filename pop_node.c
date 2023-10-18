#include "monty.h"

/**
 * pop_node - remove node in the list
 *
 * Return: 0 if success
 *
 * @line: the line of execute
*/


int pop_node(int line)
{
	stack_t *new;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		return (-1);
	}
	new = head;

	head = head->next;
	free(new);
	return (0);

}
