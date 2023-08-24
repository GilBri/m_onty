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

        /* Tokenize the line to extract opcode and arguments */
        char *opcode = strtok(line, " \t\n");
        char *argument = strtok(NULL, " \t\n");

        if (opcode)
        {
            instruction_t *instr = find_instruction(opcode);
            if (instr)
            {
                if (strcmp(opcode, "push") == 0)
                {
                    if (!argument)
                    {
                        fprintf(stderr, "L%u: usage: push integer\n", line_number);
                        free_resources(&stack, line);
                        fclose(file);
                        exit(EXIT_FAILURE);
                    }
                    instr->f(&stack, line_number, argument);
                }
                else
                {
                    instr->f(&stack, line_number);
                }
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free_resources(&stack, line);
                fclose(file);
                exit(EXIT_FAILURE);
            }
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
