#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "utils.h"
#include "cliente.h"

int main(void) {
  int opt;
  do{
    opt = mainmenu();
    switch (opt){
      case 1: 
        crud();
        break;
      case 4:
        description();
        printf("\n\nPressione uma tecla para voltar ao menu principal");
        getchar();
        break;
      case 0:
        system("clear");
        break;
      default:
        system("clear");
        printf("Você escolheu uma opção inválida!");
        printf("\n\nPrecione alguma tecla para voltar ao menu principal");
        getchar();
        break;
    }
  }while(opt != 0);
  return 0;
}
