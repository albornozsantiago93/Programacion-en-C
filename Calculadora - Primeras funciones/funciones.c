int validarOpcion(int opcion,int desde,int hasta,char* msjError)
{
    if(opcion<desde || opcion>hasta)
    {
        printf(msjError);
        return 0;
    }
    return 1;
}

int realizarSuma(int numeroA,int numeroB)
{
    int resultado;

    resultado= numeroA+ numeroB;
    return resultado;
}

int realizarResta(int numeroA,int numeroB)
{
    int resultado;

    resultado=numeroA- numeroB;
    return resultado;
}

float realizarDivision(int numeroA,int numeroB)
{
    float resultado=0;

    if(numeroB==0)
    {
        return 0;
    }
    resultado= (float)numeroA/ (float)numeroB;
    return resultado;
}

int realizarMultiplicacion(int numeroA,int numeroB)
{
    int resultado;

    resultado= numeroA* numeroB;
    return resultado;
}

long realizarFactorial(int numero)
{
        int i;
        long resultado=1;

        for(i=1; i<=numero;i++)
            resultado= resultado*i;

    return resultado;
}

int validarEntradaInt()
