#include <stdio.h>

int main()
{
  char x_char[4] = {'a','b','c','d'};         // 1 byte
  int x_int[4] = {1,2,3,4};                   // 4 bytes, considerar como 2 bytes
  float x_float[4] = {0.1,0.2,0.3,0.4};       // 4 bytes
  double x_double[4] = {1.0,2.0,3.0,4.0};     // 8 bytes

  for (int i = 0; i < 4; i++)
  {
    printf("char = %p\n",(x_char + i));
    printf("int = %p\n",(x_int + i));         // considerando que caminha de 2 em 2 bytes
    printf("float = %p\n",(x_float + i));
    printf("double = %p\n",(x_double + i));
    printf("-----------------------------\n");
  }
  return 0;
}

/*
    x for declarado como char? caminha 1 byte na memória
    x + 0 -> 4092
    x + 1 -> 4093
    x + 2 -> 4094
    x + 3 -> 4095
    -----------------------------
    x for declarado como int? caminha 2 bytes na memória
    x + 0 -> 4092
    x + 1 -> 4094
    x + 2 -> 4096
    x + 3 -> 4098
    -----------------------------
    x for declarado como float? caminha 4 bytes na memória
    x + 0 -> 4092
    x + 1 -> 4096
    x + 2 -> 4100
    x + 3 -> 4104
    -----------------------------
    x for declarado como double? caminha 8 bytes na memória
    x + 0 -> 4092
    x + 1 -> 4100
    x + 2 -> 4108
    x + 3 -> 4116
*/
