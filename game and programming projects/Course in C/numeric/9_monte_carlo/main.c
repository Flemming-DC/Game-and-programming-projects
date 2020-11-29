#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_vector.h>

void monte_carlo(double f(gsl_vector*), int inside(gsl_vector*), gsl_vector*, gsl_vector*, int, double*, double*);


double f(gsl_vector* x){

	double x0 = gsl_vector_get(x,0);
	double x1 = gsl_vector_get(x,1);
	double x2 = gsl_vector_get(x,2);

	return pow(1-cos(x0)*cos(x1)*cos(x2), -1)/pow(M_PI,3);
	}


int inside(gsl_vector* x){

	int d = x->size;
	int in = 1;
	for(int i=0; i<d; i++){
		if( gsl_vector_get(x,i)<0 || gsl_vector_get(x,i)>M_PI ) in = 0;
		}

	return in;
	}


int main(){

int d = 3;
//int n = 1e4;
double integral;
double err;

gsl_vector* x = gsl_vector_alloc(d);
gsl_vector* a = gsl_vector_alloc(d);
gsl_vector* b = gsl_vector_alloc(d);

gsl_vector_set_all(a,0);
gsl_vector_set_all(b,M_PI);

monte_carlo(f, inside, a, b, 1e7, &integral, &err);

printf("\n The triple integral of 1./[1-cos(x)*cos(y)*cos(z)]/pi^3 from 0 to pi along each dimension is given as:\n");
printf("integral = %g	error = %g\n", integral, err);

/*
int M=100;
printf("sample size for estimating præcision of monte_carlo integration = %i\n",M);

printf(, "n 	  average result of integral	standarddeviation of integral		average error-estimate\n");
for(int k=1; k<=5; k++){
	int n = pow(10,k);
	double int_avr = 0;
	double int2_avr = 0;
	double err_avr = 0;
	for(int m=0; m<M; m++){
		monte_carlo(f, inside, a, b, n, &integral, &err);
		int_avr += integral/M;
		int2_avr += pow(integral,2)/M;
		err_avr += err/M;
		}
	double biased_var_int = int2_avr-int_avr*int_avr;
	double sigma_int = M/(M-1)*sqrt(biased_var_int);
	printf("%8.6i %18.6g %28.6g  %28.6g\n", k, log10(int_avr), log10(sigma_int), log10(err_avr) );
	}
*/

FILE* plot = fopen("plot.txt","w");
fprintf(plot, "log10(n)   log10(average result of integral)	log10(standarddeviation of integral)		log10(average error-estimate)\n");

//Here I pipe some data from time-consuming runs of monte_carlo with many data_ponits, so that it can be used for the plot
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    1,    0.5,    0.5230,    0.0098);
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    2,    0.0,    0.1380,   -0.2231);
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    3,   -0.5,   -0.4465,   -0.8844);
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    4,   -1.0,   -0.8792,   -1.2179);
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    5,   -1.5,   -1.4332,   -1.8840);
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    6,   -2.0,   -2.0176,   -2.3840);
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    7,   -2.5,   -2.1947,   -2.4153);
fprintf(plot, "%i %8.2g %8.6g  %8.6g\n",    8,   -3.0,   -2.6489,   -2.6081);

fclose(plot);





printf("\n The error can be fitted to a straight line with slope 1/2 upon a log-log plot, as can be seen from the plot called plot.svg. Thus, the error must grow as O(sqrt(n)). \n");
//printf("for n<1000 then you need 10^3 or 10^4 data points, otherwise 10^2 points is enough to get a good fit\n");


monte_carlo(f, inside, a, b, pow(10,5), &integral, &err);



gsl_vector_free(x);
gsl_vector_free(a);
gsl_vector_free(b);


return 0;
}



