#include "ListDE.h"

Node *crearNodo(int num){
// crea un nodo nuevo
    Node *new = (Node *) malloc(sizeof(Node));
    new->dato = num;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void borrarNodo(Node *nodo){
// libera un nodo
    nodo->next = NULL;
    nodo->prev = NULL;
    free(nodo);
}

List *crearList(){
    List *new= (List *) malloc(sizeof(List));
    new->head = NULL;
    return new;
}

void insertar(int num, List *list){
// inserta un elemento en una lista en la posicion correcta
    Node *new = crearNodo(num);
    
    if (list->head == NULL){
        list->head = new;
    }
    else{
        Node *aux;
        aux = list->head;
        // si va adelante
        if ((list->head != NULL) && (num < list->head->dato)){
            list->head->prev = new;
            new->next = list->head;
            list->head = new;
        }
        else{
            // buscamos donde lo podemos ingresar
            while ((aux->next != NULL) && (num > aux->next->dato)){
                aux = aux->next;
            }
            if (num == aux->dato){
                printf("El elemento esta en la lista.\n");
            }
            else if ((aux->next != NULL) && (aux->next->dato == num)){
                printf("El elemento esta en la lista.\n");
            }
            else{
                new->next = aux->next;
                aux->next = new;
                new->prev = aux;
                aux->next->prev = new;
            }
        }
    }
}
    
void eliminar(int num, List *list){
// eliminar un elemento de la lista
    if (list->head == NULL){
        printf("La lista esta vacia.\n");
    }
    else{
        if (list->head->dato == num){
            if (list->head->next != NULL){
                Node *delete;
                delete = list->head;
                list->head = list->head->next;
                list->head->prev = NULL;
                borrarNodo(delete);
            }
            else{
                Node *delete;
                delete = list->head;
                list->head = list->head->next;
                borrarNodo(delete);
            }
        }
        else{
            Node *aux;
            aux = list->head;
            while ((aux->next != NULL) && (num != aux->next->dato)){
                aux = aux->next;
            }
            if ((aux->next == NULL) && (aux->dato != num)){
                printf("El elemento no esta en la lista.\n");
            }
            else{
                Node *delete;
                delete = aux->next;
                aux->next = delete->next;
                if (aux->next != NULL){
                    delete->next->prev = aux;
                }
                borrarNodo(delete);
            }
        }
    }
}

int tamanio(List *list){
// devuelve el tamaño de la lista
    int cantidad = 0;
    Node *aux;
    aux = list->head;
    while (aux != NULL){
        cantidad++;
        aux = aux->next;
    }
    return cantidad;
}

void vaciarLista(List *list){
// elimina todos los elementos de una lista
    Node *aux;
    while (list->head != NULL){
        aux = list->head;
        list->head = list->head->next;
        borrarNodo(aux);
    }
    printf("Se vacio exitosamente.\n");
}

void listar(List *list){
// imprime lalista en pantalla
    Node *aux;
    aux = list->head;
    printf("\nNULL ");
    while (aux != NULL){
        printf("<-|%d|-> ", aux->dato);
        aux = aux->next;
    }
    printf("NULL\n");
}

int main(){
    
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    
    int valor, opcion;
    do{
        printf("\nMENU:\n\n");
        printf("[1] Insertar un elemento.\n");
        printf("[2] Eliminar un elemento.\n");
        printf("[3] Mostrar la lista.\n");
        printf("[4] Vaciar la lista.\n");
        printf("[5] Tamaño de la lista.\n");
        printf("[5] Salir.\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d", &valor);
                insertar(valor, list);
                break;
            case 2:
                printf("Digite el elemento a eliminar: ");
                scanf("%d", &valor);
                eliminar(valor, list);
                break;
            case 3:
                listar(list);
                break;
            case 4:
                vaciarLista(list);
                break;
            case 5:
                printf("El tamanio de la lista es: %d.\n", tamanio(list));
                break;
            case 6:
                printf("Terminamos.\n");
                break;
        }
    }while(opcion != 6);
    
    return 0;
}
