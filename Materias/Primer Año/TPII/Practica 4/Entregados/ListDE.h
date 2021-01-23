/* ListDE.h */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
    struct nodo *prev;
}Node;

typedef struct list{
    Node *head;
}List;

Node *crearNodo(int);

void borrarNodo(Node *);

List *crearList();

void insertar(int, List *);

void eliminar(int, List *);

int tamanio(List *);

void vaciarLista(List *);

void listar(List *);
