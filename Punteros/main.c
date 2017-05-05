#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* '*' Operador de Inacceso
        '&' Operador de Direcciones
                                    */
 /*   int a = 9;
    int* punt;
    int* otro;
    punt = &a;
    otro = punt;
    printf("%p\n", otro);
    printf("%p", otro-1); */

    /*1- Funcion cargar vectores
        2- Ordenar de menor a mayor
        3- Mostrar */

        void cargaVectores(int vector[]);
        void ordenaVectores(int vector);

    int x[5], i;
    int* p;
    p=x;

    for(i=0; i<5; i++)
    {
        *(p+i) = i;
        printf("%d\n", *(p+i));
    }





return 0;
}
