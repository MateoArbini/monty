#include "monty.h"
/**
 *add_dnodeint_end - add a node at the end of the list
 *@head: pointer to the head of the list
 *@n: node data type int
 *Return: newnode
 **/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *aux = *head;
	stack_t *newnode;

	newnode = malloc(sizeof(dlistint_t));

	if (newnode != NULL)
	{
		newnode->n = n;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		return (NULL);
	}
	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	aux->next = newnode;
	newnode->prev = aux;
	return (newnode);
}

/**
 *delete_end_node - delete the last node of a list
 *@head: pointer to the head of the list
 **/
void delete_end_node(stack_t **head)
{
	stack_t *delete = NULL;

	delete = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(delete);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(delete);
	}
}

/**
 *free_list - function that frees a list
 *@head: pointer to a head
 **/
void free_list(stack_t *head)
{
	void *aux;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
