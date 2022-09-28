#include <stdio.h>
#include <stdlib.h>

/*  A função recebe as entradas do usuário e
 *  preencher o vetor com os dados de entrada.
 *  o ponteiro para float serve para usar o vetor alocado dinâmicamente.
*/
void scan(float *vetor, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d Valor: ", (i+1));
    scanf("%f", &vetor[i]);

  }
}

/*  A função imprime para o usuário os dados do vetor.
*/
void print(float *vetor, int n)
{
  printf("Valores obtidos: \n");
  for (int i = 0; i < n; i++)
  {
    printf("%.2f ",vetor[i]);
  }
}

/*  Ponteiro para função que compara dois elementos, responável por
 *  definir a ordem dos elementos.
*/
int comparador (const void * a, const void * b)
{
  return ( *(float*)a - *(float*)b );
}


int main()
{
  int n;
  float *v;
  printf("Quantidade de valores: ");
  scanf("%d",&n);

  // aloca um vetor de n elementos
  v = malloc(n * sizeof(float));

  // preenche o vetor
  scan(v, n);
  // imprime o vetor
  print(v, n);
  // ordena o vetor
  qsort(v, n, sizeof (float), comparador);
  printf("\nValores ordenador: \n");
  // imprime valores ordenados
  print(v, n);
  free(v);
  return 0;
}
