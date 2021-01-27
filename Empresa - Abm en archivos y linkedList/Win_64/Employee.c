#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "funcionesGet.h"

Employee* employee_new()
{
    return (Employee*)malloc(sizeof(Employee));
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!= NULL && nombre!=NULL)
    {
        if(validarStringLetras(nombre)==1)
        {
            retorno=0;
            strcpy(this->nombre,nombre);
        }
    }
    return retorno;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}


int employee_getNombre(Employee* this, char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!= NULL)
    {
        retorno=0;
        strcpy(nombre,this->nombre);
    }
    return retorno;

}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int idAutoincrementable= 0;

    if(this!= NULL)
    {
        if(idAutoincrementable>=0)
        {
            idAutoincrementable++;
            this->id= idAutoincrementable;
        }
        retorno= 0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;

    if(this!= NULL)
    {
        *id= this->id;
        retorno= 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;

    if(this!= NULL)
        if(horasTrabajadas>0)
        {
            this->horasTrabajadas= horasTrabajadas;
            retorno= 0;
        }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;

    if(this!= NULL)
    {
        *horasTrabajadas= this->horasTrabajadas;
        retorno= 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if(this!= NULL)
        if(sueldo>1)
        {
            this->sueldo= sueldo;
            retorno= 0;
        }

    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;

    if(this!= NULL)
    {
        *sueldo= this->sueldo;
        retorno=0;
    }
    return retorno;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* empleadoAux;

    empleadoAux= employee_new();

    if(validarInt(idStr)==0 && validarString(nombreStr)==0 && validarInt(horasTrabajadasStr)==0 && validarInt(sueldo)==0)
    {
        employee_setId(empleadoAux,atoi(idStr));
        employee_setNombre(empleadoAux,nombreStr);
        employee_setHorasTrabajadas(empleadoAux,atoi(horasTrabajadasStr));
        employee_setSueldo(empleadoAux,atof(sueldo));

        return empleadoAux;
    }
    employee_delete(empleadoAux);

    return NULL;

}



