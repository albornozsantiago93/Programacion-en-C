#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "socios.h"
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
int socio_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, socios de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int socio_init(eSocio* socios ,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        socios[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, socios de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int socio_findIsEmpty(eSocio* socios,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(socios[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}


/** \brief encuentra por id un dato de la socios
 * \param eEmployee empleado, socios de empleados
 * \param int cantidad, largo de array
 * \param int id, referencia a buscar
 * \return int  (-1)  - Numero id !=-1
 */
int socio_findById(eSocio* socios ,int cantidad,int id)
 {
     int i,retorno=-1;


        for(i=0;i<cantidad;i++)
        {
            if(socios[i].isEmpty== ESTADO_OCUPADO && socios[i].idUnico== id)
            {
                retorno= i;
                break;
            }
        }

     return retorno;
 }


 /** \brief realiza una baja logica colocando el estado en LIBRE
 * \param eEmployee empleado, socios de empleados
 * \param int cantidad, largo de array
 * \param id int
 * \return int  ERROR(-1)  - (0)  Ok
 */
int socio_remove(eSocio* socios,int cantidad,int id)
 {
     int i, retorno=-1;


         for(i=0;i<cantidad;i++)
         {
             if(socios[i].idUnico==id)
             {
                 socios[i].isEmpty=ESTADO_LIBRE;
                 retorno=0;
                 break;
             }
         }
     return retorno;
 }


 /** \brief da por alta a un empleado en la socios de eEmpleados
 * \param eEmployee empleado, socios de empleados
 * \param int cantidad, largo de array
 * \return int  (-1)  - (0)  Ok
 */
int socio_add(eSocio* socios,int cantidad)
{
    int posicionAux,retorno=-1;

    if(cantidad>=0)
    {
        posicionAux= socio_findIsEmpty(socios,cantidad);

        if(posicionAux!=-1)
        {
            getValidString("INGRESE NOMBRE: ","\tERROR\nCARACTER NO VALIDO",socios[posicionAux].name);
            getValidString("INGRESE APELLIDO: ","\tERROR\nCARACTER NO VALIDO",socios[posicionAux].lastName);
            socios[posicionAux].telefono= getValidInt("INGRESE NUMERO DE TELEFONO: ","ERROR\nCARACTER NO VALIDO");
            socios[posicionAux].idUnico= socio_array_generarProximoId();
            getCaracterSexo("INGRESE SEXO\n(M)MASCULINO\n(F)FEMENINO: ","ERROR\nCARACTER NO VALIDO\n",socios[posicionAux].sexo);
            getString("INGRESE EMAIL: ",socios[posicionAux].email);
            socios[posicionAux].fechaAsociado.anio= getValidIntOpcion("INGRESE ANIO DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",2018,2019);
            socios[posicionAux].fechaAsociado.mes= getValidIntOpcion("INGRESE MES DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",1,12);
            socios[posicionAux].fechaAsociado.dia= getValidIntOpcion("INGRESE DIA DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",1,31);
            socios[posicionAux].isEmpty= ESTADO_OCUPADO;
            system("cls");
            retorno=0;
            getChar("SE HA CARGADO EMPLEADO\n\n");
        }
    }
    return retorno;
}


 /** \brief carga datos hardcodeados en la socios de empleados
 * \param eEmployee empleado, socios de empleados
 * \param int cantidad, largo de array
 * \return void
 */
void socio_hardcodearDatos(eSocio* socios , int cantidad)
{
    int i;
    char nombres[][50]= {"Josue","Maria","Carlos","Pedro","Sofia","Mateo"};
    char apellidos[][50]= {"Perez","Lopez","Imbert","Suarez","Sanchez","Baez"};
    char sexo[][21]={"M","F","M","M","F","M"};
    int telefono[]={1152551234,1155351235,1155451236,1154551237,1152551238,1155351239};
    char email[][50]= {"josue@gmail.com","maria@gmail.com","carlo@gmail.com","pedro@gmail.com","sofia@gmail.com","mateo@gmail.com"};
    eFecha unaFecha = {22,04,2019};



    for(i=0; i<cantidad; i++)
    {
        socios[i].idUnico=socio_array_generarProximoId();
        strcpy(socios[i].name,nombres[i]);
        strcpy(socios[i].lastName,apellidos[i]);
        strcpy(socios[i].sexo,sexo[i]);
        strcpy(socios[i].email,email[i]);
        socios[i].telefono= telefono[i];
        socios[i].fechaAsociado= unaFecha;
        socios[i].isEmpty= ESTADO_OCUPADO;
    }
}


 /** \brief modifica los datos de un empleado en la socios
 * \param eEmployee empleado, socios de empleados
 * \param int cantidad de array
 * \param id int
 * \return int Return (-1)Error o (0) Ok
 */
int socio_modificar(eSocio* socios, int cantidad,int id)
{
    int idAux,retorno=-1,opcion;

    idAux= socio_findById(socios,cantidad,id);
    if(idAux!= -1)
    {
        do
        {
            system("cls");
            printf("\tMENU -MODIFICAR-\n");
            opcion= getValidIntOpcion("\n1-NOMBRE\n2-APELLIDO\n3-SEXO\n4-FECHA\n5-TELEFONO\n6-EMAIL\n7-VOLVER\n","\tERROR\nOPCION NO VALIDA\n",1,7);

            switch(opcion)
            {
            case 1:
                system("cls");
                getValidString("INGRESE NOMBRE\n","\tERROR\nCARACTER NO VALIDO\n",socios[idAux].name);
                break;

            case 2:
                system("cls");
                getValidString("INGRESE APELLIDO\n","\tERROR\nCARACTER NO VALIDO\n",socios[idAux].lastName);
                break;

            case 3:
                system("cls");
                getCaracterSexo("INGRESE SEXO\n(F)FEMENINO\n(M)MASCULINO\n","\tERROR\nCARACTER NO VALIDO\n",socios[idAux].sexo);
                break;

            case 4:
                system("cls");
                socios[idAux].fechaAsociado.dia= getValidIntOpcion("INGRESE DIA\n","\tERROR\nOPCION NO VALIDA",1,31);
                socios[idAux].fechaAsociado.mes= getValidIntOpcion("INGRESE MES\n","\tERROR\nOPCION NO VALIDA",1,12);
                socios[idAux].fechaAsociado.anio= getValidIntOpcion("INGRESE ANIO\n","\tERROR\nOPCION NO VALIDA",2018,2019);
                break;

            case 5:
                system("cls");
                getValidInt("INGRESE NUMERO TELEFONICO\n","ERROR\nCARACTER NO VALIDO\n");
                break;

            case 6:
                system("cls");
                getString("INGRESE EMAIL\n",socios[idAux].email);
                break;
            }
        }
        while(opcion!=7);
        retorno=0;
    }
    return retorno;
}


/** \brief imprime por pantalla una autores de autor
 * \param eAutor, autores de autor
 * \param int cantidad de array
 * \return void
 */
void socio_listar(eSocio* socios,int cantidad)
{
    int i;

    printf("\t\t\tLISTA SOCIOS\n\n");
    printf("ID\tNOMBRE\tAPELLIDO  SEXO\tTELEFONO\tEMAIL\t\tFECHA\n");

    for(i=0;i<cantidad;i++)
    {
        if(socios[i].isEmpty== ESTADO_OCUPADO)
        {
            printf("%d\t%s\t%s\t  %s\t%d\t%s\t%d/%d/%d\n",socios[i].idUnico,socios[i].name,socios[i].lastName,socios[i].sexo,socios[i].telefono,socios[i].email,socios[i].fechaAsociado.dia,socios[i].fechaAsociado.mes,socios[i].fechaAsociado.anio);
        }
    }
}


/** \brief administra un empleado, alta baja modificar y listar
 * \param eEmployee empleado, socio de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidad array de empleados
 * \return void
 */
void socio_admin(eSocio* socios,eAutor* autores,eLibro* libros,int cantidadSocios,int cantidadLibros,int cantidadAutores)
{
    int opcion,idAux;

    do
    {
        system("cls");
        printf("\tMENU -SOCIOS-\n");
        opcion= getValidIntOpcion("\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-LISTAR\n5-LISTAR LIBROS\n6-LISTAR AUTORES\n7-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,7);

        switch(opcion)
        {
        case 1://ALTA EMPLEADO
            system("cls");
            socio_add(socios,cantidadSocios);
            break;

        case 2://MODIFICAR EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\tAPELLIDO  SEXO\tTELEFONO\tEMAIL\t\tFECHA\n");
            socio_listar(socios,cantidadSocios);
            idAux=getValidIntOpcion("\nINGRESE ID DE SOCIO A MODIFICAR\n","\tERROR\nOPCION NO VALIDA\n",1,cantidadSocios);
            if(socio_modificar(socios,cantidadSocios,idAux)==0){
                getChar("ID MODIFICADO CORRECTAMENTE\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 3://BAJA EMPLEADO
            system("cls");
            printf("ID\tNOMBRE\tAPELLIDO  SEXO\tTELEFONO\tEMAIL\t\tFECHA\n");
            socio_listar(socios,cantidadSocios);
            idAux=getValidIntOpcion("\nINGRESE ID DE EMPLEADO A DAR DE BAJA\n","\tERROR\nOPCION NO VALIDA\n",1,cantidadSocios);
            if(socio_remove(socios,cantidadSocios,idAux)==0){
                getChar("ID DADO DE BAJA\n");}

                else
                    printf("ID NO DISPONIBLE");

                break;

        case 4://IMPRIMIR LISTA EMPLEADO
            system("cls");
            socio_ordenar(socios,cantidadSocios);
            socio_listar(socios,cantidadSocios);
            getChar("");
            break;

        case 5:
            system("cls");
            printf("\t\t\tLISTA LIBROS\n\n");
            libro_listar(libros,cantidadLibros);
            getChar("");
            break;

        case 6:
            system("cls");
            printf("\tLISTA AUTORES\n\n");
            autor_listar(autores,cantidadAutores);
            getChar("");
            break;
        }
    }while(opcion!=7);
}

/** \brief ordena los elemento de la socio
 * \param eSocio
 * \param cantidad int
 * \return void
 */
 void socio_ordenar(eSocio* socios,int cantidad)
{
    int i,j;
    eSocio aux;

    for(i=0;i<cantidad-1;i++)
    {
        for(j=i+1;j<cantidad;j++)
        {
            if(strcmp(socios[i].lastName,socios[j].lastName)>0)
            {
                aux=socios[i];
                socios[i]=socios[j];
                socios[j]=aux;
            }
            if(strcmp(socios[i].lastName,socios[j].lastName)==0)
            {
                if(strcmp(socios[i].name,socios[j].name)>0)
                {
                    aux= socios[i];
                    socios[i]=socios[j];
                    socios[j]=aux;
                }
            }
        }
    }
}





