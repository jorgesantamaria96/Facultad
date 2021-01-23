#include <stdio.h>
#include <stdlib.h>
#include "parcial1.h"

/*
Entrega via mail a:
    valentinapeirano@ips.edu.ar
    lucianodiamand@gmail.com

ASUNTO: Parcial N°1 - NOMBRE Y APELLIDO 
*/

/*
typedef struct Indocumentado{
    char *nombre;
    char *domicilio;
    int edad;
    int cant_anios;
}Ind;
*/

Ind *crear_Indocumentado(char *nombre, char *domicilio, int edad, int cant_anios){
    Ind *persona = (Ind *) malloc(sizeof(Ind));
    persona->nombre = nombre;
    persona->domicilio = domicilio;
    persona->edad = edad;
    persona->cant_anios = cant_anios;
    return persona;
}

void mostrar_Indocumentado(Ind *persona){
    printf("Nombre: %s, Domicilio: %s, Edad: %d, Años de Ingreso: %d", persona->nombre, persona->domicilio, persona->edad, persona->cant_anios);
}

void agregar_Indocumentados(Ind **lista_personas, Ind *persona, int cant_personas){
    int i = 0;
    Ind **aux;
    aux = lista_personas;
    // busco un elemento de mi lista que este apuntando a NULL
    while (aux[i] != NULL){
        aux++;
        i++;
    }
    // ahora me encuentro en una posicion de lista_personas apuntando a NULL
    // hago apuntar ese elemento a la persona que pase como argumento
    aux[i] = persona;
}

void mostrar_lista_Indocumentado(Ind **lista_personas, int cant_personas){
    Ind **aux_lista_personas;
    aux_lista_personas = lista_personas;
    printf("Mostramos la lista de indocumentados: \n");
    int i = 0;
    while (i < cant_personas){
        if (aux_lista_personas[i] != NULL){
            mostrar_Indocumentado(aux_lista_personas[i]);
            printf("   |   ");
            i++;
        }
        else{
            printf("NULL");
            printf("   |   ");
            i++;
        }
    }
    printf("\n");
}

void buscar_Indocumentados(Ind **lista_personas,int cant_personas, int anios_residencia){
    
    Ind **aux_lista_personas;
    Ind **aux2_lista_personas;
    aux_lista_personas = lista_personas;
    aux2_lista_personas = lista_personas;
    
    // primero reviso la cantidad de personas que hay con los mismos años
    int i = 0, j, count = 0;
    while (i < cant_personas){
        if (aux_lista_personas[i]->cant_anios == anios_residencia){
            count++;
        }
    }
    
    // ahora que se cuantas personas tienen la misma cantidad de años de residencia, creo una nueva lista
    Ind **nueva_lista = (Ind **) malloc(sizeof(Ind *)*count);
    Ind **aux_nueva_lista;
    aux_nueva_lista = nueva_lista;
    
    // y ahora nos fijamos cuáles son y los guardamos en la nueva lista
    for (i = 0, j = 0; i < cant_personas && j < count; i++, j++){
        if (aux2_lista_personas[i]->cant_anios == anios_residencia){
            aux_nueva_lista[j] = aux2_lista_personas[i];
        }
    }
    
    // ahora mostramos la lista de indocumentados
    mostrar_lista_Indocumentado(nueva_lista, count);
    
    // una vez mostrado todo, liberamos el espacio
    free(nueva_lista);
}


int main(){
    
    /* Para probar funciones 3, 4 y 5 */
    
    int cant;
    printf("Ingrese la cantidad de personas Indocumentadas: ");
    scanf("%d", &cant);
    
    /* Para probar ejercicios 1 y 2 */
    
    char *nombre = "Gabriel";
    char *domicilio = "Buenos Aires 5115";
    int edad = 22;
    int anios = 3;
    
    Ind *gabriel = (Ind *) malloc(sizeof(Ind));
    gabriel = crear_Indocumentado(nombre, domicilio, edad, anios);
    
    // mostrar_Indocumentado(gabriel);
    
    /* Para probar ejercicios 3, 4 y 5 */
    
    Ind **lista_personas = (Ind **) malloc (sizeof(Ind *)*cant);
    int i;
    for (i = 0; i < cant; i++){
        lista_personas[i] = NULL;
    }
    
    agregar_Indocumentados(lista_personas, gabriel, cant);
    agregar_Indocumentados(lista_personas, gabriel, cant);
    // mostrar_lista_Indocumentado(lista_personas, cant);    
    
    buscar_Indocumentados(lista_personas,cant, 3);
        
    
    return 0;
}

