#include "monty.h"
/**
 *get_op_func - function that select the correct function to execute
 *@first_arg: opcode, first bytecode
 *Return: pointer to the correct function
 **/
void (*get_op_func(char *tokenized_text))(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	instruction_t instruction_s[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{'\0', NULL},
	};

	while (x != 8)
	{
		if (instruction_s[x].opcode == tokenized_text)
			return (instruction_s[x].f);
		x++;
	}
	return (NULL);
}
/**
 *main - interpreter of Monty
 *@argc: argument counter
 *@argv: arguments given by the user
 *Return: depends
 **/
int main(int argc, char *argv[])
{
	int fileopen, read_length, lines = 1;
	char *buffer; tokenized_text;

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
	buffer = _calloc(5000, sizeof(char *));/*asignamos memoria para leer el file*/
	if (buffer == NULL) /*confirmamos si se asigno la memoria*/
	{
		return (NULL);
	}
	read_lenght = read(fileopen, buffer, 5000); /*read recorre el file, almacena en el buffer y retorna cantidad de caracteres leidos*/
	if (read_length == -1)/*condicion sobre si no pudo leer nada*/
	{
		free(buffer);/*liberamos el buffer*/
		close(fileopen);/*cerramos el file*/
		exit(EXIT_FAILURE);
	}
	tokenized_text = strtok(buffer, "\n\t$ ");/*aca obtenemos el texto tokenizado*/
	while (tokenized_text != NULL) /*aca recorremos el texto tokenizado*/
	{


	lines++;
	}
		
}
