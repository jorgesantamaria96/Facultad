/*
ACTIVIDADES:

A) Definir una función
void filecopy(FILE *origen, FILE *destino) que
copie el archivo origen en el archivo destino. Dar dos
versiones, una usando fgetc y otro fgets.

B) Escribir un programa que compare dos archivos e imprima la
primer lı́nea en donde difieran.

1) Crear un programa que cuente las palabras contenidas en un archivo.

2) Crear un programa que lea el contenido de un archivo de texto y lo vuelque en pantalla 
indicando posteriormente la longitud de la linea mas larga

3) Realizar un programa que lea de un archivo n valores enteros y cree un vector en forma dinamica para almacenarlos.
Luego, debe solicitar un valor numerico por teclado y multiplicar a cada uno de los elementos de vector por dicho numero.


*/
#include <stdio.h>
#include <stdlib.h>

// EJERCICIO A CON fgetc

void filecopy1(FILE *origen, FILE *destino){
    int c;
    while ( (c = fgetc(origen)) != EOF ){
        fputc(c,destino);
    }
    /*
    
    if (ferror(origen))
        puts("Error al leer ese archivo\n");
    else if (feof(origen))
        puts("El archivo se leyo correctamente\n");
    
    */
}

// EJERCICIO A CON fgets

void filecopy2(FILE *origen, FILE *destino){
    char linea[10];
    while ((fgets(linea, 10, origen)) != NULL);
    if (feof(origen))
        puts("Se alcanzo el fin de archivo\n");
    int l;
    l = fputs(linea, destino);    
}

// EJERCICIO B

void comp_archivos(FILE *archivo1, FILE *archivo2){
    int pos = 1;
    char *cadena1, *cadena2;
    while (archivo1 != EOF && archivo2 != EOF){
        fscanf(archivo1, "%s", cadena1);
        fscanf(archivo2, "%s", cadena2);
    }
    while (*cadena1 != '\0' && *cadena2 != '\0'){
        if (*cadena1 == *cadena2){
            cadena1++;
            cadena2++;
            pos++;
        }
        else{
            printf("La cadena1 se diferencia de la cadena2 en la pos %d y en el caracter %c", pos, *cadena1);
            printf("La cadena2 se diferencia de la cadena1 en la pos %d y en el caracter %c", pos, *cadena2);
        }
    }
}



int main(){
    FILE *origen;
    FILE *destino;
    
    FILE *copia_origen = fopen("archivo1.txt","r");
    FILE *copia_destino = fopen("archivo2.txt","r");
    
    if ( (origen = fopen("archivo1.txt","r")) == NULL ){
        printf("No se puede abrir %s\n", "archivo1.txt");
        exit(1);
    }
    
    if ( (destino = fopen("archivo2.txt","a+")) == NULL ){
        printf("No se puede abrir %s\n", "archivo2.txt");
        exit(1);
    }
    
    // filecopy1(origen, destino);
    // filecopy2(origen, destino);
    
    /*
    int x;
    while ((x = fgetc(copia_origen)) != EOF)
        printf("    %d",x-48);
    
    puts("\n");
    */
    
    /*    
    if (ferror(destino))
        puts("Error al leer el archivo");
    else if (feof(destino))
        puts("El archivo se leyo correctamente\n");
    */
    
    comp_archivos(origen, destino);
    
    fclose(origen);
    fclose(destino);
    fclose(copia_origen);
    fclose(copia_destino);
    return 0;
}
