#include <stdio.h>
#include <stdlib.h>

typedef struct char_string{
    char c;
    char *cadena;
}CS;

int cantidad (CS *ptr){
    int res = 0;
    char *aux;
    aux = ptr->cadena;
    while (*(aux) != '\0'){
        if (*(aux) == ptr->c)
            res = res + 1; 
        aux++;
    }
    return res;
}

int *ocurrencias(CS *ptr){
    int cant = cantidad(ptr);
    int *resultado = (int *) malloc(sizeof(int)*cant);
    int *aux;
    aux = resultado;
    int pos = 0;
    while (*(ptr->cadena) != '\0'){
        if (*(ptr->cadena) == ptr->c){
            *aux = pos;
            aux++;
        }
        pos++;
        ptr->cadena++;
    }
    return resultado;
}

int main(void){
    int cant = 0, i = 0;
    CS *ptr = (CS *) malloc(sizeof(CS));
    ptr->cadena = "Hola Mundo";
    ptr->c = 'o';
    cant = cantidad(ptr);
    printf("Cantidad: %d\n",cant);
    
    
    int *ocurr;
    ocurr = ocurrencias(ptr);
    while (i < cant){
        printf("    %d",*ocurr);
        i++;
    }
    printf("\n");
    free(ptr);
}
