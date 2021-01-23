/* PilaLista.h */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
}Nodo;

typedef struct pila{
    Nodo *arriba;
}Pila;

Nodo *crearNodo(int);

void borrarNodo(Nodo *);

Pila *crearPila();

void apila(Pila *, int);

void desapila(Pila *);

void vaciaPila(Pila *);

int tamanio(Pila *);

int estaVacia(Pila *);

Nodo *cimaPila(Pila *);

void mostrar_pila(Pila *);
