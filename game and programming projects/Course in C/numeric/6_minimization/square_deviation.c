#include <math.h>
#include "gsl/gsl_vector.h"

double f(double ti, gsl_vector* x){

double A = gsl_vector_get(x,0);
double T = gsl_vector_get(x,1);
double B = gsl_vector_get(x,2);

return A*exp(-ti/T)+B;
}




double square_deviation(gsl_vector* x){

double t[] = {0.23,1.29,2.35,3.41,4.47,5.53,6.59,7.65,8.71,9.77};
double y[] = {4.64,3.38,3.01,2.55,2.29,1.67,1.59,1.69,1.38,1.46};
double e[] = {0.42,0.37,0.34,0.31,0.29,0.27,0.26,0.25,0.24,0.24};
int N = sizeof(t)/sizeof(t[0]);




double sum = 0;
for(int i=0; i<N; i++){
	sum += pow( (f(t[i],x)-y[i])/e[i] ,2);
	}


return sum;
}
