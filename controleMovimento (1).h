#ifndef ControleMovimento
#define ControleMovimento

double simpson (double (*f)(double,double*,double*), double t1, double t2, int n, double* vetX, double* vetY);

int bissecao(double a, double b,double s, double (*f)(double x,double*, double*), double *r,double *vetX, double* vetY,int n);

void EqParametricos (double t,double* VetX,double* VetY,double* Xt, double* Yt);

void CalcPestrela(double a, double b,double s, double (*f)(double x,double*, double*), double *r,double *vetX, double* vetY,int n, double *Sx, double *Sy);

#endif

