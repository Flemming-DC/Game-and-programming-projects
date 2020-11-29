#include "def.h"

int main (int argc, char** argv){

  if(argc<2) {
	printf("you need to provide some arguments\n");
	}

  const gsl_multiroot_fsolver_type *T;
  gsl_multiroot_fsolver *s;

  int status;
  size_t iter = 0;
  const size_t n = 1;

  double x_init[1] = {1};
  gsl_vector *x = gsl_vector_alloc (n);
  gsl_vector_set (x, 0, x_init[0]);

  printf("første søjle = x og anden søjle = atan(x)");

  for(int arg_number=1; arg_number<argc; arg_number++){

	double a = atof(argv[arg_number]);
	struct rparams p = {a};
	gsl_multiroot_function f = {&rod, n, &p};

	T = gsl_multiroot_fsolver_hybrids;
	s = gsl_multiroot_fsolver_alloc (T, 1);
	gsl_multiroot_fsolver_set (s, &f, x);


	do{
		iter++;
	        status = gsl_multiroot_fsolver_iterate (s);

	        if (status) break;

	        status = gsl_multiroot_test_residual (s->f, 1e-7);
	    }
	while (status == GSL_CONTINUE && iter < 1000);

	printf("%g	%g\n", a, gsl_vector_get (s->x, 0));

 }

//  printf ("status = %s\n", gsl_strerror (status));

  gsl_multiroot_fsolver_free (s);
  gsl_vector_free (x);

  return 0;
}

