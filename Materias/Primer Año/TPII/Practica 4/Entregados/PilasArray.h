/* Pila Array.h */

#define CAPACIDAD 15

int elementos[CAPACIDAD];
int cima = -1;

void apila(int);

int desapila();

void vaciaPila();

int tamanio();

int estaVacia();

int cimaPila();

void mostrar_pila();
