#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "entidad.h"
#include "funcionesGet.h"
#include "controller.h"
#include "parser.h"


int main()
{
    int opcion=0;
    int opcionProblema=0;
    char pArchivo[50];
    LinkedList* listaLlamadas= ll_newLinkedList();
    int datosCargados=-1;
    LinkedList* listaNoEnciendePc=NULL;
    LinkedList* listaNoFuncionaMouse=NULL;
    LinkedList* listaNoFuncionaTeclado=NULL;
    LinkedList* listaNoHayInternet=NULL;
    LinkedList* listaNoFuncionaTelefono=NULL;

    controller_generateArchive("datos.csv");
    controller_generateArchive("noFuncionaPc.csv");
    controller_generateArchive("noFuncionaMouse.csv");
    controller_generateArchive("noFuncionaTeclado.csv");
    controller_generateArchive("noFuncionaInternet.csv");
    controller_generateArchive("noFuncionaTelefono.csv");

    do
    {
        system("cls");
        opcion=getValidIntOpcion("\tMENU\n\n1-CARGAR DATOS DESDE ARCHIVO\n2-IMPRIMIR LLAMADAS\n3-GENERAR ARCHIVO LLAMADAS\n4-SALIR\n\n","ERROR",1,4);

        switch(opcion)
        {
            case 1:
                system("cls");
                getString("INGRESE NOMBRE DEL ARCHIVO\n",pArchivo);
                if(listaLlamadas!=NULL)
                {
                    if(controller_loadFromText(pArchivo,listaLlamadas)==0)
                    {
                        datosCargados=0;
                        getChar("DATOS CARGADOS\n");
                    }
                    else
                    {
                        getChar("NO SE HA ENCONTRADO ARCHIVO");
                    }
                }
                else
                {
                    getChar("ERROR EN LA CREACION DE LISTA\n");
                }
                break;

            case 2:
                system("cls");
                if(datosCargados!=-1)
                {
                    ll_sort(listaLlamadas,compare_criterioNumero,1);
                    controller_listEntidad(listaLlamadas);
                    getChar("Enter");
                }
                else
                {
                    getChar("NO SE HAN CARGADO DATOS\n");
                }
                break;

            case 3:
                system("cls");
                if(datosCargados!=-1)
                {
                    printf("\tMENU\n  -GENERAR LISTA DE PROBLEMAS-\n\n");
                    do
                    {
                        system("cls");
                        opcionProblema=getValidIntOpcion("1-NO ENCIENDE PC\n2-NO FUNCIONA MOUSE\n3-NO FUNCIONA TECLADO\n4-NO HAY INTERNET\n5-NO FUNCIONA TELEFONO\n6-VOLVER\n","ERROR",1,6);

                        switch(opcionProblema)
                        {
                        case 1:
                            listaNoEnciendePc= ll_filter(listaLlamadas,llamadas_noEnciendePc);
                            if(controller_saveAsText("noFuncionaPc.csv",listaNoEnciendePc)==0)
                                getChar("SE HA GENERADO LISTA\n");

                            break;

                        case 2:
                            listaNoFuncionaMouse=ll_filter(listaLlamadas,llamadas_noFuncionaMouse);
                            if(controller_saveAsText("noFuncionaMouse.csv",listaNoFuncionaMouse)==0)
                                getChar("SE HA GENERADO LISTA\n");

                            break;

                        case 3:
                            listaNoFuncionaTeclado= ll_filter(listaLlamadas,llamadas_noFuncionaTeclado);
                            if(controller_saveAsText("noFuncionaTeclado.csv",listaNoFuncionaTeclado)==0)
                                getChar("SE HA GENERADO LISTA\n");

                            break;

                        case 4:
                            listaNoHayInternet=ll_filter(listaLlamadas,llamadas_noHayInternet);
                            if(controller_saveAsText("noFuncionaInternet.csv",listaNoHayInternet)==0)
                                getChar("SE HA GENERADO LISTA\n");

                            break;

                        case 5:
                            listaNoFuncionaTelefono=ll_filter(listaLlamadas,llamadas_noFuncionaTelefono);
                            if(controller_saveAsText("noFuncionaTelefono.csv",listaNoFuncionaTelefono)==0)
                                getChar("SE HA GENERADO LISTA\n");

                            break;

                        }
                    }while(opcionProblema!=6);
                }
                else
                {
                    getChar("NO SE HAN CARGADO DATOS\n");
                }
                break;

            case 4:
                system("cls");
                break;
        }
    }while(opcion!=4);

    return 0;
}
