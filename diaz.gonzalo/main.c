#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estacionamiento.h"
#define T 3
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

        char apellidos[T][20] = {"Diaz", "Gomez", "Lopez"};
        char direccion[T][50] = {"direccion1", "direccion2", "direccion3"};
        int estado[T] = {1, 1, 1};
        int id[T] = {101, 102, 103};
        char nombre[T][10] = {"Pepe", "Juan", "Fulano"};
        int long long tarjeta[T] ={123456789101, 987654321987, 321654987321};
        int hora[T]={1, 5, 3};
        int idAutos[T]={101, 102, 103};
        char marca[T][15] ={"ALPHA_ROMEO", "OTRO", "AUDI"};
        char patente[T][10] ={"WTF999", "ASD123", "QWE987"};
        for(i=0; i<T; i++)
        {
            strcpy(duenio[i].apellido , apellidos[i]);
            strcpy(duenio[i].direcion , direccion[i]);
            duenio[i].id = id[i];
            duenio[i].estado = estado[i];
            strcpy(duenio[i].nombre, nombre[i]);
            duenio[i].tarjeta = tarjeta[i];
            autos[i].hora = hora[i];
            autos[i].id = idAutos[i];
            strcpy(autos[i].marca, marca[i]);
            strcpy(autos[i].patente, patente[i]);
        }



    while(seguir=='s')
    {
        menu();

        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion)
        {
        case 1:
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
           /* if(flag != 0)
            {
                if(flagAuto != 0)*/
                    egreso(autos, duenio);
              /*  else
                    printf("Primero debe realizar un alta de auto.");
            }

            else
                        printf("Primero debe realizar una alta.");*/

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


