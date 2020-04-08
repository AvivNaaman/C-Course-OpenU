#include <stdio.h>
#include <ctype.h>
#include "tester.h" /* This header file is used to declare function for the code below. You should NOT use it. */

int main()
{
	int stop = FALSE;
	char curr_selection;
	curr_selection = '?';
	puts("2020b/12 Tester - path(adjmat, int, int) - @AvivNaaman (GPLv3.0)");
    puts("NOTICE! In these tests, we assume you defined N as 15. make the necessary changes if required, to make the tests reliable!");
	while (!stop) {
		printf("\n[A] for testing everything | [P] for testing path | [E] for exit: ");
		do 
		{
			scanf("%c", &curr_selection);
		} while (curr_selection == '\n');
		if (curr_selection == EOF || tolower(curr_selection) == 'e') stop = TRUE;
		else if (tolower(curr_selection) == 'a') test_all();
		else if (tolower(curr_selection) == 'p') test_path();
	}
	return 0;
}

void test_all() 
{
	test_path();
}

void test_path() 
{
	/* Assuming we're using fgets, we also need to NOT count the \n at the end! */
	int failed_cntr = 0, success_cntr, cntr = 0;
	char method_des[] = "match(char[], char[])";
	printf("\nTesting %s:\n", method_des);

    adjmat adjmat0 = {{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,TRUE,FALSE,FALSE},{TRUE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,TRUE,TRUE,FALSE,FALSE,FALSE,TRUE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,TRUE},{FALSE,FALSE,FALSE,FALSE,FALSE,TRUE,FALSE,FALSE,FALSE,FALSE,FALSE,TRUE,FALSE,FALSE,FALSE},{FALSE,TRUE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,TRUE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,TRUE,FALSE,FALSE,FALSE,TRUE,FALSE,FALSE,TRUE,FALSE,FALSE,FALSE,FALSE},{FALSE,FALSE,FALSE,FALSE,TRUE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE}};

    
    assert_true(path(adjmat0,6,10), method_des, 41, &cntr, &failed_cntr);
    assert_true(path(adjmat0,6,4), method_des, 42, &cntr, &failed_cntr);
    assert_true(path(adjmat0,8,4), method_des, 43, &cntr, &failed_cntr);
    assert_true(path(adjmat0,14,4), method_des, 44, &cntr, &failed_cntr);
    assert_true(path(adjmat0,9,12), method_des, 45, &cntr, &failed_cntr);
    assert_true(path(adjmat0,13,1), method_des, 46, &cntr, &failed_cntr);
    assert_true(path(adjmat0,10,1), method_des, 47, &cntr, &failed_cntr); /* No more trues after this*/
    assert_true(!path(adjmat0,10,0), method_des, 48, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,7,0), method_des, 49, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,4,10), method_des, 50, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,5,12), method_des, 51, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,12,5), method_des, 52, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,7,12), method_des, 53, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,12,7), method_des, 54, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,4,0), method_des, 55, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,0,4), method_des, 56, &cntr, &failed_cntr);
    assert_true(!path(adjmat0,-1,-1), method_des, 57, &cntr, &failed_cntr); /* Index out of lower range */
    assert_true(!path(adjmat0,321,123), method_des, 57, &cntr, &failed_cntr); /* Index out of high range */

	success_cntr = cntr - failed_cntr;
	puts("\n===========================================================================================");
	printf("Your match(char[], char[]) method passed %d out of %d tests. ", success_cntr, cntr);
	if (failed_cntr == 0) printf("That's great!\nFollow & feedback at https://github.com/avivnaaman/openu-20465-2020b\n");
	else printf("See the above output for more information.\n");
	printf("=============================================================================================\n");
}
void assert_true(int to_assert, char location_description[], int line, int *counter, int *failed_counter)
{
	if (!to_assert)
	{
		printf("\n*****************************************************\n");
		printf("TEST FAILED! at %s, line %d.\nExpected: TRUE but got FALSE", location_description, line);
		printf("\n*****************************************************\n");
		(*failed_counter)++;
	}
	(*counter)++;
}
