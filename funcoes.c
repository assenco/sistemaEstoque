//
// Created by Bruno on 28/09/2026.
//

#include "funcoes.h"
#include <stdio.h>
#include <string.h>

//Falta fazer funcao para validação de entreda de strings, verificar se nao ficou sobrendo variaveis obsoletas principalmente de "validacao", e testar o codigo atual
int lerInt(char msg[], int min) {

    int valor;
    int validacao;

    do {
        printf("%s\n", msg);
        validacao = scanf("%d", &valor);
        if (validacao!=1 || valor<min) {
            printf("Valor Invalido!\n");
            while (getchar() != '\n');
        }
    }while (validacao!=1);

    return valor;
}

float lerFloat(char msg[], int min) {

    int validacao;
    int valor;

    do {
        printf("%s\n", msg);
        validacao = scanf("%lf", &valor);
        if (validacao!=1 || valor < min) {
            printf("Valor Invalido\n");
            while (getchar() != '\n');
        }
    }while (validacao!=1);
}

void cadastrarProduto(produto estoque[]) {

    char opcao='s';
    int posicaoVazia=0;
    int validacao;

    for (int i=0; opcao!='n' && i<MAX; i++){        //Cria loop enquanto usuario quiser criar novos produtos

        for (posicaoVazia ; posicaoVazia<MAX && estoque[posicaoVazia].codigo!=0 ; posicaoVazia++);      //Verifica qual posicao do vetor esta vazia
        if (posicaoVazia>=MAX) {
            printf("Estoque cheio! Nao e possivel cadastrar mais produtos\n");
            break;
        }

        //Inserir nome do produto

        do {                                                            //Cria um loop ate o usuario digitar uma entrada valida
            printf("Produto:\n");
            validacao = scanf(" %99[^\n]", estoque[posicaoVazia].nome); //Insere o novo produto na posicao que esta vazia
            if (validacao!=1) {                                          //Faz a validacao do valor inserido
                printf("Entrada Invalida!\n");
                while (getchar() != '\n');                               //Limpa o buffer
            }
        }while (validacao!=1);

        //Gera codigo do produto

        estoque[posicaoVazia].codigo=posicaoVazia+1;

        //Inserir quantidade

        estoque[posicaoVazia].quantidade = lerInt("Digite a quantidade:", 1);

        //Inserir preco

        estoque[posicaoVazia].preco = lerFloat("Digite o preco do produto:", 0.5);

        //Mostra todos os dados do produto
        printf("\tCodigo: %03d\n", estoque[posicaoVazia].codigo);
        printf("\t%s\n", estoque[posicaoVazia].nome);
        printf("\tQuantidade: %d\n", estoque[posicaoVazia].quantidade);
        printf("\tPreco: R$%.2f\n\n", estoque[posicaoVazia].preco);

        do {
            printf("Deseja adicionar mais algum?  (s/n)\n");
            scanf(" %c", &opcao);
            if (opcao!='s' && opcao!='n') {
                printf("Entrada Invalida!\n");
                while (getchar() != '\n');
            }
        }while (opcao!='s' && opcao!='n');
    }
}

void consultarProduto(produto estoque[]) {

    int encontrado=0;

    //Faz a verificação se existem produtos em estoque

    for (int i=0; i<MAX; i++){
        if (estoque[i].codigo>0) encontrado=1;
    }

    //Caso estoque esteja vazio

    if (!encontrado) {
        printf("Estoque vazio!\n");

        return;
    }

    printf("---------------------------------------\n");
    for (int i=0; i<MAX; i++){      //Imprime a lista completa

        if (estoque[i].codigo<1) continue;     //Imprime somente a parte da lista que contem valores

        printf("%03d - ", estoque[i].codigo);
        printf("%s | ", estoque[i].nome);
        printf("Quantidade: %d | ", estoque[i].quantidade);
        printf("Preco: R$%.2f\n", estoque[i].preco);
    }
    printf("---------------------------------------\n\n");
}

void editarProduto(produto estoque[]) {

    int opcao=0;
    int produtoEditar;
    int encontrado;

    do {

        produtoEditar = lerInt("Digite o codigo do produto:", 1);

        encontrado=0;

        //Verifica se o produto existe no estoque

        for (int i=0; i<MAX; i++) {
            if (estoque[i].codigo==produtoEditar) {
                encontrado=1;
                break;
            }
        }
        if (!encontrado) printf("Codigo nao encontrado!\n");

    }while (encontrado==0);

    //Exibe o produto selecionado

    printf("---------------------------------------\n");
    printf("%03d - ", estoque[produtoEditar-1].codigo);
    printf("%s | ", estoque[produtoEditar-1].nome);
    printf("Quantidade: %d | ", estoque[produtoEditar-1].quantidade);
    printf("Preco: R$%.2f\n", estoque[produtoEditar-1].preco);
    printf("---------------------------------------\n\n");

    //Mostra opções de edição ou deletar

    do {
        opcao = lerInt("1-Apagar item\n2-Editar item", 1);
    }while (opcao!=1 && opcao!=2);

    //Apagar item do estoque

    if (opcao==1) {
        strcpy(estoque[produtoEditar-1].nome, "");
        estoque[produtoEditar-1].codigo=0;
        estoque[produtoEditar-1].quantidade=0;
        estoque[produtoEditar-1].preco=0;

        printf("Produto deletado!\n");
    }

    //Editar item do estoque

    if (opcao==2) {

        int itemModificar;
        char novaModificacao;

        do {
            printf("Qual informacao deseja editar:\n");

            printf("1-Produto\n");
            printf("2-Quantidade\n");
            printf("3-Preco\n");

            do {
                itemModificar = lerInt("Digite a opcao:", 1);
            }while (itemModificar!=1 && itemModificar!=2 && itemModificar!=3);

            if (itemModificar==1) {
                do {
                    printf("Produto:\n");
                    validacao = scanf(" %99[^\n]", estoque[produtoEditar-1].nome);
                    if (validacao!=1) {
                        printf("Entrada Invalida!\n");
                        while (getchar() != '\n');
                    }
                }while (validacao!=1);
            }

            if (itemModificar==2) {
                estoque[produtoEditar-1].quantidade = lerInt("Digite a quantidade:", 1);
            }

            if (itemModificar==3) {
                estoque[produtoEditar-1].preco = lerFloat("Digite o preco do produto:", 0.5);
            }

            printf("Item modificado!\n\n");

            do {
                printf("Deseja modificar mais algum item deste produto? (s/n)\n");
                scanf(" %c", &novaModificacao);
                if (novaModificacao!='s' && novaModificacao!='n') {
                    printf("Entrada Invalida!\n");
                    while (getchar() != '\n');
                }
            } while (novaModificacao!='s' && novaModificacao!='n');

        }while (novaModificacao=='s');

    }
}