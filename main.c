#include <stdio.h>

//Define capacidade do estoque
#define MAX 100

int main(void) {

    //Tela inicial
    int funcao;

    printf("1-Cadastrar um novo produto\n");
    printf("2-Consultar produtos em estoque\n");
    printf("3-Alterar produtos em estoque\n");
    scanf("%d", &funcao);

    switch (funcao) {
        case 1:  //Cadastrar um novo produto

            int quantidade[MAX];
            char produto[MAX][100];
            float preco[MAX];
            int codigo[MAX];
            char opcao='s';

            for (int i=0; opcao!='n' && i<=MAX; i++){
                //Inserir nome do produto
                printf("Produto:\n");
                scanf("%s", produto[i]);

                //Inserir codigo do produto
                printf("Codigo:\n");
                scanf("%d", &codigo[i]);

                //Inserir quantidade
                printf("Quantidade a ser armazenada:\n");
                scanf("%d", &quantidade[i]);

                //Inserir preco
                printf("Preco do produto:\n");
                scanf("%f", &preco[i]);

                //Mostra todos os dados do produto
                printf("\t%s\n", produto[i]);
                printf("\tCodigo: %d\n", codigo[i]);
                printf("\tPreco: %.2f\n", preco[i]);
                printf("\tQuantidade: %d\n\n", quantidade[i]);

                printf("Deseja adicionar mais algum?");
                scanf(" %c", &opcao);
            }
        break;

    }
    return 0;
}
