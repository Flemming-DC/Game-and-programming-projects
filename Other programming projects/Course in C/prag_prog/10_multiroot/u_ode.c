#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>


int u_to_ode(double r, const double u[], double dudr[], void *params)
{
	double E=*(double*) params;
        dudr[0] = u[1];
        dudr[1] = -2.0*u[0]*(E+1/r);
        return GSL_SUCCESS;
}


double u_ode(double E, double r){

        gsl_odeiv2_system sys;
        sys.function = u_to_ode;
        sys.jacobian = NULL;
        sys.dimension = 2;
        sys.params = (void*)&E;

        gsl_odeiv2_driver *driver;
        double hstart = 1e-3, abs = 1e-9, eps = 1e-9;
        driver = gsl_odeiv2_driver_alloc_y_new(&sys,
                                               gsl_odeiv2_step_rkf45,
                                               hstart, abs, eps);

        double r0 = 1e-3;
        double u[] = {r0-r0*r0, 1-2*r0};
        gsl_odeiv2_driver_apply(driver, &r0, r, u);

        gsl_odeiv2_driver_free(driver);
        return u[0];
}





