#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void onlynumb(char *num){
  int i, j;
  for (i = 0; (num[i] != '\0')||(i==15); i++){
    while(!(num[i] >= '0' && num[i] <= '9') && !(num[i] == '\0')){
      for(j = i; num[j] != '\0'; j++){
        num[j] = num[j+1];
      }
      num[j] = '\0';
    }
  }
}

void description(void){
    /// Módulo que mostra as informações do projeto.
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///           UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES           ///\n");
    printf("///                                                                         ///\n");
    printf("///            Projeto geral da disciplina DCT1106 - Programação            ///\n");
    printf("///              SIG-Customer: Sistema de Controle de Clientes              ///\n");
    printf("///                                                                         ///\n");
    printf("///  As empresas da atualidade utilizam complexos sistemas gerenciais para, ///\n");
    printf("/// entre várias outras funções, gerenciar e manter  seus clientes, além de ///\n");
    printf("/// ajudar a conseguir novos clientes. O presente projeto tem como objetivo ///\n");
    printf("/// propor um software que  implemente funcionalidades básicas relacionadas ///\n");
    printf("/// ao controle de clientes de uma empresa, facilitando a gestão.           ///\n");
    printf("///                                                                         ///\n");
    printf("///                    Dev by @xDarkow (Felipe Anderson)                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}

int mainmenu(void){
    /// Menu geral
    int opt;
    system("clear");
    printf( "========= MENU PRINCIPAL =========\n\n");
    printf( "> 1 - Gerenciamento de clientes   \n"
            "> 2 - *** \n"
            "> 3 - ***          \n"
            "> 4 - Descrição do programa        \n"
            "> 0 - Sair do programa             \n\n");
    printf( "Escolha a opção que você deseja executar > ");
    scanf("%d", &opt);
    getchar();
    return opt;
}

int gerenciamento(void){
    /// Gerenciamento dos clientes
    int opt;
    system("clear");
    printf( "\n=== Gerenciamento dos Clientes ===\n\n");
    printf( "> 1 - Cadastro de clientes         \n"
            "> 2 - Editar dados dos clientes    \n"
            "> 3 - Excluir dados dos clientes   \n"
            "> 3 - Pesquisar dados dos clientes \n"
            "> 4 - Listar dados dos clientes    \n"
            "> 0 - Voltar ao menu principal     \n\n");
    printf("Escolha a opção que você deseja executar > ");
    scanf("%d", &opt);
    getchar();
    return opt;
}

void dataresearch(void){
    /// Pesquisar dados dos clientes
    system("clear");
    printf( "\n=== Pesquisar dados dos clientes ===\n\n");
    printf( "> 1 - Pesquisa individual      \n"
            "> 2 - Listagem dos clientes    \n\n");
    printf("Escolha a opção que você deseja executar > ");
}

void datareport(void){
    /// Relatórios diversos
    system("clear");
    printf( "\n=== Relatórios diversos ===\n\n");
    printf( "> 1 - Faixa etária e sexo dos clientes \n"
            "> 2 - Vendas por mês                   \n"
            "> 3 - Média de gasto por sexo          \n"
            "> 4 - Média de gasto por faixa etária  \n\n");
    printf("Escolha a opção que você deseja executar > ");
}

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
