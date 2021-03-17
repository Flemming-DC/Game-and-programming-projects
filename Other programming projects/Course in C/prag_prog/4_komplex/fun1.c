#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void set2(double *x){
	(*x)=2;
}
void printv(double v[],int n){
//	for(int i=0;i<n;i++)printf("sizeof(v)/sizeof(v[0])\n=%i",sizeof(v)/sizeof(v[0]));
	double a[n]; //variable length array
}

int main(){
	double x=1;
	set2(&x);
	printf("x=%g\n",x);

	int n=5;
	double v[n];
	for(int i=0;i<n;i++)v[i]=i;
	for(int i=0;i<n;i++)printf("v[%i]=%g\n",i,*(v+i));
//	for(int i=0;i<n;i++)printf("sizeof(v)/sizeof(v[0])\n=%i",sizeof(v)/sizeof(v[0]));

	double M[n][n][n];
	const int nn=100000;
	double* ann=(double*)malloc(nn*sizeof(double));
	ann[400]=99;
	printf("ann=%g\n",ann[400]);
	free(ann);

return 0;}
