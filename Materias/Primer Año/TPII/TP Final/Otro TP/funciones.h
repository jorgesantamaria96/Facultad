#include "prototipos.h"

int cantVertices = 0;
int cantAristas = 0;
int aristasArbol = 0;

Vertice *vertices = NULL;
Arista *aristas = NULL;
Arista *arbol = NULL;
Arista *artmp = NULL;
Arista *ord = NULL;


Vertice *crearNodoV(){ //se usa
    static int letra = 97;
    if(letra <= 122){
        Vertice *nuevo = (Vertice*)malloc(sizeof(Vertice));
        nuevo->id = letra;
        nuevo->usado = 0;
        nuevo->sig = NULL;
        nuevo->clave = cantVertices;
        nuevo->adyacentes = NULL;
        letra++;
        return nuevo;
    }else{
        return NULL;
    }
}

Arista *crearNodoA(int peso){ //se usa
    Arista *nuevo = (Arista*)malloc(sizeof(Arista));
    nuevo->peso = peso;
    nuevo->sig = NULL;
    nuevo->a = NULL;
    nuevo->b = NULL;
    nuevo->clave = cantAristas;
    return nuevo;
}

void agregarV(){ //se usa
    if(vertices == NULL){
        vertices = crearNodoV();
        cantVertices++;
    }else{
        Vertice *nuevo = crearNodoV();
        if(nuevo == NULL){
            printf("Se alcanzo la cantidad de vertices.\n");
        }else{
            Vertice *tmp = vertices;
            while(tmp->sig != NULL){
                tmp = tmp->sig;
            }
            tmp->sig = nuevo;
            cantVertices++;
        }
    }
}

void buscar(Arista **ar,char a,char b){ //se usa
    Vertice *tmp = vertices;
    while(tmp != NULL){
        if(tmp->id == a){
            (*ar)->a = tmp;
        }
        tmp = tmp->sig;
    }
    tmp = vertices;
    while(tmp != NULL){
        if(tmp->id == b){
            (*ar)->b = tmp;
        }
        tmp = tmp->sig;
    }
}

void agregarA(char a,char b,int peso){ //se usa
        if(aristas == NULL){
            aristas = crearNodoA(peso);
            buscar(&aristas,a,b);
            cantAristas++;
        }else if(peso < aristas->peso){               /// inserta al principio
            Arista *nuevo = crearNodoA(peso);
            nuevo->sig = aristas;
            aristas = nuevo;
            buscar(&aristas,a,b);
            cantAristas++;
        }else{                                  /// inserta en medio
            Arista *tmp = aristas;
            while(tmp->sig != NULL && (peso > tmp->sig->peso)){
                tmp = tmp->sig;
            }
            Arista *nuevo = crearNodoA(peso);
            if(tmp->sig != NULL){
                nuevo->sig = tmp->sig;
                tmp->sig = nuevo;
                buscar(&nuevo,a,b);
            }else{
                tmp->sig = nuevo;
                buscar(&nuevo,a,b);
            }
                cantAristas++;
        }
}

void mostrar(Vertice *vertices){ //se usa
    if(vertices != NULL){
        Vertice *tmp = vertices;
        printf("Lista de vertices:\n");
        while(tmp != NULL){
            printf("[%c] ",tmp->id);
            tmp = tmp->sig;
        }
        printf("\n\n");
    }else{
        printf("No hay vertices.\n\n");
    }
}

void mostrarA(Arista *ar,const int b){ //se usa
    if(ar != NULL){
        Arista *tmp = ar;
        if(b == 0){
            printf("\nLista de aristas:\n");
        }else{
            printf("\nArbol resultante:\n");
        }
        while(tmp != NULL){
            printf("([%d] [%c][%c]) \n",tmp->peso,tmp->a->id,tmp->b->id);
            tmp = tmp->sig;
        }
        printf("\n\n");
    }else{
        printf("No hay aristas.\n\n");
    }
}

int pertenece(char a){ //se usa
    Vertice *tmp = vertices;
    while(tmp != NULL){
        if(tmp->id == a){
            return TRUE;
        }
        tmp = tmp->sig;
    }
    return FALSE;
}

void destruirNodo(Arista *a){ //se usa
    free(a);
}

void eliminarN(Arista *minimo){ //se usa
    int clave = minimo->clave;
    if(aristas != NULL){
        if(aristas->clave == clave){
            Arista *eliminar = aristas;
            aristas = aristas->sig;
            destruirNodo(eliminar);
        }else{
            Arista *tmp = NULL,*eliminar = NULL;
            tmp = aristas;
            while((tmp->sig != NULL) && (tmp->sig->clave != clave)){
                tmp = tmp->sig;
            }
            eliminar = tmp->sig;
            tmp->sig = eliminar->sig;
            destruirNodo(eliminar);
        }
    }
}

Arista *copia(Arista *minimo){ //se usa
    Arista *nuevo = (Arista*)malloc(sizeof(Arista));
    nuevo->a = minimo->a;
    nuevo->b = minimo->b;
    nuevo->clave = minimo->clave;
    nuevo->peso = minimo->peso;
    nuevo->sig = NULL;
    return nuevo;
}

Arista *minimo(){ //se usa
    Arista *minim = NULL,*tmp = NULL;
    tmp = aristas;
    minim = aristas;
    while(tmp != NULL){
            if(tmp->peso < minim->peso){
                minim = tmp;
            }else if(tmp->peso == minim->peso){
                if(tmp->a->clave < minim->a->clave){
                    minim = tmp;
                }else if(tmp->a->clave == minim->a->clave){
                    if(tmp->b->clave < minim->b->clave){
                        minim = tmp;
                    }
                }
            }
        tmp = tmp->sig;
    }
    return minim;
}

void ordenar(){ //se usa
    int n = 0;
    Arista *t = NULL;
    while(n != cantAristas){
        t = minimo();
        if(ord == NULL){
            ord = copia(t);
            eliminarN(t);
        }else{
            Arista *tmp;
            tmp = ord;
            while(tmp->sig != NULL){
                tmp = tmp->sig;
            }
            tmp->sig = copia(t);
            eliminarN(t);
        }
        n++;
    }
    mostrarA(ord,0);
}

Arista *desencolar(){ //se usa
    if(ord == NULL){
        return NULL;
    }else{
        Arista *e = ord;
        ord = ord->sig;
        cantAristas--;
        return e;
    }
}


int find_(int subconjuntos[],int clave){ //se usa
    if(subconjuntos[clave] == -1){
        return clave;
    }else{
        return find_(subconjuntos,subconjuntos[clave]);
    }
}

void unir(int subconjuntos[],int ca,int cb){ //se usa

    int x = find_(subconjuntos,ca);
    int y = find_(subconjuntos,cb);

    if(x != y){
        subconjuntos[x] = y;
    }
}

int ciclo(int subconjuntos[],Arista *t){ //se usa
    int x,y;
        ////

        x = find_(subconjuntos,t->a->clave);
        y = find_(subconjuntos,t->b->clave);

        if(x == y){
            return 1;
        }

        unir(subconjuntos,x,y);

    ////
    return 0;
}

void mostrarpila(){ //se usa
    Arista *tmp = ord;
    printf("\n\nDump_Stack\n\n");
    while(tmp != NULL){
        printf("[%p]\n",tmp);
        tmp = tmp->sig;
    }
}

void kruskal(){
    int *subconjuntos,n=0;

    ordenar();

    subconjuntos = (int*)malloc(sizeof(int)*cantVertices);

    for(int i = 0;i < cantVertices;i++){
        *(subconjuntos+i) = -1;
    }

    Arista *t = NULL;

    mostrarpila();

    while(aristasArbol != (cantVertices-1)){
        t = desencolar();

        if(t != NULL){
            t->sig = NULL;

            n = ciclo(subconjuntos,t);

            if(n == 0){
                if(arbol == NULL){
                    arbol = t;
                    aristasArbol++;
                }else{
                    Arista *tmp = arbol;
                    while(tmp->sig != NULL){
                        tmp = tmp->sig;
                    }
                    tmp->sig = t;
                    aristasArbol++;
                }
            }
        }
    }

}

