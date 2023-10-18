#include "monty.h"

/**
 * add_queue_node - add node to queue
 *
 * Return: void
 *
 * @arg: the data of the point
 *
 * @line: the line of the node
*/

int add_queue_node(char *arg, int line)
{
	stack_t *new, *itr;
	int check_int, arg_int;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	check_int = is_int(arg);
	if (arg == NULL || check_int == 0)
	{
		free (new);
		fprintf(stderr, "L%d: usage: push integer\n", line);
		return (-1);
	}
	arg_int = atoi(arg);
	new->n = arg_int;
	new->next = NULL;
	if (head == NULL)
	{
		new->prev = NULL;
		head = new;
	}
	else
	{
		itr = head;
		while (itr->next != NULL)
			itr = itr->next;
		itr->next = new;
		new->prev = itr;
	}
	return (0);
}
