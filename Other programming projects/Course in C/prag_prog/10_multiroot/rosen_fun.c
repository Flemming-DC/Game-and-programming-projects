/*
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
*/
#include"rosen_def.h"

int
rosenbrock_f (const gsl_vector * v, void *params,
              gsl_vector * f)
{
  double a = ((struct rparams *) params)->a;

  const double x = gsl_vector_get (v, 0);
  const double y = gsl_vector_get (v, 1);

  const double fx = -2*(1-x)-4*a*(y-x*x)*x;
  const double fy = 2*a*(y-x*x);

  gsl_vector_set (f, 0, fx);
  gsl_vector_set (f, 1, fy);

  return GSL_SUCCESS;
}


