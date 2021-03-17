#ifndef HAVE_MY_H_FIL
#define HAVE_MY_H_FIL
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>

struct rparams
  {
    double a;
  };

int rosenbrock_f (const gsl_vector * v, void *params, gsl_vector * f);

int rosenbrock_df (const gsl_vector * v, void *params, gsl_matrix * J);

int rosenbrock_fdf (const gsl_vector * v, void *params, gsl_vector * f, gsl_matrix * J);

int print_state (size_t iter, gsl_multiroot_fdfsolver * s);

#endif
