#include "TreeString.h"

void insertar(Nodo **a, char c){
    if ((*a) == NULL){
        *a = (Nodo *) malloc(sizeof(Nodo));
        (*a)->dato = c;
        (*a)->izq = NULL;
        (*a)->der = NULL;
    }
    else{
        if (c < (*a)->dato)
            insertar(&((*a)->izq), c);
        else if (c == (*a)->dato)
            printf("El dato se encuentra en el arbol.\n");
        else
            insertar(&((*a)->der), c);
    }
}

int es_miembro(Nodo *a, char c){
    if (a == NULL)
        return -1;
    else if (a->dato == c)
        return 1;
    else if (a->dato > c)
        return es_miembro(a->izq, c);
    else
        return es_miembro(a->der, c);
}

int suprime_min(Nodo **a){
    int ref;
    if ((*a)->izq == NULL){
        ref = (*a)->dato;
        Nodo *tmp;
        tmp = *a;
        *a = (*a)->der;
        free(tmp);
        return ref;
    }
    else{
        return suprime_min(&((*a)->izq));
    }
}

void eliminar(Nodo **a, char c){
    if ((*a) == NULL){
        printf("El arbol esta vacio.\n");
    }
    else{
        if (c < (*a)->dato)
            eliminar(&((*a)->izq), c);
        
        else if (c > (*a)->dato)
            eliminar(&((*a)->der), c);
        // lo encontre
        else if (((*a)->izq == NULL) && ((*a)->der == NULL)){
            Nodo *aux;
            aux = *a;
            (*a) = (*a)->der;
            free(aux);
        }
        else if ((*a)->izq == NULL){
            Nodo *aux;
            aux = *a;
            *a = (*a)->der;
            free(aux);
        }
        else if ((*a)->der == NULL){
            Nodo *aux;
            aux = *a;
            *a = (*a)->izq;
            free(aux);
        }
        else{ // ambos hijos presentes
            (*a)->dato = suprime_min(&((*a)->der));
        }
    }
}

void preOrder(Nodo *a){
    printf("PRE-ORDER: ");
    if (a != NULL){
        printf("%c -", a->dato);
        preOrder(a->izq);
        preOrder(a->der);
    }
}

void inOrder(Nodo *a){
    printf("IN-ORDER: ");
    if (a != NULL){
        inOrder(a->izq);
        printf("%c -", a->dato);
        inOrder(a->der);
    }
}

void posOrder(Nodo *a){
    printf("POS-ORDER: ");
    if (a != NULL){
        posOrder(a->izq);
        posOrder(a->der);
        printf("%c -", a->dato);
    }
}

void mostrar_arbol(Nodo **arbol){
    Nodo *aux;
    aux = *arbol;
    int opcion;
    printf("\n");
    printf("Seleccione el orden en el que mostrar el arbol: \n");
    printf("    -1- Pre-order\n");
    printf("    -2- In-order\n");
    printf("    -3- Pos-orden\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    
    if (opcion == 1)
        preOrder(*arbol);
    else if (opcion == 2)
        inOrder(*arbol);
    else
        posOrder(*arbol);
}

int main(){
    char valor;
    int opcion;
    
    char cadena[100];
    printf("Ingrese una frase: ");
    fgets(cadena, 100, stdin);
    printf("La cadena ingresada es:\n%s\n", cadena);

    Nodo **root;
    /* *root = NULL; */

    // Ingresamos la cadena al Árbol

    while (*cadena != '\n') {
        insertar(root,*cadena);
        *cadena++;
    }

    // Elegimos las diferentes opciones para mostrar el Árbol

    mostrar_arbol(root);

    
    /* do{
    
    printf("\nMENU\n\n");
    
    printf("[1] Ingresar un elemento.\n");
    printf("[2] Buscar un elemento.\n");
    printf("[3] Eliminar un elemento.\n");
    printf("[4] Mostrar el arbol.\n");
    printf("[5] Salir.\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    
    switch (opcion){
        case 1:
            printf("Ingrese un dato: ");
            scanf("%c", &valor);
            insertar(root, valor);
            break;
        case 2:
            printf("Ingrese un dato para comprobar: ");
            scanf("%c", &valor);
            int pia;
            pia = es_miembro(*root, valor);
            if (pia == -1){
                printf("El arbol esta vacio.\n");
                break;
            }
            else if (pia == 0){
                printf("El elemento no esta en el arbol.\n");
                break;
            }
            else{
                printf("El elemento esta en el arbol.\n");
                break;
            }
        case 3:
            printf("Ingrese el caracter a eliminar: ");
            scanf("%c", &valor);
            eliminar(root, valor);
            printf("El elemento se borro exitosamente.\n");
            break;
        case 4:
            mostrar_arbol(root);
            break;
        case 5:
            printf("Termianmos.\n");
            break;
    }
    
    }while(opcion != 5); */

    return 0;
}
