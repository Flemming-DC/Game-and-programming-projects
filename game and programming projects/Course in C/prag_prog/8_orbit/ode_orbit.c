#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>

int ode_orbit(double f, const double u[], double dudf[], void *params)
{
	double e = *(double*)params;

	dudf[0] = u[1];
	dudf[1] = 1-u[0]+e*u[0]*u[0];

        return GSL_SUCCESS;
}

double orbit(double f, double e, double u0, double dudf0){

        gsl_odeiv2_system sys;
        sys.function = ode_orbit;
        sys.jacobian = NULL;
        sys.dimension = 2;
        sys.params =& e;

        gsl_odeiv2_driver *driver;
        double hstart = 0.1, abs = 1e-5, eps = 1e-5;
        driver = gsl_odeiv2_driver_alloc_y_new(&sys,
                                               gsl_odeiv2_step_rkf45,
                                               hstart, abs, eps);

        double f0 = 0;
        double u[] = {u0, dudf0};
        gsl_odeiv2_driver_apply(driver, &f0, f, u);

        gsl_odeiv2_driver_free(driver);
        return u[0];
}


