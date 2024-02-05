/* 
  João Ricardo Malta De Oliveira - 2112714
  Gustavo Arcary Passos - 2110508
  Enzo Milman - 2110959
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "controleMovimento.h"

// função utilizada 
double func_comp_arco (double t,double* vetX,double* vetY){
  double x_der_value = vetX[1] + (2*vetX[2]*t) + (3*vetX[3]*t*t);
  double y_der_value = vetY[1] + (2*vetY[2]*t) + (3*vetY[3]*t*t);
  return sqrt(x_der_value*x_der_value + y_der_value*y_der_value);
}

int main(void) 
{
  // vetor de posições x e y
  double vetX[] = {5.0,3.0,2.0,1.0};
  double vetY[] = {5.0,3.0,2.0,1.0};
  
  double tempo, Xt, Yt, Sx, Sy;
  //numero de iteração   
  int n= 5;
  srand(time(0));
  double erro;
  double r;
  
  // Testes do Passos x Erro
  // for(int i = 0;i<100;i++){
  //   erro = 0;
  //   for(int j = 0;j<50;j++){
  //     double tempo = (double)rand() / RAND_MAX; 
  //     double comprimento_arco = simpson (func_comp_arco, 0, tempo, (n+i*5), vetX, vetY);
  //     EqParametricos (tempo, vetX, vetY, &Xt, &Yt);
  //     CalcPestrela(0,1,comprimento_arco,func_comp_arco,&r,vetX,vetY,n, &Sx, &Sy);
  //     erro += sqrt((Xt-Sx)*(Xt-Sx) + (Yt-Sy)*(Yt-Sy));
  //   }
  //   printf("%d\n",(n+i*5)); // numero de passos
  //   printf("%f\n",erro); // erro acumulado desse numero de passos
  // }

  // Testes do testes x iteracao
  // double iteracao;
  // n = 185;
  // for(int i = 1;i<301;i++){
  //   iteracao = 0;
  //   for(int j = 0;j<i;j++){
  //     double tempo = (double)rand() / RAND_MAX; 
  //     double comprimento_arco = simpson (func_comp_arco, 0, tempo, n, vetX, vetY);
  //     EqParametricos (tempo, vetX, vetY, &Xt, &Yt);
  //     iteracao += bissecao(0,1,comprimento_arco,func_comp_arco,&r,vetX,vetY,n);
  //   }
  //   //printf("%d\n",i); // numero de passos
  //   printf("%f\n",iteracao/i); // erro acumulado desse numero de passos
  // }
  
  return 0;
}

