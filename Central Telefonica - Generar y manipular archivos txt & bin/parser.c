#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "entidad.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
*/
int parser_entidadFromText(FILE* ptrFile, LinkedList* pArrayListEntidad)
{
    char idLlamadaAux[50],fechaAux[50],idClienteAux[50],idProblemaAux[50],solucionadoAux[50];
    int retorno = -1;
    int readElements = 0;
    Llamadas* llamadasAux= llamadas_new();

    if(ptrFile != NULL && pArrayListEntidad != NULL)
    {
        fscanf(ptrFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]",idLlamadaAux,fechaAux,idClienteAux,idProblemaAux,solucionadoAux);

        do
        {
            readElements= fscanf(ptrFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]",idLlamadaAux,fechaAux,idClienteAux,idProblemaAux,solucionadoAux);

            if(readElements == -1)
            {
                printf("Archivo vacio\n");
                break;
            }
            else
            {
                llamadasAux= llamadas_new();
                if(llamadasAux != NULL)
                {
                    llamadas_setIdProblema(llamadasAux,atoi(idProblemaAux));
                    llamadas_setIdLlamada(llamadasAux,atoi(idLlamadaAux));
                    llamadas_setIdCliente(llamadasAux,atoi(idClienteAux));
                    llamadas_setFecha(llamadasAux,fechaAux);
                    llamadas_setSolucion(llamadasAux,solucionadoAux);
                    ll_add(pArrayListEntidad,llamadasAux);
                    retorno=0;
                }
            }
        }while(!feof(ptrFile));

    }
    fclose(ptrFile);

    return retorno;

}


 /** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
 int parser_entidadFromBinary(FILE* pFile, LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     Llamadas* entidadAux;

     if(pFile!=NULL && pArrayListEntidad!=NULL)
     {
         do
         {
             entidadAux= llamadas_new();

             if(fread(entidadAux,sizeof(Llamadas),1,pFile)==1)
             {
                 ll_add(pArrayListEntidad,entidadAux);
             }
             else
             {
                 llamadas_delete(entidadAux);
             }
         }while(!feof(pFile));
         retorno=0;
     }
     return retorno;
 }
