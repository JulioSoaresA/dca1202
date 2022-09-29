Foi utilizada a biblioteca `time.h` para verificar o tempo de execução do trecho de código.

Importando a biblioteca `<time.h>` e declarando a variável `clock_t t;`, foi utilizado o trecho de código que queremos 
verificar o tempo de execução entre `t = clock();` e `t = clock() - t;`, e imprimir usando `printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));`.

Foram coletados dados sobre os tempos de execução que podem ser observados nas tabelas abaixo:

**qsort**

|     Entradas    |       Entradas      |                  Saídas                 | Tempo de Execução |
|:---------------:|:-------------------:|:---------------------------------------:|:-----------------:|
|        3        |       15 -1 0       |             -1.0 0.0 15.00              |      0.004000     |
|        5        |    33 -51 1 -5 2    |       -51.00 -5.00 1.00 2.00 33.00      |      0.006000     |
|        7        | 98 12 -5 3 -22 -1 1 | -22.00 -5.0 -1.00 1.00 3.00 12.00 98.00 |      0.004000     |

**sort**

|     Entradas    |       Entradas      |                  Saídas                 | Tempo de Execução |
|:---------------:|:-------------------:|:---------------------------------------:|:-----------------:|
|        3        |       15 -1 0       |             -1.0 0.0 15.00              |      0.003000     |
|        5        |    33 -51 1 -5 2    |       -51.00 -5.00 1.00 2.00 33.00      |      0.003000     |
|        7        | 98 12 -5 3 -22 -1 1 | -22.00 -5.0 -1.00 1.00 3.00 12.00 98.00 |      0.006000     |

**Média de tempo de execução**

|      Função      |    Média de Tempo    |
|:----------------:|:--------------------:|
|      qsort       |       0.004666       |
|      sort        |       0.004000       |

Comparando o tempo de execução das duas funçõe, a sort obteve um tempo de execução mais baixo. Mas não podemos 
afirmar que seja a mais eficiente, a IDE utilizada ou o processamento do computador pode interfirir no tempo de execução.

