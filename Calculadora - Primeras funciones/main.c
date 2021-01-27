#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int opcion=0,operandoA,operandoB,resultadoSuma=0,resultadoResta=0,resultadoMultiplicacion=0;
    long resultadoFactorialA=1, resultadoFactorialB=1;
    float resultadoDivision=0;

    while(opcion!=5)
    {
        printf("\n\n-----------MENU-----------\n\n1-Ingresar 1er operando\n2-Ingresar 2do operando\n3-Calcular todas las operaciones\n4-Informar resultados\n5-Salir\n");
        scanf("%d",&opcion);


        if(validarOpcion(opcion,1,5,"\n\nERROR - OPCION NO VALIDA\n\n")==1)
        {
            switch(opcion)
            {
            case 1:
                system("cls");
                printf("Ingrese numero: \n");
                scanf("%d",&operandoA);
                system("cls");
                printf("Operando A= %d\n",operandoA);
                break;

            case 2:
                system("cls");
                printf("Ingrese numero: \n");
                scanf("%d",&operandoB);
                system("cls");
                printf("Operando B= %d\n",operandoB);
                break;

            case 3:
                resultadoSuma= realizarSuma(operandoA,operandoB);
                resultadoResta= realizarResta(operandoA,operandoB);
                resultadoDivision= realizarDivision(operandoA,operandoB);
                resultadoMultiplicacion= realizarMultiplicacion(operandoA,operandoB);
                resultadoFactorialA= realizarFactorial(operandoA);
                resultadoFactorialB= realizarFactorial(operandoB);
                system("cls");
                printf("\nSE HAN REALIZADO TODAS LAS OPERACIONES\n");
                break;

            case 4:
                system("cls");
                printf("Operando A=%d\nOperando B=%d\n\n",operandoA,operandoB);
                printf("--------RESULTADOS--------\n");
                printf("El resultado de A+B es: %d\nEl resultado de A-B es: %d\n",resultadoSuma,resultadoResta);
                if(operandoB==0 || operandoA==0)
                {
                    printf("El resultado de A/B es: ERROR - division por cero\n");
                    printf("El resultado de A*B es: ERROR - multiplicacion por cero\n");
                }
                else
                {
                    printf("El resultado de A/B es: %.2f\n",resultadoDivision);
                    printf("El resultado de A*B es: %d\n",resultadoMultiplicacion);
                }
                printf("El factorial de A es: %ld\nEl factorial de B es: %ld\n",resultadoFactorialA,resultadoFactorialB);
                break;
            }
        }
    }
    return 0;
}

