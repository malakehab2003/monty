#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void handle_file(char *file_read);
int choose_func(char *command, char *arg, int line, int is_stack);
int print_nodes(void);
int add_queue_node(char *arg, int line);
int add_stack_node(char *arg, int line);
int is_int(const char *string);
void free_list(stack_t *head);
int print_head(int line);
int pop_node(int line);
int swap_nodes(int line);
int add_nodes(int line);
int sub_nodes(int line);
int div_nodes(int line);
int mul_nodes(int line);
int mod_nodes(int line);
int print_char(int line);
int print_str(void);
int rotate_list(void);
#endif
