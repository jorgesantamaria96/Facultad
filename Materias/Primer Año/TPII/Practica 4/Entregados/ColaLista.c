#include <stdio.h>
#include <stdlib.h>
#include "ColaLista.h"

Nodo *crearNodo(int num){
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->dato = num;
    nodo->next = NULL;
    return nodo;
}

void borrarNodo(Nodo *nodo){
    free(nodo);
}

Cola *crearCola(){
    Cola *cola = (Cola *) malloc(sizeof(Cola));
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

void encolar(Cola *cola, int num){
    Nodo *new;
    new = crearNodo(num);
    
    if (cola->primero == NULL){
        cola->primero = new;
        cola->ultimo = new;
    }
    else{
        cola->ultimo->next = new;
        cola->ultimo = new;
    }
}

void desencolar(Cola *cola){
    if (cola->primero != NULL){
        Nodo *delete;
        delete = cola->primero;
        cola->primero = cola->primero->next;
        borrarNodo(delete);
        if (cola->primero == NULL)
            cola->ultimo = NULL;
    }
    else{
        printf("La cola esta vacia.\n");
    }
}

int frente(Cola *cola){
    Cola *aux;
    aux->primero = cola->primero;
    aux->ultimo = cola->ultimo;
    
    if (aux->primero != NULL){
        return aux->primero->dato;
    }
    else{
        printf("La cola esta vacia.\n");
        return -1;
    }
}

void vaciaCola(Cola *cola){
    while (cola->primero != NULL){
        desencolar(cola);
    }
    cola->primero = NULL;
    cola->ultimo = NULL;
}

int tamanio(Cola *cola){
    int tam = 0;
    if (cola->primero == NULL){
        return tam;
    }
    else{
        Cola *aux;
        aux->primero = cola->primero;
        aux->ultimo = cola->ultimo;
        
        while (aux->primero != aux->ultimo){
            tam++;
            aux->primero = aux->primero->next;
        }
        return tam+1;
    }
}

int estaVacia(Cola *cola){
    if (cola->primero != NULL)
        return 0;
    else
        return 1;
}

void mostrarCola(Cola *cola){

    Cola *aux;
    aux->primero = cola->primero;
    aux->ultimo = cola->ultimo;
    
    printf("\n");
    printf("##### COLA #####\n");
    if (aux->primero == NULL){
        printf("      ----\n");
    }
    else{
        while (aux->primero != NULL){
            printf("\t%d\t\n", aux->primero->dato);
            aux->primero = aux->primero->next;
        }
    }
    printf("################\n");
    printf("\n");
}

int main(){
    
    Cola *cola = crearCola();
    int opcion, valor, res;
    
    do{
        printf("MENU\n\n");
        
        printf("[1] Insertar un elemento en la cola.\n");
        printf("[2] Mostrar el primer elemento de la cola.\n");
        printf("[3] Tamaño de la cola.\n");
        printf("[4] Eliminar el primer elemento de la cola.\n");
        printf("[5] Comprobar si la cola esta vacia.\n");
        printf("[6] Vaciar la cola.\n");
        printf("[7] Mostrar cola.\n");
        printf("[8] Salir.\n");
        printf("Opcion a elegir: ");
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                printf("Ingrese el numero: ");
                scanf("%d", &valor);
                encolar(cola, valor);
                printf("Se inserto el elemento en la pila.\n");
                break;
            case 2:
                printf("El primer elemento es: %d.\n", frente(cola));
                break;
            case 3:
                printf("El tamaño de la cola es: %d.\n", tamanio(cola));
                break;
            case 4:
                desencolar(cola);
                printf("Se elimino el primer elemento de la cola.\n");
                break;
            case 5:
                res = estaVacia(cola);
                if (res)
                    printf("La cola no esta vacia.\n");
                else
                    printf("La cola esta vacia.\n");
                break;
            case 6:
                vaciaCola(cola);
                printf("Se vacio la cola.\n");
                break;
            case 7:
                mostrarCola(cola);
                break;
            case 8:
                printf("Terminado.\n");
                break;
        }
    }while(opcion != 8);
    
    return 0;
}
