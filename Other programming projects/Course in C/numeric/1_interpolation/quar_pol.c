#include <stdlib.h>
#include <assert.h>

typedef struct {int n; double *x,*y,*b,*c;} q_spline;

q_spline* q_spline_alloc(int n, double *x, double *y){

q_spline* s = (q_spline*) malloc(sizeof(q_spline));   //erklæring af spline og dens indhold
s->b = (double*) malloc((n-1)*sizeof(double));
s->c = (double*) malloc((n-1)*sizeof(double));
s->x = (double*) malloc(n*sizeof(double));
s->y = (double*) malloc(n*sizeof(double));
s->n = n;

int i;

for(i=0; i<n; i++){	//x[i] og y[i] placeres i spline
	s->x[i] = x[i];
	s->y[i] = y[i];
	}

double p[n-1], h[n-1];  //h[i] og p[i] konstrueres
for(i=0; i<(n-1); i++){
	h[i] = x[i+1]-x[i];
	p[i] = (y[i+1]-y[i])/h[i];
	}

s->c[0] = 0;		//c[i] konstrueres fra c[0] til c[n-1]
for(i=0; i<(n-2); i++){
	s->c[i+1] = ( p[i+1]-p[i]-(s->c[i])*h[i] ) / h[i+1];
	}

s->c[n-2] /= 2;		//c[i] konstrures igen, men denne gang fra c[n-1] til c[0], da det øger præcisionen
for(i=n-3; i>=0; i--){
	s->c[i] = ( p[i+1]-p[i]-(s->c[i+1])*h[i+1] ) / h[i];
	}

for(i=0; i<(n-1); i++){	//b[i] konstrueres
	s->b[i] = p[i]-(s->c[i])*h[i];
	}
return s;
}





double q_spline_eval(q_spline *s, double z){

int i=0, j=(s->n)-1;
assert(z >= s->x[0]);
assert(z <= s->x[j]);

while(j>i+1){		//binary search foretages
	int m=(i+j)/2;
	if(z > s->x[m]) i=m; else j=m;
	}

double h = z-(s->x[i]);

return s->y[i] + h*s->b[i] + h*h*s->c[i];
}




double q_spline_deriv(q_spline *s, double z){

int i=0, j=(s->n)-1;
assert(z >= s->x[0]);
assert(z <= s->x[j]);

while(j>i+1){		//binary search foretages
	int m=(i+j)/2;
	if(z > s->x[m]) i=m; else j=m;
	}

double h = z-(s->x[i]);

return s->b[i] + 2*h*s->c[i];
}





double q_spline_int(q_spline *s, double z){

int i=0, j=(s->n)-1;
assert(z >= s->x[0]);
assert(z <= s->x[j]);

while(j>i+1){		//binary search foretages
	int m=(i+j)/2;
	if(z > s->x[m]) i=m; else j=m;
	}

double h;
double sum = 0;

for(int k=0; k<i; k++){
	h = s->x[k+1] - s->x[k];
	sum += s->y[k]*h + 0.5*s->b[k]*h*h + 1/3.0*s->c[k]*h*h*h;
	}

h = z - s->x[i];
sum += s->y[i]*h + 0.5*s->b[i]*h*h + 1/3.0*s->c[i]*h*h*h;

return sum;
}





void q_spline_free(q_spline* s){
	free(s->x);
	free(s->y);
	free(s->b);
	free(s->c);
	free(s);
}








