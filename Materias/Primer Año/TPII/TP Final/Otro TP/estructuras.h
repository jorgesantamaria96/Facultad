#ifndef _estructuras_

#define _estructuras_

#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _vertice{
    char id;
    int usado;
    int clave;
    struct _vertice *sig;
    struct _vertice *adyacentes;
}Vertice;

typedef struct _arista{
    int peso;
    int clave;
    Vertice *a;
    Vertice *b;
    struct _arista *sig;
}Arista;

#endif // _estructuras_
