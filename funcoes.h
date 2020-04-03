/* Aluna: Juliana Campos Degenario Ribeiro
NUSP: 11275112*/

#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct complex{     //struct para armazenar o num complexo
    double real;
    double img;
}Ncomplex;

Ncomplex * transformada(int , unsigned char *);                 //funcao p fazer a transformada
double * magnitude(Ncomplex *, int);                            //funcao p fazer as magnitudes
void selection(double *, int);                                  //funcao p ordenar as magnitudes
void remove_componentes(double *, Ncomplex *, int , int);       //funcao p remover os componentes menos importantes
unsigned char * inversa(int , Ncomplex *);                      //funcao p fazer a inversa

#endif