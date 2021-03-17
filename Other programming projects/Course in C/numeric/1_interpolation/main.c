#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double lin_pol(int n, double* x, double* y, double z);
double lin_int(int n, double* x, double* y, double z);

typedef struct {int n; double *x,*y,*b,*c;} q_spline;
q_spline* q_spline_alloc(int, double *x, double *y);
double q_spline_eval(q_spline *s, double z);
double q_spline_int(q_spline *s, double z);
double q_spline_deriv(q_spline *s, double z);
void q_spline_free(q_spline* s);


int main(){

int n=14;

double x[n];
double y[n];
double y_z;
double int_z;
double dz=0.1;
double y_z_q;
double int_z_q;
double deriv_z_q;

for(int i=0; i<n; i++) {
	x[i]=i;
	y[i]=exp(0.5*i);
	}



double z = x[0];
int N = (x[n-1]-x[0])/dz;
q_spline* s = q_spline_alloc(n,x,y);

for(int k=0; k<N; k++){
	z+=dz;

	y_z = lin_pol(n,x,y,z);
	int_z = lin_int(n,x,y,z);
	y_z_q = q_spline_eval(s,z);
	int_z_q = q_spline_int(s,z);
	deriv_z_q = q_spline_deriv(s,z);

	printf("%g	%g   	%g   	%g   	%g     	%g\n",
		z, y_z, int_z, y_z_q, int_z_q, deriv_z_q);
}


//double z = 5.7;


//printf("y_z_q = %g\n",y_z_q);

q_spline_free(s);


return 0;
}
