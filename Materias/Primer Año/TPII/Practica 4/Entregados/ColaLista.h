/* ColaLista.h */

typedef struct nodo{
    int dato;
    struct nodo *next;
}Nodo;

typedef struct cola{
    Nodo *primero;
    Nodo *ultimo;
}Cola;

Nodo *crearNodo(int);

void borrarNodo(Nodo *);

Cola *crearCola();

void encolar(Cola *, int);

void desencolar(Cola *);

int frente(Cola *);

void vaciaCola(Cola *);

int tamanio(Cola *);

int estaVacia(Cola *);
