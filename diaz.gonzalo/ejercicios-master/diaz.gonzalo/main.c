#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamiento.h"
#define T 20
#define ALPHA_ROMEO
#define FERRARI
#define AUDI
#define OTRO



int main()
{
    ePropietario duenio[T];
    eAuto autos[T];
    inicializarEstado(duenio, T);
    char seguir = 's', opcion, flag = 0, flagAuto = 0;
    int i, lugar, aux;


    while(seguir=='s')
    {
        menu();

        scanf("%d", &opcion);
        fflush(stdin);

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
            {
                flagAuto = 1;
                ingreso(duenio, autos);
            }

            else
                printf("Primero debe realizar una alta.");
            break;
        case 4:
            if(flag != 0)
            {
                if(flagAuto != 0)
                    egreso(autos, duenio);
                else
                    printf("Primero debe realizar un alta de auto.");
            }

            else
                        printf("Primero debe realizar una alta.");

            break;
        case 5:

            informar(duenio, autos);

            break;
        case 6:
            seguir = 'n';
            break;


        }
    }
}


