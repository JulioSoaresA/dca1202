#include <stdio.h>

int main()
{
    int mat[4]={1, 2, 3, 4}, *p, x;
      p = mat + 1;// é válido pois os vetores não precisam usar o operador de endereco.

      printf("mat = %p\n",mat);
      printf("mat + 1 = %p\n",p);

      //p = mat++;// não é válido, pois essa expressao incrementa um valor inteiro, mas deveria ser no array.

      //p = ++mat;// não é válido, pois essa expressao incrementa um valor inteiro, mas deveria ser no array

      x = (*mat);// é válido, x recebe o conteúdo de mat[0] e depois incrementa o valor.

      printf("x = %d\n",x);
      return 0;
}
