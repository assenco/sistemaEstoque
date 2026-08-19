#include <stdio.h>
#include <string.h>

//Define capacidade do estoque
#define MAX 100

typedef struct {
    int quantidade;
    char nome[100];
    float preco;
    int codigo;
}produto;

int main(void) {

    /*int quantidade[MAX]={0};
    char produto[MAX][100]={0};
    float preco[MAX]={0};
    int codigo[MAX]={0};*/
    produto estoque [MAX] = {0};
    int funcao;
    int validacao;



    do{

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
        }while (validacao!=1 || (funcao!=1 && funcao!=2 && funcao!=3 && funcao!=4));

        switch (funcao) {

            case 1: {       //Cadastrar novo produto

                char opcao='s';
                int posicaoVazia=0;

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

                    do {                                            //Cria um loop ate o usuario digitar uma entrada valida
                        printf("Quantidade a ser armazenada:\n");
                        validacao = scanf("%d", &estoque[posicaoVazia].quantidade);
                        if (validacao!=1 || estoque[posicaoVazia].quantidade<1) {        //Faz a validacao do valor inserido
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');                              //Limpa o buffer
                        }
                    }while (validacao!=1 || estoque[posicaoVazia].quantidade<1);

                    //Inserir preco

                    do {
                        printf("Preco do produto:\n");              //Mesmos comentarios da entrada de codigo se aplicam
                        validacao = scanf("%f", &estoque[posicaoVazia].preco);
                        if (validacao!=1 || estoque[posicaoVazia].preco<0.05) {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                        }
                    }while (validacao!=1 || estoque[posicaoVazia].preco<0.05);

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
                break;
            }

            case 2: {       //Consultar produtos existentes

                int encontrado=0;

                //Faz a verificação se existem produtos em estoque

                for (int i=0; i<MAX; i++){
                    if (estoque[i].codigo>0) encontrado=1;
                }

                //Caso estoque esteja vazio

                if (!encontrado) {
                    printf("Estoque vazio!\n");
                    break;
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
                break;
            }

            case 3: {       //Editar produtos em estoque

                int opcao=0;
                int produtoEditar;
                int encontrado;

                do {
                    do {
                        printf("Qual o codigo do produto?\n");
                        validacao = scanf("%d", &produtoEditar);
                        if (validacao!=1 || produtoEditar<1) {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                        }
                    }while (validacao!=1 || produtoEditar<1);

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
                    printf("1-Apagar item\n");
                    printf("2-Editar item\n");
                    validacao = scanf("%d", &opcao);
                    if (validacao!=1 || (opcao!=1 && opcao!=2)) {
                        printf("Entrada Invalida!\n");
                        while (getchar() != '\n');
                    }
                } while (validacao!=1 || (opcao!=1 && opcao!=2));

                //Apagar item do estoque

                if (opcao==1) {
                    strcpy(estoque[produtoEditar-1].nome, "");
                    estoque[produtoEditar-1].codigo=0;
                    estoque[produtoEditar-1].quantidade=0;
                    estoque[produtoEditar-1].preco=0;

                    printf("Produto deletado!\n");

                    break;
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

                        validacao=scanf("%d", &itemModificar);

                        if (validacao!=1 || (itemModificar!=1 && itemModificar!=2 && itemModificar!=3)) {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                            continue;
                        }

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
                            do {
                                printf("Quantidade a ser armazenada:\n");
                                validacao = scanf("%d", &estoque[produtoEditar-1].quantidade);
                                if (validacao!=1 || estoque[produtoEditar-1].quantidade<1) {
                                    printf("Entrada Invalida!\n");
                                    while (getchar() != '\n');
                                }
                            }while (validacao!=1 || estoque[produtoEditar-1].quantidade<1);
                        }

                        if (itemModificar==3) {
                            do {
                                printf("Preco do produto:\n");
                                validacao = scanf("%f", &estoque[produtoEditar-1].preco);
                                if (validacao!=1 || estoque[produtoEditar-1].preco<0.05) {
                                    printf("Entrada Invalida!\n");
                                    while (getchar() != '\n');
                                }
                            }while (validacao!=1 || estoque[produtoEditar-1].preco<0.05);
                        }

                        printf("Item modificado!\n\n");

                        printf("Deseja modificar mais algum item deste produto? (s/n)\n");
                        scanf(" %c", &novaModificacao);

                    }while (novaModificacao=='s');

                    break;
                }
                break;
            }
        }
    }while(funcao!=4);

return 0;

}