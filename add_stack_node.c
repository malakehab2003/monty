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

void add_stack_node(char *arg, int line, FILE *fp)
{
	stack_t *new;
	int check_int, arg_int;
	
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fclose(fp);
		free_list(head);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	check_int = is_int(arg);
	if (arg == NULL && check_int == 0)
	{
		free (new);
		fclose(fp);
		free_list(head);
		fprintf(stderr, "L %d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
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
		if (!isdigit(string[i]))
		{
			return (0);
		}
	}
	return (1);
}
