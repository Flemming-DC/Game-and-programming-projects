#include "fit_def.h"


double f(double A, double B, double T, double t){
return A*exp(-t/T)+B;
}


double fit_fun (const gsl_vector *v, void *params){

double t[] = {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};     //data konstrueres
double y[] = {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
double e[] = {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};
int n_data = sizeof(t)/sizeof(t[0]);

double A = gsl_vector_get(v, 0);    //parametrene fungere som variable
double B = gsl_vector_get(v, 1);
double T = gsl_vector_get(v, 2);

double sum=0;
for(int i=0; i<n_data; i++){sum += pow( ( f(A,B,T,t[i]) - y[i] )/e[i], 2);}

return sum;
}



