/*
 * Contains definition of booleans, complex structure definition, and prototypes for operations
 * on complex numbers, including creating an empty complex, read complex and printing it.
 */

/* Complex structure definition */
typedef struct complex {
    /* real - real part, imaginary - i coefficient */
    double real, imaginary;
} complex;

/* Creates a "clean" instance of a complex (represented by 0+0i) and return the pointer to it */
complex* empty_complex();

/* Assigns the second argument as the real part of the complex argument, and the third as it's imaginary part. */
void read_complex(complex*, double, double);

/* Prints a complex number, formatted as real+(img)i. e.g: 5.00-(3.25)i, 2.84+(7.99)i */
void print_complex(complex*);

/* Prints the sum of both complex arguments. */
void add_complex(complex *, complex*);

/* Prints the subtraction result of the second argument from the first. */
void sub_complex(complex *, complex*);

/* Prints the multiplication result of the complex argument and the doule number. */
void mult_complex_real(complex *, double);

/* Prints the multiplication result of the complex argument by the double argument*(i) */
void mult_complex_img(complex *, double);

/* Prints the multiplication result of both complexes, passed as arguments to the function. */
void mult_complex_complex(complex *, complex*);

/* Returns the absolute value of the complex, given as argument. */
double abs_complex(complex *);
