#include <stdio.h>
/* Aviv Naaman / 2020b / GPL3.0 */
/* Counts the even number putted in stdin until EOF is enetered, and returns it's count */
int main()
{
	int count, curr_num; 
	count = 0; /* Reset count to 0 */
	while (scanf("%d", &curr_num) != EOF) /* while not end (CTRL+D linux/unix, CTRL+Z win nt) */
	{
		/* Increase count if eve */
		if (curr_num % 2 == 0) 
			count+=1;
	}
	
	/* Print final count */
	printf("Eve count is: %d", count);

	return 0;
}