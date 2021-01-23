#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int op,peso,completo = 0;
    char a,b;
    do{
        printf("1. Agregar un vertice.\n");
        printf("2. Agregar una arista.\n");
        printf("3. Kruskal.\n");

        printf(">");
        scanf("%d",&op);
        switch(op){
            case 1:
                while(cantVertices != 9){
                    agregarV();
                }
                break;
            case 2:
                if((vertices != NULL) && (vertices->sig != NULL)){
                    if(1){
                        agregarA('a','b',2);
                        agregarA('a','d',3);
                        agregarA('a','e',3);
                        agregarA('b','c',2);
                        agregarA('b','f',3);
                        agregarA('b','e',3);
                        agregarA('c','f',3);
                        agregarA('d','e',2);
                        agregarA('e','f',2);
                        agregarA('d','g',3);
                        agregarA('d','h',5);
                        agregarA('g','h',3);
                        agregarA('e','h',1);
                        agregarA('f','i',3);
                        agregarA('e','i',4);
                        agregarA('h','i',3);
                    }else{
                        printf("\nIngrese los vertices que va a enlazar: ");
                        scanf(" %c %c",&a,&b);
                        printf("Ingrese el peso de la arista: ");
                        scanf("%d",&peso);
                        if(pertenece(a) && pertenece(b)){
                            agregarA(a,b,peso);
                        }else{
                            printf("Los vertices dados no pertenecen al grafo.\n");
                        }
                    }
                }else{
                    printf("\nNo se pueden crear aristas, vertices insuficientes.\n\n");
                }
                break;
            case 3:
                kruskal();
                mostrarA(arbol,2);
                completo = 1;
                break;
        }
        if(completo == 0){
            mostrar(vertices);
            mostrarA(aristas,0);
        }
    }while(op != 0 && completo != 1);

    return 0;
}

