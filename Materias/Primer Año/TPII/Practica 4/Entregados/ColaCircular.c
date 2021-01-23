#include "ColaCircular.h"

Queue *crearCola(){
// crea una cola vacia
    Queue *cola;
    cola = (Queue *) malloc(sizeof(Queue));
    cola->inicio = -1;
    cola->fin = -1;
}

int sumaUno(int posicion){
// clacula la posicion del siguiente elemento a insertar
    return (posicion % CAP) + 1;
}

int estaVacia(Queue *cola){
// verifica si la cola esta vacia 
    if (cola->fin == -1){
        return 1;
    }
    return 0;
}

void frente(Queue *cola){
// muestra el elemento que sale primero
    if (estaVacia(cola)){
        printf("La cola esta vacia.\n");
    }
    else{
        printf("El primer elemento es: %d.\n", cola->vector[cola->inicio]);
    }
}

int cantElementos(Queue *cola){
// devuelve la cantidad de elementos de la cola
    if (estaVacia(cola)){
        return 0;
    }
    else{
        if (cola->inicio < cola->fin){
            return cola->fin - cola->inicio + 1;
        }
        else{
            return CAP - cola->inicio + cola->fin + 1;
        }
    }
}

int estallena(Queue *cola){
// verifica si esta llena
    if (cantElementos(cola) == CAP){
        return 1;
    }
    return 0;
}

void push(Queue *cola, int n){
// inserta un elemento en la cola
    if (!estallena(cola)){
        if (estaVacia(cola)){
            cola->inicio++;
        }
        if (cola->fin == CAP-1){
            cola->fin = 0;
        }
        else{
            cola->fin++;
        }
        cola->vector[cola->fin] = n;
    }
    else{
        printf("La cola esta llena.\n");
        cola->fin = 0;
        cola->vector[cola->fin] = n;
    }
}

void pop(Queue *cola){
// elimina el elemento del frente de la cola
    if (!estaVacia(cola)){
        if(cantElementos(cola) == 1){
            cola->inicio = -1;
            cola->fin = -1;
        }
        else{
            cola->inicio++;
        }
    }
    else{
        printf("0 1 2 3 4 5 6\n");
    }
}

void vaciarCola(Queue *cola){
// vacia la cola
    cola->inicio = -1;
    cola->fin = -1;
}

void mostrar_cola(Queue *cola){
// imprime la cola en pantalla
    if (estaVacia(cola)){
        printf("\n");
        printf("  POSICIONES\n");
        printf("0 1 2 3 4 5 6\n");
        printf("\n");
    }
    else{
    printf("\n");
    printf("  POSICIONES\n");
        printf("0 1 2 3 4 5 6 \n");
        int i = cola->inicio;
        while (i < CAP){
            printf("%d ", cola->vector[i]);
            i++;
        }
        printf("\n\n");
    }
}

int main(){
    
    Queue *cola = crearCola();
    
    int valor, opcion;

    do{
        printf("MENU\n\n");
        
        printf("[1] Insertar un elemento.\n");
        printf("[2] Mostrar el primer elemento.\n");
        printf("[3] Eliminar el primer elemento.\n");
        printf("[4] Comprobar si esta vacia.\n");
        printf("[5] Vaciar la cola.\n");
        printf("[6] Mostrar cola.\n");
        printf("[7] Cantidad de elementos.\n");
        printf("[8] Salir.\n");
        printf("Opcion a elegir: ");
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                printf("Ingrese el numero: ");
                scanf("%d", &valor);
                push(cola, valor);
                printf("Se inserto el elemento en la pila.\n");
                break;
            case 2:
                frente(cola);
                break;
            case 3:
                pop(cola);
                printf("Se elimino el primer elemento de la cola.\n");
                break;
            case 4:
                if (!estaVacia(cola)){
                    printf("La cola tiene elementos.\n");
                }
                else
                    printf("La cola esta vacia.\n");
                break;
            case 5:
                vaciarCola(cola);
                printf("Se vacio la cola.\n");
                break;
            case 6:
                mostrar_cola(cola);
                break;
            case 7:
                printf("La cantidad de elementos es: %d.\n", cantElementos(cola));
                break;
            case 8:
                printf("Terminado.\n");
                break;
        }
    }while(opcion != 8);
    
    return 0;
}
