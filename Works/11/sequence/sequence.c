/*
 * A program which gets a string from the user and returns whether it's ascending, really ascending, descending, really descending or not ordered by ASCII code.
 * Assuming no white chars are given and there aren't more than 100 chars in the string.
 */
#include <stdio.h>

/* Booleans definitions */
#define TRUE 1
#define FALSE 0

/* Maximum input length */
#define MAX_INPUT_LENGTH 100

/* Prints the sequence type of the string argument, by ASCII code */
void f_sequence(char[]);

/* Entry point */
int main()
{
	char input_str[MAX_INPUT_LENGTH];
	/* Get the string and call our f_sequence function */
	printf("Enter the string you'd like to find it's sequence type (No white chars): ");
	scanf("%s", input_str);
	/* call function to print the sequence type */
	f_sequence(input_str);
	return 0;
}

/* Prints the sequence type of the string argument, by ASCII code */
void f_sequence(char string[])
{
	/* 
	 * Solution: Running over the string, comparing each char to the previous one (by ASCII code, simple comparison).
	 * turn flags on (booleans) if equal/ascnding/descending. at the end, check which flags are on and print by that.
	 */
	int i;
	/* "booleans" to indicate whether any pass between chars is equal, 
	   ascending or descending - all defaulted to "FALSE" */
	int any_equal, any_asc, any_desc;

	/* store current and previous charachter for the loop */
	char curr_char, prev_char;
	/* Print the string, sequence type later */
	printf("\nThe string \"%s\" is ", string);

	curr_char = string[0]; /* Keep everything lower */
	any_equal = any_asc = any_desc = FALSE;

	/* Edge case: string is empty => considered as ascending */
	if (curr_char == '\0') puts("ascending."); /* Complete the started senetence */

	for (i = 1; string[i] && !(any_asc && any_desc); i++) /* While not done and no conflict */
	{
		prev_char = curr_char;
		curr_char = string[i];
		if (prev_char < curr_char) any_asc = TRUE;
		else if (prev_char > curr_char) any_desc = TRUE;
		else any_equal = TRUE;
	}

	/* Print sequence type */
	if (any_desc && any_asc) puts("not ordered."); /* both asc and desc => not ordered */
	else if (any_desc && any_equal) puts("descending."); /* desc and no change somewhere => just descending */
	else if (any_desc) puts("really descending."); /* only desc => really descending */
	else if (any_asc && !any_equal) puts("really ascending."); /* only asc => really ascending */
	else puts("ascending."); /* only ascending or/and only equal => just ascending */
}
