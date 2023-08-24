#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode in the file.
 * @data: The data to push onto the stack.
 */
void push(stack_t **stack, unsigned int line_number, char *data)
{
    stack_t *new_node;
    int value;

    if (stack == NULL)
    {
        fprintf(stderr, "L%u: stack is not initialized\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (!data || !isdigit(data[0]))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(data);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}
