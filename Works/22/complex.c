/*
 * Contains operations for complex manipulation using the structure complex defined at complex.h
 * such as, reading, printing, and creating default complex.
 * prototypes are at complex.h.
 */
#include <stdlib.h> /* For malloc & free */
#include <math.h> /* For abs */
#include <stdio.h> /* For printf */
#include "complex.h"

/* Creates a "clean" instance of a complex (represented by 0+0i) and returns a pointer to it */
complex *empty_complex()
{
    complex *new = (complex *)malloc(sizeof(complex));
    if (!new)
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    /* Default value: 0.0 for both fields */
    new->imaginary = new->real = 0.0;
    return new;
}

/* Assigns the second argument as the real part of the complex argument, and the third as it's imaginary part. */
void read_complex(complex *c, double real, double img)
{
    /* Assignment */
    c->real = real;
    c->imaginary = img;
}

/* Prints a complex number, formatted as real+(img)i. e.g: 5.00-(3.25)i, 2.84+(7.99)i */
void print_complex(complex *toprint)
{
    /* Two-digit precision after dot for both numeric values */
    /* Print real, then evaluate the sign of imaginary part, at the end the (image coefficient)i */
    printf("%.2f", toprint->real);
    printf((toprint->imaginary >= 0 ? "+" : "-"));
    printf("(%.2f)i\n", fabs(toprint->imaginary));
}

/* Prints the sum of both complex arguments. */
void add_complex(complex *c1, complex *c2)
{
    complex *to_print = empty_complex(); /* Temp */
    /* (a+bi)+(c+di)=(a+c)+(b+d)i */
    to_print->imaginary = (c1->imaginary)+(c2->imaginary);
    to_print->real = (c1->real)+(c2->real);
    print_complex(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the subtraction result of the second argument from the first. */
void sub_complex(complex *c1, complex *c2)
{
    complex *to_print = empty_complex(); /* Temp */
    /* (a+bi)-(c+di)=(a-c)+(b-d)i */
    to_print->imaginary = (c1->imaginary)-(c2->imaginary);
    to_print->real = (c1->real)-(c2->real);
    print_complex(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the multiplication result of the complex argument and the doule number. */
void mult_complex_real(complex *c, double real)
{
    complex *to_print = empty_complex(); /* Temp */
    /* s(a+bi)=sa+sbi */
    to_print->imaginary = (c->imaginary)*real;
    to_print->real = (c->real)*real;
    print_complex(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the multiplication result of the complex argument by the double argument*(i) */
void mult_complex_img(complex *c, double img)
{
    complex *to_print = empty_complex(); /* Temp */
    /* si(a+bi)=sai+sbi*i=-sb+sai */
    to_print->imaginary = img * (c->real);
    to_print->real = (-1) * img * (c->imaginary);
    print_complex(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the multiplication result of both complexes, passed as arguments to the function. */
void mult_complex_complex(complex *c1, complex *c2)
{
    complex *to_print = empty_complex(); /* Temp */

    /*(a+bi)(c+di)=ac+bci+adi+bdi*i=(ac-bd)+(ad+bc)i*/
    to_print->imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);
    to_print->real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);

    print_complex(to_print);
    free(to_print); /* Free the allocated memory */
}

/* Prints the absolute value of the first complex, given as argument. */
double abs_complex(complex *c)
{
	/* formula: sqrt(real^2+img^2) */
    return sqrt(pow(c->real, 2)+pow(c->imaginary, 2));
}
