#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include "funcionesUTN.h"
#include "misValid.h"
#define LIMITE_EMPLEADOS 100
#define MAX_SALARIO 100000


int main()
{
    Employee empleado[MAXIMO_CARACTER];
    int posicionLibre=-1;
    int auxID;
    char seguir='s';
    int opcion;
    int idParaModificar=-1;
    int idRemove=-1;
    int opcion2;

    if(emp_initArray(empleado,LIMITE_EMPLEADOS)==0)
    {
        printf("\n INICIALIZACION EXITOSA");
    }

    while(seguir=='s')
    {
        printf("\n  MENU \n");
        printf("\n 1. ALTAS");
        printf("\n 2. MODIFICAR");
        printf("\n 3. BAJA");
        printf("\n 4. INFORMAR\n");

        do
        {
            printf("\n Ingrese la opcion a realizar: ");
            scanf("%d",&opcion);
            system("clear");
        }while(opcion<1 || opcion>4);

        switch(opcion)
        {
            case 1:
                 if(emp_addEmployees(empleado,LIMITE_EMPLEADOS,posicionLibre)==0)
                {
                    printf("\n ALTA EXITOSA\n");
                    empleado[posicionLibre].idEmployees=auxID;
                    auxID++;
                }
               break;
            case 2:
                emp_modifyEmployee(empleado,LIMITE_EMPLEADOS,idParaModificar);
                break;
            case 3:
                if(emp_buscaPosicionOcupada(empleado,LIMITE_EMPLEADOS)==0)
                {
                    if(emp_removeEmployee(empleado,LIMITE_EMPLEADOS,idRemove))
                    {
                        printf("\nBAJA EXITOSA");
                    }
                }
                else
                {
                    printf("\nNo hay empleados cargados\n");
                }
                emp_printEmployees(empleado,LIMITE_EMPLEADOS);
                break;
            case 4:
                if(emp_buscaPosicionOcupada(empleado,LIMITE_EMPLEADOS)==0)
                {
                     do
                    {
                        printf("\n Indique dato a informar: \n\n1-Listado de empleados ordenados\n2-Total y promedio de salarios\n");
                        scanf("%d",&opcion2);
                        system("clear");
                    }while(opcion2<1 || opcion2>2);

                        switch(opcion2)
                        {
                            case 1:
                                emp_ordenarPorDobleCriterio(empleado,LIMITE_EMPLEADOS);
                                emp_printEmployees(empleado,LIMITE_EMPLEADOS);
                                break;

                            case 2:
                                emp_totalYpromedioDeSalario(empleado,LIMITE_EMPLEADOS);
                                break;
                        }
                }
                else
                {
                    printf("\nNo hay empleados cargados para informar\n");
                }
        }
    }
    return 0;
}

