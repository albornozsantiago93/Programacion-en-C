#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct{
        int idLibro;
        char tituloLibro[51];
        int idAutor;
        int isEmpty;
        int cantidadPrestamos;
}eLibro;
#endif // LIBROS_H_INCLUDED
#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0
#include "autores.h"

int libro_array_generarProximoId(void);
int libro_init(eLibro* libros ,int cantidad);
int libro_findById(eLibro* libros ,int cantidad,int id);
int libro_findIsEmpty(eLibro* libros ,int cantidad);
int libro_remove(eLibro* libros ,int cantidad,int id);
int libro_add(eLibro* libros,eAutor* autores,int cantidadAutores,int cantidadLibros);
void libro_hardcodearDatos(eLibro* libros , int cantidad);
int libro_modificar(eLibro* libros,eAutor* autores,int cantidadAutores,int cantidadLibros,int id);
void libro_admin(eLibro* libros,eAutor* autores,int cantidadAutores,int cantidadLibros);
void libro_listar(eLibro* libros,int cantidad);
void libro_ordenar(eLibro* libros,int cantidad);

