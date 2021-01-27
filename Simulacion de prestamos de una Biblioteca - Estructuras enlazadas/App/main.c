#include <stdio.h>
#include <stdlib.h>
#include "socios.h"
#include "autores.h"
#include "libros.h"
#include "prestamos.h"
#include "funcionesGet.h"
#define CANTIDAD_PRESTAMOS 20
#define CANTIDAD_LIBROS 7
#define CANTIDAD_SOCIOS 10
#define CANTIDAD_AUTORES 7

int main()
{
    int opcion;

    eSocio arraySocios[CANTIDAD_SOCIOS];
    eAutor arrayAutores[CANTIDAD_AUTORES];
    eLibro arrayLibros[CANTIDAD_LIBROS];
    ePrestamo arrayPrestamos[CANTIDAD_PRESTAMOS];

    socio_init(arraySocios,CANTIDAD_SOCIOS);
    autor_init(arrayAutores,CANTIDAD_AUTORES);
    libro_init(arrayLibros,CANTIDAD_LIBROS);
    prestamo_init(arrayPrestamos,CANTIDAD_PRESTAMOS);

    socio_hardcodearDatos(arraySocios,6);
    autor_hardcodearDatos(arrayAutores,6);
    libro_hardcodearDatos(arrayLibros,6);
    prestamo_hardcodearDatos(arrayPrestamos,6);

    do
    {
        system("cls");
        printf("\t-MENU PRINCIPAL-\n");
        opcion= getValidIntOpcion("\n1-ADMINISTRAR SOCIO\n2-ADMINISTRAR AUTORES\n3-ADMINISTRAR LIBROS\n4-PRESTAMOS DE LIBRO\n5-LISTAR\n6-SALIR\n","ERROR\nOPCION NO VALIDA",1,6);

        switch(opcion)
        {
        case 1:
            socio_admin(arraySocios,arrayAutores,arrayLibros,CANTIDAD_SOCIOS,CANTIDAD_LIBROS,CANTIDAD_AUTORES);
            system("cls");
            break;

        case 2:
            autor_admin(arrayAutores,CANTIDAD_AUTORES);
            system("cls");
            break;

        case 3:
            libro_admin(arrayLibros,arrayAutores,CANTIDAD_AUTORES,CANTIDAD_LIBROS);
            system("cls");
            break;

        case 4:
            system("cls");
            prestamo_alta(arrayPrestamos,arrayLibros,CANTIDAD_PRESTAMOS,CANTIDAD_AUTORES,CANTIDAD_LIBROS,CANTIDAD_SOCIOS);
            break;

        case 5:
            system("cls");
            prestamo_admin(arrayPrestamos,arrayLibros,arraySocios,CANTIDAD_PRESTAMOS,CANTIDAD_LIBROS,CANTIDAD_SOCIOS);
            break;
        }
    }while(opcion!=6);

    return 0;
}
