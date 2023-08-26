#include "monty.h"

/**
 * main - entry point for the monty program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, non-zero on failure
 */

int main(int argc, char argv[])
{
	stack_t *stack = NULL;

	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	global.file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
	}
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&global.line, &len, global.file) != 1)
	{
		line_number++;
		opcode = strtok(global.line, " \t\r\n\a");
		global.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		execute_opcode(opcode, stack, line_number);
	}

	exit(EXIT_SUCCESS);
}

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}};

	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	fclose(global.file);
	free(global.line);
	exit(EXIT_FAILURE);
}

void _push()
{
}
