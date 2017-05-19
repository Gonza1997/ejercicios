#include <stdio.h>
#include <stdlib.h>
#define T 5

int main()
{
    int* punt;
    int* p;
    int* aux;
    int i;

    punt = (int*) malloc(sizeof(int) * T);

    if(punt!=NULL)
    {
        for(i=0; i<T; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", punt+i);
        }

        for(i=0; i<T; i++)
        {
            printf("%d\n", *(punt+i));
        }


    }
    else
    {
        printf("No hay memoria disponible.");
    }

    printf("Ingrese el numero que desea eliminar: ");
        scanf("%d", p);

        for(i=0; i<T; i++)
        {
            if((*p) == *(punt+i))
            {
                aux = (punt+i);
            }
        }
        for(i=0; i<T; i++)
        {
            printf("%d\n", *(p+i));
        }

}
