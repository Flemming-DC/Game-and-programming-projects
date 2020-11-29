#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>


double feed_forward(double, gsl_vector*);
double derivative(double, gsl_vector*);
double integral(double, gsl_vector*);

double square_deviation(gsl_vector*, gsl_vector*, gsl_vector*);

void qnewton(double beta(gsl_vector*, gsl_vector*, gsl_vector*)
	     , gsl_vector*, gsl_vector*, gsl_vector*, double);

void train_without_guess(gsl_vector*, gsl_vector*, gsl_vector*, gsl_matrix*, int, double);
void train_with_guess(gsl_vector*, gsl_vector*, gsl_vector*, double);



