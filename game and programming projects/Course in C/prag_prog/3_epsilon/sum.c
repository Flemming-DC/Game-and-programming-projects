#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(){

//int i=-2.14748364e9;
//do {printf("my min int = %i\n",i),i--;} while(i-1<i);

//for(int k=-i;k+1>k;k--) {printf("my min int = %i\n",k);};


int max=INT_MAX/3;
int m;
float su_f=0;
float sd_f=0;

for(m=1; m<max; m++){su_f=su_f+1.0f/m;};
printf("sum_up_float = %g\n",su_f);


for(m=1; m<max; m++){sd_f=sd_f+1.0f/(max-m);};
printf("sum_down_float = %g\n",sd_f);


//float sum_up_float = 1.0f + 1.0f/2 + 1.0f/3 + ... + 1.0f/max;
//float sum_down_float = 1.0f/max + 1.0f/(max-1) + 1.0f/(max-2) + ...  +1.0f;

double su_d=0;
double sd_d=0;

for(m=1; m<max; m++){su_d=su_d+1.0/m;};
printf("sum_up_double = %g\n",su_d);


for(m=1; m<max; m++){sd_d=sd_d+1.0f/(max-m);};
printf("sum_down_float = %g\n",sd_d);

printf("sum_up_float og sum_down_float er forskellige, da vi opsummere en hel masse tal, som er så tæt på nul, at de ligger udenfor float's precision, hvilket generer tilfældig støj. Sum_up_double og sum_down_double er derimod ens, pga double's højere præcision.");



/*
double e;
for(e=1; 1+e!=1; e/=2){}
e*=2;

printf("%g\n",e);
printf("%g\n",DBL_EPSILON);



float x=1;
do {x/=2;} while(1+x!=1);
x*=2;
printf("%g\n",x);

printf("%g\n",FLT_EPSILON);

double y=1;
while(1+y!=1){y/=2;} y*=2;
printf("%g\n",y);

printf("%g\n",DBL_EPSILON);


long double l=1L;
long double t=2L;
long double z=1L;
while(l+z!=l){z/=t;} z*=t;
printf("%Lg\n",z);

printf("%Lg\n",LDBL_EPSILON);
*/


return 0;}

