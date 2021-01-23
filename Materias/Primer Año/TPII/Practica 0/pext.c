#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

// Ejercicio 7)a)

// #undef TRUE
// #define TRUE 1

// Ejercicio 7)b)

/*
#if __STDC__
#define TRUE 1
#else
#define TRUE 0
#endif

*/

// Ejercicio 7)c)



// Ejercicio 1

void ejercicio1 (int x, int y, int z){
    printf("Los numeros son: \n x = %d;\n y = %d;\n z = %d;\n",x,y,z);
    int aux = 0;
    aux = x;
    x = y;
    y = z;
    z = aux;
    printf("Los numeros ahora son: \n x = %d;\n y = %d;\n z = %d;\n",x,y,z);
}

// Ejercicio 2 ---- Resuelto en main ----

// Ejercicio 3

int len_array(int array[]){
    int count = 0, i = 0;
    while (array[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

int min_array(int array[]){
    int min, i;
    if (len_array(array) == 0)
        printf("Error, ingrese un arreglo con elementos");
    else
        min = array[0];
        for (i = 0; i < len_array(array) && array[i] != '\0'; i++){
            if (array[i] < min)
                min = array[i];
        }
    return min;
}

int max_array(int array[]){
    int max = 0, i;
    if (len_array(array) == 0)
        printf("Error, ingrese un arreglo con elementos");
    else
        for (i = 0; i < len_array(array) && array[i] != '\0'; i++){
            if (array[i] > max)
                max = array[i];
        }
    return max;
}

void ejercicio3 (){
    printf("Vamos a calcular la cantidad de agua caida (en milimetros) durante ciertos dias: \n");
    printf("Ingrese los dias a analizar, luego presione Enter y comience a ingresar las cantidades: ");
    int tam = 0;
    scanf("%d\n",&tam);
    int i, v, valores[tam], t, k, min = 0, max = 0, aux = 0;
    float promedio = 0;
    for (i = 0; i < tam; i++){
        scanf("%d",&v);
        valores[i] = v;
        printf("El valor ingresado del dia %d es: %d\n",i+1,v);
    }
    valores[tam] = '\0';
    printf("Ahora calculamos el dia de mayor y menos lluvia, y ademas, el promedio\n");
    min = min_array(valores);
    max = max_array(valores);
    for (t = 0; t < tam; t++)
        aux = aux + valores[t];
    promedio = aux/tam;
    printf("El maximo de agua es %d, el minimo es %d y el promedio es %f \n",max,min,promedio);
}

// Ejercicio 4)a)

void ejercicio4a(){
    int tam = 0, p, b, aux, suma = 0;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d\n",&tam);
    int matriz[tam][tam];
    for(p = 0; p < tam; p++){
        for(b = 0; b < tam; b++){
            scanf("%d",&aux);
            matriz[p][b] = aux;
        }
    }
    for (p = 0; p < tam; p++){
        for (b = 0; b < tam; b++){
            printf(" %d ",matriz[p][b]);
        }
        printf("\n");
    }
    printf("Ahora calculamos la suma de la diagonal principal:");
    for (p = 0; p < tam; p++){
        for (b = 0; b < tam; b++){
            if (p == b)
                suma = suma + matriz[p][b];
        }
        printf("\n");
    }
    printf("La suma de los elementos de la diagonal principal es: %d\n", suma);
}

// Ejercicio 4)b)

void ejercicio4b (){
    int tam = 0, p, b, aux;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d",&tam);
    int matriz[tam][tam];
    printf("Ingrese los valores para cada posicion de la matriz: \n");
    for(p = 0; p < tam; p++){
        for(b = 0; b < tam; b++){
            scanf("%d",&aux);
            matriz[p][b] = aux;
        }
    }
    printf("La matriz original es: \n");
    for (p = 0; p < tam; p++){
        for (b = 0; b < tam; b++){
            printf(" %d ",matriz[p][b]);
        }
        printf("\n");
    }
    aux = 0;
    printf("La matriz transpuesta es: \n");
    for(p = 0; p <= tam/2; p++){
        for(b = 0; b < tam/2; b++){
            if (p != b) {
                aux = matriz[p][b];
                matriz[p][b] = matriz[b][p];
                matriz[b][p] = aux;
                }
        }
    }
    for (p = 0; p < tam; p++){
        for (b = 0; b < tam; b++){
            printf(" %d ",matriz[p][b]);
        }
        printf("\n");
    }
}

// Ejercicio 4)c)

int prod_vect(int a[], int b[]){
    int suma = 0, i = 0;
    while (a[i] != '\0' && b[i] != '\0'){
        suma = suma + a[i] * b[i];
        i++;
    }
    return suma;
}

//                                REVISAR
void ejercicio4c(){
    int dim, i, j, aux;
    printf("Ingrese la dimension de las matrices cuadradas: ");
    scanf("%d", &dim);
    
    int matriz_1[dim][dim], matriz_2[dim][dim];
    printf("Ingrese las dos matrices a multiplicar: \n");
    printf("Primera matriz: \n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%d",&aux);
            matriz_1[i][j] = aux;
        }
    }
    printf("Los valores ingresados para la prmera matriz son: \n");
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            printf(" %d ",matriz_1[i][j]);
        }
        printf("\n");
    }
    printf("Segunda matriz: \n");
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            scanf("%d",&aux);
            matriz_2[i][j] = aux;
        }
    }
    printf("Los valores ingresados para la segunda matriz son: \n");
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            printf(" %d ",matriz_2[i][j]);
        }
        printf("\n");
    }
    printf("El resultado del producto de las matrices es: \n");
    int resultado[dim][dim];
    for(i = 0; i < dim; i++){
//        int t = 0;
        for(j = 0; j < dim; j++){
            int t;
            int array_aux[dim];
            for (t = 0; t < dim; t++){
                array_aux[t] = matriz_2[t][j];
            }
            resultado[i][j] = prod_vect(matriz_1[i], array_aux);
        }
    }
    for (i = 0; i < dim; i++){
        for (j = 0; j < dim; j++){
            printf(" %d ",resultado[i][j]);
        }
        printf("\n");
    }
}

void ejercicio5a(){
    printf("Ingrese una frase: \n");
    char frase[256];
    scanf("%s\n", frase);
    printf("%s\n", frase);
}

void ejercicio5b(){
    printf("Ingrese una frase: \n");
    char frase[256];
    fgets(frase, 256, stdin);
    printf("La frase ingresada es: \n%s", frase);
}



int main(){
    //ejercicio1()
    
    /*
    printf("Ingrese tres nuemros\n");
    int x = 0, y = 0, z = 0;
    printf("Ingrese el valor de x: ");
    scanf("%d",&x);
    printf("\n");
    printf("Ingrese el valor de y: ");
    scanf("%d",&y);
    printf("\n");
    printf("Ingrese el valor de z: ");
    scanf("%d",&z);
    printf("\n");
    ejercicio1(x,y,z);
    return 0;
    */    
    
    //ejercicio2()
    
    /*
    int vleidos[10], valor,i;
    for (i=0; i<10; i++){
        scanf(" \n %d",&valor);
        vleidos[i]=valor;
        printf ("El valor leido es: %d \n",valor);
    }
    while (valor != 0){
        printf ("Ingrese un valor \n");
        scanf(" \n %d",&valor);
        for (int j=0; j<10; j++){
            if (valor==vleidos[j])
                printf (" Valor ocupa el lugar : %d del vector \n", j );
            else continue;
        }
    }
    return 0;
    */

//    ejercicio3();
    
//    int array[] = {1,2,3,4,5,'\0'};
//    printf("%d\n",len_array(array));
//    return 0;

//    ejercicio4a(); 

//    ejercicio4b();
//    int a[] = {1, 2, 3, 4, 5, '\0'};
//    int b[] = {1, 2, 3, 4, 5, '\0'};
//    printf("%d\n", prod_vect(a,b));

//    ejercicio4c();

//    ejercicio5a();

//    ejercicio5b();

// Ejercicio 6

/*    
    char a;
    short int b;
    int c;
    long int d;
    unsigned char e;
    unsigned short int f;
    unsigned int g;
    unsigned long int h;
    float i;
    double j;
    long double k;
    printf("Longitud de cada uno de los tipos basicos \n\n");
    printf("La longitud de char a= %d\n",sizeof(a));
    printf("La longitud de short int b= %d\n",sizeof(b));
    printf("La longitud de int c= %d\n",sizeof(c));
    printf("La longitud de long int d= %d\n",sizeof(d));
    printf("La longitud de unsigned char e= %d\n",sizeof(e));
    printf("La longitud de unsigned short int f= %d\n",sizeof(f));
    printf("La longitud de unsigned int g= %d\n",sizeof(g));
    printf("La longitud de unsigned long int h= %d\n",sizeof(h));
    printf("La longitud de float i= %d\n",sizeof(i));
    printf("La longitud de double j= %d\n",sizeof(j));
    printf("La longitud de long double k= %d\n",sizeof(k));
    printf("\nValores minimos y maximos de cada uno de los tipos\n\n");
    printf("Minimo y maximo de char a= %d\t\t%d\n",CHAR_MIN,CHAR_MAX);
    printf("Minimo y maximo de short int b=%d\t\t%d\n",SHRT_MIN,SHRT_MAX);
    printf("Minimo y maximo de int c= %d\t\t%d\n",INT_MIN,INT_MAX);
    printf("Minimo y maximo de long int d=%d\t\t%d\n",LONG_MIN,LONG_MAX);
    printf("Maximo de unsigned char e= %d\n",UCHAR_MAX);
    printf("Maximo de unsigned short int f= %d\n",USHRT_MAX);
    printf("Maximo de unsigned int g= %d\n",UINT_MAX);
    printf("Maximo de unsigned long int h= %d\n",ULONG_MAX);
    printf("Minimo y maximo de float i= %d\t\t%d\n",FLT_MIN,FLT_MAX);
    printf("Minimo y maximo de double j= %d\t\t%d\n",DBL_MIN,DBL_MAX);
    printf("Minimo y maximo de long double k=%d\t\t%d\n",LDBL_MIN,LDBL_MAX);
*/

















    return 0;
}
