#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "autores.h"
#include "funcionesGet.h"

static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int autor_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, autores de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int autor_init(eAutor* autores ,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        autores[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, autores de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int autor_findIsEmpty(eAutor* autores,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(autores[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}


/** \brief encuentra por id un dato de la autores
 * \param eEmployee empleado, autores de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int autor_findById(eAutor* autores ,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(autores[i].isEmpty== ESTADO_OCUPADO && autores[i].idAutor== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 /** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, autores de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int autor_remove(eAutor* autores,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(autores[i].idAutor==id)
             {
                 autores[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }


 /** \brief da por alta a un empleado en la autores de eEmpleados
 * \param eEmployee empleado, autores de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int autor_add(eAutor* autores,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= autor_findIsEmpty(autores,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE NOMBRE:\n","\tERROR\nCARACTER NO VALIDO",autores[posicionAux].nombreAutor);
            getValidString("INGRESE APELLIDO:\n","\tERROR\nCARACTER NO VALIDO",autores[posicionAux].apellidoAutor);
            autores[posicionAux].idAutor= autor_array_generarProximoId();
            system("cls");
            autores[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO AUTOR\n\n");
        }
    }
    return retorno;
}


 /** \brief carga datos hardcodeados en la autores de empleados
 * \param eEmployee empleado, autores de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void autor_hardcodearDatos(eAutor* autores , int cantidad)
{
    int i;
    char nombres[][50]= {"Josue","Maria","Carlos","Pedro","Sofia","Mateo"};
    char apellidos[][50]= {"Borgues","Lakatos","Borieu","Khan","Marx","Diaz"};

    for(i=0; i<cantidad; i++)
    {
        autores[i].idAutor=autor_array_generarProximoId();
        strcpy(autores[i].nombreAutor,nombres[i]);
        strcpy(autores[i].apellidoAutor,apellidos[i]);
        autores[i].isEmpty= ESTADO_OCUPADO;
    }
}


 /** \brief modifica los datos de un empleado en la autores
 * \param eEmployee empleado, autores de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int autor_modificar(eAutor* autores, int cantidad,int id)
{
    int idAux,retorno=-1,opcion;

    idAux= autor_findById(autores,cantidad,id);

    if(idAux!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-NOMBRE\n2-APELLIDO\n3-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,3);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE NOMBRE\n","\tERROR\nCARACTER NO VALIDO\n",autores[idAux].nombreAutor);
                break;

            case 2:
                system("cls");
                getValidString("INGRESE APELLIDO\n","\tERROR\nCARACTER NO VALIDO\n",autores[idAux].apellidoAutor);
                break;
            }
        }
        while(opcion!=3);
        retorno=0;
    }
    return retorno;
}


/** \brief imprime por pantalla una autores de autor
 * \param eAutor, autores de autor
 * \param int cantidad de array
 * \return void
 */
void autor_listar(eAutor* autores,int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(autores[i].isEmpty== ESTADO_OCUPADO)
        {
            printf("%d\t%s\t%s\n",autores[i].idAutor,autores[i].nombreAutor,autores[i].apellidoAutor);
        }
    }
}


/** \brief administra un empleado, alta baja modificar y listar
 * \param eEmployee empleado, autores de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad array de empleados
 * \return void
 */
void autor_admin(eAutor* autores,int cantidad)
{
    int opcion,idAux;

    do
    {
        system("cls");
        printf("\tMENU -AUTORES-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,5);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            system("cls");
            autor_add(autores,cantidad);
            break;

        case 2://MODIFICAR EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\t\tAPELLIDO\n");
            autor_listar(autores,cantidad);
            idAux=getValidIntOpcion("\nINGRESE ID DE AUTOR A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(autor_modificar(autores,cantidad,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\tAPELLIDO\n\n");
            autor_listar(autores,cantidad);
            idAux=getValidIntOpcion("\nINGRESE ID DE AUTOR A DAR DE BAJA\n","\tERROR\nOPCION NO VALIDA\n",1,cantidad);
            if(autor_remove(autores,cantidad,idAux)==0){
                getChar("ID DADO DE BAJA\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 4:
            system("cls");
            printf("ID\tNOMBRE\tAPELLIDO\n\n");
            autores_ordenar(autores,cantidad);
            autor_listar(autores,cantidad);
            getChar("");
            break;
        }

    }while(opcion!=5);
}


/** \brief ordena los elemento de la socio
 * \param esocio
 * \param cantidad int
 * \return void
 */
void autores_ordenar(eAutor* autores,int cantidad)
{
    int i,j;
    eAutor aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(autores[i].apellidoAutor,autores[j].apellidoAutor)>0)
            {
                aux=autores[i];
                autores[i]=autores[j];
                autores[j]=aux;
            }
            if(strcmp(autores[i].apellidoAutor,autores[j].apellidoAutor)==0)
            {
                if(strcmp(autores[i].nombreAutor,autores[j].nombreAutor)>0)
                {
                    aux= autores[i];
                    autores[i]= autores[j];
                    autores[j]= aux;
                }
            }
        }
    }
}



