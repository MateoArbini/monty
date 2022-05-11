#include "monty.h"
/**
 *add_node_end - add a node at the end of the list
 *@head: pointer to the head of the list
 *@n: node data type int
 *Return: 0
 **/
int add_node_end(stack_t **head, const int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));

	if (newnode != NULL)
	{
		newnode->n = n;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		return (1);
	}
	if (*head == NULL)
	{
		*head = newnode;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		*head = newnode;
		newnode->next = *head;
		newnode->prev = NULL;
	}
	return (0);
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
 *@head: pointer to the head
 **/
void free_list(stack_t **head)
{
	if (*head == NULL)
	{
		return;
	}

	while (head != NULL && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
