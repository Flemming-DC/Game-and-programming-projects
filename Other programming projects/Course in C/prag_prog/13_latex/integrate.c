#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double gauss(double x, void* params){
double gau = 2/sqrt(M_PI)*exp(-x*x);
return gau;
}

int main(int argc, char** argv){

if(argc!=3){
	printf("you need three arguments\n");
	}

double a=atof(argv[1]);
double b=atof(argv[2]);
double dx=atof(argv[3]);
double N=(b-a)/dx;

double result_step, result, error_estimate;
size_t n_eval;

gsl_function Gauss;
Gauss.function = &gauss;
Gauss.params = NULL;

printf ("x			 erf(x)			  error on erf(x)\n");

gsl_integration_qng(&Gauss, 0, a, 0, 1e-7, &result, &error_estimate, &n_eval);  //Function, grænser, error-abs, eroor-rel, result, error-estimate, max evaluation-number
printf ("%.18f	 %.18f     %.18f\n", a, result, error_estimate);


for(int n=0; n<N; n++){

	gsl_integration_qng(&Gauss, a+n*dx, a+(n+1)*dx, 0, 1e-7, &result_step, &error_estimate, &n_eval);  

	result = result + result_step;
	printf ("%.18f     %.18f     %.18f\n", a+(n+1)*dx, result, error_estimate);
	}


return 0;
}



