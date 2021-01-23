#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

typedef struct tiempo{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct {
    char *nombre;
    Tiempo ultima_mod;
} Archivo;

typedef struct {
    int n;
    double *coeficiente;
} Polinomio;

typedef struct {
    double abscisa;
    double ordenada;
} TipoPunto;

typedef struct {
    TipoPunto situacion;
    char nombre[50];
} TipoCiudad;

typedef struct Auto{
    char *patente;
    int motor;
    int marca;
    int modelo;
    int potencia;
    char *color;
}Automovil;


// Ejercicio 1

int compara_tiempos(Tiempo *t1, Tiempo *t2){
    if ( (t1->anio < t2->anio)
        || (t1->anio == t2->anio && t1->mes < t2->mes)
        || (t1->anio == t2->anio && t1->mes == t2->mes && t1->dia < t2->dia)
        || (t1->anio == t2->anio && t1->mes == t2->mes && t1->dia == t2->dia && t1->hora < t2->hora)
        || (t1->anio == t2->anio && t1->mes == t2->mes && t1->dia == t2->dia && t1->hora == t2->hora && t1->minuto < t2->minuto)
        || (t1->anio == t2->anio && t1->mes == t2->mes && t1->dia == t2->dia && t1->hora == t2->hora && t1->minuto == t2->minuto && t1->segundo < t2->segundo) )
        return 1;
    else if (t1->anio == t2->anio 
            && t1->mes == t2->mes 
            && t1->dia == t2->dia 
            && t1->hora == t2->hora 
            && t1->minuto == t2->minuto 
            && t1->segundo == t2->segundo)
        return 0;
    else
        return -1;
}

void imprime_tiempo(Tiempo *t){
    printf("Fecha: %d/%d/%d\t Hora: %d:%d:%d\n",t->dia, t->mes, t->anio, t->hora, t->minuto, t->segundo);
}

/*
void ordena_alfa(Archivo *lista, int n){
    
}

void ordena_temporal(Archivo *lista, int n){
    int i = 0;
    while (i < n){
        if (compara_tiempos(lista, lista+(i+1) == -1)){
            Archivo *aux = malloc(sizeof(Archivo));
            aux->nombre = lista->nombre;
            aux->ultima_mod = lista->ultima_mod;
            lista = lista+(i+1);
            lista+(i+1) = aux;
        }
    }
}
*/

// Ejercicio 2

Polinomio *creaPolinomio(int orden){
    Polinomio *p = (Polinomio *) malloc(sizeof(Polinomio)*orden);
    p->n = orden;
    return p;
}

void setCoef(int exp, double c, Polinomio *p){
    int i = 0;
    while (p->n != exp)
        p++;
    p->coeficiente = &c;
}

double getCoef(int n, Polinomio *p){
    int i = 0;
    while (p->n != n)
        p++;
    return *(p->coeficiente);
}

double especializa(double x, Polinomio *p){
    double resultado = 0;
    int i = 0;
    for (i = 0; i <= p->n; i++){
        resultado = resultado + *(p->coeficiente) * pow(x,(p->n));
    }
    return resultado;
}

Polinomio *suma_pol(Polinomio *p1, Polinomio *p2){
    Polinomio *p, *aux1;
    int orden_mayor, orden_menor;
    // Busco el polinomio de menor orden para luego rellenarlo con 0's y hacer la suma con el de mayor orden
    if (p1->n < p2->n){
        orden_mayor = p2->n;
        orden_menor = p1->n;
        Polinomio *p = (Polinomio *) malloc(sizeof(Polinomio)*(p1->n));
        p->n = p1->n;
    }
    else{
        orden_mayor = p1->n;
        orden_menor = p2->n;
        Polinomio *p = (Polinomio *) malloc(sizeof(Polinomio)*(p2->n));
        p->n = p2->n;
    }
    // Creo un puntero auxiliar para llegar hasta el orden menor y de ahi rellerar el polinomio de menor orden
    int i;
    Polinomio *aux = p;
    for(i = 0; i <= orden_menor; i++){
        aux++;
    }
    // Estoy en el final del polinomio de menor orden
    aux = (Polinomio *) malloc(sizeof(Polinomio)*(orden_mayor-orden_menor));
    // Relleno con ceros
    for(i = aux->n; i <= orden_mayor; i++){
        aux->n++;
        *(aux->coeficiente) = 0;
    }
    // Ahora tengo los polinomios del mismo orden y los sumo
    aux1 = p;
    for (i = 0; i <= orden_mayor; i++){
        aux1->n++;
        *(aux1->coeficiente) = *(p1->coeficiente) + *(p2->coeficiente);
        aux1++;
    }
    return p;
    free(aux);
    free(p);
}

Polinomio *mult(Polinomio *p1, Polinomio *p2){
    
}

Polinomio *deriv(Polinomio *p){
    Polinomio *cero;
    cero = p;
    if (p->n == 0){
         *(cero->coeficiente) = *(p->coeficiente); // revisar derivada de una constante
         return p;
    }
    int i;
    Polinomio *d;
    d = p;
    for (i = 1; i <= p->n; i++){
        *(d->coeficiente) = *(d->coeficiente) * (double)(d->n);
        d->n--;
    }
    return p;
}

void destruyePolinomio(Polinomio *p){
    int i;
    for (i = 0; i <= p->n; i++){
        free(p);
    }
}

// EJERCICIO 5

typedef struct matrix{
    int fil, col;
    int **matriz;
}Matriz;

Matriz *suma_Matrices(Matriz *matriz1, Matriz *matriz2){
    int i, j;
    for (i = 0; i < matriz1->fil; i++){
        for (j = 0; j < matriz1->col; j++){
            matriz1->matriz[i][j] = matriz1->matriz[i][j] + matriz2->matriz[i][j];
        }
    }
    return matriz1;
}

// EJERCICIO 6

typedef struct{
    unsigned char R, G, B; //componentes primarios de un color
}RGB;

typedef struct{
    int ancho, alto;
    RGB **pixel;
}ImagenRGB;

typedef unsigned char Gris;

typedef struct{
    int ancho, alto;
    Gris **pixel;
}ImagenGris;

ImagenRGB *creaImagenRGB(int ancho, int largo){
    ImagenRGB *img = (ImagenRGB *) malloc(sizeof(ImagenRGB));
    img->ancho = ancho;
    img->alto = largo;
    return img;
}

ImagenGris *creaImagenGris(int ancho, int alto){
    ImagenGris *img = (ImagenGris *) malloc(sizeof(ImagenGris));
    img->ancho = ancho;
    img->alto = alto;
    return img;
}

void setPixelRGB(ImagenRGB *img, int fila, int columna, RGB *pix){
    
}



// Ejercicio 10

Automovil *crearAuto(){
    Automovil *coche = (Automovil *) malloc(sizeof(Automovil));
    int motor, marca, modelo, potencia;
    char *patente = NULL;
    char *color = NULL;
    printf("Ingrese los datos de su automovil:\n");
    printf("Ingrese la patente: \n");
    scanf("%s", patente);
    coche->patente = patente;
    printf("Ingrese el numero de motor: \n");
    scanf("%d", &motor);
    coche->motor = motor;
    printf("Ingrese la marca de su auto: \n");
    scanf("%d", &marca);
    coche->marca = marca;
    printf("Ingrese el modelo: \n");
    scanf("%d", &modelo);
    coche->modelo = modelo; 
    printf("Ingrese la potencia del motor: \n");
    scanf("%d", &potencia);
    coche->potencia = potencia;
    printf("Ingrese el color de la carroseria: \n");
    scanf("%s", color);
    coche->color = color;
    return coche;
}








int main(){
    //Ejercicio 1
    
    /*
    Tiempo *t1 = malloc(sizeof(struct tiempo)), *t2 = malloc(sizeof(struct tiempo));
    t1->anio = 2019;
    t1->mes = 8;
    t1->dia = 23;
    t1->hora = 00;
    t1->minuto = 34;
    t1->segundo = 26;
    t2->anio = 2019;
    t2->mes = 8;
    t2->dia = 23;
    t2->hora = 00;
    t2->minuto = 34;
    t2->segundo = 25;
    int res = compara_tiempos(t1,t2);
    printf("%d\n", res);
    imprime_tiempo(t1);
    free(t1);
    free(t2);
    */
    
    //Automovil *coche1 = crearAuto();


    /*
    // EJERCICIO 5
    int i, j;
    
    int fil;
    printf("Ingrese la cantidad de filas de las matices: ");
    scanf("%d", &fil);
    
    int col;
    printf("Ingrese la cantidad de columnas de las matices: ");
    scanf("%d", &col);
    
    // creo las dos matrices    
    Matriz *matriz1 = (Matriz *) malloc(sizeof(Matriz));
    Matriz *matriz2 = (Matriz *) malloc(sizeof(Matriz));
    
    matriz1->fil = fil;
    matriz1->col = col;
    matriz2->fil = fil;
    matriz2->col = col;
    
    matriz1->matriz = (int **) malloc(sizeof(int *)*fil);
    matriz2->matriz = (int **) malloc(sizeof(int *)*fil);
    
    for (i = 0; i < fil; i++){
        matriz1->matriz[i] = (int *) malloc(sizeof(int)*col);
        matriz2->matriz[i] = (int *) malloc(sizeof(int)*col);
    }
    
    // llenamos las matrices con valores aleatorios
    
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            matriz1->matriz[i][j] = random()%9;
            matriz2->matriz[i][j] = random()%9;
        }
    }
    
    // mostramos las matrices
    printf("Las matrices son:\n");
    
    printf("Matriz 1:\n");
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            printf("    %d", matriz1->matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("Matriz 2:\n");
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            printf("    %d", matriz2->matriz[i][j]);
        }
        printf("\n");
    }
    
    // realizo la suma y la guardo en la matriz 1
    Matriz *suma = (Matriz *) malloc(sizeof(Matriz));
    suma = suma_Matrices(matriz1, matriz2);
    
    //mostramos el resultado
    printf("La suma de las matrices es:\n");
    for(i = 0; i < fil; i++){
        for(j = 0; j < col; j++){
            printf("    %d", matriz1->matriz[i][j]);
        }
        printf("\n");
    }
    
    // liberamos el espacio pedido para la matriz
    free(suma);
    
    for(i = 0; i < fil; i++){
        free(matriz1->matriz[i]);
        free(matriz2->matriz[i]);
    }
    free(matriz1->matriz);
    free(matriz2->matriz);
    
    //liberamos el espacio pedido para las estructuras
    free(matriz1);
    free(matriz2);
    */

}
