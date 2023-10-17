#include "monty.h"

stack_t *head = NULL;
void free_list(stack_t *head);

/**
 * main - entry point
 *
 * Return: 0 on success
 *
 * @argc: the number of arguments
 *
 * @argv: the passed arguments
*/

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	handle_file(argv[1]);
	free_list(head);
	return (0);
}


/**
 * free_list - free double linked list
 *
 * Return: void
 *
 * @head: the head of the list
*/

void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
