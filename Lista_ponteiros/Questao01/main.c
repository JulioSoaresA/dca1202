#include <stdio.h>

/*
    Determinar o valor das expressões:
    p == &i;
    *p - *q;
    **&p;
    3 - *p/(*q) + 7;
*/

int main()
{
    int i = 3, j = 7;
    int *p, *q;

    p = &i;
    q = &j;

    printf("p == &i: %d\n",p == &i); //Valor de p é o mesmo que está no enderećo de i
    printf("*p - *q: %d\n",(*p - *q));//Conteúdo de p menos o conteúdo de q == 3 - 7 = -4
    printf("**&p: %d\n",(**&p));//Ponteiro que aponta pro ponteiro que aponta pra o enderećo de p
    printf("3 - *p/(*q) + 7: %d\n",(3 - *p/(*q) + 7));
    return 0;
}
