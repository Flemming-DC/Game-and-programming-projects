#include "rosen_def.h"


int main(){

const gsl_multimin_fdfminimizer_type *m;
gsl_multimin_fdfminimizer *pm;
gsl_vector* gaet;
gsl_multimin_function_fdf rosen;
int N=2;
int i=0;
int status;
double a[1]={100};

printf("\n searching for minimum in rosen\n");

rosen.n=N;
rosen.f=&r_fun;
rosen.df=&dr_fun;
rosen.fdf=&rdr_fun;
rosen.params=(void*)a;

gaet=gsl_vector_alloc(2);
gsl_vector_set(gaet,0,2);
gsl_vector_set(gaet,1,1.5);

m = gsl_multimin_fdfminimizer_conjugate_fr;
pm = gsl_multimin_fdfminimizer_alloc(m,N);    //pointer to minimizer

gsl_multimin_fdfminimizer_set(pm, &rosen, gaet, 0.1, 1e-4);


do{
	i++;
	status = gsl_multimin_fdfminimizer_iterate(pm);

	if(status!=GSL_SUCCESS) break;

	status =  gsl_multimin_test_gradient((*pm).gradient,1e-3);

	if(status==GSL_SUCCESS) printf("Minimum found at:\n");

	printf ("%5d %.5f %.5f %10.5f\n",
		i,
        	gsl_vector_get ((*pm).x, 0),
        	gsl_vector_get ((*pm).x, 1),
        	(*pm).f);

	}
while(status==GSL_CONTINUE && i<100);

printf("first row = step number,  second row = x,  third row = y,  fourth row = rosen(x,y)\n");
printf("number of iterations = %i\n",i);


gsl_multimin_fdfminimizer_free(pm);
gsl_vector_free(gaet);

return 0;}





