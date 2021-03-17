#include "def.h"

int print_state (size_t iter, gsl_multiroot_fsolver * s)
{
  printf ("iter = %3lu x = % .3f "
          "f(x) = % .3e \n",
          iter,
          gsl_vector_get (s->x, 0),
          gsl_vector_get (s->f, 0));
}
