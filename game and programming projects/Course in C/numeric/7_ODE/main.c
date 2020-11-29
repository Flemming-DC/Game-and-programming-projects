#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "gsl/gsl_matrix.h"

void rkstep23(void f(double, double*, double*),
		int, double, double, double*, double*, double* );

int driver(void f(double, double*, double*),
		int, double*, double*, gsl_matrix*, double, double, double, double, double, int );

void poly(double x, double* y, double* dydx){

dydx[0] = exp(x);
dydx[1] = x;
dydx[2] = 1.0/x;

}


int main(){


int n = 3;

double y_start[] = {exp(2), 2, log(2)};
double yh[n], dy[n];
double b = 10;
double a = 2.0;
double h = 1e-2;
double err_abs = 1e-4;
double err_rel = 1e-4;
int max_n_step = 1e3;
double x_list[max_n_step];
gsl_matrix* y_matrix = gsl_matrix_calloc(max_n_step,n);


printf("\n the following equation-system will be integrated from 2 to 10:\n");
printf("y1' = exp(x)\n");
printf("y2' = x\n");
printf("y3' = 1./x\n\n");

rkstep23(poly, n, a, h, y_start, yh, dy);


printf("first step = %8.5g  %8.5g  %8.5g\n", yh[0]-2, yh[1]-2, yh[2]-2 );


int n_step = driver(poly, n, x_list, y_start, y_matrix, a, b, h, err_abs, err_rel, max_n_step);






int i,k;

FILE* plot = fopen("path.txt","w");
fprintf(plot, "x    ");
for(i=0; i<n; i++) fprintf(plot, "y[%i]     ",i);
fprintf(plot, "\n");

for(k=0; k<n_step; k++){
        fprintf(plot, "%8.5g", x_list[k]);
        for(i=0; i<n; i++) fprintf(plot, "%12.5g", gsl_matrix_get(y_matrix,k,i) );
        fprintf(plot, "\n");
	}
fclose(plot);

printf("y(last step) = ");
for(int i=0; i<n; i++) printf("%g	", gsl_matrix_get(y_matrix,n_step-1,i) );
printf("\n");

printf("x(last step) = %g\n", x_list[n_step-1]);
printf("number of steps = %i\n",n_step);
printf("the path has been stored in path.txt and is shown on the plots\n");


gsl_matrix_free(y_matrix);

return 0;
}
