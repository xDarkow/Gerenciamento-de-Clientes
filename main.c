#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "functions/funcoes.h"
#include "functions/validacao.h"

typedef struct dados Dados;

struct dados{
  char cpf[15];
  char name[51];
  char bday[11];
  char adress[101];
  char cidade[31];
  char uf[3];
  char phone[15];
  char sexo[10];
  char email[51];
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
  do{
    opt = mainmenu();
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
        system("clear");
        break;
      default:
        system("clear");
        printf("Você escolheu uma opção inválida!");
        printf("\n\nPrecione alguma tecla para voltar ao menu principal");
        getchar();
        getchar();
        break;
    }
  }while(opt != 0);
  free(cliente);
  return 0;
}

Dados* cadastro(){
  system("clear");
  printf("=== Cadastro de clientes ===");
  printf("\n\n");
  printf("Por favor informe os dados dos clientes a seguir!\n\n");
  Dados* dds;
  dds = (Dados*) malloc(sizeof(Dados));
  printf("CPF:                       ");
  scanf(" %14[^\n]", dds->cpf);
  //onlynumb(dds->cpf);
  while(validacpf(dds->cpf)!=1){
    // system("clear");
    printf("\nVocê não digitou um CPF válido!\n");
    printf("CPF:                       ");
    scanf(" %14[^\n]", dds->cpf);
    //onlynumb(dds->cpf);
  }
  printf("NOME:                      ");
  scanf(" %50[^\n]", dds->name);
  while(validaname(dds->name)!=1){
    printf("\nVocê não digitou um Nome válido!\n");
    printf("NOME:                      ");
    scanf(" %50[^\n]", dds->name);
  }
  printf("DATA DE NASCIMENTO:        ");
  scanf(" %10[^\n]", dds->bday);
  printf("UF(Unidade Federativa):    ");
  scanf(" %2[^\n]", dds->uf);
  printf("CIDADE:                    ");
  scanf(" %30[^\n]", dds->cidade);
  printf("ENDEREÇO:                  ");
  scanf(" %100[^\n]", dds->adress);
  printf("TELEFONE/CELULAR:          ");
  scanf(" %14[^\n]", dds->phone);
  printf("SEXO (Masculino/Feminino): ");
  scanf(" %9[^\n]", dds->sexo);
  printf("EMAIL:                     ");
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