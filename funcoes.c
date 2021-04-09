#include <stdio.h>
#include <stdlib.h>

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
    printf( "\n=== MENU PRINCIPAL ===\n\n");
    printf( "> 1 - Gerenciamento dos clientes   \n"
            "> 2 - Pesquisar dados dos clientes \n"
            "> 3 - Relatórios diversos          \n"
            "> 4 - Descrição do programa        \n"
            "> 0 - Sair do programa             \n\n");
    printf( "Escolha a opção que você deseja executar > ");
    scanf("%d", &opt);
    return opt;
}

int gerenciamento(void){
    /// Gerenciamento dos clientes
    system("clear");
    int select;
    printf( "\n=== Gerenciamento dos Clientes ===\n\n");
    printf( "> 1 - Cadastro de clientes         \n"
            "> 2 - Editar dados dos clientes    \n"
            "> 3 - Cadastro de vendas           \n"
            "> 4 - Excluir dados dos clientes   \n\n");
    printf("Escolha a opção que você deseja executar > ");
    scanf("%d", &select);
    return select;
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
