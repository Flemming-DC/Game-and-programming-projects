/*
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
*/
#include "u_def.h"


int
main (void)
{
  const gsl_multiroot_fsolver_type *T;
  gsl_multiroot_fsolver *s;

  int status;
  size_t iter = 0;

  const size_t n = 2;
  struct rparams r_max = {10};
  gsl_multiroot_function f = {&u_lim,
                                  n, &r_max};

  double gaet_init[1] = {-0.6};
  gsl_vector *gaet = gsl_vector_alloc (n);

  gsl_vector_set (gaet, 0, gaet_init[0]);

  T = gsl_multiroot_fsolver_hybrids;
  s = gsl_multiroot_fsolver_alloc (T, n);
  gsl_multiroot_fsolver_set (s, &f, gaet);

  printf("searching for energies that siatisfy the boundery condition: \n");

  u_print (iter, s);

  do
    {
      iter++;

      status = gsl_multiroot_fsolver_iterate (s);

      u_print (iter, s);

      if (status)
        break;

      status = gsl_multiroot_test_residual (s->f, 1e-7);
    }
  while (status == GSL_CONTINUE && iter < 1000);

  printf ("status = %s\n", gsl_strerror (status));


  double E=gsl_vector_get (s->x, 0);
  u_ode_plot(E,10);


  gsl_multiroot_fsolver_free (s);
  gsl_vector_free (gaet);
  return 0;
}






