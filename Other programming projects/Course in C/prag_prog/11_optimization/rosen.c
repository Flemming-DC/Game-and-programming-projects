#include "rosen_def.h"



double r_fun (const gsl_vector *v, void *params){

double *a = (double *)params;

double x = gsl_vector_get(v, 0);
double y = gsl_vector_get(v, 1);

double r = (1-x)*(1-x) + a[0]*(y-x*x)*(y-x*x);

return r;
}



void dr_fun (const gsl_vector *v, void *params, gsl_vector *dr){

double *a = (double *)params;

double x = gsl_vector_get(v, 0);
double y = gsl_vector_get(v, 1);

double drdx = 2*(x-1)-4*a[0]*x*(y-x*x);
double drdy = 2*a[0]*(y-x*x);

gsl_vector_set(dr, 0, drdx);
gsl_vector_set(dr, 1, drdy);
}



void rdr_fun (const gsl_vector *v, void *params, double *r, gsl_vector *dr){
*r = r_fun(v, params);
dr_fun(v, params, dr);
}






