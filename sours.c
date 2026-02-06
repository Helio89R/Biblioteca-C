#include <stdio.h>
#include <stdlib.h>
#include "heder.h"

void criarfila(Fila *fila){
     fila ->inicio = NULL;
     fila->fim = NULL;
}
int inserirlivro(Livro **livro){

     Livro *novo = malloc(sizeof(Livro));
     if(novo == NULL){
        return 0;
     }

     printf("Digite id do livro");
     scanf("%d",&novo->ID);
     getchar();

     printf("Digite o Autor do livor");
     fgets(novo->Autor,50,stdin);
     novo->Autor[strcspn(novo->Autor,"\n")] = '\0';

     printf("Digite o titulo do livro");
     fgets(novo->titulo,50,stdin);
     novo->titulo[strcspn(novo->titulo,"\n")] = '\0';
     getchar();

     novo->imprestado = 0;
     novo->next = *livro;
     *livro = novo;

     return 1;
}
void mostrar_livor(Livro *lista){

      if(lista == NULL){
        return;
      }
     // Livro *aux = lista;

      while(lista !=NULL){
            printf("ID: %d | %s - %s | Estado: %s\n",
               lista->ID,
               lista->Autor,
               lista->titulo,
               (lista->imprestado == 1) ? "Emprestado" : "Disponivel");

        lista = lista->next;

      }
}
Livro* percurar_livropid(Livro *lista, int id){

    Livro *aux = lista;
    while(aux != NULL){
        if(aux->ID == id){
            return aux;

        }aux = aux->next;
    }return NULL;
}
void Devolverlivor(Livro *lista){

    int id;

    printf("id do livro que eu quero intregrar ");
    scanf("%d", &id);
    Livro *aux = percurar_livropid(lista,id);
    if(aux != NULL && aux->imprestado == 1){
            aux->imprestado = 0;
            printf("O livro foi entrega");
    }else{
        printf("livro nao encontrado");
    }
}

// funcoe de fila de pedido

void adicionarpedido(Fila *fila){


    Pedido *novo = malloc(sizeof(Pedido));
    if(novo == NULL){
        return;
    }
    novo->prox = NULL;
    printf("Digite id do livro");
    scanf("%d",&novo->idlivor);
    getchar();

    printf("Nome do utilizador ");
    fgets(novo->utilizador,50,stdin);
    novo->utilizador[strcspn(novo->utilizador,"\n")] = '\0';

    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;

    }else{
        fila->fim->prox = novo;
        fila->fim = novo;

    }
}
void mostrar_fila(Fila *fila){

     if(fila == NULL){
        return;
     }
     Pedido *aux = fila->inicio;

     while(aux != NULL){
        printf("ID do utilizador");
        printf("%d",aux->idlivor);
        printf("\n");
        printf("Nome do cliente");
        printf("%s",aux->utilizador);
        printf("\n");
        aux = aux->prox;

     }


}
void procesarPedidos(Fila *fila, Livro *lista){

    if(fila->inicio == NULL){
        printf("fila esta vazia");
        return ;
    }
    Pedido *p = fila->inicio;
    Livro *livro = percurar_livropid(lista,p->idlivor);

    // caso o livor nao existe
    if(livro == NULL){
        fila->inicio = p->prox;
        if(fila->inicio == NULL){
            fila->fim = NULL;
            printf("nao tem livor dispunivel neste momento");
            return;
        }
    }
    // livor  existe e esta dispunuvel
    else if(livro->imprestado == 0){
        livro->imprestado = 1;
        printf("Livro emprestado");

        fila->inicio = p->prox;
        if(fila->inicio== NULL){
            fila->fim = NULL;
        }
    }else{
        printf("Livro ainda imprestado");
    }

}









