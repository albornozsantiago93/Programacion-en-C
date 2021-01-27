#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funcionesGet.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("cls");
        option= getValidIntOpcion("\tMENU\n\n1-CARGAR DATOS EMP. MODO TEXTO\n2-CARGAR DATOS EMP. MODO BINARIO\n3-ALTA EMPLEADO\n4-MODIFICAR EMPLEADO\n5-BAJA EMPLEADO\n6-LISTAR EMPLEADO\n7-ORDENAR EMPLEADOS\n8-GUARDAR DATOS MODO TEXTO\n9-GUARDAR DATOS MODO BINARIO\n10-SALIR\n","ERROR",1,10);

        switch(option)
        {
            case 1:
                system("cls");
                if(controller_loadFromText("data.csv",listaEmpleados)==0)
                {
                    getChar("CARGADO OK\n");
                }

                break;

            case 2:
                system("cls");
                if(controller_loadFromBinary("data.bin",listaEmpleados)==0);
                {
                    getChar("CARGADO OK\n");
                }

                break;

            case 3:
                system("cls");
                if(controller_addEmployee(listaEmpleados)==0)
                {
                    getChar("CARGADO OK\n");
                }

                break;

            case 4:
                system("cls");
                printf("ID | NOMBRE | HS TRABAJADAS | SUELDO\n");
                controller_ListEmployee(listaEmpleados);
                if(controller_editEmployee(listaEmpleados)==0)
                    getChar("\nMODIFICADO OK\n");

                break;

            case 5:
                system("cls");
                printf("ID | NOMBRE | HS TRABAJADAS | SUELDO\n");
                controller_ListEmployee(listaEmpleados);
                if(controller_removeEmployee(listaEmpleados)==0)
                    getChar("\n SE HA DADO DE BAJA");

                break;

            case 6:
                system("cls");
                printf("ID | NOMBRE | HS TRABAJADAS | SUELDO\n");
                controller_ListEmployee(listaEmpleados);
                getChar("");
                break;

            case 7:

                break;

            case 8:
                system("cls");
                if(controller_saveAsText("data.csv",listaEmpleados)==0)
                    getChar("\nGUARDADO OK");

                break;

            case 9:
                system("cls");
                if(controller_saveAsBinary("data.bin",listaEmpleados)==0)
                    getChar("\nGUARDAD OK");

                break;
        }
    }while(option != 10);
    return 0;
}
