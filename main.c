#include "monty.h"
/**
 *main - interpreter of Monty
 *@argc: argument counter
 *@argv: arguments given by the user
 *Return: depends
 **/
int main(int argc, char *argv[])
{
	int fileopen, read_length;
	char *buffer;

	if (argc != 2) /*si son dos argumentos, el monty y filename*/
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileopen = open(argv[1], O_RDONLY); /*comando para abrir el archivo en modo lectura*/
	if (fileopen == -1) /*Condicion para cuando no se abrio el file*/
	{
		dprintf(STDERR_FILENO, "Error: Can't open file <file>\n");
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

	
}
