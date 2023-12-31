#include "monty.h"

/**
 * main - Entry point for the Monty program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		char *opcode = strtok(line, " \t\n");
		char *argument = strtok(NULL, " \t\n");

		if (opcode)
		{
			process_instruction(opcode, argument, &stack, line_number);
		}
	}

	free_resources(&stack, line);
	fclose(file);
	exit(EXIT_SUCCESS);
}


/**
 * free_resources - Frees allocated resources.
 * @stack: Pointer to the stack.
 * @line: Pointer to the line buffer.
 */
void free_resources(stack_t **stack, char *line)
{
	while (*stack)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}

	if (line)
		free(line);
}
