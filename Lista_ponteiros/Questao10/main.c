#include <stdio.h>


int main()
{
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;

    aloha[2] = value;// é válido, aloha[2] está recebendo o valor da variável value.
    scanf("%f", &aloha);// não é válido, para usar o &, aloha deveria ser um ponteiro ou deveria referenciar a posicão do vetor a ser salva.

    //aloha = value";// não é válido, deve ser explicitado em qual posicão do vetor se quer guardar o valor de value.
    printf("%f", aloha);// deveria ser impresso um valor float e não um vetor float
    coisas[4][4] = aloha[3];// é válido, a posicão da matriz coisas[4][4] recebe o conteúdo de aloha[3]
    coisas[5] = aloha;// não é válido, deveria ser passado elemento por elemento em cada posicão
    pf = value;// não é válido, pf não aponta para value sem o operador de endereco
    pf = aloha;// é valido, os vetores já são referenciados, logo não precisam do operador de endereco
