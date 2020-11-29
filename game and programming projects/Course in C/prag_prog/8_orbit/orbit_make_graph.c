#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include<math.h>

int ode_orbit_make_graph(double f, const double u[], double dudf[], void *params)
{
	double e = *(double*)params;

	dudf[0] = u[1];
	dudf[1] = 1-u[0]+e*u[0]*u[0];

        return GSL_SUCCESS;
}

double orbit_make_graph(double f, double e, double u0, double dudf0){

        gsl_odeiv2_system sys;
        sys.function = ode_orbit_make_graph;
        sys.jacobian = NULL;
        sys.dimension = 2;
        sys.params =& e;

        gsl_odeiv2_driver *driver;
        double hstart = 1e-5, abs = 1e-6, eps = 1e-6;
        driver = gsl_odeiv2_driver_alloc_y_new(&sys,
                                               gsl_odeiv2_step_rkf45,
                                               hstart, abs, eps);

	FILE* data = fopen("data.txt","w");
        double f0 = 0;
        double u[] = {u0, dudf0};
	double df=0.02;		//denne df giver antal punkter, hvor løsningen bestemmes, ikke løsningens præcision.
	for(int i=0; i<=f/df; i++){
		double fi = i*df;
		gsl_odeiv2_driver_apply(driver, &f0, fi, u);
		double xi = cos(fi)/u[0];
		double yi = sin(fi)/u[0];
		double yi_control = sin(fi)/(1-0.5*sin(fi));
		fprintf(data, "%g  	%g  	%g\n",xi,yi,yi_control);
		}
	fclose(data);

        gsl_odeiv2_driver_free(driver);
        return u[0];
}


