#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "libros.h"
#include "autores.h"
#include "funcionesGet.h"

static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int libro_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, libros de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int libro_init(eLibro* libros ,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        libros[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, libros de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int libro_findIsEmpty(eLibro* libros,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(libros[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}


/** \brief encuentra por id un dato de la libros
 * \param eEmployee empleado, libros de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int libro_findById(eLibro* libros ,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(libros[i].isEmpty== ESTADO_OCUPADO && libros[i].idLibro== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }
/** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, libros de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int libro_remove(eLibro* libros,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(libros[i].idLibro==id)
             {
                 libros[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }


 /** \brief da por alta a un empleado en la libros de eEmpleados
 * \param eEmployee empleado, libros de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int libro_add(eLibro* libros,eAutor* autores,int cantidadAutores,int cantidadLibros)
{
    int posicionAux,retorno=-1;

    if(cantidadLibros>=0)
    {
        posicionAux= libro_findIsEmpty(libros,cantidadLibros);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE TITULO DE LIBRO:\n","\tERROR\nCARACTER NO VALIDO",libros[posicionAux].tituloLibro);
            libros[posicionAux].idLibro= libro_array_generarProximoId();
            system("cls");
            printf("ID\tNOMBRE\tAPELLIDO\n");
            autor_listar(autores,cantidadAutores);
            libros[posicionAux].idAutor= getValidIntOpcion("ESCOGA ID DE AUTOR\n","ERROR\nID NO VALIDO",0,cantidadAutores);
            libros[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO LIBRO\n\n");
        }
    }
    return retorno;
}


 /** \brief carga datos hardcodeados en la libros de empleados
 * \param eEmployee empleado, libros de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void libro_hardcodearDatos(eLibro* libros , int cantidad)
{
    int i;
    char titulo[][50]= {"Luces de bohemia","Crimen y castigo","La comedia humana","Preludio a la fundacion","Cumbres borrascosas","100 anios de soledad"};
    int idAutor[]={1,2,3,4,5,6};


    for(i=0; i<cantidad; i++)
    {
        libros[i].idLibro=libro_array_generarProximoId();
        strcpy(libros[i].tituloLibro,titulo[i]);
        libros[i].idAutor= idAutor[i];
        libros[i].isEmpty= ESTADO_OCUPADO;
    }
}


 /** \brief modifica los datos de un empleado en la libros
 * \param eEmployee empleado, libros de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int libro_modificar(eLibro* libros,eAutor* autores,int cantidadAutores,int cantidadLibros,int id)
{
    int idAux,retorno=-1,opcion;

    idAux= libro_findById(libros,cantidadLibros,id);

    if(idAux!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-TITULO\n2-ID AUTOR\n3-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,3);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE TITULO\n","\tERROR\nCARACTER NO VALIDO\n",libros[idAux].tituloLibro);
                break;

            case 2:
                system("cls");
                autor_listar(autores,cantidadAutores);
                break;
            }

        }while(opcion!=3);

        retorno=0;
    }
    return retorno;
}


/** \brief imprime por pantalla una autores de autor
 * \param eAutor, autores de autor
 * \param int cantidad de array
 * \return void
 */
void libro_listar(eLibro* libros,int cantidad)
{
    int i;

    printf("ID LIBRO\t\tTITULO\t\t\tID AUTOR\n\n");
    for(i=0;i<cantidad;i++)
    {
        if(libros[i].isEmpty== ESTADO_OCUPADO)
        {
            printf("    %d   \t%s\t\t  %d\n",libros[i].idLibro,libros[i].tituloLibro,libros[i].idAutor);
        }
    }
}



/** \brief administra un empleado, alta baja modificar y listar
 * \param eEmployee empleado, libros de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad array de empleados
 * \return void
 */
void libro_admin(eLibro* libros,eAutor* autores,int cantidadAutores,int cantidadLibros)
{
    int opcion,idAux;

    do
    {
        system("cls");
        printf("\tMENU -LIBROS-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            system("cls");
            libro_add(libros,autores,cantidadAutores,cantidadLibros);
            break;

        case 2://MODIFICAR LIBRO
            system("cls");
            libro_listar(libros,cantidadLibros);
            idAux=getValidIntOpcion("\nINGRESE ID DE LIBRO A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidadLibros);
            if(libro_modificar(libros,autores,cantidadAutores,cantidadLibros,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            libro_ordenar(libros,cantidadLibros);
            libro_listar(libros,cantidadLibros);
            idAux=getValidIntOpcion("\nINGRESE ID DE LIBRO A DAR DE BAJA\n","\tERROR\nOPCION NO VALIDA\n",1,cantidadLibros);
            if(libro_remove(libros,cantidadLibros,idAux)==0){
                getChar("ID DADO DE BAJA\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 4://IMPRIMIR LISTA EMPLEADO
            system("cls");
            libro_ordenar(libros,cantidadLibros);
            libro_listar(libros,cantidadLibros);
            getChar("");
            break;
        }

    }while(opcion!=5);
}


/** \brief ordena los elemento de libros
 * \param eLibro libros
 * \param cantidad int
 * \return void
 */
void libro_ordenar(eLibro* libros,int cantidad)
{
    int i,j;
    eLibro aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(libros[i].tituloLibro,libros[j].tituloLibro)>0)
            {
                aux=libros[i];
                libros[i]=libros[j];
                libros[j]=aux;
            }
        }
    }
}


