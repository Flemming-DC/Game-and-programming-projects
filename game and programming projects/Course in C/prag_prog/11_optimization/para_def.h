#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_multimin.h>

double my_f (const gsl_vector *v, void *params);

void my_df (const gsl_vector *v, void *params, gsl_vector *df);

void my_fdf (const gsl_vector *v, void *params, double *f, gsl_vector *df);






