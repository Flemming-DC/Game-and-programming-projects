#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "gsl/gsl_matrix.h"

void rkstep23(void f(double, double*, double*),
                int, double, double, double*, double*, double* );


int driver(void f(double x, double* y, double* dydx),
		int n, double* x_list, double* y_start, gsl_matrix* y_matrix, double a, double b, double h, double err_abs, double err_rel, int max){

int i;
int k = 0;


memset( x_list, 0, n*sizeof(double) );
x_list[0] = a;

double y_list[max][n];
memset( y_list, 0, max*n*sizeof(double) );
for(int i=0; i<n; i++) y_list[0][i] = y_start[i];

double x, *y, s, err, norm_y, tol, yh[n], dy[n];



while(x_list[k]<b && k<max){

	x = x_list[k];
	y = y_list[k];

	rkstep23(f,n,x,h,y,yh,dy);
	s = 0;
	for(i=0; i<n; i++){
		s += dy[i]*dy[i];
		}
	err = sqrt(s);

	s = 0;
	for(i=0; i<n; i++){
		s += yh[i]*yh[i];
		}
	norm_y = sqrt(s);

	tol = (norm_y*err_rel+err_abs)*sqrt( h/(b-a) );

	if(err < tol){
		k++;
		if(k > max-1) {
			printf("error: maksimum step number reached\n");
			return k;
			}
		x_list[k] = x+h;


		for(i=0; i<n; i++){
			y_list[k][i] = yh[i];
			gsl_matrix_set(y_matrix,k,i, y_list[k][i] );
			}
	}

	if(tol==0) {printf("NEVER GET HERE: tol=%g\n",tol);return 1;}
	if(err==0) h*=2;  //dette forhindrer division med nul
	else h *= pow(tol/err,0.25)*0.95;

	}


return k+1;

}

