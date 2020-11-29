/*
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
*/
#include "rosen_def.h"

int
rosenbrock_df (const gsl_vector * v, void *params,
               gsl_matrix * J)
{
  const double a = ((struct rparams *) params)->a;

  const double x = gsl_vector_get (v, 0);
  const double y = gsl_vector_get (v, 1);

  const double Jxx = 2+4*a*(x*x+y);
  const double Jxy = -4*a*x;
  const double Jyx = -4*a*x;
  const double Jyy = 2*a;

  gsl_matrix_set (J, 0, 0, Jxx);
  gsl_matrix_set (J, 0, 1, Jxy);
  gsl_matrix_set (J, 1, 1, Jyx);
  gsl_matrix_set (J, 1, 1, Jyy);

  return GSL_SUCCESS;
}

int
rosenbrock_fdf (const gsl_vector * v, void *params,
                gsl_vector * f, gsl_matrix * J)
{
  rosenbrock_f (v, params, f);
  rosenbrock_df (v, params, J);

  return GSL_SUCCESS;
}


