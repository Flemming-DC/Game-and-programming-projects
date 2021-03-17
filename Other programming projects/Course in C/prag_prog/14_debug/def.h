#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <math.h>

struct rparams
  {
    double a;
    double b;
  };

int rod (const gsl_vector * x, void *params, gsl_vector * f);

int print_state (size_t iter, gsl_multiroot_fsolver * s);



