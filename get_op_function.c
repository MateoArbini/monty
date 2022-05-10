#include "monty.h"
/**
 *get_op_func - function that select the correct function to execute
 *@first_arg: opcode, first bytecode
 *Return: pointer to the correct function
 **/
void (*get_op_func(char *first_arg))(stack_t **stack, unsigned int line_number)
{
	int x;

	instruction_t instruction_s[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"NULL, NULL"}
	};

	x = 0;
	while (instruction_s[x].f != NULL)
	{
		if (strcmp(first_arg, instruction_s[x].opcode) == 0)
			return (instrunction_s[x].f);
		x++;
	}
	return (NULL);
}
