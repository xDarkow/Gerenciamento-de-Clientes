#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "funcoes.h"
#include "validacao.h"

typedef struct dados Dados;

struct dados{
  char cpf[15];
  char name[51]; // fazer de forma dinâmica
  char bday[11];
  char adress[101]; //fazer de forma dinâmica
  char phone[15];
  char sexo[10];
  char email[51]; //fazer de forma dinâmica
};

struct vendas{
  char cpf[15];
  char date[11];
  float valor;
};

Dados* cadastro();
void clienteinfo(const Dados*);

int main(void) {
  Dados* cliente;
  int opt;
  opt = mainmenu();
  while (opt != 0){
    switch (opt){
      case 1: 
        cliente = cadastro();
        break;
      case 2:
        clienteinfo(cliente);
        getchar();
        getchar();
        break;
      case 0:
        system("clear");
        printf("Programa Encerrado!");
        printf("\n\nPrecione alguma tecla para sair do programa");
        getchar();
        getchar();
        break;
      default:
        system("clear");
        printf("Você escolheu uma opção inválida!");
        printf("\n\nPrecione alguma tecla para voltar ao menu principal");
        getchar();
        getchar();
    }
    opt = mainmenu();
  }
  free(cliente);
  return 0;
}

Dados* cadastro(){
  system("clear");
  printf("=== Cadastro de clientes ===\n\n");
  Dados* dds;
  dds = (Dados*) malloc(sizeof(Dados));
  printf("Informe o cpf do cliente:                ");
  scanf(" %14[^\n]", dds->cpf);
  //onlynumb(dds->cpf);
  while(validacpf(dds->cpf)!=1){
    // system("clear");
    printf("\nVocê não digitou um CPF válido!\n");
    printf("Informe o cpf do cliente:                ");
    scanf(" %14[^\n]", dds->cpf);
    //onlynumb(dds->cpf);
  }
  printf("Informe o nome do cliente:               ");
  scanf(" %50[^\n]", dds->name);
  while(validaname(dds->name)!=1){
    printf("\nVocê não digitou um Nome válido!\n");
    printf("Informe o nome do cliente:               ");
    scanf(" %50[^\n]", dds->name);
  }
  printf("Informe a data de nascimento do cliente: ");
  scanf(" %10[^\n]", dds->bday);
  printf("Informe o endereço do cliente:           ");
  scanf(" %100[^\n]", dds->adress);
  printf("Informe o telefone/celular do cliente:   ");
  scanf(" %14[^\n]", dds->phone);
  printf("Informe o sexo do cliente:               ");
  scanf(" %9[^\n]", dds->sexo);
  printf("Informe o email do cliente:              ");
  scanf(" %50[^\n]", dds->email);
  return dds;
}

void clienteinfo(const Dados* dds){
  system("clear");
  printf("=== Cliente Cadastrado ===\n\n");
  printf("CPF:          %s\n", dds->cpf);
  printf("Nome:         %s\n", dds->name);
  printf("Data de nasc: %s\n", dds->bday);
  printf("Endereço:     %s\n", dds->adress);
  printf("Telefone:     %s\n", dds->phone);
  printf("Sexo:         %s\n", dds->sexo);
  printf("email:        %s\n", dds->email);
}