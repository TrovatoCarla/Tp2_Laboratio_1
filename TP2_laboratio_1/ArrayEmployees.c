#ifndef ARRAYEMPLOYEES_C_INCLUDED
#define ARRAYEMPLOYEES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define LIMITE_EMPLEADOS 100
#define MAX_SALARIO 100000

/** \brief Inicializa todas las posiciones en 1
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleados
 * \return int retorna 0 si inicializo con exito y -1 si no pudo
 *
 */
int emp_initArray(Employee* empleado,int len)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        empleado[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
/** \brief Busca la primer posicion libre
 *
 * \param Employee* empleado array de empleados
 * \param len limite de empleados
 * \param *posicionLibre guarda por puntero la posicion libre
 * \return retorna 0 si encontro posicion libre,y -1 si no pudo
 *
 */

int emp_buscaPosicionLibre(Employee* empleado,int len,int* posicionLibre)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
    {
        if(empleado[i].isEmpty==1)
        {
            *posicionLibre=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
/** \brief Busca posicion ocupada
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleados
 * \return int Retorna 0 si encontro posicion ocupada,y -1 si no la encontro
 *
 */
int emp_buscaPosicionOcupada(Employee* empleado,int len)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
    {
        if(empleado[i].isEmpty==0)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

/** \brief Muestra datos de los empleados
 *
 * \param empleado Employee* array de emplados
 * \param len int limite de empleados
 * \return int retorna 0 si salio todo bien,y -1 si no
 *
 */
int emp_printEmployees(Employee* empleado,int len)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(empleado[i].isEmpty==0)
        {
            printf("\nPosicion %d:  Legajo: %d",i,empleado[i].idEmployees);
            printf("\n             Nombre: %s",empleado[i].name);
            printf("\n             Apellido: %s",empleado[i].lastName);
            printf("\n             Salario: %.2f",empleado[i].salary);
            printf("\n             Sector Nª %d\n",empleado[i].sector);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Da de alta a un empleado
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleados
 * \param posicionDisponible int posicion disponible para dar de alta al empleado
 * \return int Retorna 0 si la alta salio bien, y -1 si no salio bien
 *
 */
int emp_addEmployees(Employee* empleado,int len,int posicionDisponible)
{
    int retorno=-1;

    if(!emp_buscaPosicionLibre(empleado,LIMITE_EMPLEADOS,&posicionDisponible))
    {
        if(!getName("\nNombre del empleado: ","\nError,nombre invalido",MAXIMO_CARACTER,2,3,empleado[posicionDisponible].name))
        {
            if(!getApellido("\nApellido: ","\nApellido invalido",MAXIMO_CARACTER,2,3,empleado[posicionDisponible].lastName))
            {
                if(!getFloat("\nSalario: ","\nError,salario invalido",MAX_SALARIO,1000,3,&empleado[posicionDisponible].salary))
                {
                    if(!getInt("\nSector: ","Error,sector invalido",100,1,3,&empleado[posicionDisponible].sector))
                    {
                        empleado[posicionDisponible].isEmpty=0;
                        empleado[posicionDisponible].idEmployees=posicionDisponible;
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Busca empleado po ID
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleados
 * \param idEncontrado int* ID encontrado
 * \return int retorna 0 si encontro el ID,y -1 si no lo encontro
 *
 */
int emp_findEmployeeById(Employee* empleado,int len,int* idEncontrado)
{
    int i;
    int retorno=-1;
    int bufferId;

    if(getInt("\nIngrese ID a buscar: ","\nError,ID no encontrado",LIMITE_EMPLEADOS,0,3,&bufferId)==0)
    {
        for(i=0;i<len;i++)
        {
            if(bufferId==empleado[i].idEmployees)
            {
                *idEncontrado=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Modifica algun dato de un empleado
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleados
 * \param idAmodificar int ID del empleado a modificar
 * \return int retorna 0
 *
 */
int emp_modifyEmployee(Employee* empleado,int len,int idAmodificar)
{
    int opcion;
    char seguir='s';
    char bufferNuevoNombre[20];
    char bufferNuevoApellido[20];
    float bufferNuevoSalario;
    int bufferNuevoSector;

    emp_printEmployees(empleado,LIMITE_EMPLEADOS);


    if(emp_buscaPosicionOcupada(empleado,len)==0)
    {
        if(emp_findEmployeeById(empleado,LIMITE_EMPLEADOS,&idAmodificar)==0)
        {
            while(seguir=='s')
            {
                printf("\n 1- NOMBRE: ");
                printf("\n 2- APELLIDO: ");
                printf("\n 3- SALARIO: ");
                printf("\n 4- SECTOR: ");
                printf("\n 5- SALIR: ");

                do
                {
                    printf("\n Ingrese la opcion a modificar: ");
                    scanf("%d",&opcion);
                }while(opcion<1 || opcion>5);

                switch(opcion)
                {
                    case 1:
                        if(getName("\nIngrese nombre: ","\nError,nombre invalido",MAXIMO_CARACTER,2,3,bufferNuevoNombre)==0)
                        {
                            strncpy(empleado[idAmodificar].name,bufferNuevoNombre,MAXIMO_CARACTER);
                            printf("\n NOMBRE MODIFICADO CORRECTAMENTE");
                        }
                        break;
                    case 2:
                        if(getApellido("\nIngrese apellido: ","\nError,apellido invalido",MAXIMO_CARACTER,2,3,bufferNuevoApellido)==0)
                        {
                            strncpy(empleado[idAmodificar].lastName,bufferNuevoApellido,MAXIMO_CARACTER);
                            printf("\nAPELLIDO MODIFICADO CORRECTAMENTE");
                        }
                        break;
                    case 3:
                        if(getFloat("\nIngrese salario: ","\nError,salario invalido",MAX_SALARIO,1000,3,&bufferNuevoSalario)==0)
                        {
                            empleado[idAmodificar].salary=bufferNuevoSalario;
                            printf("\nSALARIO MODIFICADO CORRECTAMENTE");
                        }
                        break;
                    case 4:
                        if(getInt("\nIngrese sector: ","\nError,sector invalido",100,1,3,&bufferNuevoSector)==0)
                        {
                            empleado[idAmodificar].sector=bufferNuevoSector;
                            printf("\nSECTOR MODIFICADO CORRECTAMENTE");
                        }
                        break;
                    case 5:
                        seguir='n';
                        break;
                }
            }
        }
        else
        {
            printf("\nERROR,ID NO ENCONTRADO");
        }
    }
    else
        printf("\nNo se ningun empleado cargado para la modificacion\n");

    return 0;
}

/** \brief Da de baja a un empleado
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleado
 * \param idBaja int ID a dar de baja
 * \return int retorna 0 si se dio de baja correctamente,y -1 si no pudo
 *
 */
int emp_removeEmployee(Employee* empleado,int len,int idBaja)
{
    int retorno=-1;

        if(emp_findEmployeeById(empleado,LIMITE_EMPLEADOS,&idBaja)==0)
        {
            empleado[idBaja].isEmpty=1;
            retorno=0;
        }
        else
        {
            printf("\n ID NO ENCONTRADO");
        }


return retorno;
}

/** \brief Ordena alfabeticamente y por sector
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleados
 * \return int retorna 0 si se ordeno correctamente,y -1 si no pudo
 *
 */
int emp_ordenarPorDobleCriterio(Employee* empleado,int len)
{
    int retorno=-1;
    int i;
    Employee buffer;
    int flagSwap;

    if(empleado!=NULL && len>=0)
    {
        do
        {
            flagSwap=0;
            for (i=0; i<len-1;i++)
            {
                if( (empleado[i].sector<empleado[i+1].sector))
                {
                    flagSwap=1;
                    buffer = empleado[i];
                    empleado[i] = empleado[i+1];
                    empleado[i+1] = buffer;
                }
                else if(strcmp(empleado[i].lastName,empleado[i+1].lastName) == 0)
                {
                    if(strcmp(empleado[i].lastName,empleado[i+1].lastName)>0)
                    {
                        flagSwap=1;
                        buffer = empleado[i];
                        empleado[i] = empleado[i+1];
                        empleado[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

/** \brief Calcula total y promedio de los salarios de los empleados
 *
 * \param empleado Employee* array de empleados
 * \param len int limite de empleados
 * \return int retorna 0 si salio todo bien,y -1 si no pudo
 *
 */
int emp_totalYpromedioDeSalario(Employee* empleado,int len)
{
    int i;
    float acumuladorDeSalarios=0;
    int acumuladorDeEmpleados=0;
    int contadorDeEmpleadosPromedio=0;
    int retorno=-1;
    float promedio;

    if(emp_buscaPosicionOcupada(empleado,len)==0)
    {
        if(empleado!=NULL && len>0)
        {
            for(i=0;i<len;i++)
            {
                if((empleado[i].salary>0) && (empleado[i].isEmpty==0))
                {
                    acumuladorDeSalarios=acumuladorDeSalarios+empleado[i].salary;
                    acumuladorDeEmpleados++;
                    retorno=0;
                }
            }
        }
        promedio=acumuladorDeSalarios/acumuladorDeEmpleados;

        for(i=0;i<len;i++)
        {
            if(empleado[i].salary>promedio)
            {
                contadorDeEmpleadosPromedio++;
            }
        }

        printf("\nEl total de los salarios es: %.2f\n",acumuladorDeSalarios);
        printf("\nEl promedio de los salarios es: %.2f\n",promedio);
        printf("\nEl total de empleados que superan el salario promedio es: %d\n",contadorDeEmpleadosPromedio);

    }
    else
        printf("\nNo se ha cargado ningun empleado para informar\n");


    return retorno;
}



#endif // ARRAYEMPLOYEES_C_INCLUDED
