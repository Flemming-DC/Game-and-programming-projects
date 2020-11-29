#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

double norm(gsl_vector*);

void print_matrix(FILE*, gsl_matrix*);

void jac(void f(const gsl_vector*, gsl_vector*),gsl_vector*,gsl_matrix*);

void rosen_grad_jac(const gsl_vector*, gsl_vector*, gsl_matrix*);
void himmel_grad_jac(const gsl_vector*, gsl_vector*, gsl_matrix*);

double rosen(gsl_vector*);
double himmel(gsl_vector*);
double square_deviation(gsl_vector*);

void back_sub(gsl_matrix*, gsl_vector*);

void QR_solve(gsl_matrix*, gsl_matrix*, gsl_vector*, gsl_vector*);

void gram_schmidt(gsl_matrix*, gsl_matrix*);

void newton_jac(void f(const gsl_vector*, gsl_vector*, gsl_matrix*), gsl_vector*, double);
void qnewton(double beta(gsl_vector*), gsl_vector*, double);








