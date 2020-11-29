#include "fit_def.h"


int main(){

//definitioner foretages
const gsl_multimin_fminimizer_type *m;
gsl_multimin_fminimizer *pm;
gsl_vector *gaet,*first_step;
gsl_multimin_function R_squared;
int N=3;   //number of variables
int i=0;
int status;
double step_size;


printf("\n searching for minimum in rosen\n");

//her bygges struktueren {antal_variable, funktion_som_skal_minimeres, parametre}
R_squared.n = N;
R_squared.f = &fit_fun;
R_squared.params = NULL;

gaet = gsl_vector_alloc(N);    //her gætter vi på minimumets placering
gsl_vector_set(gaet, 0, 2);    //A_gæt
gsl_vector_set(gaet, 1, 1.5);  //B_gæt
gsl_vector_set(gaet, 2, 1.5);  //T_gæt

first_step = gsl_vector_alloc(N);    //step_size_vector
gsl_vector_set_all(first_step, 1.0);

m = gsl_multimin_fminimizer_nmsimplex2;
pm = gsl_multimin_fminimizer_alloc(m,N);    //pointer to minimizer

gsl_multimin_fminimizer_set(pm, &R_squared, gaet, first_step);


do{
	i++;
	status = gsl_multimin_fminimizer_iterate(pm);

	if(status!=GSL_SUCCESS) break;

        step_size = gsl_multimin_fminimizer_size (pm);
        status = gsl_multimin_test_size (step_size, 1e-2);

	if(status==GSL_SUCCESS) printf("Minimum found at:\n");

	printf ("%5d %.5f %.5f %.5f %10.5f\n",
		i,
        	gsl_vector_get ((*pm).x, 0),
        	gsl_vector_get ((*pm).x, 1),
        	gsl_vector_get ((*pm).x, 2),
        	(*pm).fval);

	}
while(status==GSL_CONTINUE && i<100);

printf("first row = step number,  second row = A,  third row = B,  fourth row = T,  fifth row = R_squared(A,B,T)\n");
printf("number of iterations = %i\n",i);



//nu er fitningen af A,B,T færdig og vi begynder plotte resultatet

double A = gsl_vector_get ((*pm).x, 0);
double B = gsl_vector_get ((*pm).x, 1);
double T = gsl_vector_get ((*pm).x, 2);
//double R_squared_min = (*pm).fval;


double t[] = {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};
double y[] = {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
double e[] = {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};
int n_data = sizeof(t)/sizeof(t[0]);


double f(double tau){
	return A*exp(-tau/T)+B;
	}

for(int i=0; i<n_data; i++) {
	fprintf( stderr,"%g %g %g %g\n",t[i],y[i],e[i],f(t[i]) );
	}



gsl_multimin_fminimizer_free(pm);
gsl_vector_free(gaet);

return 0;}





