#include <stdio.h>
#include <ctype.h>
#include "tester.h" /* This header file is used to declare function for the code below. You should NOT use it. */

int main()
{
	int stop = false;
	char curr_selection;
	curr_selection = '?';
	printf("2020b/11 Tester - match(char[], char[]) - @AvivNaaman (GPLv3.0)");
	while (!stop) {
		printf("\n[A] for testing everything | [M] for testing match | [E] for exit: ");
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
	/* Assuming we're using fgets, we also need to NOT count the \n at the end! */
	int err_cntr = 0, success_cntr, cntr = 0;
	char method_des[] = "match(char[], char[])";
	printf("\nTesting %s:\n", method_des);
	assert_eq(1, match("viva\n","vviaaa\n"), method_des, 35, &cntr, &err_cntr);
	assert_eq(0, match("viva\n","viva\n"), method_des, 36, &cntr, &err_cntr);
	assert_eq(0, match("viva\n","vivaviv\n"), method_des, 37, &cntr, &err_cntr);
	assert_eq(1, match("viva\n","aviva\n"), method_des, 38, &cntr, &err_cntr);

	assert_eq(7, match("abc\n","adcbacbabc\n"), method_des, 40, &cntr, &err_cntr);
	assert_eq(1, match("db\n","bdb\n"), method_des, 41, &cntr, &err_cntr);
	assert_eq(0, match("affa\n","abfassf\n"), method_des, 42, &cntr, &err_cntr);
	assert_eq(3, match("abc\n","acbabcabb\n"), method_des, 43, &cntr, &err_cntr);

	assert_eq(0, match("a\n","a\n"), method_des, 45, &cntr, &err_cntr);
	assert_eq(1, match("a\n","ba\n"), method_des, 46, &cntr, &err_cntr);
	assert_eq(19, match("a\n","qwertyuiopoiuytrewqa\n"), method_des, 47, &cntr, &err_cntr);
	assert_eq(6, match("abcd\n","bbbafgdbcd\n"), method_des, 48, &cntr, &err_cntr);
	assert_eq(0, match("lambda\n","lambda\n"), method_des, 49, &cntr, &err_cntr); /* Perfect match */
	assert_eq(0, match("lambda\n","adbmal\n"), method_des, 50, &cntr, &err_cntr); /* No match at all */
	assert_eq(0, match("viva\n","hello\n"), method_des, 51, &cntr, &err_cntr); /* No match at all */
	assert_eq(6, match("match\n","aathhcmftch\n"), method_des, 52, &cntr, &err_cntr);
	assert_eq(0, match("match\n","mamah\n"), method_des, 53, &cntr, &err_cntr);
	assert_eq(2, match("match\n","mamahch\n"), method_des, 54, &cntr, &err_cntr);
	assert_eq(2, match("$%$\n","$$$%$\n"), method_des, 55, &cntr, &err_cntr);
	assert_eq(3, match("^&&\n","@^%^&*\n"), method_des, 56, &cntr, &err_cntr);
	assert_eq(2, match("465\n","65465\n"), method_des, 57, &cntr, &err_cntr);
	assert_eq(17, match("5\n","1e231798uifhj89235eqwfcd\n"), method_des, 58, &cntr, &err_cntr);
	/* Some GUIDs to test with: */
	assert_eq(24, match("19ec77c5","267d56feaedc453a91e338f5f9ec18c5"), method_des, 60, &cntr, &err_cntr);
	assert_eq(14, match("45a8852277","f6e1e95357294545a8b52a77a79af53e"), method_des, 61, &cntr, &err_cntr);
	assert_eq(5, match("bc7fa9643aa","bb5f47c7ea9343abaeaf858c327dd416"), method_des, 62, &cntr, &err_cntr);
	assert_eq(4, match("674bccd2b4c48be3","106516410cd2b4c48be14b4b1d76e220e"), method_des, 63, &cntr, &err_cntr);
	assert_eq(17, match("6681b0908aab869","c3388b96398a4837ab681b0908abb86f"), method_des, 64, &cntr, &err_cntr);

	success_cntr = cntr - err_cntr;
	printf("\n===========================================================================================");
	printf("\nYour match(char[], char[]) method passed %d out of %d tests. ", success_cntr, cntr);
	if (err_cntr == 0) printf("That's great!\nFollow & feedback at https://github.com/avivnaaman/openu-20465-2020b\n");
	else printf("See the above output for more information.\n");
	printf("=============================================================================================\n");
}

void assert_eq(int expected, int actual, char location_description[], int line, int *counter, int *failed_counter)
{
	if (expected != actual)
	{
		printf("\n*****************************************************\n");
		printf("TEST FAILED! at %s, line %d.\nExpected: %d\n But Got: %d", location_description, line, expected, actual);
		printf("\n*****************************************************\n");
		(*failed_counter)++;
	}
	(*counter)++;
}
