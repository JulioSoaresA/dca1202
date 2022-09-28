#include <stdio.h>
#include <stdlib.h>

void scan(float *vetor, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d Valor: ", (i+1));
    scanf("%f", &vetor[i]);

  }
}

void print(float *vetor, int n)
{
  printf("Valores obtidos: \n");
  for (int i = 0; i < n; i++)
  {
    printf("%.2f ",vetor[i]);
  }
}

void ordena_crescente(void (*f)(float*,int),float *vetor, int n, void (*i)(float*,int))
{
  int aux = 0;

  f(vetor,n);

  i(vetor,n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(vetor[i] < vetor[j])
      {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  printf("\nValores ordenados: \n");
  i(vetor,n);
}

int main()
{
  int n;
  float *v;
  printf("Quantidade de valores: ");
  scanf("%d",&n);

  v = malloc(n * sizeof(float));

  ordena_crescente(scan, v, n, print);

  free(v);
  return 0;
}
