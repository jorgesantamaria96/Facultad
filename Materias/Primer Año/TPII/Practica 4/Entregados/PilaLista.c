#include "PilaLista.h"

Nodo *crearNodo(int num){
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->dato = num;
    nodo->next = NULL;
    return nodo;
}

void borrarNodo(Nodo *nodo){
    free(nodo);
}

Pila *crearPila(){
    Pila *pila = (Pila *) malloc(sizeof(Pila));
    pila->arriba = NULL;
    return pila;
}

void apila(Pila *pila, int e){
    
    Nodo *new = crearNodo(e);
    
    if (pila->arriba == NULL){
        pila->arriba = new;
    }
    else{
        new->next = pila->arriba;
        pila->arriba = new;
    }
}

void desapila(Pila *pila){
    
    Pila *aux;
    if (estaVacia(pila) == 1){
        aux->arriba = pila->arriba;
        pila->arriba = pila->arriba->next;
        borrarNodo(aux->arriba);
    }
}

int tamanio(Pila *pila){
    
    int tam = 0;
    Pila *aux;
    aux->arriba = pila->arriba;
    while (aux->arriba != NULL){
        tam++;
        aux->arriba = aux->arriba->next;
    }
    return tam;
}

void vaciaPila(Pila *pila){
    
    Nodo *aux, *aux2;
    aux = pila->arriba;
    
    if (aux == NULL)
        printf("La pila esta vacia.\n");
    else{
        while (aux != NULL){
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }
        pila->arriba = NULL;
        printf("La pila se vacio exitosamente.\n");
    }
}

int estaVacia(Pila *pila){
    if (pila->arriba == NULL)
        return 0;
    return 1;
}

Nodo *cimaPila(Pila *pila){
    
    return pila->arriba;
}

void mostrar_pila(Pila *pila){
    
    Nodo *aux;
    aux = pila->arriba;
    
    printf("##### PILA #####\n");
    while (aux != NULL){
        printf("\t%d\t\n", aux->dato);
        aux = aux->next;
    }
    printf("################\n");
}

int main(){

    Pila *pila;
    pila = crearPila();
    
    Nodo *cima;
    int valor, opcion;
    do{
        printf("MENU\n\n");

        printf("[1] Digite el elemento a ingresar.\n");
        printf("[2] Desapilamos un elemento.\n");
        printf("[3] Tamaño de la pila.\n");
        printf("[4] Verificamos si esta vacia.\n");
        printf("[5] Cima de la pila.\n");
        printf("[6] Mostrar pila.\n");
        printf("[7] Vacia la pila.\n");
        printf("[8] Salir.\n");
        printf("Opcion a elegir: ");
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                printf("Ingrese un valor: ");
                scanf("%d", &valor);
                apila(pila, valor);
                printf("Se apilo el elemento correctamente.\n");
                break;
            case 2:
                desapila(pila);
                printf("Se desapilo el elemento correctamente.\n");
                break;
            case 3:
                printf("El tamanio de la pila es: %d.\n", tamanio(pila));
                break;
            case 4:
                if (estaVacia(pila) == 0)
                    printf("La pila esta vacia.\n");
                else
                    printf("La pila posee elementos.\n");
                break;
            case 5:
                cima = cimaPila(pila);
                printf("La cima de la pila es: %d.\n", cima->dato);
                break;
            case 6:
                mostrar_pila(pila);
                break;
            case 7:
                vaciaPila(pila);
                printf("Se vacio la pila.\n");
                break;  
            case 8:
                printf("Terminamos.\n");
                break;
        }
    }while(opcion != 8);

    return 0;
}
