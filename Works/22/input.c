/*
 * Contains input analysis helper functions, mainly the get_command which parses a single one.
 * input_analyze.h contains the input-related macros, cmd_type enum typedef & prototypes.
 * */
#include <stdio.h> /* for error output */
#include <string.h> /* for cmd_type parsing - strcmp */
#include "input.h"
#include "mycomp.h" /* booleans */

/* Processes a single command line. returns the command by the cmd_type enum and puts the arguments and argument count. */
cmd_type get_command(char line[], char *args_out[3], int *arg_count)
{
    cmd_type to_return; /* value to return at end */
    char *command, *rest;
    char line_copy[MAX_LINE_LEN];
	int total_line_length = strlen(line);
			/* take first sequence of non tab/space/line brake */
    command = strtok(line, "\t \n");

    if (command == NULL)
    {
        return NONE;
    }

    /* Parse command string to enum. if error, print error message */
    to_return = parse_cmd_str_enum(command);
    if (to_return == ERROR || to_return == STOP || strlen(command) == total_line_length-1) return to_return; /* if error or stop or command only (no args), no parse needed */

    /* To avoid editing the line but still checking unexepected comma, create a copy of the line */
    memcpy(line_copy, line, total_line_length);
    rest = command + strlen(command) + 1;
    if (*strtok(command + strlen(command)+1, "\t ") == ',') {
    	puts("Illegal comma");
    	return ERROR;
    }

    /* restore state of line, *rest points to end of command in line */
    memcpy(line, line_copy, total_line_length);

	/* Now, put the arguments themselves in the arguments array: */
	for (*arg_count = 0; *arg_count < MAX_ARGUMENT_COUNT && strlen(rest) > 0;) {
		char *first, *second, *curr_part;

		/* Part from current location to next comma */
		curr_part = strtok(rest, ",");
		rest = curr_part + strlen(curr_part) + 1;
		/* first non-white char sequence */
		first = strtok(curr_part, "\t ");

		/* after removing spaces and tabs there's nothing or there's , in the rest of the string */
		if (first == NULL || (rest < line+total_line_length && *rest == ',')) {
			puts("Multiple consecutive commas");
			return ERROR;
		}
		/* if all left is line break, then there are no more operands! */
		else if (*first == '\n') {
			break;
		}

		/* check if anything else after first non-white char sequence */
		second = strtok(NULL, "\t ");
		if (second != NULL && *second != '\n') {
			puts("Missing comma");
			return ERROR;
		}

		/* if last char in first is '\n', cut it. */
		if (*(first+strlen(first)-1) == '\n')
			first[strlen(first)-1] = '\0';

		/* now first holds the pointer to the first argument */
		args_out[(*arg_count)++] = first;

		/* if after separating commas there's \n or we're out of the line already */
		if (rest > line+total_line_length || *rest == '\n') break;
	}

	/* Something left afterwards (extraneous comma or text). is something was left in the buffer before, ignore it */
	if ((rest != NULL && strlen(rest) != 0 && rest < line+total_line_length)) {
		puts("Extraneous text after end of command");
		return ERROR;
	}

    /* successful parse, return the command type */
    return to_return;
}

/* Returns an enum cmd_type by command text (e.g, for text "read_comp" returns READ_COMP.
 * if unidentified, returns ERROR and prints an error message. */
cmd_type parse_cmd_str_enum(char command[])
{
    /* Parse command and return enum value */
    /* (strcmp returns 0 is equal) */
    if (strcmp(command, "read_comp") == 0) return READ_COMP;
    else if (strcmp(command, "print_comp") == 0) return PRINT_COMP;
    else if (strcmp(command, "add_comp") == 0) return ADD_COMP;
    else if (strcmp(command, "sub_comp") == 0) return SUB_COMP;
    else if (strcmp(command, "mult_comp_real") == 0) return MULT_COMP_REAL;
    else if (strcmp(command, "mult_comp_img") == 0) return MULT_COMP_IMG;
    else if (strcmp(command, "mult_comp_comp") == 0) return MULT_COMP_COMP;
    else if (strcmp(command, "abs_comp") == 0) return ABS_COMP;
    else if (strcmp(command, "stop") == 0) return STOP;
    else
    {
        /* Not any of the above, print error message & return error */
        puts("Undefined command name");
        return ERROR;
    }
}