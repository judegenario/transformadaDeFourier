#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <funcoes.h>

int main(void) {
  int C, cont=0, i, counter=0;
  char *nome;
  Ncomplex *aux;
  double *mag;
  nome = (char*) malloc (sizeof(char)*10);
  unsigned char *vet;
  vet = (unsigned char*) malloc (sizeof(unsigned char));

  scanf("%s", nome);

  FILE *arq = fopen(nome, "rb");
	if (arq == NULL){
		exit(0);
	}

  while(fread(&vet[cont], sizeof(unsigned char), 1, arq)){
    cont++;
    vet = (unsigned char *) realloc( vet, (cont+1)*sizeof(unsigned char) );
      
  }

	fclose(arq);

  scanf("%d", &C);
  aux = transformada(cont, vet);
  mag = magnitude(aux, cont);
  selection(mag, cont);
  remove_componentes(mag, aux, cont, C);
  free(vet);
  vet = inversa(cont, aux);


  printf("%d\n", cont);

  for(i=0;i<(cont/2)+1;i++){
    if(mag[i] > 0.1){
      counter++;
    }
  }

  printf("%d\n", counter);

  for (i=0; i<C; i++){
    printf("%d " , (int) mag[i]);
  }
  printf("\n");
    
  for (i=0; i<cont; i++){
    printf("%d\n" , vet[i]);
  }

  return 0;


}