#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cantidad;
    char idAux[25],nombreAux[25],horasTrabajadasAux[25],sueldoAux[25];
    int retorno=-1;
    Employee* empleadoAux;


    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);//DESCARTO LOS TITULOS

        do
        {
            cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);

            if(cantidad==4)
            {
               empleadoAux= employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
               if(empleadoAux!=NULL)
               {
                   ll_add(pArrayListEmployee,empleadoAux);
               }
            }
        }while(!feof(pFile));

        retorno=0;
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* empleadoAux;


    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        do
        {
           empleadoAux= employee_new();

            if(fread(empleadoAux,sizeof(Employee),1,pFile)==1)
            {
               ll_add(pArrayListEmployee,empleadoAux);
            }
            else
            {
                employee_delete(empleadoAux);
            }
        }while(!feof(pFile));

        retorno=0;
    }
    return retorno;
}

