#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>

double u_ode(double, double);

double u_ode_plot(double, double);

struct rparams
  {
    double r_max;
  };

int
u_lim (const gsl_vector * x, void *params, gsl_vector * f);

int u_print (size_t iter, gsl_multiroot_fsolver * s);
