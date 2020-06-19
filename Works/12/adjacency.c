/*
 * A program which gets a matrix from the user, representing a directed tree, by adajacencies.
 * The program gets a couple of node numbers, and returns whether there's a directed path from first to second.
 * It stops collecting couples when it gets a couple of (-1, -1)
 */
#include <stdio.h>
#include "adjacency.h" /* constants & adjmat definition */

/* Returns whether there's a directed path from node numbered by the second argument to
the node numbered by the third argument, in the tree represented by the adjmat argument. */
int path(adjmat, int, int);

/* Prints the adjmat argument, each row in a line, each cell seperated by space. */
void print_adjmat(adjmat);


/* Entry point */
int main()
{
    int i;
    int u,v, result, stop; /* For later (path function) */
    adjmat curr_adjmat;
    printf("Enter %d lists of %d booleans [0|1] seperated by space. press enter after each list:\n", N, N);
    /* Assuming input is in the correct format */
    for (i = 0; i < N; i++)
    {
        int input_indx, adjmat_row_indx = 0;
        /* Process single line */
        /* Temp string for current line entered */
        char temp_line[N*3]; 
        fgets(temp_line, N*3, stdin);

        /* move values to adjmat */
        /* foreach char in input, if 0 or 1 set in the matrix */
        for (input_indx = 0; temp_line[input_indx]; input_indx++)
        {
            if (temp_line[input_indx] == '0' || temp_line[input_indx] == '1')
            {
                /* add current number to array '0'-'0' = 0, '1'-'0'=1 */
                curr_adjmat[i][adjmat_row_indx] = (temp_line[input_indx] - '0' ? TRUE : FALSE);
                adjmat_row_indx++;
            }
        }
    }

    /* Print the matrix */
    print_adjmat(curr_adjmat);
    
    /* Get input & call path function */
    u = v = 0; /* temporary node identifiers */
    do {
        printf("\nEnter two node identifiers, enter after each. -1 -1 for exit:\n");
        stop = scanf("%d%d", &u, &v);
        /* Make sure no EOF detected and exit value isn't entered in both (as defined in header) */
        stop = !(stop != EOF && v != EXIT_VALUE && u != EXIT_VALUE);
        if (!stop) {
            result = path(curr_adjmat, u,v);
	    /* Print a nice message to the user */
            printf("There is");
            printf(result == TRUE ? " a" : "n't");
            printf(" path from (%d) to (%d).\n", u, v);
        }
    } while (!stop); /* Not EOF and not both values are the exit ones as defined in header */


    return 0;
}


/* Prints the adjmat, provided as argument. each row in line, each cell seperated by a space */
void print_adjmat(adjmat mat)
{
    int i, j;
    puts("\nThe matrix is: ");
	/* Iterate rows & columns: */
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", mat[i][j]); /* Print value */
        }
        puts(""); /* line brake on row end */
    }
}

/* Returns whether there's a directed path between the nodeu to the node v,
in the tree described by the adjmat argument. */
int path(adjmat mat, int u, int v)
{
    /* Solution: Recursion, with backtracing. we'll try calling the function from the cells in the row u where
    the cell value is TRUE. if we got to destination (means u == v) that's great! return true. otherwise return false */
    int indx, flag;
    /* Out of matrix size */
    if (u >= N || v >= N || v < 0 || u < 0) return FALSE;
    /* if u == v we got to the place we want */
    if (v == u) return TRUE;
    /* flag for backtracking (we try calling from multiple cells, so we'll use that with || operator) */
    flag = FALSE;
    /* Call this function for each cell in u row where TRUE */
    for (indx = 0; indx < N && !flag; indx++)
    {
        /* If current cell in row u is true, call this function for current cell and same destination */
        if (mat[u][indx] == TRUE)
        {
            flag = flag || path(mat, indx, v);
        }
    }
    /* Return result */
    return flag;
}
