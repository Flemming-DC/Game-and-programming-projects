#include <stdio.h>
#include <math.h>

double logistic(double);
double orbit(double, double, double, double);
double orbit_make_graph(double, double, double, double);
double gen_rel_orbit(double, double, double);

int main(){

double t=10;

double y=logistic(t);
double y_control=1/(1+exp(-t));
printf("\n integrating the logistic equation from 0 to 3 with y_0=0.5 gives:\n");
printf("logistic(%g)=%g\n",t,y);
printf("logistic_correct_result(%g)=%g\n",t,y_control);

double f=180;


printf("\n integrating the orbital equation for (1) circular motion, (2) elliptical motion og (3) general relativistic motion\n");

double u_cirkel=orbit(f,0,1,0);
double u_cirkel_control=1;
printf("u_cirkel(%g)=%g\n",f,u_cirkel);
printf("u_cirkel_correct_result(%g)=%g\n",f,u_cirkel_control);

double u_ellipse = orbit(f,0,1,-0.5);
double u_ellipse_control = 1-0.5*sin(f);
printf("u_ellipse(%g)=%g\n",f,u_ellipse);
printf("u_ellipse_correct_result(%g)=%g\n",f,u_ellipse_control);

double u_GR=orbit(f,0.01,1,-0.5);
printf("u_GR(%g)=%g\n\n",f,u_GR);


orbit_make_graph(f,0.01,1.0,-0.5);




return 0;}
