#include <stdio.h>

//Define capacidade do estoque
#define MAX 100

int main(void) {

    //Tela inicial

    int quantidade[MAX]={0};
    char produto[MAX][100]={};
    float preco[MAX]={0};
    int codigo[MAX]={0};
    int funcao;
    int entradaValida;
    int novoProduto=0;

    do{

        do {                                                    //Cria o loop caso receba a entrada invalida
            printf("1-Cadastrar um novo produto\n");
            printf("2-Consultar produtos em estoque\n");
            printf("3-Alterar produtos em estoque\n");
            entradaValida = scanf("%d", &funcao);
            if (entradaValida!=1 || funcao!=1 && funcao!=2 && funcao!=3) {    //Verifica se a entrada é valida
                printf("Entrada Invalida!\n");
                while (getchar() != '\n');      //Limpa o buffer
            }
        }while (entradaValida!=1 || funcao!=1 && funcao!=2 && funcao!=3);

        switch (funcao) {

            case 1: {
                //Cadastrar um novo produto

                char opcao='s';

                for (int i=0; opcao!='n' && i<MAX; i++){

                    //Inserir nome do produto

                    do {
                        printf("Produto:\n");
                        entradaValida = scanf(" %99[^\n]", produto[novoProduto]); //Limita a entrada de uma string menor que 100 caracteres
                        if (entradaValida!=1) {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                        }
                    }while (entradaValida!=1);

                    //Inserir codigo do produto

                    codigo[novoProduto]=novoProduto+1;

                    //Inserir quantidade

                    do {                                            //Cria um loop ate o usuario digitar uma entrada valida
                        printf("Quantidade a ser armazenada:\n");
                        entradaValida = scanf("%d", &quantidade[novoProduto]);
                        if (entradaValida!=1 || quantidade[novoProduto]<1) {        //Verifica se o usuario digitou uma entrada valida
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');                              //Limpa o buffer
                        }
                    }while (entradaValida!=1 || quantidade[novoProduto]<1);

                    //Inserir preco

                    do {
                        printf("Preco do produto:\n");              //Mesmos comentarios da entrada de codigo se aplicam
                        entradaValida = scanf("%f", &preco[novoProduto]);
                        if (entradaValida!=1 || preco[novoProduto]<0.5) {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                        }
                    }while (entradaValida!=1 || preco[novoProduto]<0.5);

                    //Mostra todos os dados do produto
                    printf("\tCodigo: %03d\n", codigo[novoProduto]);
                    printf("\t%s\n", produto[novoProduto]);
                    printf("\tQuantidade: %d\n", quantidade[novoProduto]);
                    printf("\tPreco: R$%.2f\n", preco[novoProduto]);

                    novoProduto++;

                    do {
                        printf("Deseja adicionar mais algum?  (s/n)");
                        scanf(" %c", &opcao);
                        if (opcao!='s' && opcao!='n') {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                        }
                    }while (opcao!='s' && opcao!='n');
                }
                break;
            }

            case 2: {
                //Consultar produtos em estoque

                for (int i=0; i<MAX; i++){      //Imprime a lista completa

                    if (codigo[i]<1) break;     //Imprime somente a parte da lista que contem valores

                    printf("%03d - ", codigo[i]);
                    printf("%s | ", produto[i]);
                    printf("Quantidade: %d | ", quantidade[i]);
                    printf("Preco: R$%.2f\n", preco[i]);
                }

            }

        }
    }while(1);      //Faz programa rodar infinitamente

return 0;
}