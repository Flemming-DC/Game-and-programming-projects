/*
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
*/
#include "u_def.h"


int
u_lim (const gsl_vector * x, void *params,
              gsl_vector * f)
{
//  double r_max = ((struct rparams *) params)->r_max;
  double r_max = *(double*)params;

  const double E = gsl_vector_get (x, 0);

  const double U = u_ode(E,r_max);

  gsl_vector_set (f, 0, U);

  return GSL_SUCCESS;
}
