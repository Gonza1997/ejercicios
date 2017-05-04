#include "estacionamiento.h"
#define T 20
#include <stdio.h>
#include <stdlib.h>
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

void menu()
{
    printf("\n1- Alta del Duenio\n");
    printf("2- Modificacion del Duenio\n");
    printf("3- Ingreso del Automovil\n");
    printf("4- Egreso del automovil\n\n");
    printf("5- Salir\n");

}

void alta(ePropietario duenio[])
{
    int lugar, i;
    lugar = espacio(duenio, T);
    if(lugar != -1)
    {
        printf("Ingrese la ID del duenio: ");
        scanf("%d", &duenio[lugar].id);
        fflush(stdin);
        printf("Ingrese el apellido del duenio: ");
        gets(duenio[lugar].apellido);
        fflush(stdin);
        printf("Ingrese el nombre del duenio: ");
        gets(duenio[lugar].nombre);
        fflush(stdin);
        printf("Ingrese la direccion del duenio: ");
        gets(duenio[lugar].direcion);
        fflush(stdin);
        printf("Ingrese el numero de tarjeta de credito del duenio: ");
        scanf("%d", &duenio[lugar].tarjeta);
        fflush(stdin);
        duenio[lugar].estado = 1;
    }
    else
    {
        printf("No hay mas espacio.");
    }
}

void ingreso(ePropietario duenio[], eAuto autos[])
{
    int lugar, i, j, opcion;
    lugar = espacio(duenio, T);
    if(lugar != '-1')
    {
        printf("Ingrese la patente del auto: ");
        scanf("%d", &autos[lugar].patente);
        fflush(stdin);
        printf("Ingrese la marca del auto: (1- Alpha Romeo, 2- Ferrari, 3- Audi, 4- Otros)");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
        autos[lugar].marca = ALPHA_ROMEO;
            break;
    case 2:
        autos[lugar].marca = FERRARI;
        break;
    case 3:
        autos[lugar].marca = AUDI;
            break;
    case 4:
        autos[lugar].marca = OTRO;
        break;
        }
        fflush(stdin);
        printf("Ingrese la ID del dueño: ");
        gets(autos[lugar].id);
        fflush(stdin);
        printf("Ingrese el horario de entrada: ");
        scanf("%d", &autos[lugar].hora);
        autos[lugar].hora = validarInt(autos[lugar].hora, 0, 25);
        fflush(stdin);

    }
}

void modificar(ePropietario duenio[])
{
    int aux, i, aux2;
    char confirmar, flag = 0;
    printf("Ingrese la id del duenio que desea modificar: ");
    scanf("%d", &aux);
    fflush(stdin);
    for(i=0; i<T; i++)
    {
        if(aux == duenio[i].id && duenio[i].estado == 1)
        {
            flag = 1;
            printf("Duenio encontrado: \n");
            printf("%d \t %s \t %s \t %s \t %d\n", duenio[i].id, duenio[i].apellido, duenio[i].nombre, duenio[i].direcion, duenio[i].tarjeta);
            printf("Ingrese el nuevo numero de tarjeta de credito: ");
            scanf("%d", &aux2);
            fflush(stdin);
            printf("Esta seguro que desea modificar? (s / n)");
            scanf("%c", &confirmar);
            tolower(confirmar);
            fflush(stdin);

            if(confirmar == 's')
            {
                duenio[i].tarjeta = aux2;
                break;
            }
            else
            {
                printf("Accion cancelada.");
                break;
            }
        }
        if(flag == 0)
        {
            printf("No se encontro el duenio.");
            break;
        }

    }
}

void inicializarEstado(ePropietario persona[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        persona[i].estado = 0;
    }
}

int espacio(ePropietario persona[], int tam)
{
    int lugar = -1, i;
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado == 0)
        {
            lugar = i;
            break;
        }
    }

    return lugar;
}

int validarInt(int numero, int max, int min)
{
    int i;
    while(numero < min || numero > max)
    {
        printf("Ingrese un numero valido: ");
        scanf("%d", &numero);
    }

    return numero;

}
