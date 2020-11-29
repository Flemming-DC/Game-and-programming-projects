#include "def.h"

int rod (const gsl_vector * x, void *params, gsl_vector * f){

  double a = ((struct rparams *) params)->a;

  const double x0 = gsl_vector_get (x, 0);

  const double y0 = tan(x0) - a;

  gsl_vector_set (f, 0, y0);

  return GSL_SUCCESS;
}
