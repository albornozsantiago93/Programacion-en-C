#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <ctype.h>
#include "employee.h"
#include "funcionesGet.h"


static int idAutoincrementable= 0;

/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* empleados,int cantidad)
{
    int i, retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            empleados[i].isEmpty=ESTADO_LIBRE;
        }
        retorno=0;

    return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(eEmployee* empleados,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= findIsEmpty(empleados,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("Ingrese nombre:\n","Error\nCaracter no valido",empleados[posicionAux].name);
            getValidString("Ingrese apellido:\n","Error\nCaracter no valido",empleados[posicionAux].lastName);
            empleados[posicionAux].salary= getValidFloat("Ingrese sueldo:\n","Error\nCaracter no valido");
            empleados[posicionAux].id= array_generarProximoId();
            system("cls");
            empleados[posicionAux].sector= getValidIntOpcion("ELIGA SU SECTOR\nSECTOR 1\nSECTOR 2\nSECTOR 3\nSECTOR 4\n","ERROR\nOpcion no valida\n",1,4);
            empleados[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            printf("SE HA CARGADO EMPLEADO\n\n");
            retorno=0;
        }
    }
    return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* empleados,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(empleados[i].id== id)
            {
                retorno= id;
                break;
            }
        }

     return retorno;
 }


 /** \brief find an Employee by Id en returns the free place position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findIsEmpty(eEmployee* empleados,int cantidad)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(empleados[i].isEmpty==ESTADO_LIBRE)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* empleados,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(empleados[i].id==id)
             {
                 empleados[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }

     return retorno;
 }

 /** \brief modifica datos en el arrey de empleados
 * \param list employee*
 * \param cantidad int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int modificarEmployee(eEmployee* empleados, int cantidad,int id)
{
    int retorno=-1,opcion;

    id= findEmployeeById(empleados,cantidad,id);

    if(id!= -1 && id>0)
    {
        do
        {
            opcion= getValidIntOpcion("Que desea modificar\n1-NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SECTOR\n5-SALIR\n","Opcion no valida\n",1,5);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("Ingrese nombre:\n","Error\nCARACTER NO VALIDO\n",empleados[id-1].name);
                break;

            case 2:
                system("cls");
                getValidString("Ingrese apellido:\n","Error\nCARACTER NO VALIDO\n",empleados[id-1].lastName);
                break;

            case 3:
                system("cls");
                empleados[id-1].salary= getValidFloat("Ingrese sueldo: \n","Error\nCARACTER NO VALIDO");
                break;

            case 4:
                system("cls");
                empleados[id-1].sector= getValidIntOpcion("Sector\nSECTOR 1\nSECTOR 2\nSECTOR 3\nSECTOR 4\n","ERROR\nOpcion no valida\n",1,4);
                break;
            }
        }
        while(opcion!=5);
        retorno=0;
    }
    return retorno;
}

 /** \brief modifica datos en el arrey de empleados
 * \param list employee*
 * \param cantidad int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
void ordenarArrayPorNombre(eEmployee* empleados,int cantidadEmpleados)
{
    eEmployee empleadoAux;

    int i,j;

        for(i=0; i < cantidadEmpleados - 1; i++)
        {
            if(empleados[i].isEmpty == ESTADO_LIBRE)
            {
                continue;
            }
            for(j=i+1; j < cantidadEmpleados; j++)
            {
                if(empleados[j].isEmpty == ESTADO_LIBRE)
                {
                    continue;
                }
                if(strcmp(empleados[j].lastName,empleados[i].lastName)<0)
                {
                    empleadoAux = empleados[j];
                    empleados[j] = empleados[i];
                    empleados[i] = empleadoAux;
                }
                else if(strcmp(empleados[j].lastName,empleados[i].lastName) == 0)
                {
                    if(empleados[i].sector > empleados[j].sector)
                    {
                        empleadoAux = empleados[j];
                        empleados[j] = empleados[i];
                        empleados[i] = empleadoAux;
                    }
                }
            }
        }
}

  /** \brief print the list of employees array
 *
 * \param lista de empleados*
 * \param int cantidadEmpleados
 * \param  lista de sectores*
 * \param int cantidadSectores
 * \return void
 *
*/
void printListEmployee(eEmployee* empleados,int cantidadEmpleados, eSector* sectores,int cantidadSectores)
{
    int i;

    for(i=0; i<cantidadEmpleados; i++)
    {
        if(empleados[i].isEmpty==ESTADO_OCUPADO)
        printEmployee(empleados[i],sectores,cantidadSectores);
    }
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param list sectores*
* \param cantidad int
* \return void
*
*/
void printEmployee(eEmployee empleado,eSector* sectores,int cantidad)
{
    int i;
    char descripcionAux[21];

    for(i=0; i<cantidad; i++)
    {
        if(empleado.sector== sectores[i].idSector)
        {
            strcpy(descripcionAux,sectores[i].descripcion);
        }
    }
    printf("Nombre: %s \nApellido: %s\nSector: %s \nSalario:%.2f\nID: %d\n\n",empleado.name,empleado.lastName,descripcionAux,empleado.salary,empleado.id);
}

/** \brief Obtiene el menor valor del array del elemento salary
*
* \param list Employee*
* \param list cantidad int
* \param
* \return float. (-1)ERROR o !=-1
*
*/

float getSalaryMinimo(eEmployee* empleados,int cantidad)
{
    int i;
    float retorno=-1, salaryAux;


    for(i=0;i<cantidad;i++)
    {
        if(empleados[i].isEmpty == ESTADO_OCUPADO)
        {
            salaryAux= empleados[i].salary;
            break;
        }
    }

    if(salaryAux == -1)
        return retorno;

    for(i=0;i<cantidad;i++)
    {
        if(salaryAux>empleados[i].salary && empleados[i].isEmpty==ESTADO_OCUPADO)
        {
            salaryAux = empleados[i].salary;
        }
    }
    return salaryAux;
}

/** \brief Obtiene el menor valor del array del elemento salary
*
* \param list Employee*
* \param list cantidad int
* \param
* \return float. (-1)ERROR o !=-1
*
*/

float getSalaryMaximo(eEmployee* empleados,int cantidad)
{
    int i;
    float retorno=-1, salaryAux;


    for(i=0;i<cantidad;i++)
    {
        if(empleados[i].isEmpty == ESTADO_OCUPADO)
        {
            salaryAux= empleados[i].salary;
            break;
        }
    }

    if(salaryAux == -1)
        return retorno;

    for(i=0;i<cantidad;i++)
    {
        if(salaryAux<empleados[i].salary && empleados[i].isEmpty==ESTADO_OCUPADO)
        {
            salaryAux = empleados[i].salary;
        }
    }
    return salaryAux;
}

/**
 * \brief Busca el precio promedio
 * \param productArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay productos activos (-1) y si lo hay el precio de ese producto
 *
 */

float getPromedio(eEmployee* empleados,int cantidad)
 {
     int i;
     float acumulador=0,promedio=0;
     int contadorEmpleados=0;

     for(i=0;i<cantidad;i++)
     {
         if(empleados[i].isEmpty== ESTADO_OCUPADO)
         {
             acumulador= acumulador+ empleados[i].salary;
             contadorEmpleados ++;
         }
     }
     if(contadorEmpleados==0)
        return -1;

     promedio= acumulador/(float)contadorEmpleados;

     return promedio;
 }



