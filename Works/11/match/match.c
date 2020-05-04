/*
 * A porgram that gets two string from user - pattern & text, and prints the index in text where there's the best match of chars from.
 * if pattern longer than text, prints -1 because no such one. Assuming the user won't enter more than 1023 characters.
 */
#include <stdio.h>
#include <limits.h> /* for INT_MAX */
#include <string.h>

/* Assuming the user won't enter a line longer then 1024 chars */
#define MAX_STRING_LENGTH 1024

/* Return the index where the text matches the most the pattern at. if pattern longer than text, returns -1 */
int match(char pattern[], char text[]);
/* Replaces all the '\n' by '\0' in a string. */
void cutFromNewLine(char string[]); 

/* Entry Point */
int main()
{
	/* buffers for pattern & text inputs */
	char pattern[MAX_STRING_LENGTH], text[MAX_STRING_LENGTH];
	int indx; /* Final returned index from match(char[], char[]) */
	puts("Enter the pattern: ");
	fgets(pattern, MAX_STRING_LENGTH, stdin);
	puts("Enter the Text: ");
	fgets(text, MAX_STRING_LENGTH, stdin);	
	/* remove \n from the end, shouldn't go to the comparison */
	cutFromNewLine(pattern);
	cutFromNewLine(text);
	/* Print the inputs */
	printf("\nThe pattern is: %s And the text is: %s.\n", pattern, text);
	/* print the index */
	indx = match(pattern, text);
	printf("The pattern matches the most to the text from index %d\n", indx);
	return 0;
}

/* Returns the first index where the pattern matches the most to the text, starting from the index */
int match(char pattern[], char text[])
{
	/* 
	 * Solution: running on the text, from each char in the text run on the pattern.
	 * store the minimum mismatches and the index from, each time choose the minimum
	 * (between current minimum and current mismatches from char in text). finally return the minimum.
	 */
	int min_indx, min_mismatches; /* Stores the minimum mismatches count and the place from */
	int text_indx, pattern_indx; /* indexes for check in both strings */

	/* pattern can't be longer than the text. */
	if (strlen(pattern) > strlen(text)) return -1;
	
	/* Defaults: maximum value of integer for min_mismatches (because we'd like to find minimal mismatches) */
	min_mismatches = INT_MAX;
	min_indx = 0;
	for (text_indx = 0; text[text_indx]; text_indx++)
	{
		/* save index for next loop */
		int temp_text_indx = text_indx; /* temporary index in text string */
		int curr_mismatch_count = 0; /* counter for mismatches in current check */
		/* count char mismatches foreach char, starting at text_indx, until we're at the end of a char */
		for (pattern_indx = 0; pattern[pattern_indx] && curr_mismatch_count != INT_MAX; pattern_indx++)
		{
			if (!text[temp_text_indx]) curr_mismatch_count = INT_MAX; /* not enough chars in the part from text_indx to fit pattern */
			else if (text[temp_text_indx] != pattern[pattern_indx])
				curr_mismatch_count++;
			temp_text_indx++;
		}
		/* if our current mismatches count is less than the smallest yet,
		set the minimum to the current */
		if (curr_mismatch_count < min_mismatches) 
		{
			min_mismatches = curr_mismatch_count;
			min_indx = text_indx;
		}
	}
	return min_indx; /* Return the index where there are the least mismatches */
}

/* Replaces \n by \0 */
void cutFromNewLine(char string[])
{
	int i;
	/* iterate & reaplce */
	for (i = 0; string[i]; i++)
	{
		if (string[i] == '\n') string[i] = '\0';
	}
}
