#include <stdio.h>

//Define capacidade do estoque
#define MAX 100

int main(void) {

    //Tela inicial

    int funcao;
    int entradaValida;

    do {                                                    //Cria o loop caso receba a entrada invalida
        printf("1-Cadastrar um novo produto\n");
        printf("2-Consultar produtos em estoque\n");
        printf("3-Alterar produtos em estoque\n");
        entradaValida = scanf("%d", &funcao);
        if (entradaValida!=1 || funcao!=1 && funcao!=2 && funcao!=3) {    //Verifica se a entrada é valida
            while (getchar() != '\n');      //Limpa o buffer
        }
    }while (entradaValida!=1 || funcao!=1 && funcao!=2 && funcao!=3);

    switch (funcao) {

        case 1: {
            //Cadastrar um novo produto

            int quantidade[MAX];
            char produto[MAX][100];
            float preco[MAX];
            int codigo[MAX];
            char opcao='s';

            for (int i=0; opcao!='n' && i<MAX; i++){

                //Inserir nome do produto

                do {
                    printf("Produto:\n");
                    entradaValida = scanf("%99s", produto[i]); //Limita a entrada de uma string menor que 100 caracteres
                    if (entradaValida!=1) {
                        while (getchar() != '\n');
                    }
                }while (entradaValida!=1);

                //Inserir codigo do produto

                do {                                            //Cria um loop ate o usuario digitar uma entrada valida
                    printf("Codigo:\n");
                    entradaValida = scanf("%d", &codigo[i]);
                    if (entradaValida!=1 || codigo[i]<0) {      //Verifica se o usuario digitou uma entreda valida
                        while (getchar() != '\n');              //Limpa o buffer
                    }
                }while (entradaValida!=1 || codigo[i]<0);

                //Inserir quantidade

                do {
                    printf("Quantidade a ser armazenada:\n");   //Mesmos comentarios da entrada de codigo se aplicam
                    entradaValida = scanf("%d", &quantidade[i]);
                    if (entradaValida!=1 || quantidade[i]<1) {
                        while (getchar() != '\n');
                    }
                }while (entradaValida!=1 || quantidade[i]<1);

                //Inserir preco

                do {
                    printf("Preco do produto:\n");              //Mesmos comentarios da entrada de codigo se aplicam
                    entradaValida = scanf("%f", &preco[i]);
                    if (entradaValida!=1 || preco[i]<0.5) {
                        while (getchar() != '\n');
                    }
                }while (entradaValida!=1 || preco[i]<0.5);

                //Mostra todos os dados do produto
                printf("\t%s\n", produto[i]);
                printf("\tCodigo: %d\n", codigo[i]);
                printf("\tPreco: %.2f\n", preco[i]);
                printf("\tQuantidade: %d\n\n", quantidade[i]);

                do {
                    printf("Deseja adicionar mais algum?  (s/n)");
                    scanf(" %c", &opcao);
                    if (opcao!='s' && opcao!='n') {
                        while (getchar() != '\n');
                    }
                }while (opcao!='s' && opcao!='n');
            }
            break;
        }

    }
    return 0;
}