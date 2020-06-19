/* Contains assignment-wide definitions (such as booleans) and prototypes for main-used function */

#include "complex.h" /* for complex */
#define USER_VAR_COUNT 6 /* count of user accessible variables */


/* Basic boolean values (t/f) */
typedef enum booleans { FALSE = 0, TRUE } boolean;


/* Compares required to actual, if equal return TRUE, otherwise FALSE. prints an error message to the user if FALSE. */
boolean check_arg_num(int required, int actual);

/* Returns the pointer to the user variable (A-F) by it's name. If no such, returns NULL and prints an error */
complex *get_var_by_name(char *name);
