`"%x\n", p`: é o endereço hexadecimal, assumindo que p aponta para um unsigned int

`%d\n",*p+2`: *p mostra o valor guardado em i que p aponta, nisso temos que o valor para o qual aponta + 2 resulta em 7.

`%d\n",**&p`: é ponteiro para ponteiro de um valor em um endereço e resulta em 5 que é o valor de i. 

`%d\n",3**p`: é uma operação onde o valor inteiro que p aponta vai ser multiplicado por 3 e resultando no valor de 15.

`%d\n",**&p+4`: ponteiro para ponteiro de um valor em um endereço,resultando em 5 sendo o valor de i que p aponta e somando 4, resultando em 9. 
