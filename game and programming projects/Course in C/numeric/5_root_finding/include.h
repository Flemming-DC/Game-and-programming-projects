#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

double norm(gsl_vector*);

void print_matrix(FILE*, gsl_matrix*);

void jac(void f(const gsl_vector*, gsl_vector*),gsl_vector*,gsl_matrix*);

void fun_jac(const gsl_vector*, gsl_vector*, gsl_matrix*);
void rosen_grad_jac(const gsl_vector*, gsl_vector*, gsl_matrix*);
void himmel_grad_jac(const gsl_vector*, gsl_vector*, gsl_matrix*);

void fun_nojac(const gsl_vector*, gsl_vector*);
void rosen_grad_nojac(const gsl_vector*, gsl_vector*);
void himmel_grad_nojac(const gsl_vector*, gsl_vector*);

int fun_gsl(const gsl_vector*, void*, gsl_vector*);
int rosen_grad_gsl(const gsl_vector*, void*, gsl_vector*);
int himmel_grad_gsl(const gsl_vector*, void*, gsl_vector*);


void back_sub(gsl_matrix*, gsl_vector*);

void QR_solve(gsl_matrix*, gsl_matrix*, gsl_vector*, gsl_vector*);

void gram_schmidt(gsl_matrix*, gsl_matrix*);

void newton_jac(void f(const gsl_vector*, gsl_vector*, gsl_matrix*), gsl_vector*, double);
void newton_nojac(void f(const gsl_vector*, gsl_vector*), gsl_vector*, double);
void gsl_solver(int g(const gsl_vector*, void*, gsl_vector*), gsl_vector*, double);




