#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>


int u_to_ode_plot(double r, const double u[], double dudr[], void *params)
{
        double E=*(double*) params;
        dudr[0] = u[1];
        dudr[1] = -2.0*u[0]*(E+1/r);
        return GSL_SUCCESS;
}


//int u_to_ode(double, const double, double, void*);


double u_ode_plot(double E, double r_max){

        gsl_odeiv2_system sys;
        sys.function = u_to_ode_plot;
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
	double ri = r0;

	int N=1000;
	FILE* data = fopen("data.txt","w+");
	for(int i=0; i<N; i++){
		ri += r_max/N;
	        gsl_odeiv2_driver_apply(driver, &r0, ri, u);

		fprintf(data, "%g	%g	%g\n",ri,u[0],u[1]);
	}
	fclose(data);

	printf("r_max = %g\n",r_max);
        gsl_odeiv2_driver_free(driver);
        return u[0];
}



