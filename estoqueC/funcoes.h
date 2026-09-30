//
// Created by Bruno on 28/09/2026.
//

#ifndef SISTEMAESTOQUE_MINHAS_FUNCOES_H
#define SISTEMAESTOQUE_MINHAS_FUNCOES_H

//Define capacidade do estoque
#define MAX 100

typedef struct {
    int quantidade;
    char nome[100];
    float preco;
    int codigo;
}produto;

//Prototipo da função cadastrarProduto
void cadastrarProduto(produto estoque[]);

//Prototipo da função consultarProduto
void consultarProduto(produto estoque[]);

//Prototipo da função editarProduto
void editarProduto(produto estoque[]);

int validacao(varvalidacao);


#endif //SISTEMAESTOQUE_FUNCOES_H
