#ifndef HEDER_H_INCLUDED
#define HEDER_H_INCLUDED

typedef struct livro{
    int ID;
    char titulo [50];
    char Autor [50];
    int imprestado;
    struct livro *next;
}Livro;

typedef struct pedido{
    int idlivor;
    char utilizador [50];
    struct pedido *prox;
}Pedido;

typedef struct{
    Pedido *inicio;
    Pedido *fim;
}Fila;

void criarfila(Fila *fila);
int inserirlivro(Livro **livro);
void mostrar_livor(Livro *lista);
Livro* percurar_livropid(Livro *lista, int id);
void Devolverlivor(Livro *lista);
void adicionarpedido(Fila *fila);
void mostrar_fila(Fila *fila);
void procesarPedidos(Fila *fila, Livro *lista);




#endif // HEDER_H_INCLUDED
