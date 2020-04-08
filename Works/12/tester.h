/* NOTICE! Put all the typedefs & constants in adjacency.h, so i'll be able to use that! */
#include "adjacency.h"

int path(adjmat, int u, int v);


void test_all();
void test_path();
void assert_true(int to_assert, char description[], int line, int *counter, int *failed_counter);