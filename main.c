#include <stdio.h>
#include <string.h>

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

    do{

        do {                                                    //Cria o loop caso receba a entrada invalida
            printf("1-Cadastrar um novo produto\n");
            printf("2-Consultar produtos em estoque\n");
            printf("3-Editar produtos em estoque\n");
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
                int n=0;

                for (int i=0; opcao!='n' && i<MAX; i++){

                    //Inserir nome do produto

                    for (n ;codigo[n]!=0; n++);

                    do {
                        printf("Produto:\n");
                        entradaValida = scanf(" %99[^\n]", produto[n]); //Limita a entrada de uma string menor que 100 caracteres
                        if (entradaValida!=1) {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                        }
                    }while (entradaValida!=1);

                    //Inserir codigo do produto

                    codigo[n]=n+1;

                    //Inserir quantidade

                    do {                                            //Cria um loop ate o usuario digitar uma entrada valida
                        printf("Quantidade a ser armazenada:\n");
                        entradaValida = scanf("%d", &quantidade[n]);
                        if (entradaValida!=1 || quantidade[n]<1) {        //Verifica se o usuario digitou uma entrada valida
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');                              //Limpa o buffer
                        }
                    }while (entradaValida!=1 || quantidade[n]<1);

                    //Inserir preco

                    do {
                        printf("Preco do produto:\n");              //Mesmos comentarios da entrada de codigo se aplicam
                        entradaValida = scanf("%f", &preco[n]);
                        if (entradaValida!=1 || preco[n]<0.5) {
                            printf("Entrada Invalida!\n");
                            while (getchar() != '\n');
                        }
                    }while (entradaValida!=1 || preco[n]<0.5);

                    //Mostra todos os dados do produto
                    printf("\tCodigo: %03d\n", codigo[n]);
                    printf("\t%s\n", produto[n]);
                    printf("\tQuantidade: %d\n", quantidade[n]);
                    printf("\tPreco: R$%.2f\n", preco[n]);

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

                    if (codigo[i]<1) continue;     //Imprime somente a parte da lista que contem valores

                    printf("%03d - ", codigo[i]);
                    printf("%s | ", produto[i]);
                    printf("Quantidade: %d | ", quantidade[i]);
                    printf("Preco: R$%.2f\n", preco[i]);
                }
                break;
            }

            case 3: {

                int opcao;
                int produtoEditar;

                printf("Qual o codigo do produto?\n");
                scanf("%d", &produtoEditar);

                printf("%03d - ", codigo[produtoEditar-1]);
                printf("%s | ", produto[produtoEditar-1]);
                printf("Quantidade: %d | ", quantidade[produtoEditar-1]);
                printf("Preco: R$%.2f\n", preco[produtoEditar-1]);

                printf("1-Apagar item\n");
                printf("2-Editar item\n");
                scanf("%d", &opcao);

                //Apagar item do estoque

                if (opcao==1) {
                    strcpy(produto[produtoEditar-1], "");
                    codigo[produtoEditar-1]=0;
                    quantidade[produtoEditar-1]=0;
                    preco[produtoEditar-1]=0;

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

                        scanf("%d", &itemModificar);

                        if (itemModificar==1) {
                            printf("Digite o produto:\n");
                            strcpy("%s", produto[produtoEditar-1]);
                        }

                        if (itemModificar==2) {
                            printf("Digite a quantidade:\n");
                            scanf("%d", &quantidade[produtoEditar-1]);
                        }

                        if (itemModificar==3) {
                            printf("Digite o preco:\n");
                            scanf("%f", &preco[produtoEditar-1]);
                        }

                        printf("Item modificado!\n");

                        printf("Deseja modificar mais algum item deste produto?\n");
                        scanf("%s", novaModificacao);

                    }while (novaModificacao=='s');      //Revisar loop

                    break;

                }

                break;
            }
        }
    }while(1);      //Faz programa rodar infinitamente

return 0;
}