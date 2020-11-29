#include "include.h"
#include <gsl/gsl_multiroots.h>

struct rparams {double a; double b; };




void gsl_solver(int (*g)(const gsl_vector*, void*, gsl_vector*), gsl_vector* x, double err_tol){

  const gsl_multiroot_fsolver_type *T;
  gsl_multiroot_fsolver *s;

  int status;
  int iter = 0;

  const size_t n = 2;
  struct rparams p = {1.0, 10.0};
  gsl_multiroot_function f = {g, n, &p};

  T = gsl_multiroot_fsolver_hybrids;
  s = gsl_multiroot_fsolver_alloc (T, 2);
  gsl_multiroot_fsolver_set (s, &f, x);


  do
    {
      iter++;
      status = gsl_multiroot_fsolver_iterate (s);


      if (status)   /* check if solver is stuck */
        break;

      status =
        gsl_multiroot_test_residual (s->f, err_tol);
    }
  while (status == GSL_CONTINUE && iter < 1000);

  printf("number of steps = %i\n", iter);
  printf("norm of f(x_root) = %g\n", norm(s->f) );
  printf("x_root = %g	%g\n", gsl_vector_get(s->x,0), gsl_vector_get(s->x,1) );

//  printf ("status = %s\n", gsl_strerror (status));

  gsl_multiroot_fsolver_free (s);

}

