#include<gsl/gsl_sf.h>
#include<math.h>
#include"airy.h"

void airy(void){
	for(double x=-15;x<5;x+=0.013){
		double Ai=gsl_sf_airy_Ai(x,1e-3);
		double Bi=gsl_sf_airy_Bi(x,1e-3);
		fprintf(stderr,"%g %g %g\n",x,Ai,Bi);
	}
}
