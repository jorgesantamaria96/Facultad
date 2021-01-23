#include <stdio.h>
#include <stdlib.h>

typedef struct char_string{
    char c;
    char *cadena;
}CS;

int cantidad(CS *ptr){
    int cantidad = 0;
    char *aux;
    aux = ptr->cadena;
    while (*aux != '\0'){
        if (ptr->c == *aux)
            cantidad++;
        aux++;
    }
    return cantidad;
}

int *ocurrencias(CS *ptr, int *resultado){
    int cant = cantidad(ptr);
    //int *resultado = (int *) malloc(sizeof(int)*cant);
    int *aux_res;
    aux_res = resultado;
    
    CS *aux;
    aux = ptr;
    
    int posicion = 0;
    while (*(aux->cadena) != '\0'){
        if(ptr->c == *(aux->cadena)){
            *aux_res = posicion;
            aux_res++;
        }
        aux->cadena++;
        posicion++;
    }
    *aux_res = '\0';
    return resultado;
}

int main(void){
    
    char *cadena = "los buscadores de Google son los mejores";
    CS *ptr = (CS *) malloc(sizeof(CS));
    ptr->c = 'o';
    ptr->cadena = cadena;
    int res; 
    res = cantidad(ptr);
    printf("Cantidad de veces que aparece: %d\n", res);
    
    int *resultado = (int *) malloc(sizeof(int)*res);
    int *result;
    result = ocurrencias(ptr, resultado);
    
    printf("Posiciones: ");
    int i;
    for(i = 0; i < res; i++){
        printf("    %d", *resultado);
        resultado++;
    }
    printf("\n");
    
    free(ptr);
    free(resultado);
    
    return 0;
}
