#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_multimin.h>

double r_fun (const gsl_vector *v, void *params);

void dr_fun (const gsl_vector *v, void *params, gsl_vector *dr);

void rdr_fun (const gsl_vector *v, void *params, double *r, gsl_vector *dr);

