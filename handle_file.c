#include "monty.h"

void file_error(char *file_read);
int is_all_spc(char *input);
/**
 * handle_file - open and read the file
 *
 * Return: void
 *
 * @file_read: the file to handle
*/

void handle_file(char *file_read)
{
	FILE *fp;
	char *buffer = NULL, *command, *arg;
	size_t size = 0;
	int line, is_stack = 1, error = 0;

	fp = fopen(file_read, "r");
	if (fp == NULL || file_read == NULL)
		file_error(file_read);
	for (line = 1; getline(&buffer, &size, fp) != -1; line++)
	{
		if (buffer == NULL)
		{
			error = -1;
			break;
		}
		command = strtok(buffer, " \n");
		if (command == NULL || command[0] == '#')
			continue;
		if (strcmp(command, "stack") == 0)
		{
			is_stack = 1;
			continue;
		}
		else if (strcmp(command, "queue") == 0)
		{
			is_stack = 0;
			continue;
		}
		arg = strtok(NULL, " \n");
		error = choose_func(command, arg, line, is_stack);
		if (error == -1)
			break;
	}
	free(buffer);
	fclose(fp);
	if (error == -1)
	{
		free_list(head);
		exit(EXIT_FAILURE);
	}
}

/**
 * choose_func - choose the function to execute
 *
 * Return: void
 *
 * @command: the command to execute
 *
 * @arg: the args to the command
 *
 * @line: the number of the line executing
 *
 * @is_stack: if queue or stack
 *
*/

int choose_func(char *command, char *arg, int line, int is_stack)
{
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		return (-1);
	}
	else if (strcmp(command, "push") == 0 && is_stack == 1)
		return (add_stack_node(arg, line));
	else if (strcmp(command, "push") == 0 && is_stack == 0)
		return (add_queue_node(arg, line));
	else if (strcmp(command, "pall") == 0)
		return (print_nodes());
	else if (strcmp(command, "pint") == 0)
		return (print_head(line));
	else if (strcmp(command, "pop") == 0)
		return (pop_node(line));
	else if (strcmp(command, "swap") == 0)
		return (swap_nodes(line));
	else if (strcmp(command, "add") == 0)
		return (add_nodes(line));
	else if (strcmp(command, "nop") == 0)
		return (0);
	else if (strcmp(command, "sub") == 0)
		return (sub_nodes(line));
	else if (strcmp(command, "div") == 0)
		return (div_nodes(line));
	else if (strcmp(command, "mul") == 0)
		return (mul_nodes(line));
	else if (strcmp(command, "mod") == 0)
		return (mod_nodes(line));
	else if (strcmp(command, "pchar") == 0)
		return (print_char(line));
	else if (strcmp(command, "pstr") == 0)
		return (print_str());
	else if (strcmp(command, "rotl") == 0)
		return (rotate_list());
	else if (strcmp(command, "rotr") == 0)
		return (rotate_last());
	fprintf(stderr, "L%d: unknown instruction %s\n", line, command);
	return (-1);
}

/**
 * file_error - print the file error
 *
 * Return: void
 *
 * @file_read: the file to read
*/

void file_error(char *file_read)
{
	if (head != NULL)
		free_list(head);
	fprintf(stderr, "Error: Can't open file %s\n", file_read);
	exit(EXIT_FAILURE);
}

/**
 * is_all_spc - check if all the input are spaces
 *
 * Return: 1 if success
 *
 * @input: the input to check
*/

int is_all_spc(char *input)
{

	int i = 0;

	if (input == NULL)
		return (1);
	while (input[i] != '\0')
	{
		if (input[i] != ' ' &&  input[i] != '\n')
			return (0);
		i++;
	}
	return (1);

}
