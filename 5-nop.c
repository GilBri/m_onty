#include "monty.h"

/**
 * nop - Doesn't do anything.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode in the file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
