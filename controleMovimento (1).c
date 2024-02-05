#include <math.h>
#include <stdio.h>

double simpson(double (*f)(double,double*,double*), double t1, double t2, int n, double* vetX, double* vetY) {
  double acumulador = 0.0;
  double x = t1;
  double fxagora = f(x,vetX,vetY);
  double fxprox;
  double fxmid;
  double h = (t2 - t1) / n;
  while (x < t2) {
    fxmid = f(x + h / 2,vetX,vetY);
    x = x + h;
    fxprox = f(x,vetX,vetY);
    acumulador += (h / 6) * (fxagora + 4 * fxmid + fxprox);
    fxagora = fxprox;
  }
  return acumulador;
}


int bissecao(double a, double b,double s, double (*f)(double x,double*, double*), double *r,double *vetX, double* vetY,int n) {
  double erro = 0.5E-8;
  double c;
  int conta = 0;
  double fa = s - simpson(f,0, a, n, vetX, vetY); // simpson(f,0, a, 16, vetX, vetY)
  double fb = s - simpson(f,0, b, n, vetX, vetY); // simpson(f,0, b, 16, vetX, vetY)
  double fc;
  if(fabs(fb) < 10E-12)
  {
    *r = b;
  }
  if(fabs(fa) < 10E-12)
  {
    *r = a;
  }
  
  if (fa * fb < 0) 
  {
    while (fabs((b - a)) / 2 > erro) 
    {
      conta++;
      c = ((a + b) / 2);
      fc = s - simpson(f,0, c, n, vetX, vetY); // simpson(f,0, c, 16, vetX, vetY)
      if (fabs(fc) < 10E-12) 
      {
        *r = c;
        return conta;
      }

      if (fa * fc < 0) 
      {
        b = c;
        fb = fc;
      } 
      else 
      {
        a = c;
        fa = fc;
      }
    }
    *r = c;
  } 
  else 
  {
    return 0;
  }
  return conta;
}


void EqParametricos (double t,double* VetX,double* VetY,double* Xt, double* Yt){
  double soma = VetX[0] + VetX[1]*t + VetX[2]*t*t + VetX[3]*t*t*t;
  *Xt = soma;
  soma = VetY[0] + VetY[1]*t + VetY[2]*t*t + VetY[3]*t*t*t;
  *Yt = soma;
  return;
}

void CalcPestrela(double a, double b,double s, double (*f)(double x,double*, double*), double *r,double *vetX, double* vetY,int n, double *Sx, double *Sy){
  bissecao(a,b,s,f,r,vetX,vetY,n);
  EqParametricos (*r, vetX, vetY, Sx, Sy);
}
// double f(double x) {