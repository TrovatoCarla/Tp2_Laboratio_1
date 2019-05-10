#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "funcionesUTN.h"
#include "misValid.h"
#define EMPLEADOS 6
#define MAXIMO_CARACTER 100
#define TRUE 1
#define FALSE 0

int getInt(char *mensaje,char *mensajeError,int maximo,int minimo,int reintentos,int *resultado)
{
    int auxiliar;
    int i;
    int retorno=-1;
        if(mensaje!=NULL &&
            mensajeError!=NULL &&
            maximo>=minimo &&
            reintentos>=0 &&
            resultado!=NULL)

            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%d",&auxiliar);
                if(isValidInt(auxiliar,maximo)==0)
                {
                    *resultado=auxiliar;
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                }
            }
    return retorno;
}

int getFloat(char *mensaje,char *mensajeError,float maximo,float minimo,int reintentos,float *resultado)
{
    float auxiliar;
    int i;
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>=0 && resultado!=NULL)
        {
            for(i=0;i<reintentos;i++)
            {
                printf("%s",mensaje);
                scanf("%f",&auxiliar);
                if(isValidFloat(auxiliar,maximo,minimo)==0)
                {
                    *resultado=auxiliar;
                    retorno=0;
                    break;
                }
                else
                    printf("%s",mensajeError);
            }
        }
    return retorno;
}

int getChar(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{
    char buffer;
    int retorno=-1;

        if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>0 && resultado!=NULL)
        {
           do
           {
               printf("%s",mensaje);
               scanf("%c",&buffer);
               if(isValidChar(buffer,maximo))
               {
                   *resultado=buffer;
                   retorno=0;
                   break;
               }
               else
                printf("%s",mensajeError);
           }while(reintentos>=0);
        }
    return retorno;
}

int getString(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{
    char buffer[MAXIMO_CARACTER];
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            __fpurge(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            buffer[strlen(buffer)-1]= '\0';
            if(strlen(buffer)<=maximo && strlen(buffer)>=minimo)
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }
     return retorno;
}

int getName(char *mensaje,char *mensajeError,char maximo,char minimo,int reintentos,char *resultado)
{
    int retorno=-1;
    char buffer[MAXIMO_CARACTER];

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>=0 && resultado!=NULL)
    {
       if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,buffer))
        {
            if(isValidNombre(buffer))
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
             }
             else
             {
                printf("%s",mensajeError);
             }
        }
    }
    return retorno;
}

int getApellido(char* mensaje,char* mensajeError,char maximo,char minimo,int reintentos,char* resultado)
{
    char buffer[MAXIMO_CARACTER];
    int retorno=-1;

    if(mensaje!=NULL && mensajeError!=NULL && maximo>minimo && reintentos>0 && resultado!=NULL)
    {
        if(!getString(mensaje,mensajeError,maximo,minimo,reintentos,buffer))
        {
            if(isValidApellido(buffer))
            {
                strncpy(resultado,buffer,maximo);
                retorno=0;
            }
        }
    }
        return retorno;
}

int muestraArray(char arrayStr[][MAXIMO_CARACTER],int limite)
{
    int i;

      for(i=0;i<limite;i++)
    {
        printf("%s",arrayStr[i]);
    }
    return 0;
}

int iniciarlizarArrays(char arrayStr [][MAXIMO_CARACTER], int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        strncpy(arrayStr[i],"\0",MAXIMO_CARACTER);
    }

    return 0;
}

int encuentraPosVacia(char arrayStr [] [MAXIMO_CARACTER],int* posicionDisponible, int limite)
{
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(strncmp(arrayStr[i],"\0",MAXIMO_CARACTER)==0)
        {
            *posicionDisponible=i;
            retorno=0;
            break;
         }
      else
         continue;
    }
    return retorno;
}

int buscaSiYaExiste(char arrayStr [] [MAXIMO_CARACTER],char* nombre,int* posicionNombreExistente,int limite)
{

    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(strncmp(arrayStr[i],nombre,MAXIMO_CARACTER)==0)
        {
            *posicionNombreExistente=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}

int ordenarArray(char arrayStr[] [MAXIMO_CARACTER],int limite)
{
    int i;
    int j;
    char auxiliar[MAXIMO_CARACTER];

        for(i=0;i<EMPLEADOS-1;i++)
    {
        j=i+1;
        if(strncmp(arrayStr[i],arrayStr[j],EMPLEADOS)>0)
        {
            strncpy(auxiliar,arrayStr[i],MAXIMO_CARACTER);
            strncpy(arrayStr[i],arrayStr[j],MAXIMO_CARACTER);
            strncpy(arrayStr[j],auxiliar,MAXIMO_CARACTER);
        }
    }
    return 0;
}



