#include "monty.h"
/**
 *get_op_func - function that select the correct function to execute
 *@first_arg: opcode, first bytecode
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
		if (strcmp(ops, instruction_s[x].opcode) == 0)
			return (instruction_s[x].f);
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

	if (argc != 2) /*si son dos argumentos, el monty y filename*/
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileopen = open(argv[1], O_RDONLY); /*comando para abrir el archivo en modo lectura*/
	if (fileopen == -1) /*Condicion para cuando no se abrio el file*/
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = _calloc(500, sizeof(char *));/*asignamos memoria para leer el file*/
	if (buffer == NULL) /*confirmamos si se asigno la memoria*/
	{
		close(fileopen);
		return (0);
	}
	read_length = read(fileopen, buffer, 5000); /*read recorre el file, almacena en el buffer y retorna cantidad de caracteres leidos*/
	if (read_length == -1)/*condicion sobre si no pudo leer nada*/
	{
		free(buffer);/*liberamos el buffer*/
		close(fileopen);/*cerramos el file*/
		exit(EXIT_FAILURE);
	}
	tokenized_text = strtok(buffer, "\n\t $");/*aca obtenemos el texto tokenizado*/
	while (tokenized_text != NULL) /*aca recorremos el texto tokenizado*/
	{
		if (get_op_func(tokenized_text) != 0)/*confirmamos si la funcion que recibe tok != 0*/
			get_op_func(tokenized_text)(&h, lines);
		else if (strcmp(tokenized_text, "push") == 0) /*utilizamos el strcmp para comparar el tok con la func*/
		{
			tokenized_text = strtok(NULL, "\n\t $");
			push(&h, lines, tokenized_text);
		}
		else /*en caso contrario, no se entiende la instruccion dada y printea mensaje de error*/
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", lines, tokenized_text);
			free_list(&h);
			exit(EXIT_FAILURE);
		}
		lines++; /*iteramos contador de lineas*/
		tokenized_text = strtok(NULL, "\n\t $");
	}
	free_list(&h);/*liberamos el puntero*/
	free(buffer);/*liberamos el buffer*/
	close(fileopen);/*cerramos el archivo*/
	return (0);
}
