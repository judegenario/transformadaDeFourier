#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <funcoes.h>

Ncomplex * transformada(int cont, unsigned char *vet) {

    int t, k, N, E;
    double res=0;
    N = (cont/2);
    Ncomplex *aux = (Ncomplex*) malloc (sizeof(Ncomplex)*(N+1));

    for (k=0; k<=N;k++){
        aux[k].real=0;
      aux[k].img=0;
      for (t=0; t<cont;t++){
        res = (k*2*M_PI)*(double)t/(cont);
        aux[k].real += vet[t] * cos (res);
        aux[k].img += vet[t] * -1 * sin (res);
      }

      if(k==0){
        E=1;
      } else E=2;

      aux[k].real = aux[k].real*(double)E/(cont);
      aux[k].img = aux[k].img*(double) E/(cont);
    }

    return aux;
}

double * magnitude(Ncomplex *aux, int cont){

    int N = (cont/2)+1, k;
    double *vetM = (double*) malloc (sizeof(double)*N);
    for(k=0; k<N;k++){
      vetM[k] = sqrt(pow(aux[k].real, 2) + pow(aux[k].img, 2));
    }

    return vetM; 
}

void selection(double *vetM, int cont){

  int i, j, m;
  double aux;
  for(i=0; i<=cont/2; i++){
    m=i;
    for(j=i+1; j<=cont/2; j++){
      if(vetM[j] >  vetM[m]){
        m=j;
      }
    }

    aux = vetM[m];
    vetM[m] = vetM[i];
    vetM[i] = aux;
  }
}

void remove_componentes(double *vetM, Ncomplex *aux, int cont, int C){
    int i;
    double mag_min = vetM[C-1];
    for (i=0; i<=cont/2;i++){
        if (sqrt(pow(aux[i].real, 2) + pow(aux[i].img, 2)) < mag_min){
          aux[i].real=0;
          aux[i].img=0;
        }
    }
}

unsigned char * inversa(int cont, Ncomplex *vet) {

    int t, k;
    double somaR, somaI, res=0;
    int N=cont/2;
    unsigned char *aux = (unsigned char*) malloc (sizeof(unsigned char)*cont);

    for (k=0; k<cont;k++){
      somaR = 0;
      somaI = 0;
      for (t=0; t<=N;t++){
        res = (double)k*2*M_PI*t/cont;
        somaR = somaR + vet[t].real * cos (res);
        somaI = somaI + vet[t].img * sin (res);
      }
      aux[k] = (unsigned char) round(somaR - somaI);
      
    }

    return aux;
}
