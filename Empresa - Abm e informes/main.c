#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "funcionesGet.h"
#define CANTIDAD 5


int main()
{
    int opcion,flag=0,idAux;
    float salarioMinimo=0,salarioMaximo=0,promedio=0;

    eEmployee arrayEmpleados[CANTIDAD];
    initEmployees(arrayEmpleados,CANTIDAD);
    eSector arraySectores[4]={{1,"SECTOR 1"},{2,"SECTOR 2"},{3,"SECTOR 3"},{4,"SECTOR 4"}};

    do
    {
        system("cls");
        opcion= getValidIntOpcion("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR\n","Opcion no valida",1,5);

        switch(opcion)
        {
        case 1://ALTA
            system("cls");
            addEmployee(arrayEmpleados,CANTIDAD);
            flag=1;
            break;

        case 2://MODIFICAR
            system("cls");
            if(flag==0)
                printf("No se han cargado datos aun\n");

            else
            {
                idAux= getValidIntOpcion("Ingrese id a modificar\n","Error\nID NO VALIDO",0,CANTIDAD);
                if(modificarEmployee(arrayEmpleados,CANTIDAD,idAux)==0)
                    printf("Se han modificado los datos\n");

                flag=1;
            }
            break;

        case 3://BAJA
            system("cls");
            if(flag==0)
                printf("No se han cargado datos aun\n");

            else
            {
                idAux= getValidIntOpcion("Ingrese id a dar de baja\n","Error\nID NO VALIDO",0,CANTIDAD);
                if(removeEmployee(arrayEmpleados,CANTIDAD,idAux)==0)
                    printf("\nSe ha dado de baja\n\n");

                    flag=1;
            }
            break;

        case 4://INFORMAR
            system("cls");
            if(flag==1)
            {
                salarioMinimo= getSalaryMinimo(arrayEmpleados,CANTIDAD);
                salarioMaximo= getSalaryMaximo(arrayEmpleados,CANTIDAD);
                promedio= getPromedio(arrayEmpleados,CANTIDAD);
                ordenarArrayPorNombre(arrayEmpleados,CANTIDAD);
                printListEmployee(arrayEmpleados,CANTIDAD,arraySectores,4);
                printf("Sueldo Maximo: %.2f\nSueldo Minimo: %.2f\nPromedio sueldos: %.2f\n\n",salarioMaximo,salarioMinimo,promedio);
                getChar("");

            }
            else
                printf("No se han cargado datos aun\n");

            break;
        }
    }
    while(opcion!=5);

    return 0;
}
