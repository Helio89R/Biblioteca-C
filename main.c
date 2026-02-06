#include <stdio.h>
#include <stdlib.h>
#include "heder.h"

int main()
{
    Livro *biblioteca = NULL;
    Fila pedidos;

    criarfila(&pedidos);

    int menu;

    do{
        printf(".....MENU.....\n");
        printf("1. Adicionar livro\n");
        printf("2. Mostrar livro\n");
        printf("3. Adicionar pedido\n");
        printf("4. Procesar pedido\n");
        printf("5. Devolver pedidos\n");
        printf("6. Mostrar pedidos\n");
        printf("7. Sair\n");
        printf("opcao:");
        scanf("%d",&menu);
        getchar();

        switch(menu){
            case 1: inserirlivro(&biblioteca);break;
            case 2: mostrar_livor(biblioteca);break;
            case 3: adicionarpedido(&pedidos);break;
            case 4: procesarPedidos(&pedidos,biblioteca);break;
            case 5: Devolverlivor(biblioteca); break;
            case 6: mostrar_fila(&pedidos);break;
            case 7: printf("Programa terminado. "); break;
            default: printf("Opcao invalida");
        }

    }while(menu != 7);


    return 0;
}
