#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct{
            int dia;
            int mes;
            int anio;
}eFecha;


typedef struct{
        char name[31];
        char lastName[31];
        int isEmpty;
        char sexo[3];
        int idUnico;
        int telefono;
        char email[31];
        eFecha fechaAsociado;
        int cantidadPrestamos;
}eSocio;

#endif // SOCIOS_H_INCLUDED

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "autores.h"
#include "libros.h"


int socio_array_generarProximoId(void);
int socio_init(eSocio* ,int cantidad);
int socio_findById(eSocio* ,int cantidad,int id);
int socio_findIsEmpty(eSocio* ,int cantidad);
int socio_remove(eSocio* ,int cantidad,int id);
int socio_add(eSocio* ,int cantidad);
void socio_hardcodearDatos(eSocio* , int cantidad);
int socio_modificar(eSocio* , int cantidad,int idAux);
void socio_listar(eSocio* ,int cantidad);
void socio_admin(eSocio* socios,eAutor* autores,eLibro* libros,int cantidadSocios,int cantidadLibros,int cantidadAutores);
void socio_ordenar(eSocio* socios,int cantidad);
