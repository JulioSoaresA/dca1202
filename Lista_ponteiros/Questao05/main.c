#include <stdio.h>



int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;
  printf("contador/valor/valor/endereco/endereco");
  for(i = 0 ; i <= 4 ; i++){
    printf("\ni = %d ",i); // mostra o indice do array
    printf("vet[%d] = %.1f ",i, vet[i]); // mostra o conteúdo da posição i do array
    printf("*(f + %d) = %.1f ",i, *(f+i)); // desloca pela memória, mostrando o mesmo conteudo de v[i]
    printf("&vet[%d] = %X ",i, &vet[i]); // mostra o endereço de v[i]
    printf("(f + %d) = %X ",i, f+i); // mostra o endereço de f+i
  }
}
// Todos os valores são mostrados conforme o esperado

