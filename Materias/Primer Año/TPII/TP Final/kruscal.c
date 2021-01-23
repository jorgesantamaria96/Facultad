/* kruskal.c */

#include "kruskal.h"

int main()
{
    int M_Costos[VERTICES][VERTICES];
    rama *arbol;

    int i, j;
    for (i = 0; i <= VERTICES - 1; i++)
    {
        for (j = i + 1; j <= VERTICES - 1; j++)
        {
            printf("Ingrese costo de lado entre vértices %d y %d:  ", i, j);
            scanf("%d ", &M_Costos[i][j]);
        }
    }

    for (i = 0; i <= VERTICES - 1; i++)
    {
        // la mitad inferior de la diagonal de la matirz
        for (j = i + 1; j <= VERTICES - 1; j++)
        {
            if (M_Costos[i][j] != 0)
            {
                inserta(i, j, M_Costos[i][j], &arbol); // inserto en la cola de prioridad
            }
        }
    }

    kruskal(arbol);
    return 0;
}