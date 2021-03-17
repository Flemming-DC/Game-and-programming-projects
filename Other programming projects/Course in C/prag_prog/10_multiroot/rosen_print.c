/*
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
*/
#include "rosen_def.h"


int
print_state (size_t iter, gsl_multiroot_fdfsolver * s)
{
  printf ("iter = %3lu x = % .3f y = % .3f "
          "fx = % .3e fy = % .3e\n",
          iter,
          gsl_vector_get (s->x, 0),
          gsl_vector_get (s->x, 1),
          gsl_vector_get (s->f, 0),
          gsl_vector_get (s->f, 1));
return 0;
}

