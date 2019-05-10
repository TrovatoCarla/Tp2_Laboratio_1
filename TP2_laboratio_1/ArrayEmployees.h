#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int idEmployees;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;
}Employee;


int emp_initArray(Employee* empleado,int len);
int emp_buscaPosicionLibre(Employee* empleado,int len,int* posicionLibre);
int emp_addEmployees(Employee* empleado,int len,int posicionDisponible);
int emp_printEmployees(Employee* empleado,int len);
int emp_findEmployeeById(Employee* empleado,int len,int* idEncontrado);
int emp_modifyEmployee(Employee* empleado,int len,int idAmodificar);
int emp_removeEmployee(Employee* empleado,int len,int idBaja);
int emp_ordenarPorDobleCriterio(Employee* empleado,int len);
int emp_totalYpromedioDeSalario(Employee* empleado,int len);
int emp_buscaPosicionOcupada(Employee* empleado,int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
