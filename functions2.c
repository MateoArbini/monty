#include "monty.h"
/**
 *swap - function that swaps the two top elements of the stack
 *@h: pointer to the header of the function
 *@line_number: line number of the bytecode monty program
 **/
void swap(stack_t **h, unsigned int line_number)
{
	stack_t *aux == NULL;

	if (h == NULL || *h == NULL || (*h)->next == NULL) /*checkeamos lista*/
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = (*h)->next;/*igualamos el puntero aux al puntero next de head*/
	(*h)->next = aux->next;
	
	if (aux->next)
	{
		aux->next->prev = (*h);
	}
	(*h)->prev = aux->prev;
	aux->prev = NULL;
	aux->next = (*h);
	(*h) = aux;
}

/**
 *add - function that adds the top two elements of the stack
 *@h: pointer to the head of the list
 *@line_number:  line number of the bytecode monty program
 **/
void add(stack_t **h, unsigned int line_number)
{	
	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*h)->next->n = (*h)->n + (*h)->next->n;
		(*h)->prev = NULL;
		free(*h);
		*h = (*h)->next;
	}
}

/**
 *nop - function that doesn´t do anything
 *@h: pointer to the head of the list
 *@line_number: line number of the bytecode monty program
 **/
void nop(stack_t **h, unsigned int line_number)
{
	void (*h);
	void line_numbers;
}

