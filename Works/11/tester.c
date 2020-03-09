#include <stdio.h>
#include <ctype.h>
#include "tester.h"
#define true 1
#define false 0
int main()
{
	int stop = false;
	char curr_selection;
	curr_selection = '?';
	printf("2020b/11 Tester - match(char[], char[])");
	while (!stop) {
		printf("\n[A] for testing everything [M] for testing match [E]/EOF for exit: ");
		do 
		{
			scanf("%c", &curr_selection);
		} while (curr_selection == '\n');
		if (curr_selection == EOF || tolower(curr_selection) == 'e') stop = true;
		else if (tolower(curr_selection) == 'a') test_all();
		else if (tolower(curr_selection) == 'm') test_match();
	}
	return 0;
}

void test_all() 
{
	test_match();
}

void test_match() 
{
	int err_cntr = 0, success_cntr, cntr = 0;
	char method_des[] = "match(char[], char[])";
	printf("\nTesting %s:\n", method_des);

	assert_eq(1, match("viva","vviaaa"), method_des, 35, &cntr, &err_cntr);
	assert_eq(0, match("viva","viva"), method_des, 36, &cntr, &err_cntr);
	assert_eq(0, match("viva","vivaviv"), method_des, 37, &cntr, &err_cntr);
	assert_eq(1, match("viva","aviva"), method_des, 38, &cntr, &err_cntr);

	assert_eq(7, match("abc","adcbacbabc"), method_des, 40, &cntr, &err_cntr);
	assert_eq(1, match("db","bdb"), method_des, 41, &cntr, &err_cntr);
	assert_eq(0, match("affa","abfassf"), method_des, 42, &cntr, &err_cntr);
	assert_eq(3, match("abc","acbabcabb"), method_des, 43, &cntr, &err_cntr);

	assert_eq(0, match("a","a"), method_des, 45, &cntr, &err_cntr);
	assert_eq(1, match("a","ba"), method_des, 46, &cntr, &err_cntr);
	assert_eq(6, match("abcd","bbbafgdbcd"), method_des, 47, &cntr, &err_cntr);
	assert_eq(0, match("lambda","lambda"), method_des, 48, &cntr, &err_cntr);
	assert_eq(0, match("lambda","adbmal"), method_des, 49, &cntr, &err_cntr);

	assert_eq(6, match("match","aathhcmftch"), method_des, 51, &cntr, &err_cntr);

	success_cntr = cntr - err_cntr;
	printf("\nYour match(char[], char[]) method passed %d out of %d tests. ", success_cntr, cntr);
	if (err_cntr == 0) printf("That's great! follow & feedback at https://github.com/avivnaaman/openu-20465-2020b\n");
	else printf("See the above output for more information.\n");
}

void assert_eq(int expected, int actual, char location_description[], int line, int *counter, int *failed_counter)
{
	if (expected != actual)
	{
		printf("\n*****************************************************\n");
		printf("TEST FAILED! at %s, line %d.\n Expected: %d\n But Got: %d", location_description, line, expected, actual);
		printf("\n*****************************************************\n");
		(*failed_counter)++;
	}
	(*counter)++;
}
