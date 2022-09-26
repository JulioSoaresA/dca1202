#include <stdio.h>

int main(){
  int vet[] = {4,9,13};
  int i;
  for(i=0;i<3;i++){
    printf("%d ",*(vet+i)); // 8a, imprime o conteúdo de v + i
    printf("%X \n",(vet+i));// 8b, imprime o enderećo de v + i
  }
}

