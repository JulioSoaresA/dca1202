#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//funcao de ordenacao baseada na qsort
void sort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*))
{
  void *a, *b;

  for (int i = 0; i < num-1; i++)
  {
    a = base + (size*i);
    b = base + (size*(i+1));

    if(compar(a,b) > 0)
    {
      float *pa = (float*)a;
        float *pb = (float*)b;

        float aux = *pb;
        *pb = *pa;
        *pa = aux;
    }
    for(int j = num-1; j > 0 && j > i; j--)
    {
      a = base + (size*j);
      b = base + (size*(j-1));

      if(compar(a,b) < 0)
      {
        float *pa = (float*)a;
          float *pb = (float*)b;

          float aux = *pa;
          *pa = *pb;
          *pb = aux;
      }
    }
  }
}


int main()
{
  int n;
  float *v;
  printf("Quantidade de valores: ");
  scanf("%d",&n);

  // aloca um vetor de n elementos
  v = malloc(n * sizeof(float));

  scan(v, n);
  print(v, n);

  clock_t t;
  t = clock();
  sort(v, n, sizeof (float), comparador);
  t = clock() - t;

  printf("\nValores ordenador: \n");
  print(v, n);
  free(v);
  printf("\nTempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
  return 0;
}
