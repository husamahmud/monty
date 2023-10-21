#include "monty.h"

stack_t *stk_top = NULL;

/**
 * instruction - parses and executes the instruction
 * @line: pointer to the instruction line
 * @line_num: line number of the instruction
 * @fd: file descriptor of the Monty file
 * Return: the instruction structure
 */
instruction_t instruction(char *line, unsigned int line_num, FILE *fd)
{
	bool valid;
	char *arg = NULL;
	int n = 0, i;
	char *line_c = line;
	instruction_t instrct;

	instrct.opcode = NULL;
	instrct.f = NULL;
	instrct.opcode = strtok(line_c, " \t\n");

	if (instrct.opcode && instrct.opcode[0] == '#')
		return (instrct);
	if (instrct.opcode == NULL)
		return (instrct);

	if (strcmp(instrct.opcode, "push") != 0)
	{
		if (strcmp(instrct.opcode, "pall") == 0)
		{
			instrct.f = pall;
			pall(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "pint") == 0)
		{
			instrct.f = pint;
			pint(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "pop") == 0)
		{
			instrct.f = pop;
			pop(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "swap") == 0)
		{
			instrct.f = swap;
			swap(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "add") == 0)
		{
			instrct.f = add;
			add(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "sub") == 0)
		{
			instrct.f = sub;
			sub(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "div") == 0)
		{
			instrct.f = div;
			div(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "mul") == 0)
		{
			instrct.f = mul;
			mul(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "mod") == 0)
		{
			instrct.f = mod;
			mod(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "nop") == 0)
		{
			instrct.f = nope;
			nope(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "pchar") == 0)
		{
			instrct.f = pchar;
			pchar(&stk_top, line_num);
		} else if (strcmp(instrct.opcode, "pstr") == 0)
		{
			instrct.f = pstr;
			pstr(&stk_top, line_num);
		} else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num,
				instrct.opcode);
			free(instrct.opcode);
			fclose(fd);
			exit(EXIT_FAILURE);
		}

		return (instrct);
	}

	arg = strtok(NULL, " \t\n");
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free(f_close.line);
		fclose(fd);
		free_stk(f_close.stack);
		exit(EXIT_FAILURE);
	}

	valid = true;
	if (arg[0] == '-')
	{
		i = 1;
		while (arg[i] != '\0')
		{
			if (isdigit(arg[i]))
			{
				n = n * 10 - (arg[i] - '0');
				if (n < INT_MIN)
				{
					valid = false;
					break;
				}
			} else
			{
				valid = false;
				break;
			}
			i++;
		}
	} else
	{
		i = 0;
		while (arg[i] != '\0')
		{
			if (isdigit(arg[i]))
			{
				n = n * 10 + (arg[i] - '0');
				if (n > 2147483647)
				{
					valid = false;
					break;
				}
			} else
			{
				valid = false;
				break;
			}
			i++;
		}
	}

	if (!valid)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		return (instrct);
	}

	instrct.f = push;
	push(&stk_top, n);

	return (instrct);
}

