#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "utils.h"
#include "cliente.h"

typedef struct dados Dados;

struct dados{
  char cpf[15];
  char name[51];
  char bday[11];
  char uf[3];
  char cidade[33];
  char adress[101];
  char phone[15];
  char sexo[10];
  char email[51];
  unsigned long int userid;
};

Dados* preencherdados();
void savedata(Dados*);
void clienteinfo(const Dados*);
void cadastro(void);

void crud(void){
  //Dados* cliente;
  int opt;
  do{
    opt = gerenciamento();
    switch(opt){
      case 1:
        cadastro();
      case 2:
      case 3:
      case 4:
        printf("\n\nPrecione uma tecla para voltar ao módulo Gerenciamento de Clientes");
        getchar();
        break;
      case 0:
      default:
        break;
    }
  }while(opt != 0);
}

void cadastro(void){
  Dados* dds;

  dds = preencherdados();
  savedata(dds);
  free(dds);
}

Dados* preencherdados(){
  system("clear");
  printf("============== Cadastro de clientes ==============");
  printf("\n\n");
  printf("Por favor informe os dados dos clientes a seguir!\n\n");
  Dados* dds;
  dds = (Dados*) malloc(sizeof(Dados));
  printf("CPF:                                ");
  scanf(" %14[^\n]", dds->cpf);
  onlynumb(dds->cpf);
  while(validacpf(dds->cpf)!=1){
    // system("clear");
    printf("\nVocê não digitou um CPF válido!\n");
    printf("CPF:                                ");
    scanf(" %14[^\n]", dds->cpf);
    onlynumb(dds->cpf);
  }
  printf("NOME:                               ");
  scanf(" %50[^\n]", dds->name);
  while(validaname(dds->name)!=1){
    printf("\nVocê não digitou um Nome válido!\n");
    printf("NOME:                               ");
    scanf(" %50[^\n]", dds->name);
  }
  printf("DATA DE NASCIMENTO(dd/mm/aaaa):     ");
  scanf(" %10[^\n]", dds->bday);
  printf("UF(Unidade Federativa):             ");
  scanf(" %2[^\n]", dds->uf);
  printf("CIDADE:                             ");
  scanf(" %32[^\n]", dds->cidade);
  printf("ENDEREÇO:                           ");
  scanf(" %100[^\n]", dds->adress);
  printf("TELEFONE/CELULAR (Números com DDD): ");
  scanf(" %14[^\n]", dds->phone);
  printf("SEXO (Masculino/Feminino):          ");
  scanf(" %9[^\n]", dds->sexo);
  printf("EMAIL:                              ");
  scanf(" %50[^\n]", dds->email);
  return dds;
}

void savedata(Dados* dds){
  FILE* fp;

  fp = fopen("clientes.dat", "ab");
  if(fp == NULL){
    printf("Ocorreu um problema ao abrir o arquivo!");
    exit(1);
  }
  fwrite(dds, sizeof(Dados), 1, fp);
  fclose(fp);
}

void clienteinfo(const Dados* dds){
  system("clear");
  printf("=== Cliente Cadastrado ===\n\n");
  printf("CPF:          %s\n", dds->cpf);
  printf("Nome:         %s\n", dds->name);
  printf("Data de nasc: %s\n", dds->bday);
  printf("UF:           %s\n", dds->uf);
  printf("Cidade:       %s\n", dds->cidade);
  printf("Endereço:     %s\n", dds->adress);
  printf("Telefone:     %s\n", dds->phone);
  printf("Sexo:         %s\n", dds->sexo);
  printf("email:        %s\n", dds->email);
}