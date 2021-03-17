#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double f (double x, void * params) {
//  double alpha = *(double *) params;
  double f = log(x) / sqrt(x);
  return f;
}

int
main (void)
{
  gsl_integration_workspace * w
    = gsl_integration_workspace_alloc (1000);

  double result, error;
  double expected = -4.0;
//  double alpha = 1.0;
  double p=1.0;

  gsl_function F;
  F.function = &f;
  F.params = &p;

//printf("F.params=%p\n",F.params);

  gsl_integration_qags (&F, 0, 1, 0, 1e-7, 1000,
                        w, &result, &error);

  printf ("numberic integral of ln(x)/sqrt(x) = % .8f\n", result);
  printf ("exact integral of ln(x)/sqrt(x)    = % .8f\n", expected);
  printf ("estimated error = % .8f\n", error);
  printf ("actual error    = % .8f\n", result - expected);

  gsl_integration_workspace_free (w);

  return 0;
}
