/*
 * A program to convert number between 0 to 99 to their names.
 */
#include <stdio.h>
#include <stdlib.h>

/* Prints the string representation of a number between 0-99 to the specified file as is. */
void print_number_name(int number, FILE *print_to);

/* Entry Point */
int main(int argc, char *argv[]) {
	/* file descriptor pointers */
	FILE *input_file, *output_file;
	/* current number to process */
	int curr_number;

	/* Too many arguments (more than 2) */
	if (argc > 3){
		fputs("Too many arguments", stderr);
		exit(1);
	}

	/* Default I/O for program is stdin/stdout. if args to change them are specified, they will be replaced. */
	input_file = stdin;
	output_file = stdout;

	/* if there is at least 1 argument, the first is used as input */
	if (argc >= 2) {
		/* Try to open file. if returns 0 (NULL) print error and exit with stat code 1 (error) */
		if (!(input_file = fopen(argv[1], "rt"))) {
			fprintf(stderr, "Can't read from file %s.\n", argv[1]);
			exit(1);
		}
	}

	/* if there are 2 argument, the second is used as output   */
	if (argc == 3) {
		/* Try to open file. if returns 0 (NULL) print error and exit with stat code 1 (error) */
		if (!(output_file = fopen(argv[2], "wt"))) {
			fprintf(stderr, "Can't write/create file %s.\n", argv[2]);
			exit(1);
		}
	}

	/* read first number from input file, if got EOF before any number, nothing more to process. */
	while (fscanf(input_file, "%d", &curr_number) != EOF) {
		print_number_name(curr_number, output_file); /* print string representation */
		fprintf(output_file,"\n"); /* Brake line */
	}

	fclose(input_file);
	fclose(output_file);

	/* Done */
	return 0;
}

/* number names in the range of 0-19 */
char *units_names[] =  {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                        "seventeen", "eighteen", "nineteen"};

/* Tens from 20-90 */
char *tens_names[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

/* Prints the string representation of a number between 0-99 to the specified file as is. */
void print_number_name(int number, FILE *print_to)
{
	int tens, units;
	/* if number is less than 20, print it from the units_names array */
	if (number <= 19) {
		/* Print and exit */
		fprintf(print_to, "%s", units_names[number]);
		return;
	}
	/* Otherwise, get first and second digit. */
	tens = number / 10;
	units = number % 10;

	/* Print tens */
	fprintf(print_to, "%s ", tens_names[tens]);

	/* if there is no units digit, print just the tens */
	if (units == 0) return;

	/* if there is units digit, print it and break line. */
	fprintf(print_to, "%s", units_names[units]);
}