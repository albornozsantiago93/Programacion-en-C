#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct{
            int dia;
            int mes;
            int anio;
}eFechaPrestamo;

typedef struct{
        int idPrestamo;
        int idLibro;
        int idSocio;
        int isEmpty;
        eFechaPrestamo fecha;
}ePrestamo;

#endif // PRESTAMOS_H_INCLUDED

#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "socios.h"
#include "libros.h"

int prestamo_array_generarProximoId(void);
int prestamo_init(ePrestamo* ,int cantidad);
int prestamo_findIsEmpty(ePrestamo* ,int cantidad);
void prestamo_alta(ePrestamo* prestamos,eLibro* libros,int cantidadPrestamos,int cantidadAutores,int cantidadLibros,int cantidadSocios);
void prestamo_listarSocioLibro(ePrestamo* prestamos,eSocio* socios,eLibro* libros,int cantidadSocios,int cantidadLibros);
void prestamo_listarLibroSolicitadoSocio(eSocio* socios, eLibro* libros, ePrestamo* prestamos, int cantidadSocios, int cantidadLibros,int idSocio);
void prestamo_listarLibrosSolicitadosFecha(eSocio* socios, eLibro* libros, ePrestamo* prestamos, int cantidadSocios, int cantidadLibros,eFechaPrestamo);
void prestamo_listarSocioSolicitaronFecha(eSocio* socios, eLibro* libros, ePrestamo* prestamos, int cantidadSocios, int cantidadLibros,eFechaPrestamo);
void prestamo_admin(ePrestamo* prestamo,eLibro* libros,eSocio* socios,int cantidadPrestamos,int cantidadLibros,int cantidadSocios);
void prestamo_hardcodearDatos(ePrestamo* prestamos, int cantidad);
void prestamo_ordenarInsertion(eSocio* socios,int cantidad);
void prestamo_bubbleSort (eLibro* libros,int cantidad);
float prestamo_promedioDiario();
int prestamo_cantDiasNoSuperanPromedio(eLibro* libros,int cantidad);


void prestamo_calcularSolicutudesSocios(ePrestamo* prestamos,int cantidadPrestamos,eSocio* socios,int cantidadSocios,eLibro* libros,int cantidadLibros);
 void prestamo_listarSolicitudesSocios(eSocio* socios,int cantidadSocios);


 void prestamo_calcularSolicutudesLibros(ePrestamo* prestamos,int cantidadPrestamos,eSocio* socios,int cantidadSocios,eLibro* libros,int cantidadLibros);
 void prestamo_listarSolicitudesLibros(eLibro* libros,int cantidadLibros);
