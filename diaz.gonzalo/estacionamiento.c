#include "estacionamiento.h"
#define T 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA_ROMEO
#define FERRARI
#define AUDI
#define OTRO

void menu()
{
    printf("\n1- Alta del Duenio\n");
    printf("2- Modificacion del Duenio\n");
    printf("3- Ingreso del Automovil\n");
    printf("4- Egreso del automovil\n");
    printf("5- Informar.\n");
    printf("\n6- Salir");

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
    int lugar, i, aux, opcion, aux2, flag = 0;
    lugar = espacio(duenio, T);
    if(lugar != '-1')
    {
        printf("Ingrese la patente del auto: ");
        gets(autos[lugar].patente);
        fflush(stdin);
        printf("Ingrese la marca del auto: (1- Alpha Romeo, 2- Ferrari, 3- Audi, 4- Otros)");
        scanf("%d", &opcion);
        fflush(stdin);
        opcion = validarInt(opcion, 1, 4);
        switch(opcion)
        {
        case 1:
            strcpy(autos[lugar].marca, "ALPHA_ROMEO");
            break;
        case 2:
            strcpy(autos[lugar].marca, "FERRARI");
            break;
        case 3:
            strcpy(autos[lugar].marca, "AUDI");
            break;
        case 4:
            strcpy(autos[lugar].marca, "OTRO");
            break;
        }

        printf("Ingrese la ID del dueño: ");
        scanf("%d", &aux);
        fflush(stdin);
        autos[lugar].id = buscarDuenio(aux, duenio);

        printf("Ingrese el horario de entrada: ");
        scanf("%d", &aux);
        autos[lugar].hora = validarInt(aux, 1, 24);
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
        if(persona[i].estado =! 1)
        {
            lugar = i;
            break;
        }
    }

    return lugar;
}

int validarInt(int numero, int mini, int maxi)
{
    int i;
    while(numero < mini || numero > maxi)
    {
        printf("Reingrese un dato valido.");
        scanf("%d", &numero);
        fflush(stdin);
    }
    return numero;
}

int buscarDuenio(int aux, ePropietario duenio[])
{
    int i, flag = 0;

    for(i=0; i<T; i++)
    {

        if(aux == duenio[i].id)
        {
            printf("Se ha encontrado al duenio.");
            flag = 1;
            break;
        }


    }
    if(flag != 1)
    {
        printf("El duenio no existe. Reingrese");
        scanf("%d", &aux);
        fflush(stdin);
        buscarDuenio(aux, duenio);
    }
    return aux;

}

int buscarAuto(char aux[], eAuto autos[])
{
    int i, flag = 0;

    for(i=0; i<T; i++)
    {

        if(strcmp(aux, autos[i].patente) == 0)
        {
            printf("Se ha encontrado el auto.");
            flag = 1;
            return i;
        }


    }
    if(flag != 1)
    {
        printf("El auto no existe. Reingrese");
        gets(aux);
        buscarAuto(aux, autos);
    }



}

void egreso(eAuto autos[], ePropietario duenio[])
{
    int i, flag = 0, lugar, aux2, tiempo;
    char aux[10];
    printf("Ingrese la patente del auto a retirar: ");
    gets(aux);
    fflush(stdin);
    lugar = buscarAuto(aux, autos);
    printf("Ingrese el horario de salida.");
    scanf("%d", &aux2);
    fflush(stdin);

    while(aux2 < autos[lugar].hora || aux2 > 24)
    {
        printf("El auto no puede estar mas de un dia estacionado. Reingrese");
        scanf("%d", &aux2);
    }
    for(i=0; i<T; i++)
    {
        if(autos[lugar].id == duenio[i].id)
        {
            duenio[i].estado == 0;
            break;
        }
    }
    tiempo = aux2 - autos[lugar].hora;
    printf("El tiempo de estadia es de %d horas", tiempo);
    ticket(autos, duenio, lugar, tiempo);

}

void ticket(eAuto autos[], ePropietario duenio[], int lugar, int estadia)
{
    int i, aux, aux2 = estadia;
    for(i=0; i<T; i++)
    {
        if(duenio[i].id == autos[lugar].id)
        {
            aux = i;
            break;
        }

    }

    if(strcmp("ALPHA_ROMEO", autos[lugar].marca) == 0)
    {
        aux2 = estadia * 150;
    }

    if(strcmp("FERRARI", autos[lugar].marca) == 0)
    {
        aux2 = estadia * 175;
    }

    if(strcmp("AUDI", autos[lugar].marca) == 0)
    {
        aux2 = estadia * 200;
    }

    if(strcmp("OTRO", autos[lugar].marca) == 0)
    {
        aux2 = estadia * 250;
    }


    printf("\nTicket:\nNombre del propietario: %s\nPatente del auto: %s\nMarca del auto: %s\nValor de la estadia: %d\n", duenio[aux].nombre, autos[lugar].patente, autos[lugar].marca, aux2);

}

void informar(ePropietario duenio[], eAuto autos[])
{
    int i, lugar;
    printf("Hora: Patente: Nombre: Marca:\n\n");
    for(i=0; i<T; i++)
    {
        if(autos[i].id == duenio[i].id && duenio[i].estado == 1)
        {

            printf("%d \t", autos[i].hora);
            printf("%s \t", autos[i].patente);
            printf("%s \t", duenio[i].nombre);
            printf("%s \n", autos[i].marca);

        }

    }
}





void  ordenar(eAuto autos[])
{
    int i, j;
    eAuto aux;

    for(i=0; i<T-1; i++)
    {
        for(j=i+1; j<T; j++)
        {
            if(autos[i].hora < autos[j].hora)
            {
                aux = autos[i];
                autos[i] = autos[j];
                autos[j] = aux;
            }
        }
    }
}


