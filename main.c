#include <stdio.h>
#include  "funcoes.h"

int main(void) {

    produto estoque [MAX] = {0};
    int funcao;

    do {
        do {    //Cria o loop caso receba a entrada invalida

            //Tela inicial

            printf("1-Cadastrar um novo produto\n");
            printf("2-Consultar produtos em estoque\n");
            printf("3-Editar produtos em estoque\n");
            printf("4-Encerrar sessao\n");

            //Verifica se a entrada é valida

            do {
                funcao = lerInt("Digite a funcao que deseja executar:", 1);
            }while (funcao<1 || funcao>4);

        switch (funcao) {
            case 1: cadastrarProduto(estoque); break;  //Cadastrar novo produto

            case 2: consultarProduto(estoque); break;       //Consultar produtos existentes

            case 3: editarProduto(estoque); break;      //Editar produtos em estoque
        }
    }while(funcao!=4);

    return 0;
}