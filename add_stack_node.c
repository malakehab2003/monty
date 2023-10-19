#include "monty.h"

int is_int(const char *string);

/**
 * add_stack_node - add a node to the stack
 *
 * Return: void
 *
 * @arg: the data to add
 *
 * @line: the line which execute
*/

int add_stack_node(char *arg, int line)
{
	stack_t *new;
	int check_int, arg_int;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		/*fprintf(stderr, "Error: malloc failed");*/
		return (-1);
	}
	check_int = is_int(arg);
	if (arg == NULL || check_int == 0)
	{
		free(new);
		fprintf(stderr, "L%d: usage: push integer\n", line);
		return (-1);
	}
	arg_int = atoi(arg);
	new->n = arg_int;
	new->prev = NULL;
	if (head == NULL)
	{
		head = new;
		head->next = NULL;
	}
	else
	{
		new->next = head;
		head->prev = new;
		head = new;
	}
	return (0);
}

/**
 * is_int - check if the string an int
 *
 * Return: 1 if int
 *
 * @string: the string to check
*/

int is_int(const char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '-')
		{
			continue;
		}
		if (!isdigit(string[i]))
		{
			return (0);
		}
	}
	return (1);
}
