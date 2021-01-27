#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "funcionesGet.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    FILE* pFile;

    if(path!= NULL && pArrayListEmployee!= NULL)
    {
        pFile= fopen(path,"r");

        if(pFile!=NULL)
        {
            if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0);
                retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        pFile= fopen(path,"rb");
        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            retorno=0;
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int horasTrabajadasAux, retorno=-1;
    int sueldoAux;
    char nombreAux[21];
    Employee* empleadoAux;

    if(pArrayListEmployee!= NULL)
    {
        getValidString("INGRESE NOMBRE:\n","ERROR\n",nombreAux);
        horasTrabajadasAux= getValidIntOpcion("INGRESE CANTIDAD DE HORAS TRABAJADAS:\n","ERROR\n",1,1000);
        sueldoAux= getValidIntOpcion("INGRESE SUELDO:\n","ERROR\n",100,99999999);
        empleadoAux= employee_new();

        if(empleadoAux!=NULL)
        {
            if(employee_setNombre(empleadoAux,nombreAux)==0)
                if(employee_setHorasTrabajadas(empleadoAux,horasTrabajadasAux)==0)
                    if(employee_setSueldo(empleadoAux,sueldoAux)==0)
                        if(employee_setId(empleadoAux,0)!=-1)
                        {
                            ll_add(pArrayListEmployee,empleadoAux);
                            retorno= 0;
                        }
        }
        else
        {
            employee_delete(empleadoAux);
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int retorno=-1,i,cantidad,sueldoAux,idAux,horasTrabajadasAux;
    char nomreAux[21];
    int idBuscador;
    int opcion=0;

    if(pArrayListEmployee!=NULL)
    {
        cantidad= ll_len(pArrayListEmployee);
        idBuscador= getValidIntOpcion("\nINGRESE ID:\t ","ERROR",0,cantidad);

        for(i=0;i<cantidad;i++)
        {
            empleadoAux= (Employee*)ll_get(pArrayListEmployee,i);
            if(employee_getId(empleadoAux,&idAux)!=-1)
            {
                if(idAux==idBuscador)
                {
                    getChar("ID ENCONTRADO\nPRESS ENTER");

                    do{
                        opcion=getValidIntOpcion("QUE DESEA MODIFICAR\n\n1-NOMBRE\n2-HS TRABAJADAS\n3-SUELDO\n4-SALIR","ERROR",1,4);

                         switch(opcion)
                        {
                            case 1:
                                system("cls");
                                getValidString("INGRESE NOMBRE:\n","ERROR",nomreAux);
                                employee_setNombre(empleadoAux,nomreAux);
                                break;

                            case 2:
                                system("cls");
                                horasTrabajadasAux= getValidIntOpcion("INGRESE CANTIDAD DE HORAS TRABAJADAS:\n","ERROR",0,10000);
                                employee_setHorasTrabajadas(empleadoAux,horasTrabajadasAux);
                                break;

                            case 3:
                                system("cls");
                                sueldoAux= getValidIntOpcion("INGRESE SUELDO:\n","ERROR",0,999999999);
                                employee_setSueldo(empleadoAux,sueldoAux);
                                break;
                        }

                    }while(opcion!=4);

                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int retorno=-1,i,cantidad, idAux;
    int idBuscador;

    if(pArrayListEmployee!=NULL)
    {
        cantidad= ll_len(pArrayListEmployee);
        idBuscador= getValidIntOpcion("\nINGRESE ID:\t ","ERROR",0,cantidad);

        for(i=0;i<cantidad;i++)
        {
            empleadoAux= (Employee*)ll_get(pArrayListEmployee,i);
            if(employee_getId(empleadoAux,&idAux)!=-1)
            {
                if(idAux==idBuscador)
                {
                    getChar("ID ENCONTRADO\nPRESS ENTER PARA ELIMINAR");
                    ll_remove(pArrayListEmployee,i);
                    retorno=0;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int retorno= -1,cantidad,idAux,sueldoAux,horasTrabajadasAux;
    int i;
    char nombreAux[21];

    if(pArrayListEmployee!=NULL)
    {
        cantidad= ll_len(pArrayListEmployee);

        for(i=0;i<cantidad;i++)
        {
            empleadoAux= (Employee*)ll_get(pArrayListEmployee,i);//PARSEO DATO A TIPO PUNTERO EMPLOYEE
            employee_getNombre(empleadoAux,nombreAux);
            employee_getHorasTrabajadas(empleadoAux,&horasTrabajadasAux);
            employee_getSueldo(empleadoAux,&sueldoAux);
            employee_getId(empleadoAux,&idAux);
            printf("%d %11s   %5d   %12d\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    FILE* pFile;
    Employee* empleadoAux;
    int i=0,cantidad;
    char nombreAux[21];
    int sueldoAux;
    int horasTrabajadoaAux;
    int idAux;


    if(path!= NULL && pArrayListEmployee!= NULL)
    {
        pFile= fopen(path,"w");
        cantidad= ll_len(pArrayListEmployee);//obtengo el largo del llEmployee

        if(pFile!=NULL)
        {
            fprintf(pFile,"ID  NOMBRE   HS  SUELDO\n");

            do
            {
                empleadoAux= ll_get(pArrayListEmployee,i);
                employee_getNombre(empleadoAux,nombreAux);
                employee_getHorasTrabajadas(empleadoAux,&horasTrabajadoaAux);
                employee_getSueldo(empleadoAux,&sueldoAux);
                employee_getId(empleadoAux,&idAux);
                i++;
                fprintf(pFile,"%d,%s,%d,%d\n",idAux,nombreAux,horasTrabajadoaAux,sueldoAux);

            }while(i<cantidad);

            fclose(pFile);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    int i, cantidad;
    Employee* empleadoAux;

    if(path!= NULL && pArrayListEmployee !=NULL)
    {
        pFile= fopen(path,"wb");

        if(pFile!=NULL)
        cantidad= ll_len(pArrayListEmployee);

        for(i=0;i<cantidad;i++)
        {
            empleadoAux= ll_get(pArrayListEmployee,i);

            if(empleadoAux!=NULL)
            {
                fwrite(empleadoAux,sizeof(Employee),1,pFile);
            }
        }
        fclose(pFile);
        retorno=0;
    }
    return retorno;
}

