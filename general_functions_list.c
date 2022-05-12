#include "monty.h"
/**
 *add_node_end - add a node at the end of the list
 *@head: pointer to the head of the list
 *@n: node data type int
 *Return: 0
 **/
int add_node_end(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		return (0);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	if (new_node != NULL)
	{
		new_node->n = n;
		new_node->next = *head;
		(*head) = new_node;
	}
	return (1);	
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
