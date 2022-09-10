#include <stdio.h>

/*
    Determine o que será mostrado pelo seguinte programa (compile-o, execute-o e verifique se foram obtidas as respostas esperadas)
*/

int main()
{
    int valor, *p1;
    float temp, *p2;
    char aux, *nome = "Ponteiros", *p3;
    int idade, vetor[3], *p4, *p5;

    /* (a) */ // Será impresso 20 pois o ponteiro p1 aponta para o endereco de valor e *p = 20 sobrescreve o valor de 10 na variável valor
    valor = 10;
    p1 = &valor;
    // printf("p1 = %x \n*p1 = %d \nvalor = %d \n", p1, *p1, valor);
    *p1 = 20;
    // printf("p1 = %x \n*p1 = %d \nvalor = %d \n", p1, *p1, valor);
    printf("%d \n", valor);

    /* (b) */ // Mesma situacão da questão anterior, o ponteiro sobrescreverá o conteúdo da variável temp por 29.0
    temp = 26.5;
    p2 = &temp;
    // printf("p2 = %x \n*p2 = %.1f \ntemp = %.1f \n", p2, *p2, temp);
    *p2 = 29.0;
    // printf("p2 = %x \n*p2 = %.1f \ntemp = %.1f \n", p2, *p2, temp);
    printf("%.1f \n", temp);

    /* (c) */ // p3 aponta para o endereco do primeiro elemento do array nome sendo P e aux recebe esse valor
    p3 = &nome[0];
    aux = *p3;
    printf("%c \n", aux);

    /* (d) */ // Mesma situacão, mas p3 aponta para o quarto elemento do arraym sendo e e aux recebe esse valor
    p3 = &nome[4];
    aux = *p3;
    printf("%c \n", aux);

    /* (e) */ // p3 aponta para o array nome apartir do endereco do primeiro elemento, logo será impresso P
    p3 = nome;
    printf("%c \n", *p3);

    /* (f) */ // Será impresso e, pois é incrementado 4 unidades no índice do array, no caso nome[4]
    p3 = p3 + 4;
    printf("%c \n", *p3);

    /* (g) */ // Será impresso t, pois é decrementado 1 unidade no índice do array, ou seja nome[3]
    p3--;
    printf("%c \n", *p3);

    /* (h) */ // Como o índice não foi informado, será impresso o conteúdo do primeiro enderećo do array, ou seja 31
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;
    idade = *p4;
    printf("%d \n", idade);

    /* (i) */ // Será incrementado 1 unidade no índice do array vetor, ou seja, vetor[1] imprimindo 45
    p5 = p4 + 1;
    idade = *p5;
    printf("%d \n", idade);

    /* (j) */ // Será incrementado 1 unidade no índice do array vetor, ou seja, vetor[2] imprimindo 27
    p4 = p5 + 1;
    idade = *p4;
    printf("%d \n", idade);

    /* (l) */ // Será decrementado 2 unidade no índice do array vetor, ou seja, vetor[0] imprimindo 31
    p4 = p4 - 2;
    idade = *p4;
    printf("%d \n", idade);

    /* (m) */ // Será decrementado 1 unidade no endereco, ou seja, vetor[1] imprimindo 45
    p5 = &vetor[2] - 1;
    printf("%d \n", *p5);

    /* (n) */ // Será incrementado 1 unidade no índice do array vetor, ou seja, vetor[2] imprimindo 27
    p5++;
    printf("%d \n", *p5);
    return 0;
}
