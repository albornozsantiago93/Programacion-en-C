 /** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *

 int controller_addEntidad(LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     int horasTrabajadas, sueldo;
     char nombre[26], apellido[26];
     Entidad* entidadAux;

     if(pArrayListEntidad!=NULL)
     {

         getValidString("INGRESE NOMBRE:\n","ERROR",nombre);
         getValidString("INGRESE APELLIDO:\n","ERROR",apellido);
         horasTrabajadas= getValidIntOpcion("INGRESE CANTIDAD DE HORAS TRABAJADAS:\n","ERROR",0,90000);
         sueldo= getValidIntOpcion("INGRESE SUELDO\n","ERROR",100,999999999);
         entidadAux= entidad_new();

         if(entidadAux!=NULL)
         {
             if(entidad_setNombre(entidadAux,nombre)==0)
             {
                 if(entidad_setApellido(entidadAux,apellido)==0)
                 {
                     if(entidad_setHorasTrabajadas(entidadAux,horasTrabajadas)==0)
                     {
                         if(entidad_setId(entidadAux,0)!=-1)
                         {
                             if(entidad_setSueldo(entidadAux,sueldo)==0)
                             {
                                 ll_add(pArrayListEntidad,entidadAux);
                                 retorno=0;
                             }
                         }
                     }
                 }
             }
         }
         else
         {
             entidad_delete(entidadAux);
         }

     }
     return retorno;
 }


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *

 int controller_editEntidad(LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     int idAux,sueldoAux,cantidadHorasTrabajadasAux,lenght,i,idBuscador;
     char nombreAux[26],apellidoAux[27];
     int opcion=0;
     Entidad* entidadAux;

     if(pArrayListEntidad!=NULL)
     {
         lenght= ll_len(pArrayListEntidad);
         idBuscador= getValidIntOpcion("INGRESE SU ID PARA MODIFICAR:\n","ERROR",0,lenght);

         for(i=0;i<lenght;i++)
         {
             entidadAux= ll_get(pArrayListEntidad,i);
             if(entidad_getId(entidadAux,&idAux)!=-1)
             {
                 if(idAux== idBuscador)
                 {
                     getChar("ID ENCONTRADO\npress Enter\n");

                     do
                     {
                         opcion=getValidIntOpcion("\tMENU MODIFICAR\n\n1-NOMBRE\n2-APELLIDO\n3-SUELDO\n4-HORAS TRABAJADAS\n5-SALIR","ERROR",1,5);

                         switch(opcion)
                         {
                            case 1:
                                system("cls");
                                getValidString("INGRESE NOMBRE:\n","ERROR\n",nombreAux);
                                entidad_setNombre(entidadAux,nombreAux);
                                break;

                            case 2:
                                system("cls");
                                getValidString("INGRESE APELLIDO:\n","ERRO",apellidoAux),
                                entidad_setApellido(entidadAux,apellidoAux);
                                break;

                            case 3:
                                system("cls");
                                sueldoAux= getValidInt("INGRESE SUELDO:","ERROR");
                                entidad_setSueldo(entidadAux,sueldoAux);
                                break;

                            case 4:
                                system("cls");
                                cantidadHorasTrabajadasAux=getValidIntOpcion("INGRESE HS TRABAJADAS:\n","ERROR",1,900000);
                                entidad_setHorasTrabajadas(entidadAux,cantidadHorasTrabajadasAux);
                                break;
                         }

                     }while(opcion!=5);
                     retorno=0;
                 }
             }
         }
     }
     return retorno;
 }


 /** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *

 int controller_removeEntidad(LinkedList* pArrayListEntidad)
 {
     int retorno=-1;
     int i,lenght,idAux,idBuscador;
     Entidad* entidadAux;

     if(pArrayListEntidad!=NULL)
     {
         lenght= ll_len(pArrayListEntidad);
         idBuscador= getValidIntOpcion("INGRESE ID PARA DAR DE BAJA\n","ERROR\n",0,lenght);

         for(i=0;i<lenght;i++)
         {
             entidadAux= ll_get(pArrayListEntidad,i);

             if(entidad_getId(entidadAux,&idAux)!=-1)
             {
                 if(idAux==idBuscador)
                 {
                     getChar("ID ENCONTRADO\npressEnter\n");
                     ll_remove(pArrayListEntidad,i);
                     retorno=0;
                     break;
                 }
             }
         }
     }
     return retorno;
 }


int entidad_setId(Entidad* this, int id)
{
    int retorno=-1;
    static int idAutoincrementable=0;

    if(this!=NULL)
    {
        if(idAutoincrementable>=0)
        {
            idAutoincrementable++;
            this->idUnico= idAutoincrementable;
        }
        retorno=0;
    }
    return retorno;
}
*/
