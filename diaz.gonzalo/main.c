#include <stdio.h>
#include <stdlib.h>
#include "estacionamiento.h"
#define T 20
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4



int main()
{
    ePropietario duenio[T];
    eAuto autos[T];
    inicializarEstado(duenio, T);
    char seguir = 's', opcion, flag = 0;
    int i, lugar, aux;


    while(seguir=='s')
    {
        menu();

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            flag = 1;
            alta(duenio);
            break;
        case 2:
            if(flag != 0)
            modificar(duenio);
            else
                printf("Primero debe realizar una alta.");
            break;
        case 3:
            if(flag != 0)
            ingreso(duenio, autos);
            else
                printf("Primero debe realizar una alta.");
            break;
        case 4:
            printf("Ingrese la patente del auto a retirar: ");
            gets(aux);

            break;
        case 5:
            seguir = 'n';
            break;

        }
    }
}


