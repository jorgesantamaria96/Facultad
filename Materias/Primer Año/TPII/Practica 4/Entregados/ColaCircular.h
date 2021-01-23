/* ColaCircular.h */
#include <stdio.h>
#include <stdlib.h>

#define CAP 7

typedef struct queue{
    int inicio;
    int fin;
    int vector[CAP];
}Queue;

Queue *crearCola();

int sumaUno(int);

int estaVacia(Queue *);

void frente(Queue *);

int cantElementos(Queue *);

int estallena(Queue *);

void push(Queue *, int);

void pop(Queue *);

void mostrar_cola(Queue *);
