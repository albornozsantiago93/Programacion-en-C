#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "prestamos.h"
#include "funcionesGet.h"
static int contadorPrestamos=0;
static int idAutoincrementable= 0;


/**
 * \brief Genera un id que se ira autoincrementando
 * \param void
 * \return int, id unico generado
 *
 */
int prestamo_array_generarProximoId(void)
{
    idAutoincrementable ++;
    return idAutoincrementable;
}


/** \brief inicializa el estado de un array
 * \param eAlmuerzos almuerzos, prestamos de almuerzos
 * \param int cantidad, largo de array
 * \return int (-1) Error  - (0)  Ok
 */
int prestamo_init(ePrestamo* prestamos ,int cantidad)
{
    int i, retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        prestamos[i].isEmpty= ESTADO_LIBRE;
    }
    retorno=0;

    return retorno;
}


 /** \brief encuentra un lugar disponible en el array
 * \param eAlmuerzos almuerzos, prestamos de almuerzos
 * \param int cantidad, largo de array
 * \return int  (-1)  - Numero !=-1 (ubicacion disponible en array)
 */
int prestamo_findIsEmpty(ePrestamo* prestamos,int cantidad)
{
    int i,retorno=-1;


    for(i=0; i<cantidad; i++)
    {
        if(prestamos[i].isEmpty==ESTADO_LIBRE)
        {
            retorno= i;
            break;
        }
    }

    return retorno;
}



/** \brief da por alta un almuerzo en la estructura
 * \param ePrestamos
 * \param eAutores
 * \param eLibros
 * \param eSocio
 * \param int cantidadPrestamos, largo de array
 * \param int cantidadAutores, largo de array
 * \param int cantidadLibros, largo de array
 * \param int cantidadSocios, largo de array
 * \return void
 */
void prestamo_alta(ePrestamo* prestamos,eLibro* libros,int cantidadPrestamos,int cantidadAutores,int cantidadLibros,int cantidadSocios)
{
    int  posicionDisponible;

    posicionDisponible= prestamo_findIsEmpty(prestamos,cantidadPrestamos);

    if(posicionDisponible!=-1)
    {
        prestamos[posicionDisponible].idPrestamo= prestamo_array_generarProximoId();
        printf("\t\t\t-LIBROS-\n\n");
        libro_listar(libros,cantidadLibros);
        prestamos[posicionDisponible].idLibro= getValidIntOpcion("\n\nESCOGA LIBRO MEDIANTE ID LIBRO\n","ERROR\nOPCION no VALIDA\n",0,cantidadLibros);
        prestamos[posicionDisponible].idSocio= getValidIntOpcion("\n\nINGRESE SU ID PARA COMPLETAR LA OPERACION\n","ERROR\nOPCION no VALIDA\n",0,cantidadSocios);
        system("cls");
        prestamos[posicionDisponible].fecha.anio= getValidIntOpcion("INGRESE ANIO DE PRESTAMO\n ","\tERROR\nOPCION NO VALIDA\n",2018,2019);
        prestamos[posicionDisponible].fecha.mes= getValidIntOpcion("INGRESE MES DE PRESTAMO\n ","\tERROR\nOPCION NO VALIDA\n",1,12);
        prestamos[posicionDisponible].fecha.dia= getValidIntOpcion("INGRESE DIA DE PRESTAMO\n ","\tERROR\nOPCION NO VALIDA\n",1,31);
        contadorPrestamos++;
        prestamos[posicionDisponible].isEmpty= ESTADO_OCUPADO;
    }
}


 /** \brief imprime por pantalla los listado de socio libro
 * \param ePrestamo estructura
 * \param eSocio, estructura
 * \param eSector sectores, array de sectores
 * \param int cantidadSocios, largo de array
 * \param int cantidadLibros, largo de array
 * \return void
 */
void prestamo_listarSocioLibro(ePrestamo* prestamos,eSocio* socios,eLibro* libros,int cantidadSocios,int cantidadLibros)
{
    int i,j,k;

    printf("\tLISTADO DE SOCIO-LIBRO\n\n");

    for(i=0;i<cantidadLibros;i++)
    {
        for(j=0;j<cantidadSocios;j++)
        {
            if(libros[i].idLibro== prestamos[j].idLibro)
            {
                for(k=0;k<cantidadSocios;k++)
                {
                    if(socios[k].isEmpty==ESTADO_OCUPADO && prestamos[j].isEmpty==ESTADO_OCUPADO && prestamos[j].idSocio== socios[k].idUnico)
                    {
                        printf("%s %s\t%s\t\n",socios[k].name,socios[k].lastName,libros[i].tituloLibro);
                    }
                }
            }
        }
    }
}

 /** \brief imprime por pantalla los menues consumidos por empleados
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadLibros, largo de array
 * \param int cantidadSocios, largo de array
 * \param int id, empleado
 * \return void
 */
void prestamo_listarLibroSolicitadoSocio(eSocio* socios, eLibro* libros, ePrestamo* prestamos, int cantidadSocios, int cantidadLibros,int idSocio)
{
    int i, j, k;

    system("cls");
    printf("SOCIO \t LIBRO \n\n");

    for(i=0; i<cantidadLibros; i++)
    {
        for(j=0; j<cantidadSocios; j++)
        {
            if(libros[i].idLibro == prestamos[j].idLibro)
            {
                for(k=0; k<cantidadSocios; k++)
                {
                    if(socios[k].isEmpty==ESTADO_OCUPADO && prestamos[j].isEmpty==ESTADO_OCUPADO && prestamos[j].idSocio == socios[k].idUnico)
                    {
                        if(socios[k].idUnico== idSocio)
                            printf("%s %s\t-%s\n",socios[k].name,socios[k].lastName, libros[i].tituloLibro);
                    }
                }
            }
        }
    }
}


 /** \brief imprime por pantalla los libros que consumieron esa fecha
 * \param ePrestamos, estructura
 * \param eLibros, estructura
 * \param eSocios, estructura
 * \param int cantidadSocios, largo de array
 * \param int cantidadLibros, largo de array
 * \param  eFecha fecha, fecha buscar
 * \return void
 */
void prestamo_listarLibrosSolicitadosFecha(eSocio* socios, eLibro* libros, ePrestamo* prestamos, int cantidadSocios, int cantidadLibros,eFechaPrestamo fechaAux)
{
    int i, j, k;

    system("cls");
    printf("\t LIBROS \n\n");

    for(i=0; i<cantidadLibros; i++)
    {
        for(j=0; j<cantidadSocios; j++)
        {
            if(libros[i].idLibro == prestamos[j].idLibro)
            {
                for(k=0; k<cantidadSocios; k++)
                {
                    if(socios[k].isEmpty== ESTADO_OCUPADO && prestamos[j].isEmpty== ESTADO_OCUPADO && prestamos[j].idSocio == socios[k].idUnico)
                    {
                        if(prestamos[j].fecha.anio== fechaAux.anio && prestamos[j].fecha.mes== fechaAux.mes && prestamos[j].fecha.dia== fechaAux.dia )
                            printf("%s \n",libros[i].tituloLibro);
                    }
                }
            }
        }
    }
}


 /** \brief imprime por pantalla los socios que consumieron esa fecha
 * \param ePrestamos, estructura
 * \param eLibros, estructura
 * \param eSocios, estructura
 * \param int cantidadSocios, largo de array
 * \param int cantidadLibros, largo de array
 * \param  eFecha fecha, fecha buscar
 * \return void
 */
void prestamo_listarSocioSolicitaronFecha(eSocio* socios, eLibro* libros, ePrestamo* prestamos, int cantidadSocios, int cantidadLibros,eFechaPrestamo fechaAux)
{
    int i, j, k;

    system("cls");
    printf("\t SOCIOS \n\n");

    for(i=0; i<cantidadLibros; i++)
    {
        for(j=0; j<cantidadSocios; j++)
        {
            if(libros[i].idLibro == prestamos[j].idLibro)
            {
                for(k=0; k<cantidadSocios; k++)
                {
                    if(socios[k].isEmpty== ESTADO_OCUPADO && prestamos[j].isEmpty== ESTADO_OCUPADO && prestamos[j].idSocio == socios[k].idUnico)
                    {
                        if(prestamos[j].fecha.anio== fechaAux.anio && prestamos[j].fecha.mes== fechaAux.mes && prestamos[j].fecha.dia== fechaAux.dia)
                            printf("%s %s\n",socios[k].name,socios[k].lastName);
                    }
                }
            }
        }
    }
}



/** \brief administra un prestamor
 * \param ePrestame prestamo
 * \param eLibros libros
 * \param eSocio socios
 * \param int cantidadLibros array
 * \param int cantidadSocios array
 * \return void
 */
void prestamo_admin(ePrestamo* prestamo,eLibro* libros,eSocio* socios,int cantidadPrestamos,int cantidadLibros,int cantidadSocios)
{
    int opcion,idAux,total=0;
    float promedio=0;
    int cantidadDiasQueNoSuperanPromedio=0;
    eFechaPrestamo fechaAux;

    do
    {
        system("cls");
        printf("\tMENU -PRESTAMOS-\n");
        opcion= getValidIntOpcion("\n1-LISTAR SOCIOS Y SU LIBRO \n2-LIBROS SOLICITADOS POR SOCIO ESPECIFICAMENTE\n3-SOCIOS SOLICITARON EN FECHA\n4-LIBROS SOLICITADOS POR FECHA\n5-LISTAR SOCIOS ORDENADOS\n6-LISTAR TITULOS ORDENADOS\n7-TOTAL GENERAL Y PROMEDIO\n8-CANTIDAD DE PRESTAMOS DE SOCIOS\n9-CANTIDAD PRESTAMOS LIBROS\n10-VOLVER\n\n","\tERROR\nOPCION NO VALIDA",1,10);

        switch(opcion)
        {
        case 1:
            system("cls");
            prestamo_listarSocioLibro(prestamo,socios,libros,cantidadSocios,cantidadLibros);
            getChar("");
                break;

        case 2:
            system("cls");
            socio_listar(socios,cantidadSocios);
            idAux=getValidIntOpcion("\nINGRESE ID DE SOCIO\n","\tERROR\nOPCION NO VALIDA\n",0,cantidadSocios);
            prestamo_listarLibroSolicitadoSocio(socios,libros,prestamo,cantidadSocios,cantidadLibros,idAux);
            getChar("");
                break;

        case 3:
            system("cls");
            fechaAux.anio= getValidIntOpcion("INGRESE ANIO DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",2018,2019);
            fechaAux.mes= getValidIntOpcion("INGRESE MES DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",1,12);
            fechaAux.dia= getValidIntOpcion("INGRESE DIA DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",1,31);
            prestamo_listarSocioSolicitaronFecha(socios,libros,prestamo,cantidadSocios,cantidadLibros,fechaAux);
            getChar("");
                break;

        case 4:
            system("cls");
            fechaAux.anio= getValidIntOpcion("INGRESE ANIO DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",2018,2019);
            fechaAux.mes= getValidIntOpcion("INGRESE MES DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",1,12);
            fechaAux.dia= getValidIntOpcion("INGRESE DIA DE INGRESO:  ","\tERROR\nOPCION NO VALIDA",1,31);
            prestamo_listarLibrosSolicitadosFecha(socios,libros,prestamo,cantidadSocios,cantidadLibros,fechaAux);
            getChar("");
                break;

        case 5:
            system("cls");
            prestamo_ordenarInsertion(socios,cantidadSocios);
            socio_listar(socios,cantidadSocios);
            getChar("");
                break;

        case 6:
            system("cls");
            prestamo_bubbleSort(libros,cantidadLibros);
            libro_listar(libros,cantidadLibros);
            getChar("");
                break;

        case 7:
            system("cls");
            total= contadorPrestamos;
            promedio=prestamo_promedioDiario();
            printf("TOTAL DE SOLICITUDES: %d\nPROMEDIO DE SOLICITUDES: %.2f\n",total,promedio);
            cantidadDiasQueNoSuperanPromedio= prestamo_cantDiasNoSuperanPromedio(libros,cantidadLibros);
            printf("\nCANTIDAD DE DIAS QUE NO SUPERAN EL PROMEDIO: %d\n",cantidadDiasQueNoSuperanPromedio);
            getChar("");
                break;

        case 8:
            system("cls");
            prestamo_calcularSolicutudesSocios(prestamo,cantidadPrestamos,socios,cantidadSocios,libros,cantidadLibros);
            prestamo_listarSolicitudesSocios(socios,cantidadSocios);
            getChar("");
            break;

        case 9:
            system("cls");
            prestamo_calcularSolicutudesLibros(prestamo,cantidadPrestamos,socios,cantidadSocios,libros,cantidadLibros);
            prestamo_listarSolicitudesLibros(libros,cantidadLibros);
            getChar("");
            break;
        }

    }while(opcion!=10);
}


 /** \brief carga datos hardcodeados en la estructura de prestamos
 * \param ePrestamos empleado, estructura de prestamos
 * \param int cantidad, largo de array
 * \return void
 */
void prestamo_hardcodearDatos(ePrestamo* prestamos, int cantidad)
{
    int i;
    int idSocios[]={1,2,3,4,5,1};
    int idLibros[]= {1,2,3,1,4,5};

    eFechaPrestamo unaFecha = {5,5,2019};


    for(i=0; i<cantidad; i++)
    {
        prestamos[i].idPrestamo=prestamo_array_generarProximoId();
        contadorPrestamos ++;
        prestamos[i].idSocio= idSocios[i];
        prestamos[i].idLibro= idLibros[i];
        prestamos[i].fecha= unaFecha;
        prestamos[i].isEmpty= ESTADO_OCUPADO;
    }
}
/** \brief ordena por insersion
 * \param eSocios
 * \param int cantidad array
 * \return void
 *
 */
void prestamo_ordenarInsertion(eSocio* socios,int cantidad)
{
    int i,j;
    eSocio temp;
    for(i=1; i<cantidad; i++)
    {
        temp = socios[i];
        j=i-1;

        while(j>=0 && strcmp(socios[j].lastName,temp.lastName)>0) // temp<data[j] o temp>data[j]
        {
            socios[j+1] = socios[j];
            j--;
        }
        socios[j+1]=temp; // inserción
    }
}
/** \brief ordena bubbleSort
 * \param eLibros
 * \param int cantidad array
 * \return void
 *
 */
void prestamo_bubbleSort (eLibro* libros,int cantidad)
{
    int j;
    int flagNoEstaOrdenado = 1;
    eLibro auxLibro;

    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < cantidad; j++)
        {
            if (strcmp(libros[j].tituloLibro,libros[j-1].tituloLibro)<0)
            {
                auxLibro = libros[j];
                libros[j] = libros[j - 1];
                libros[j - 1] = auxLibro;
                flagNoEstaOrdenado = 1;
            }
        }
    }
}


 /** \brief calcula el promedio de los prestamos
 * \return float, promedio
 */
float prestamo_promedioDiario()
{
    float acumulador;

    acumulador= (float)contadorPrestamos/7;

    return acumulador;
}


 /** \brief calcula la cantidad de dias que no superan el promedio de los prestamos
 * \param eLibro* array de libros
 * \param int cantidad de array de libros
 * \return float, promedio
 */
 int prestamo_cantDiasNoSuperanPromedio(eLibro* libros,int cantidad)
 {
     int i, acumuladorDias=0;
     float promedio;

     promedio= prestamo_promedioDiario();

     for(i=0;i<cantidad;i++)
     {
         if(libros[i].cantidadPrestamos<promedio)
         {
             acumuladorDias++;
         }
     }
     return acumuladorDias;
 }
 /** \brief calcula la cantidad de solicitudes por cada socio
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadLibros, largo de array
 * \param int cantidadSocios, largo de array
 */
void prestamo_calcularSolicutudesSocios(ePrestamo* prestamos,int cantidadPrestamos,eSocio* socios,int cantidadSocios,eLibro* libros,int cantidadLibros)
{
    int i, j, k;

    for(i=0;i<cantidadSocios;i++)
        socios[i].cantidadPrestamos=0;


    for(i=0; i<cantidadLibros; i++)
    {
        for(j=0; j<cantidadSocios; j++)
        {
            if(libros[i].idLibro == prestamos[j].idLibro)
            {
                for(k=0; k<cantidadSocios; k++)
                {
                    if(socios[k].isEmpty== ESTADO_OCUPADO && prestamos[j].isEmpty== ESTADO_OCUPADO && prestamos[j].idSocio == socios[k].idUnico)
                    {
                        socios[k].cantidadPrestamos ++;
                    }
                }
            }
        }
    }
}


 /** \brief lista la cantidad de prestamos por socio y tambien el maximo socio con mas prestamos
 * \param eSocio, array de socios
 * \param int cantidadSocios, largo de array
 */
 void prestamo_listarSolicitudesSocios(eSocio* socios,int cantidadSocios)
 {
     int i,maximo;

     maximo= socios[0].cantidadPrestamos;

     for(i=0;i<cantidadSocios;i++)
     {
         if(socios[i].isEmpty== ESTADO_OCUPADO && socios[i].cantidadPrestamos>maximo)
         {
             maximo= socios[i].cantidadPrestamos;
         }

     }


     printf("   SOCIOS\tCANTIDAD SOLICITUDES\n\n");

     for(i=0;i<cantidadSocios;i++)
     {
         if(socios[i].isEmpty== ESTADO_OCUPADO)
         {
             printf("%s %s\t\t%d\n",socios[i].name,socios[i].lastName,socios[i].cantidadPrestamos);
         }
     }
     printf("\nEL SOCIO CON MAS PRESTAMOS: %d\n",maximo);
 }




  /** \brief calcula la cantidad de solicitudes por cada libro
 * \param eAlmuerzos almuerzos, estructura de almuerzos
 * \param eMenu menues, estructura de menu
 * \param eEmpleados empleados, estructura de empleados
 * \param eSector sectores, array de sectores
 * \param int cantidadLibros, largo de array
 * \param int cantidadSocios, largo de array
 */
void prestamo_calcularSolicutudesLibros(ePrestamo* prestamos,int cantidadPrestamos,eSocio* socios,int cantidadSocios,eLibro* libros,int cantidadLibros)
{
    int i, j, k;

    for(i=0;i<cantidadLibros;i++)
        libros[i].cantidadPrestamos=0;


    for(i=0; i<cantidadLibros; i++)
    {
        for(j=0; j<cantidadSocios; j++)
        {
            if(libros[i].idLibro == prestamos[j].idLibro)
            {
                for(k=0; k<cantidadSocios; k++)
                {
                    if(socios[k].isEmpty== ESTADO_OCUPADO && prestamos[j].isEmpty== ESTADO_OCUPADO && prestamos[j].idLibro == libros[k].idLibro)
                    {
                        libros[k].cantidadPrestamos ++;
                    }
                }
            }
        }
    }
}


 /** \brief lista la cantidad de prestamos por socio y tambien el maximo socio con mas prestamos
 * \param eSocio, array de socios
 * \param int cantidadSocios, largo de array
 */
 void prestamo_listarSolicitudesLibros(eLibro* libros,int cantidadLibros)
 {
     int i,minimo;

     minimo= libros[0].cantidadPrestamos;

     for(i=0;i<cantidadLibros;i++)
     {
         if(libros[i].isEmpty== ESTADO_OCUPADO && libros[i].cantidadPrestamos<minimo)
         {
             minimo= libros[i].cantidadPrestamos;
         }

     }


     printf("   LIBROS\t\t\tCANTIDAD SOLICITUDES\n\n");

     for(i=0;i<cantidadLibros;i++)
     {
         if(libros[i].isEmpty== ESTADO_OCUPADO)
         {
             printf("%s \t\t\t%d\n",libros[i].tituloLibro,libros[i].cantidadPrestamos);
         }
     }
     printf("\nEL LIBRO CON MENOS PRESTAMOS: %d\n",minimo);
 }
