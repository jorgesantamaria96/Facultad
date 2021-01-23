#include <stdio.h>
#include "PilasArray.h"

void apila(int x){
// apila un elemento si tiene espacio
    if (tamanio() == CAPACIDAD)
        printf("Error: No hay más espacio\n");
    else {
        cima++;
        elementos[cima] = x;
    }
}

int desapila(){
// desapila un elemento si es que hay elementos
    if (estaVacia() == 0)
        printf("Error: No hay elementos\n");
    else{
        cima--;
        return elementos[cima+1];
    }
}

void vaciaPila(){
// vacio la pila llevando la posicion de la cima a -1
    cima = -1;
}

int estaVacia(){
// devuelve 0 si la pila esta vacia, 1 si no
    if (cima == -1)
        return 0;
    else
        return 1;
}

int cimaPila(){
    if (estaVacia() == 0)
        printf("Error: No hay elementos\n");
    else
        return elementos[cima];
}

int tamanio(){
// devuelve el tamaño de la pila (cantidad de elementos apilados)
    return cima+1;
}

void mostrar_pila(){
    int i = cima;
    if (i == -1){
        printf("##### PILA #####\n");
        printf("################\n");
    }
    else{
        puts("\n");
        printf("##### PILA #####\n");
        while(i != -1){
            printf("\t%d\t\n",elementos[i]);
            i--;
        }
        printf("################\n");
        puts("\n");
    }
}

int main(){
    
    int valor, opcion;
    do{
    
        printf("MENU:\n\n");
        
        printf("[1] Apile un elemento.\n");
        printf("[2] Desapile un elemento.\n");
        printf("[3] Tamaño de la pila.\n");
        printf("[4] Cima de la pila.\n");
        printf("[5] Verificar si esta vacia.\n");
        printf("[6] Mostramos la pila.\n");
        printf("[7] Vaciamos la pila.\n");
        printf("[8] Salir.\n");
        printf("Opcion a elegir: ");
        scanf("%d", &opcion);
        
        switch (opcion){
            case 1:
                printf("Ingrese un valor: ");
                scanf("%d", &valor);
                apila(valor);
                printf("Se apilo correctamente.\n");
                break;
            case 2:
                printf("El elemento desapilado es: %d.\n", desapila());
                break;
            case 3:
                printf("El tamaño de la pila es: %d.\n", tamanio());
                break;
            case 4:
                printf("La cima de la pila es: %d.\n", cimaPila());
                break;
            case 5:
                if (estaVacia() == 0)
                    printf("La pila esta vacia.\n");
                else
                    printf("La pila posee elementos.\n");
                break;
            case 6:
                mostrar_pila();
                break;
            case 7:
                vaciaPila();
                printf("La pila se vacio correctamente.\n");
                break;
            case 8:
                printf("Terminamos.\n");
                break;
        }
    
    }while(opcion != 8);
      
    return 0;
}
