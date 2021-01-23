#ifndef _PROTOTIPOS_

#define _PROTOTIPOS_

#include "estructuras.h"

int pertenece(char a);
int find_(int subconjuntos[],int clave);
int ciclo(int subconjuntos[],Arista *t);
void agregarV();
void buscar(Arista **ar,char a,char b);
void agregarA(char a,char b,int peso);
void mostrar(Vertice *vertices);
void mostrarA(Arista *ar,const int b);
void destruirNodo(Arista *a);
void eliminarN(Arista *minimo);
void unir(int subconjuntos[],int ca,int cb);
void mostrarpila();
void kruskal();
void ordenar();
Vertice *crearNodoV();
Arista *crearNodoA(int peso);
Arista *desencolar();
Arista *copia(Arista *minimo);
Arista *minimo();

#endif // _PROTOTIPOS_
