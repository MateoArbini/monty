#include "monty.h"
/**
 *numbers - function that checks if the string that was read, is composed by
 *only numbers.
 *@tokenized_text: Text that will be used to check
 *Return: 1 if the text is composed by only number, 0 otherwise
 **/
int numbers(char *tokenized_text)
{
	int x = 0;

	for (x = 0; tokenized_text[x]; x++)
	{
		if (tokenized_text[x] == '-' && x == 0)
		{
			continue;
		}
		if (isdigit(tokenized_text[x]) > 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 *push - function that add a new element to the top of the stack
 *@h: pointer to the head of the list
 *@line_number: line number of the bytecode monty program
 *@tokenized_text: string which we will use to check for numbers
 **/
void push(stack_t **h, unsigned int line_number, char *tokenized_text)
{
	if (h == NULL) /*confirmamos si la lista no esta vacia*/
	{
		return;
	}
	if (numbers(tokenized_text) == 0)/*condicion si lo que leyo es solo numeros*/
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_list(h);/*libero la lista*/
		exit(EXIT_FAILURE);
	}
	else /*en caso contrario, inserta el dato en el stack*/
	{
		if (add_node_end(h, atoi(tokenized_text)) == 0)
		{
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 *pop - function that deletes the top element of the stack
 *@h: pointer to the head
 *@line_number: line number of the bytecode monty program
 **/
void pop(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)/*chequeamos que la lista no este vacia*/
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else/*en caso de que la lista no este vacia, procedemos a elimina*/
	{
		delete_end_node(h);
	}
}

/**
 *pall - function that prints all the elements of a list
 *@h: pointer to the head of the list
 *@line_number: line_number
 **/
void pall(stack_t **h, __attribute__((unused))unsigned int line_number)
{
	stack_t *aux = (*h);/*igualamos el puntero aux al head*/

	while (aux != NULL)/*recorre la lista hasta que aux sea NULL*/
	{
		printf("%u\n", aux->n); /*printea el dato*/
		aux = aux->next;/*iteracion de aux en la lista*/
	}
}

/**
 *pint - function that prints tha value at the top of the stack
 *@h: pointer to the head of the list
 *@line_number: line number of the bytecode monty program
 **/
void pint(stack_t **h, unsigned int line_number)
{
	stack_t *aux = *h;

	if (*h != NULL)
	{
		printf("%d\n", aux->n);
	}
	else
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
                free_list(h);
                exit(EXIT_FAILURE);	
	}
}

