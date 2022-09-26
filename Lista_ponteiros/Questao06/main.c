#include <stdio.h>

int main()
{
    int pulo[5] = {1, 2, 3, 4, 5};

      printf("%d\n",*(pulo + 2));/* referencia ao terceiro elemento, assumindo que o primeiro indice do vetor eh 0,
                                    temos 2 como terceiro indice que é o terceiro elemento, imprimindo 3*/

      printf("%d\n",*(pulo + 4));/*referencia ao quinto elemento do vetor, imprimindo 5.*/

      printf("%d\n",pulo + 4);// endereco do quinto elemento do vetor

      printf("%d\n",pulo + 2);// endereco do terceiro elemento do vetor
      return 0;
}
