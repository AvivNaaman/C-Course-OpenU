/*
 * An interactive program for complex number calculation
 * Modules:
 *  mycomp  - entry point
 *  input   - input analysis helper functions
 *  complex - complex number calculation helper functions
 *
*/
#include <stdio.h>
#include <string.h> /* For strlen */
#include <stdlib.h> /* For atof */
#include <ctype.h>
#include "input.h"
#include "mycomp.h"

/* Holds our user-exposed complexes, A@[0],...,F@[5] */
static complex *complexes[6];

/* Program entry point */
int main() {
	/* holds the current line from user & analyzes parameters */
	char line[MAX_LINE_LEN], *args[3];
	/* user's argument count + general counter */
	int arg_count, i;
	/* user's entered command */
	cmd_type command;

	/* Initialize A-F variables in the array - memory allocation + defaulting to 0+0i */
	for (i = 0; i < USER_VAR_COUNT; i++) {
		complexes[i] = empty_complex();
	}

	/* Basic instructions + First prompt */
	printf("Type a command and press enter to execute:\n>> ");

	/* as long as EOF isn't typed previously, get string from stdin,
	 * analyze it's command and arguments, validate them and call the function from complex module. */
	while (fgets(line, MAX_LINE_LEN, stdin) != NULL) {
		printf("%s", line); /* Print the current input */
		command = get_command(line, args, &arg_count); /* Process command and get arguments */

		/* After got command, validate the parameters and call functions from complex.c */
		switch (command) {
			/* CMD <var>,<double>,<double> */
			case READ_COMP:
				/* validate */
				if (check_arg_num(3, arg_count)) {
					complex *var = get_var_by_name(args[0]);
					if (var) {
						/* pointers for strtod result (for conversion errors) */
						char *err0 = NULL, *err1 = NULL;
						double real_val = strtod(args[1], &err0);
						double img_val = strtod(args[2], &err1);
						/* if conversion failed... (= err0 holds pointer to non-white char) */
						if (!(isspace((unsigned char) *err0) || *err0 == 0) ||
						    !(isspace((unsigned char) *err1) || *err1 == 0)) {
							puts("Invalid parameter - not a number");
							break;
						}
						read_complex(var, real_val, img_val);
					}
				}
				break;
				/* CMD <var> */
			case PRINT_COMP:
			case ABS_COMP:
				/* validate */
				if (check_arg_num(1, arg_count)) {
					complex *var = get_var_by_name(args[0]);
					if (var) {
						if (command == PRINT_COMP)
							print_complex(var);
						else
							printf("%.2f", abs_complex(var));
					}
				}
				break;
				/* CMD <var> <var> */
			case ADD_COMP:
			case SUB_COMP:
			case MULT_COMP_COMP:
				/* validate */
				if (check_arg_num(2, arg_count)) {
					complex *var1 = get_var_by_name(args[0]);
					complex *var2 = get_var_by_name(args[1]);
					if (var1 && var2) {
						/* Call the appropriate function */
						switch (command) {
							case ADD_COMP:
								add_complex(var1, var2);
								break;
							case SUB_COMP:
								sub_complex(var1, var2);
								break;
							case MULT_COMP_COMP:
								mult_complex_complex(var1, var2);
								break;
							default:
								break;
						}
					}
				}
				break;
				/* CMD <var>, <double> */
			case MULT_COMP_REAL:
			case MULT_COMP_IMG:
				/* validate */
				if (check_arg_num(2, arg_count)) {
					complex *var1 = get_var_by_name(args[0]);
					if (var1) {
						/* pointer for strtod result (for conversion errors) */
						char *err0 = NULL;
						double val = strtod(args[1], &err0);
						if (!(isspace((unsigned char) *err0) || *err0 == 0)) {
							puts("Invalid parameter - not a number");
							break;
						}
						/* call the right function */
						if (command == MULT_COMP_REAL)
							mult_complex_real(var1, val);
						else
							mult_complex_img(var1, val);
					}
				}
				break;
				/* Exit with nice message */
			case STOP:
				puts("\nGoodbye!");
				return 0;
			default: /* Error/None: Error was printed, get another line from user */
				break;
		}
		/* Prompt sign */
		printf(">> ");
	}
	/* Exited using EOF */
	puts("Please exit using the stop command.");
	return 0;
}

/* Returns a pointer to the user variable (A-F) by it's name. If no such, return NULL */
complex *get_var_by_name(char *name) {
	/* validate variable is in range, make it as flexible as possible */
	if (strlen(name) == 1 && name[0] >= 'A' && name[0] <= ('A'+USER_VAR_COUNT)) {
		/* First variable is A, then B, C, etc, so we can: */
		return complexes[name[0] - 'A'];
	}
	/* Validation failed - print error */
	puts("Undefined complex variable");
	return NULL;
}

/* Returns whether required == actual and prints error if needed. */
boolean check_arg_num(int required, int actual) {
	if (required == actual) return TRUE;
	else if (required < actual) puts("Extraneous text after end of command.");
	else puts("Missing Argument");
	return FALSE;
}
