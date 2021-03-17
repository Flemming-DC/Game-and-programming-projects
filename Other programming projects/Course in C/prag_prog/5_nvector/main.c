#include "nvector.h"
#include "stdio.h"
#include "stdlib.h"
#define RND (double)rand()/RAND_MAX



int  nvector_equal    (nvector* a, nvector* b){

	int double_equal(double a, double b){

		double t=1e-5;
		double e=1e-5;
		if (abs(a-b)<t) {return 1;}
		else if (abs(a-b)/(a+b)<e) {return 1;}
		else return 0;
	}

	nvector r;
	for(int i=0;i<(*a).size;i++){r.data[i]=double_equal((*a).data[i],(*b).data[i]);};
	int j=1;
	for(int i=0;i<(*a).size;i++){j=j*r.data[i];};
	return j;
}


nvector nvector_add(nvector* a,nvector* b){

	nvector r;
	for(int i=0;i<(*a).size;i++){r.data[i]=(*a).data[i]+(*b).data[i];};
	return r;
}


/*
nvector* nvector_alloc(int n){
  nvector* v = malloc(sizeof(nvector));
  (*v).size = n;
  (*v).data = malloc(n*sizeof(double));
  if( v==NULL ) fprintf(stderr,"error in nvector_alloc\n");
  return v;
}

void nvector_free(nvector* v){ free(v->data); free(v);} // v->data is identical to (*v).data

void nvector_set(nvector* v, int i, double value){ (*v).data[i]=value; }

double nvector_get(nvector* v, int i){return (*v).data[i]; }
*/
int double_equal(double a, double b){

	double t=1e-5;
	double e=1e-5;
	if (abs(a-b)<t) {return 1;}
	else if (abs(a-b)/(a+b)<e) {return 1;}
	else return 0;
}

void nvector_print(char* s,nvector* v){
	printf("%s (",s);
	for(int i=0;i<(*v).size;i++){printf("%g,",(*v).data[i]);};
	printf(")\n");

}



int main()
{
	int n = 5;

	printf("\nmain: testing nvector_alloc ...\n");
	nvector *v = nvector_alloc(n);
	if (v == NULL) printf("test failed\n");
	else printf("test passed\n");

	printf("\nmain: testing nvector_set and nvector_get ...\n");
	double value = RND;
	int i = n / 2;
	nvector_set(v, i, value);
	double vi = nvector_get(v, i);
	if (double_equal(vi, value)) printf("test passed\n");
	else printf("test failed\n");

	printf("\nmain: testing nvector_add ...\n");
	nvector *a = nvector_alloc(n);
	nvector *b = nvector_alloc(n);
	nvector *c = nvector_alloc(n);
	for (int i = 0; i < n; i++) {
		double x = RND, y = RND;
		nvector_set(a, i, x);
		nvector_set(b, i, y);
		nvector_set(c, i, x + y);
	}

	nvector_add(a, b);
	nvector_print("a+b should   = ", c);
	nvector_print("a+b actually = ", a);

	if (nvector_equal(c, a)) printf("test passed\n");
	else printf("test failed\n");

	nvector_free(v);
	nvector_free(a);
	nvector_free(b);
	nvector_free(c);

	return 0;
}
