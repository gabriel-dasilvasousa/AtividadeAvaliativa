#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void imprimeMenuDeProdutos(){
  printf("Produtos disponíveis:\n");
  printf("Cod Produto Preço\n");
  printf("10 Regrigerante R$2,50\n");
  printf("15 Casquinha Simples R$1,50\n");
  printf("20 Casquinha Dupla R$2,50\n");
}

void verificaSeEstaCheio(int quantidadeDeVendas){
  if(quantidadeDeVendas>=1000){
    
  }
}

bool verificaEstoque(int estoqueDiario[2][2], int opcaoDeProduto, int quantidadeDesejada){
  //refrigerante
  if(opcaoDeProduto == 10){
    if(estoqueDiario[1][0] < quantidadeDesejada){
      return false;
    }
    else{
      estoqueDiario[1][0] -= quantidadeDesejada;
      return true;
    }
  }
  else if(opcaoDeProduto == 15 || opcaoDeProduto == 20){
    if(estoqueDiario[1][1] < quantidadeDesejada){
      return false;
    }
    else{
      estoqueDiario[1][1] -= quantidadeDesejada;
      return true;
    }
  }
  else{
    return false;
  }
}

void armazenar_Informações(int opcaoDeProduto, int quantidadeDesejada, int vendas[2][1000], int quantidadeDeVendas, int estoqueDiario[2][2]){
  bool estoqueDisponivel = verificaEstoque(estoqueDiario, opcaoDeProduto, quantidadeDesejada);

  if(estoqueDisponivel){
    vendas[0][quantidadeDeVendas] = opcaoDeProduto;
    vendas[1][quantidadeDeVendas] = quantidadeDesejada;
    printf("Venda armazenada");
    printf("\e[H\e[2J");
  }
  else{
    printf("estoque insuficiente");
    printf("\e[H\e[2J");
  }
  
}

void emitirRelatorio(int vendas[2][1000]){
  
  int quantidadeDeRefrigerantes=0, quantidadeDeCasquinhasSimples=0, quantidadeDeCasquinhasDuplas=0;
  int numeroDeVendas=0;
  float valorVendasRefrigerantes=0, valorVendasCasquinhasSimples=0, valorVendasCasquinhasDuplas=0, totalPago;
  for(int i=0;i<1000;i++){
    if(vendas[0][i] == 10){
      quantidadeDeRefrigerantes += vendas[1][i];
      valorVendasRefrigerantes += quantidadeDeRefrigerantes*2.50;
    }
    else if(vendas[0][i] == 15){
      quantidadeDeCasquinhasSimples += vendas[1][i];
      valorVendasCasquinhasDuplas += quantidadeDeCasquinhasDuplas*1.50;
    }
    else if(vendas[0][i] == 20){
      quantidadeDeCasquinhasDuplas += vendas[1][i];
      valorVendasCasquinhasSimples += quantidadeDeCasquinhasSimples*2.50;
    }
  }

  printf("\nExtrato do Dia:\n%d de Refrigerantes\n%d de Casquinhas Simples\n%d de Casquinhas Duplas\n", quantidadeDeRefrigerantes, quantidadeDeCasquinhasSimples, quantidadeDeCasquinhasDuplas);
  printf("\nValor total faturada em cada dia:\nR$%.2f Refrigerantes;\nR$%.2f Casquinhas Simples;\nR$%.2f Casquinhas Duplas\n", valorVendasRefrigerantes, valorVendasCasquinhasSimples, valorVendasCasquinhasDuplas);
  totalPago = valorVendasRefrigerantes+valorVendasCasquinhasSimples+valorVendasCasquinhasDuplas;
  printf("\nTotal (geral) arrecadado: R$%.2f\n", totalPago);

  for(int i=0; i<1000; i++){
    if(vendas[1][i] != 0){
      numeroDeVendas++;
    }
  }

  printf("\nA média de valor pago por pedido é: %.2f\n", (double) totalPago/numeroDeVendas);
}

int main(void) {
  
  int escolhaOpcaoDeAtividade=0, opcaoDeProduto, quantidadeDesejada, quantidadeDeVendas=0;
  int vendas [2][1000];
  int estoqueDiario[2][2];

  for(int i=0;i<1000;i++){
    vendas[0][i] = 0;
    vendas[1][i] = 0;
  }
  
  estoqueDiario[0][0] = 10;
  estoqueDiario[0][1] = 15;
  estoqueDiario[1][0] = 300;
  estoqueDiario[1][1] = 700;
  

  while(escolhaOpcaoDeAtividade!=2){
    
    printf("======MENU======\n");
    printf("======Escolha uma das opções:======\n");
    printf("======1-Realizar nova venda======\n");
    printf("======2-Encerrar o Movimento do Dia======\n");
    scanf(" %d", &escolhaOpcaoDeAtividade);

    if(escolhaOpcaoDeAtividade!=1 && escolhaOpcaoDeAtividade !=2){
      printf("Opção inválida\n\n");
    }
    else if(escolhaOpcaoDeAtividade==1){
      imprimeMenuDeProdutos();
      do{
        printf("Digite o Codigo do Produto desejado:\n");
        scanf("%d", &opcaoDeProduto);
      }while(opcaoDeProduto!=10 && opcaoDeProduto!=15 && opcaoDeProduto!=20);

      do{
        printf("Digite a quantidade desejada\n");
        scanf("%d", &quantidadeDesejada);
      }while(quantidadeDesejada==0);
      
      quantidadeDeVendas++;
      armazenar_Informações(opcaoDeProduto, quantidadeDesejada, vendas, quantidadeDeVendas, estoqueDiario);
    }
    
  }

  if(escolhaOpcaoDeAtividade==2){
    emitirRelatorio(vendas);
  }
  return 0;
}
