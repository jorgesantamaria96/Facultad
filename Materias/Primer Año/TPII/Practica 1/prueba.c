#include <stdio.h>

// Prueba en clase 15/8

//revisar
void f(int **x){
    printf("direccion: %p\nvalor: %d\n", x, *x);
    **x = 10;
    printf("direccion: %p\nvalor: %d\n", x, *x);
    int *j;
    *j = 20;
    printf("direccion: %p\n", j);
    *x = j;
}

void g(){
    int *x;
    *x = 5;
    printf("direccion: %p\nvalor: %d\n", &x, x);
    f(x);
//    printf("direccion: %p\nvalor: %d\n", &x, x);
    printf("%d\n", x);
    printf("%d\n", *x);
}

int main(){
    g();
}

/*
int main(){
    int x,y,num=1;
    for (x = 1; x <= 10; x++){
        for (y = 1; y <= 10; y++){
            printf(" %d X %d = %d \n", x, y, x*y);
            num++;
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
*/
