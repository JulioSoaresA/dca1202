#include <stdio.h>
/*
    Se i e j são variáveis inteiras e p e q ponteiros para int, quais das seguintes expressões de atribuição são ilegais?
    p = i;
    q = &j;
    p = &*&i;
    i = (*&)j;
    i = *&j;
    i = *&*&j;
    q = *p;
    i = (*p)++ + *q;
*/
int main()
{
    int i = 7, j = 2;
    int *p, *q;

    p = i; // ilegal, p não aponta para i, pois falta o &

    q = &j; // Legal

    p = &*&i; // Legal, é o mesmo de &(*(&i))

    i = (*&)j; // ilegal, expressão escrita errado, seria (*&j) ou (*(&j))

    i = *&j; // legal

    i = *&*&j; // legal, i recebe o valor de um endereco, que seria 2

    q = *p; // ilegal, deveria ser usado & para que q aponte para o endereco

    i = (*p)++ + *q; // legal, o valor que p aponta está sendo somado p = p + 1 e somando com o valor que q está apontando
    return 0;
}
