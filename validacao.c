#include <string.h>

int validacpf(char cpf[]){
  int cpfint[11];
  int i, j, sum, dig1, dig2, equal;
  // Converte o array de char em int
  for (i=0; i<11; i++){
      cpfint[i]=cpf[i]-48;//O -48 é por causa da tabela ASCII ONDE DO CHARACTER '0' TEM VALOR INT 48  E ASSIM POR DIANTE ATÉ CHAR '9' = INT 57
  }
  //digito 1
  sum = 0;
  for(i=0; i<9; i++){
    sum += cpfint[i]*(10-i);
  }
  dig1 = (sum*10)%11;
  if (dig1 == 10){
    dig1 = 0;
  }
  //digito 2
  sum = 0;
  for(i=0; i<10; i++){
    sum += cpfint[i]*(11-i);
  }
  dig2 = (sum*10)%11;
  if (dig2 == 10){
    dig2 = 0;
  }
  //checando se todos os dígitos são iguais
  equal = 0;
  for (i=0; i<10; i++){
    if (cpfint[i] == cpfint[i+1]){
      equal+=1;
    }
  }
  //validação
  if((dig1 == cpfint[9])&&(dig2 == cpfint[10])&&(equal<10)){
    return 1;
  }else{
    return 0;
  }
}

int validaname(char *a){
  int i, check = 0, stringsize;
  for (i = 0; i<strlen(a); i++){
    if ((a[i] >= 'a' && a[i]<= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || a[i] == ' '){
      check++;
    }
  }
  stringsize = strlen(a);
  if (stringsize == check){
    return 1;
  }else{
    return 0;
  }
}