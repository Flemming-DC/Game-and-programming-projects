/*
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
*/
#include "rosen_def.h"


int
main (void)
{
  const gsl_multiroot_fdfsolver_type *T;
  gsl_multiroot_fdfsolver *s;

  int status;
  size_t iter = 0;

  const size_t n = 2;
  double a = 100.;
  struct rparams p = {a};
  gsl_multiroot_function_fdf f = {&rosenbrock_f,
                                  &rosenbrock_df,
                                  &rosenbrock_fdf,
                                  n, &p};

  double x_init[2] = {1.5, 2};
  gsl_vector *x = gsl_vector_alloc (n);

  gsl_vector_set (x, 0, x_init[0]);
  gsl_vector_set (x, 1, x_init[1]);

  T = gsl_multiroot_fdfsolver_gnewton;
  s = gsl_multiroot_fdfsolver_alloc (T, n);
  gsl_multiroot_fdfsolver_set (s, &f, x);

  printf("\n Minimizing rosen:\n");
  printf("x_initial = %g    %g\n", x_init[0], x_init[1]);

//  print_state (iter, s);

  do
    {
      iter++;

      status = gsl_multiroot_fdfsolver_iterate (s);


      if (status)
        break;

      status = gsl_multiroot_test_residual (s->f, 1e-7);
    }
  while (status == GSL_CONTINUE && iter < 1e4);

//  print_state (iter, s);
  double x_root_0 = gsl_vector_get (s->x, 0);
  double x_root_1 = gsl_vector_get (s->x, 1);
  double rosen_root = (1-x_root_0)*(1-x_root_0)+a*(x_root_1-x_root_0*x_root_0)*(x_root_1-x_root_0*x_root_0);

  printf("number of iterations = %lu    x_root = %g    %g   rosen(x_root) = %g\n",
          iter, x_root_0, x_root_1, rosen_root );

  printf ("status = %s\n\n", gsl_strerror (status));

  gsl_multiroot_fdfsolver_free (s);
  gsl_vector_free (x);
  return 0;
}
