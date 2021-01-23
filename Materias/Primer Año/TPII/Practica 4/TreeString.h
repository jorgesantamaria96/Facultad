#include <stdio.h>
#include <stdlib.h>

#define CAP 25

typedef struct nodo{
    char dato;
    struct nodo *izq;
    struct nodo *der;
}Nodo;

void insertar(Nodo **, char);

void eliminar(Nodo **, char);

int suprime_min(Nodo **);

int es_miembro(Nodo *, char);

void preOrder(Nodo *);

void inOrder(Nodo *);

void posOrder(Nodo *);

void mostrar_arbol(Nodo **);
