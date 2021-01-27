#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "funcionesGet.h"
#include "controller.h"
#include "parser.h"
#include "entidad.h"


 /** \brief Genera un archivo de tipo texto
 *
 * \param path char* nombre del archivo
 * \return int 0 (ok) - (-1)error
 *
*/
int controller_generateArchive(char* path)
{
    int retorno=0;
    FILE* pFile;

    if((pFile= fopen(path,"r+"))==NULL)
    {
        if((pFile= fopen(path,"w+"))==NULL)
        {
            retorno=-1;
        }
    }
    fclose(pFile);
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_loadFromText(char* path, LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     FILE* pFile;

     pFile= fopen(path,"r");
     if(path!=NULL && pArrayListEntidad!=NULL)
     {
        if(parser_entidadFromText(pFile,pArrayListEntidad)==0)
        {
            retorno=0;
        }
     }
     fclose(pFile);
     return retorno;
 }



 /** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
*/
int controller_saveAsText(char* path, LinkedList* pArrayListEntidad)
{
    int retorno=-1;
    FILE* pFile;
    int i,lenght;
    Llamadas* llamadasAux;


    pFile=fopen(path,"w");

    if(pFile!=NULL && pArrayListEntidad!=NULL)
    {
        llamadasAux= llamadas_new();
        lenght= ll_len(pArrayListEntidad);

        fprintf(pFile,"ID FECHA  USUARIO  PROBLEMA  SOLUCIONADO\n");

        for(i=0; i<lenght; i++)
        {
            llamadasAux= (Llamadas*)ll_get(pArrayListEntidad,i);

            fprintf(pFile,"%d,%s,%d,%d,%s\n",llamadasAux->idLlamada,llamadasAux->fecha,llamadasAux->idCliente,llamadasAux->idProblema,llamadasAux->solucionado);
        }
        fclose(pFile);
        retorno=0;
    }
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int controller_loadFromBinary(char* path, LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     FILE* pFile;

     if(path!=NULL && pArrayListEntidad!=NULL)
     {
         pFile= fopen(path,"rb");
         if(pFile!=NULL)
         {
             parser_entidadFromBinary(pFile,pArrayListEntidad);
             retorno=0;
             fclose(pFile);
         }
     }
     return retorno;
 }


  /** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntidad)
{
    int retorno=-1;
    FILE* pFile;
    int i,lenght;
    Llamadas* entidadAux;

    if(path!=NULL && pArrayListEntidad!=NULL)
    {
        pFile= fopen(path,"wb");
        lenght= ll_len(pArrayListEntidad);

        if(pFile!=NULL)
        {
            for(i=0;i<lenght;i++)
            {
                entidadAux= ll_get(pArrayListEntidad,i);

                if(entidadAux!=NULL)
                {
                    fwrite(entidadAux,sizeof(Llamadas),1,pFile);
                }
            }
            fclose(pFile);
            retorno=0;
        }
    }
    return retorno;
}



 /** \brief Lista un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return void
 *
*/
void controller_printEntidad(Llamadas* this)
{
    if(this!=NULL)
    {
        int opcionProblema;

        opcionProblema= this->idProblema;


        switch(opcionProblema)
        {
            case 1:
                printf("%d,%s,%d,noEnciendePC%s\n",this->idLlamada,this->fecha,this->idCliente,this->solucionado);
                break;

            case 2:
                printf("%d,%s,%d,noFuncionaMouse%s\n",this->idLlamada,this->fecha,this->idCliente,this->solucionado);
                break;

            case 3:
                printf("%d,%s,%d,noFuncionaTeclado%s\n",this->idLlamada,this->fecha,this->idCliente,this->solucionado);
                break;

            case 4:
                printf("%d,%s,%d,noFuncionaInternet%s\n",this->idLlamada,this->fecha,this->idCliente,this->solucionado);
                break;

            case 5:
                printf("%d,%s,%d,noFuncionaTelefono%s\n",this->idLlamada,this->fecha,this->idCliente,this->solucionado);
                break;
        }
    }
}


 /** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return void
 *
*/
 void controller_listEntidad(LinkedList* pArrayListEntidad)
 {
     int i,lenght;
     Llamadas* entidadAux;

     if(pArrayListEntidad!=NULL)
     {
         lenght= ll_len(pArrayListEntidad);

         for(i=0;i<lenght;i++)
         {
             entidadAux= (Llamadas*)ll_get(pArrayListEntidad,i);
             if(entidadAux!=NULL)
             {
                 controller_printEntidad(entidadAux);
             }

         }
     }
 }
