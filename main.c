#include "monty.h"
/**
 *get_op_func - function that select the correct function to execute
 *@ops: opcode, first bytecode
 *Return: pointer to the correct function
 **/
void (*get_op_func(char *ops))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	int x = 0;

	while (x != 7)
	{
		if (instruction_s[x].opcode == ops)
			return (instruction_s[x].f);
		else
			x++;
	}
	return (NULL);
}
#include "monty.h"
/**
 *main - interpreter of Monty
 *@argc: argument counter
 *@argv: arguments given by the user
 *Return: depends
 **/
int main(int argc, char *argv[])
{
	int fileopen = 0, read_length = 0;
	unsigned int lines = 1;
	char *buffer = NULL, *tokenized_text = NULL;
	stack_t *h = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileopen = open(argv[1], O_RDONLY);
	if (fileopen == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 5000);
	if (buffer == NULL)
	{
		close(fileopen);
		return (0);
	}
	read_length = read(fileopen, buffer, 5000);
	if (read_length == -1)
	{
		free(buffer);
		close(fileopen);
		exit(EXIT_FAILURE);
	}
	tokenized_text = strtok(buffer, "\n\t $");
	while (tokenized_text != NULL)
	{
		if (tokenized_text = NULL || token[0] == '#')
			continue;
		if (get_op_func(tokenized_text) != 0)
			get_op_func(tokenized_text)(&h, lines);
		else if (strcmp(tokenized_text, "push") == 0)
		{
			tokenized_text = strtok(NULL, "\n\t\a\r :;$");
			push(&h, lines, tokenized_text);
		}
		else
		{
			dprintf(2, "L%d: unknown instruction %s\n", lines, tokenized_text);
			free_list(&h);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		lines++; /*iteramos contador de lineas*/
		tokenized_text = strtok(NULL, "\n\t\a\r :;$");
	}
	free_list(&h);/*liberamos el puntero*/
	free(buffer);/*liberamos el buffer*/
	close(fileopen);/*cerramos el archivo*/
	return (0);
}
