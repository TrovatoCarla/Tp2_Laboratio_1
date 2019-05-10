#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 6
#define MAXIMO_CARACTER 100
#define TRUE 1
#define FALSE 0


int isValidStringInt(char cadena[])
{
    int i=0;
    while(cadena[i]!= '\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')

            return 0;
      i++;
    }
    return 1;
}
int isValidInt(int numero, int maximo)
{
    int i;
   for(i=0;i<maximo;i++)
   {
        if(numero<'0' || numero>'9')
        {
            return 0;
        }
   }
    return 1;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    int retorno=1;
   if(numero<maximo && numero>minimo)
   {
    retorno=0;
   }

    return retorno;

}

int isValidChar(char aux,int maximo)
{
    int i;
    for(i=0;i<maximo;i++)
    {
       if((aux<'a' || aux>'z') && (aux<'A' || aux>'Z'))
       {
            return 0;
       }
    }
    return 1;
}

int isValidStringChar(char cadena[])
{
   int i;

   while(cadena[i]!='\0')
   {
        if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))

            return 0;
    i++;
   }
   return 1;
}

int isValidNombre(char *cadena)
{
    int retorno= TRUE;
    int i;

    for(i=0;cadena[i]!= '\0';i++)
    {
        if((cadena[i] <'A' || cadena[i] >'Z') && (cadena[i] <'a' || cadena[i] >'z'))
        {
            if(cadena[i]<= '9' && cadena[i]>='0')
            {
                retorno= FALSE;
            }
        }
    }
    return retorno;
}

int isValidApellido(char* cadena)
{
    int retorno= TRUE;
    int i;

    for(i=0;cadena[i]!= '\0';i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A' || cadena[i]>'Z'))
        {
            if(cadena[i]<'0' &&  cadena[i]>'9')
            {
                retorno=FALSE;
            }
        }
    }
    return retorno;
}

int isTelefono(char cadena[])
{
    int i=0;
    int retorno=-1;
    int contadorGuiones=0;

    while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ') && (cadena[i]<'0' || cadena[i]>'9') && (cadena[i]<'a' || cadena[i]>'z'))
        {
            retorno=0;
        }
        if(cadena[i]=='-')
        {
            contadorGuiones++;
        }
     i++;
    }
       if(contadorGuiones==1)
        {
            retorno=1;
        }
        return retorno;
}
