#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double f_gsl (double x, int* calls) {
  (*calls)++;
  double f_gsl = 4*sqrt(1-(1-x)*(1-x));
  return f_gsl;
}

int
gsl_integrator (void)
{
  gsl_integration_workspace * w
    = gsl_integration_workspace_alloc (1000);

  double Q, err;
  double exact = 3.141592653589793238462643383279502884197169399375;
  int calls = 0;
  double acc = 1e-13;
  double eps = 1e-13;

  gsl_function F;
  F.function = &f_gsl;
  F.params = &calls;

  gsl_integration_qags (&F, 0, 1, acc, eps, 1000,
                        w, &Q, &err);


  printf ("\n integrand: 4*sqrt(1-(1-x)^2)\n");
  printf ("Q               = % .18f\n", Q);
  printf ("exact	   = % .18f\n", exact);
  printf ("calls           = %i\n", calls);
  printf ("estimated error = % .18f\n", err);
  printf ("actual error    = % .18f\n", Q - exact);

  gsl_integration_workspace_free (w);

  return 0;
}
