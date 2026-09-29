#include <stdio.h>
#include  "funcoes.h"

int main(void) {

    produto estoque [MAX] = {0};
    int funcao;
    int validacao;

    do {
        do {    //Cria o loop caso receba a entrada invalida

            //Tela inicial

            printf("1-Cadastrar um novo produto\n");
            printf("2-Consultar produtos em estoque\n");
            printf("3-Editar produtos em estoque\n");
            printf("4-Encerrar sessao\n");

            //Verifica se a entrada é valida

            validacao = scanf("%d", &funcao);
            if (validacao!=1 || (funcao!=1 && funcao!=2 && funcao!=3 && funcao!=4)) {
                printf("Entrada Invalida!\n");
                while (getchar() != '\n');      //Limpa o buffer
            }
        }while (validacao!=1 || (funcao<1 || funcao>4));

        switch (funcao) {
            case 1: cadastrarProduto(estoque); break;  //Cadastrar novo produto

            case 2: consultarProduto(estoque); break;       //Consultar produtos existentes

            case 3: editarProduto(estoque); break;      //Editar produtos em estoque
        }
    }while(funcao!=4);

    return 0;
}