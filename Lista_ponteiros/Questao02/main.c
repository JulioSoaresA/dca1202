#include <stdio.h>

/*
    Mostre o que será impresso por programa supondo que i ocupa o endereço 4094 na memória.
*/

int main()
{
    int i = 5, *p;
    p = &i;

    printf("p: %x\n", p);
    printf("*p: %d\n", *p);
    printf("*p + 2: %d\n", *p + 2);
    printf("**&p: %d\n", **&p);
    printf("3**p: %d\n", 3**p);
    printf("**&p + 4: %d\n", **&p + 4);

    printf("%x %d %d %d %d\n", p,*p+2,**&p,3**p,**&p+4);
    return 0;
}
