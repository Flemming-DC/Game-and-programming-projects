/*
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
*/
#include "u_def.h"


int
u_print (size_t iter, gsl_multiroot_fsolver * s)
{
  printf ("iter = %3lu E = % .3f" " "
          "u = % .3e \n",
          iter,
          gsl_vector_get (s->x, 0),
          gsl_vector_get (s->f, 0)  );
return 0;
}

