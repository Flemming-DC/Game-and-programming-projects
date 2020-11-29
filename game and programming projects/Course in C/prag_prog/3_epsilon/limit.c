
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(){


int i=-2.14748364e9;
do {printf("my min int = %i\n",i),i--;} while(i-1<i);
printf("\n");

for(int k=-i;k+1>k;k--) {printf("my min int = %i\n",k);};
printf("\n");


int i_plus=2.14748364e9;
do {printf("my max int = %i\n",i_plus),i_plus++;} while(i_plus+1>i_plus);
printf("\n");

for(int k=i_plus;k+1>k;k++) {printf("my max int = %i\n",k);};
printf("\n");




double e;
for(e=1; 1+e!=1; e/=2){}
e*=2;

printf("e_for_double   = %g\n",e);
printf("e_DBL_EPSILON = %g\n",DBL_EPSILON);



float x=1;
do {x/=2;} while(1+x!=1);
x*=2;
printf("e_while_float  = %g\n",x);

printf("e_FLT_EPSILON = %g\n",FLT_EPSILON);

double y=1;
while(1+y!=1){y/=2;} y*=2;
printf("e_while_double = %g\n",y);

printf("e_DBL_EPSILON  = %g\n",DBL_EPSILON);


long double l=1L;
long double t=2L;
long double z=1L;
while(l+z!=l){z/=t;} z*=t;
printf("e_while_long   = %Lg\n",z);


printf("e_LDBL_EPSILON = %Lg\n",LDBL_EPSILON);
printf("\n");



return 0;}

