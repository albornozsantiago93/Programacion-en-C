#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "entidad.h"
#include "funcionesGet.h"

Llamadas* llamadas_new()
{
    return (Llamadas*)malloc(sizeof(Llamadas));
}

void llamadas_delete(Llamadas* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

int llamadas_setIdLlamada(Llamadas* this, int numeroAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->idLlamada= numeroAux;
        retorno=1;
    }
    return retorno;
}

int llamadas_getIdLlamada(Llamadas* this, int* idLlamadaAux)
{
    int retorno=-1;

    if(this!=NULL && idLlamadaAux!=NULL)
    {
        *idLlamadaAux= this->idLlamada;
        retorno=1;
    }
    return retorno;
}



int llamadas_setSolucion(Llamadas* this, char* solucionAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(this->solucionado,solucionAux);
        retorno=1;
    }
    return retorno;
}

int llamadas_getSolucion(Llamadas* this, char* solucionAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(solucionAux,this->solucionado);
        retorno=1;
    }
    return retorno;
}

int llamadas_setFecha(Llamadas* this, char* fechaAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(this->fecha,fechaAux);
        retorno=1;
    }
    return retorno;
}

int llamadas_getFecha(Llamadas* this, char* fechaAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        strcpy(fechaAux,this->fecha);
        retorno=1;
    }
    return retorno;
}



int llamadas_setIdCliente(Llamadas* this, int idAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->idCliente= idAux;
        retorno=1;
    }
    return retorno;
}

int llamadas_getIdCliente(Llamadas* this, int* idAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *idAux= this->idCliente;
        retorno=1;
    }
    return retorno;
}

int llamadas_setIdProblema(Llamadas* this, int idAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->idProblema= idAux;
        retorno=1;
    }
    return retorno;
}

int llamadas_getIdProblema(Llamadas* this, int* idAux)
{
    int retorno=-1;

    if(this!=NULL)
    {
        *idAux= this->idProblema;
        retorno=1;
    }
    return retorno;
}

int llamadas_noEnciendePc(void *this)
{
    int retorno=-1;
    int problemaAux;

    if(this!=NULL)
    {
        llamadas_getIdProblema(this,&problemaAux);
        if(problemaAux==1)
        {
            retorno=1;
        }
    }
    return retorno;
}

int llamadas_noFuncionaMouse(void* this)
{
    int retorno=-1;
    int problemaAux;

    if(this!=NULL)
    {
        llamadas_getIdProblema(this,&problemaAux);
        if(problemaAux==2)
        {
            retorno=1;
        }
    }
    return retorno;
}

int llamadas_noFuncionaTeclado(void* this)
{
    int retorno=-1;
    int problemaAux;

    if(this!=NULL)
    {
        llamadas_getIdProblema(this,&problemaAux);
        if(problemaAux==3)
        {
            retorno=1;
        }
    }
    return retorno;
}

int llamadas_noHayInternet(void* this)
{
    int retorno=-1;
    int problemaAux;

    if(this!=NULL)
    {
        llamadas_getIdProblema(this,&problemaAux);
        if(problemaAux==4)
        {
            retorno=1;
        }
    }
    return retorno;
}

int llamadas_noFuncionaTelefono(void* this)
{
    int retorno=-1;
    int problemaAux;

    if(this!=NULL)
    {
        llamadas_getIdProblema(this,&problemaAux);
        if(problemaAux==5)
        {
            retorno=1;
        }
    }
    return retorno;
}



