#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int len_array(int *array){
    int n;
    for (n = 0; *array != '\0'; array++)
        n++;
    return n;
}

void invertirCadena(int *array){
    int i, j, len = len_array(array);
    int *aux = &array[len-1];  
    int nuevo_array[len]; 
    int *nuevo = &nuevo_array[0];
    for (i = 0; i < len; i++){
        *(nuevo + i) = array[len-i];
    }
    printf("La cadena invertida es: \n");
    for (i = 0; i < len; i++){
        printf("%d", *nuevo+i);
    }
    printf("\n");
}


char *dias_semana(int dia){
    char *lunes = "Lunes";
    char *martes = "Martes";
    char *miercoles = "Miercoles";
    char *jueves = "Jueves";
    char *viernes = "Viernes";
    char *sabado = "Sabado";
    char *domingo = "Domingo";
    switch (dia){
        case 1:
            return lunes;
            break;
        case 2:
            return martes;
            break;
        case 3:
            return miercoles;
            break;
        case 4:
            return jueves;
            break;
        case 5:
            return viernes;
            break;
        case 6:
            return sabado;
            break;
        case 7:
            return  domingo;
            break; 
    }
}


void ejercicio5(float cant_kilos, float precio_x_kilo){
    float importe_compra = cant_kilos * precio_x_kilo;
    printf("El precio final es : $%f\n", importe_compra);
    if (importe_compra > 100){
        printf("Posee un descuento del 10 porciento\n");
        importe_compra = importe_compra / 1.1;
        printf("El precio final es: $%f\n", importe_compra);
    }
}

// Ejercicio 6

typedef enum { MAYUSCULAS, MINUSCULAS } may_min;

int strLargo(const char *origen){
//Cantidad de caracteres
    const char *aux;
    aux = origen;
    int cantidad = 0;
    while (*aux != '\0'){
        cantidad++;
        aux++;
    }
    return cantidad;
}

int strVacio(const char *origen){
//retorna 1 si tiene al menos un caracter, 0 en otro caso
    int cantidad = strLargo(origen);
    if (cantidad = 0)
        return 0;
    else
        return 1;
}

void strCopia(char *destino, const char *origen){// Copiador
/*prototipo modificado para permitir argumentos de tipo string literales, en casi todos los
compiladores un literal string es considerado una constante, o sea la función no podría
modificarlos pero, en algunos compiladores tales como GCC es posible modificarlos (según
K&R el comportamiento es indefinido)*/
    int n = strLargo(origen);
    char *aux = (char *) malloc(sizeof(char)*n);
    char *aux2;
    aux2 = aux;
    destino = (char *) malloc(sizeof(char)*n);
    aux = destino;
    while (*origen != '\0'){
        *aux = *origen;
        aux++;
        origen++;
    }
    printf("%s\n",destino);
    free(aux2);
    free(destino);
}

char *reverse(char *stringt){
//retorna una cadena que es string invertida
    int i = 0;
    
    // aux para no tocar stringt    
    char *aux;
    aux = stringt;
    
    // defino un nuevo arreglo para guardar la cadena
    int n = strLargo(stringt);
    char *temp = (char *) malloc(sizeof(char)*(n+1));
    
    // defino un temp_aux para ir al final y poner un \0
    char *temp_aux;
    temp_aux = temp;
    while (i < n){
        temp_aux++;
        i++;
    }
    *temp_aux = '\0';
    
    // voy al elemento anterior de temp
    temp_aux--;
    
    // me voy a crear otro puntero al origen de stringt y uno al origen de temp
    char *stringt_origen, *temp_origen;
    stringt_origen = stringt;
    temp_origen = temp;
    
    // ahora comienzo a guardar los elementos
    while (*aux != '\0'){
        *temp_aux = *aux;
        aux++;
        temp_aux--;
    }
    
    // y ahora piso los datos de temp en stringt
    while (*stringt_origen != '\0'){
        *stringt_origen = *temp_origen;
        stringt_origen++;
        temp_origen++;
    }
    
    // y ahora libero la memoria usada en temp
    free(temp);
    
    // devuelvo la cadena original
    return stringt;
}

void strIzq(char *destino, const char *origen){
// Saca blancos Izq.
    if (*origen == ' ')
        origen++;
    strCopia(destino, origen);
}

void strDer(char *destino, const char *origen){
// Saca blancos Der.
    const char *aux, *aux2;
    aux = malloc(sizeof(char *));
    aux = origen;
    while (*aux != '\0'){
        aux++;
    }
    while (*aux == ' '){
        aux2 = malloc(sizeof(char));
        aux2 = aux;
        aux--;
        free((void *)aux2);
    }
}

void strAmbos(char *destino, const char *origen){
// Saca blancos Izq. y Der.
    int n = strLargo(origen);
    destino = (char *) malloc(sizeof(char)*n);
    strIzq(destino, origen);
    strDer(destino, origen);
    free(destino);
}

void strMayMin(char *destino, const char *origen, may_min m){
// Convierte May. Min.

}

// EJERCICIO 9

void ejercicio9(int n){
    
    int i, j;
    int **matriz = NULL;
    
    // reservamos espacio para las filas
    matriz = (int **) malloc(sizeof(int *)*n);
    
    // reservamos espacio para las columnas
    for (i = 0; i < n; i++){
        matriz[i] = (int *) malloc(sizeof(int)*n);
    }
    
    // lenamos la matriz con los elementos de la Identidad
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i == j){
                matriz[i][j] = 1;
            }
            else{
                matriz[i][j] = 0;
            }
        }
    }
    
    // mostramos la matriz
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("    %d",matriz[i][j]);
        }
        printf("\n");
    }
    
    // liberamos el espacio de memoria
    for (i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);
}


void producto_Escalar_Matriz1(){
    
    int i, j;

    printf("Ingrese el valor esclalar: ");
    int valor_escalar;
    scanf("%d", &valor_escalar);
    printf("\n");
    
    printf("Ingrese la dimension de la matriz: ");
    int dim;
    scanf("%d", &dim);
    printf("\n");
    
    // reservo espacio para las filas
    int **matriz = (int **) malloc(sizeof(int *)*dim);
    
    // reservo espacio para las columnas 
    for(i = 0; i < dim; i++){
        matriz[i] = (int *) malloc(sizeof(int)*dim);
    }
    
    // llenamos la matriz con valores random
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            matriz[i][j] = 1 + rand()%9;
        }
    }
    
    // creamos una nueva matriz
    // reservo espacio para las filas
    int **nueva_matriz = (int **) malloc(sizeof(int*)*dim);
    
    //reservo espacio para las columknas
    for(i = 0; i < dim; i++){
        nueva_matriz[i] = (int *) malloc(sizeof(int)*dim);
    }
    
    // realizo el cálculo
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            nueva_matriz[i][j] = matriz[i][j] * valor_escalar;
        }
    }
    
    // mostramos la matriz original
    printf("Matriz original:\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("    %d",matriz[i][j]);
        }
        printf("\n");
    }
    
    // Ahora mostramos el resultado final
    printf("Matriz resultante del producto escalar:\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("    %d",nueva_matriz[i][j]);
        }
        printf("\n");
    }
    
    // liberamos el espacio de matriz
    for(i = 0; i < dim; i++)
        free(matriz[i]);
    free(matriz);
    
    // liberamos el espacio de la nueva matriz
    for(i = 0; i < dim; i++)
        free(nueva_matriz[i]);
    free(nueva_matriz);
}

// EJERCICIO 10

int determinante_Matriz(int tam, int **matriz){
    int det;
    if (tam = 2){
        det = matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
    }
    else{
        det = matriz[0][0]*matriz[1][1]*matriz[2][2] +
              matriz[0][1]*matriz[1][2]*matriz[2][0] +
              matriz[0][2]*matriz[1][0]*matriz[2][1] -
              matriz[2][0]*matriz[1][1]*matriz[0][2] -
              matriz[2][1]*matriz[1][2]*matriz[0][0] -
              matriz[2][2]*matriz[1][0]*matriz[0][1];
    }
    return det;
}

// EJERCICIO 11

int **producto_escalar_Matriz(int fil, int col, int esc, int **matriz){
    int i = 0, j = 0;
    int **nueva_matriz;
    nueva_matriz = matriz;
    while (i < fil-1)
        i++;
    while (j < col-1)
        j++;
    matriz[i][j] = matriz[i][j] * esc;
    return nueva_matriz;
}

// EJERCICIO 12

// A)

int len_string(char *cadena){
    int i;
    char *aux;
    aux = cadena;
    for(i = 0; *aux != '\0'; aux++)
        i++;
    return i;
}

void es_IP(char *cadena){
    if (isdigit(*cadena) && isdigit(*(cadena+1)) && isdigit(*(cadena+2)) && *(cadena+3) == '.'){
        printf("Ingreso una direccion IP\n");
    }
    else
        printf("Por favor, ingrese una direcion IP\n");
}

void es_MAIL(char *cadena){
    while (*cadena != '\0'){
        if (*cadena == '@'){
            printf("Ingreso una direccion de correo electronico\n");
            break;
        }
        cadena++;
    }
    if (*cadena == '\0')
        printf("Por favor, ingrese una direccion de correo electronico valida\n");    
}
    
void es_CREDIT(char *cadena){
    if (isdigit(*cadena) && isdigit(*(cadena+1)) && isdigit(*(cadena+2)) && isdigit(*(cadena+3)) && *(cadena+4) == ' '){
        printf("Ingreso su tarjeta de credito\n");
    }
        else{
        printf("Por favor ingrese el numero de su tarjeta de credito\n");
    }
}

void validate_string(char *cadena, void (* funcion)(char *)){
    char *aux;
    aux = cadena;
    printf("Dada la siguente cadena: ");
    while (*aux != '\0'){
        printf("%c", *aux);
        aux++;
    }
    printf("\n");
    funcion(cadena);
}


int main(void){
    
    // Ejercicio 1
    
    /*
    int i = 8, *pi=&i;
    long long l = 8, *pl=&l;
    float f = 102.8f, *pf=&f;
    double d=678.44, *pd=&d;
    int vec[100];
    vec[0] = 44;
    printf("variable int, tam.bytes: %d \tdir.&i: %p \tvalor: %d\n", sizeof(i), &i, i);
    printf("puntero int, tam.bytes= %d \tdir.&pi: %p \tvalor: %p\n", sizeof(pi), &pi, pi);
    printf("variable long, tam.bytes: %d \tdir.&l: %p \tvalor: %ld\n", sizeof(l), &l, l);
    printf("puntero long, tam.bytes: %d \tdir.&pl: %p \tvalor: %p\n", sizeof(pl), &pl, pl);
    printf("variable float, tam.bytes: %d \tdir.&f: %p \tvalor: %.1f\n", sizeof(f), &f, f);
    printf("puntero float, tam.bytes: %d \tdir.&pf: %p \tvalor: %p\n", sizeof(pf), &pf, pf);
    printf("variable double, tam.bytes: %d \tdir.&d: %p \tvalor: %.2lf\n", sizeof(d), &d, d);
    printf("puntero double, tam.bytes: %d \tdir.&pd: %p \tvalor: %p\n", sizeof(pd), &pd, pd);
    printf("variable array, tam.bytes: %d \tdir.&vec[0]: %p \tvalor: %d\n", sizeof(vec[0]), &vec[0], vec[0]);
    printf("puntero array, tam.bytes: %d \tdir.&vec: %p \tvalor: %p\n", sizeof(vec), &vec, vec);
    return 0;
    */
    
    // Ejercicio 2
    
    /*
    int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
    char x = 'a', pal [] ="texto en c";
    int *pi;
    char *pc;
    
    printf("\t||| CON ENTEROS |||\n");
    printf("Direccion: %p\t Valor: %d\n", &i, i);
    pi = &i;
    printf("Direccion: %p\t Valor: %d\n", &pi, *pi);
    int a;
    printf("SIN PUNTEROS: \n");
    for (a = 0; a < 10; a++){
        printf("Direccion: %p\t Valor: %d\n", &j[a], j[a]);
    }
    printf("CON PUNTEROS: \n");
    pi = j;
    for (a = 0; a < 10; a++){
        printf("Direccion: %p\t Valor: %d\n", &pi+a, *(pi+a));
    }
    
    printf("\t||| CON CHARS |||\n");
    printf("Direccion: %p\t Valor: %c\n", &x, x);
    pc = &x;
    printf("Direccion: %p\t Valor: %c\n", &pc, *pc);
    int b;
    printf("SIN PUNTEROS: \n");
    for (b = 0; b < 10; b++){
        printf("Direccion: %p\t Valor: %c\n", &pal[b], pal[b]);
    }
    printf("CON PUNTEROS: \n");
    pc = pal;
    for (b = 0; b < 10; b++){
        printf("Direccion: %p\t Valor: %c\n", &pc+b, *(pc+b));
    }
    printf("Direccion donde se almacenan ambos punteros: \n");
    printf("Puntero a int: %p\t Puntero a char: %p\n", &pi, &pc);
	    
    return 0;
    */
    
    // Ejercicio 3

    /*        
    int cadena[] = {1,2,3,4,5,6,7,8,'\0'};
    invertirCadena(cadena);

    printf("%d\n",len_array(cadena));
    */
    
    // Ejercicio 4
    /*
    int dia;
    printf("Ingrese un numero del 1 al 7: ");
    scanf("%d\n", &dia);
    char *semana = dias_semana(dia);
    printf("%s\n",semana);    
    */
    
    // Ejercicio 5
    
    /*
    float x,y;
    printf("Ingrese la cantidad de kilos del producto: ");
    scanf("%f", &x);
    printf("Ingrese el precio por kilo: ");
    scanf("%f", &y);
    ejercicio5(x,y);
    */
    
    // Ejercicio 6
    
    char *c = "Mundo";
    printf("%s\n",reverse(c));
    
    //char *origen = "Hola";
    //char *destino;
    //strCopia(destino, origen);
    
    // Ejercicio 9
    
    /*
    
    int n = 3;
    ejercicio9(n);
    */
    
    // EJERCICIO 10
    
    /*
    int i, j;
    
    int dim;
    printf("Ingrese la dimension de la matriz: ");
    scanf("%d", &dim);
    
    // Creamos la matriz
    
    int **matriz = (int **) malloc(sizeof(int *)*dim);
    for(i = 0; i < dim; i++){
        matriz[i] = (int *) malloc(sizeof(int)*dim);
    }
    
    // llenamos la matriz con valores aleatorios
    
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            matriz[i][j] = 1 + rand()%9;
        }
    }
    
    // Mostramos la matriz original
    
    printf("Matriz original:\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("    %d",matriz[i][j]);
        }
        printf("\n");
    }   
    
    int det;
    int **aux;
    aux = matriz;
    det = determinante_Matriz(dim, aux);
    
    printf("El determinante de la matiz es: %d\n", det);
    
    // liberamos el espacio
    
    for(i = 0; i < dim; i++){
        free(matriz[i]);
    }
    free(matriz);
    */    
    
    
    
    /* 
    
    // EJERCICIO 11
    
    //producto_Escalar_Matriz();
    
    int i, j;
    
    int dim;
    printf("Ingrese la dimension de la matriz: ");
    scanf("%d", &dim);
    
    int escalar;
    printf("Ingrese el escalar: ");
    scanf("%d", &escalar);
    
    int fila;
    printf("Ingrese la fila donde se encuentra el elemento a modificar: ");
    scanf("%d", &fila);
    
    int columna;
    printf("Ingrese la columna donde se encuentra el elemento a modificar: ");
    scanf("%d", &columna);
    
    // Creamos la matriz
    
    int **matriz = (int **) malloc(sizeof(int *)*dim);
    for(i = 0; i < dim; i++){
        matriz[i] = (int *) malloc(sizeof(int)*dim);
    }
    
    // llenamos la matriz con valores aleatorios
    
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            matriz[i][j] = 1 + rand()%9;
        }
    }
    
    // Mostramos la matriz original
    
    printf("Matriz original:\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("    %d",matriz[i][j]);
        }
        printf("\n");
    }
    
    int **aux;
    aux = matriz;
    
    matriz = producto_escalar_Matriz(fila, columna, escalar, aux);
    
    // mostramos la matriz resultante
    
    printf("Matriz luego del producto escalar:\n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            printf("    %d",matriz[i][j]);
        }
        printf("\n");
    }
    
    // liberamos el espacio
    
    for(i = 0; i < dim; i++){
        free(matriz[i]);
    }
    free(matriz);
    
    */
    
    // EJERCICIO 12
    //char *cadena = "jorge.santamaria966@gmail.com";    
    //validate_string(cadena, es_MAIL);   
    
}


