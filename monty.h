#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

/*General functions for lists*/
int add_node_end(stack_t **head, const int n);
void delete_end_node(stack_t **head);
void free_list(stack_t **head);

/*functions*/
void (*get_op_func(char *ops))(stack_t **stack, unsigned int line_number);
int numbers(char *tokenized_text);
void push(stack_t **h, unsigned int line_number, char *tokenized_text);
void pop(stack_t **h, unsigned int line_number);
void pall(stack_t **h, __attribute__((unused))unsigned int line_number);
void pint(stack_t **h, unsigned int line_number);
void swap(stack_t **h, unsigned int line_number);
void add(stack_t **h, unsigned int line_number);
void nop(stack_t **h, unsigned int line_number);

#endif
