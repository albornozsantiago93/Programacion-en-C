#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "funcionesGet.h"


/**
 * \brief Solicita un número al usuario y devuelve un int
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje)
{
    int auxiliar;

    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve un float
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char* mensaje)
{
    float auxiliar;

    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve un char
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje)
{
    char auxiliar;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char* mensaje,char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int validarStringNumerico(char* stringNumerico)
{
   int i=0;
   while(stringNumerico[i] != '\0')
   {
       if(stringNumerico[i] < '0' || stringNumerico[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numéricos flotante
 * \param Array con la cadena a ser analizada
 * \return 1 si es númerico flotante y 0 si no lo es
 *
 */
int validarStringNumericoFlotante(char* str)
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es alfanumérico
 * \param Array con la cadena a ser analizada
 * \return 1 si es alfanúmerico y 0 si no lo es
 *
 */
int validarStringAlfaNumerico(char* stringNumerico)
{
    int i=0, retorno=1;

    while(stringNumerico[i]!='\0')
    {
        if((stringNumerico[i]!=' ')&&(stringNumerico[i]<'a'|| stringNumerico[i]>'z')&&(stringNumerico[i]<'A'|| stringNumerico[i]>'Z')&&(stringNumerico[i]<'0'|| stringNumerico[i]>'9'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el array recibido contiene solo letras
 * \param Array con la cadena a ser analizada
 * \return 1 si es solo letras y 0 si no lo es
 *
 */
int validarStringLetras(char* stringLetras)
{
   int i=0;

   while(stringLetras[i] != '\0')
   {
       if((stringLetras[i] != ' ') && (stringLetras[i] < 'a' || stringLetras[i] > 'z') && (stringLetras[i] < 'A' || stringLetras[i] > 'Z'))
           return 0;

       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el array recibido es numérico telefonico
 * \param Array con la cadena a ser analizada
 * \return 1 si es númerico telefonico y 0 si no lo es
 *
 */
int validarStringTelefonico(char* stringTelefono)
{
    int i=0;
    int contadorGuiones=0;

    while(stringTelefono[i] != '\0')
   {
       if((stringTelefono[i] != ' ') && (stringTelefono[i] != '-') && (stringTelefono[i] < '0' || stringTelefono[i] > '9'))
           return 0;
       if(stringTelefono[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras y 0 si no
 */
int getStringLetras(char* mensaje,char* input)
{
    char auxiliar[351];

    getString(mensaje,auxiliar);
    if(validarStringLetras(auxiliar)==1)
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char* mensaje,char* input)
{
    char auxiliar[50];

    getString(mensaje,auxiliar);
    if(validarStringNumerico(auxiliar))
    {
        strcpy(input,auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(validarStringNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char* mensaje,char* mensajeError)
{
    char auxStr[256];
    int auxInt;

        if (!getStringNumeros(mensaje,auxStr))
        {
            printf ("%s\n",mensajeError);
        }
        auxInt = atoi(auxStr);

        return auxInt;
}

/**
 * \brief Solicita una opcion numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit numero minimo posible
 * \param highLimit numero maximo posible
 * \return El número ingresado por el usuario
 *
 */
 int getValidIntOpcion(char* requestMessage,char* errorMessage, int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("\tERROR\nEL NUMERO DEBE SER MAYOR A %d Y MENOR A %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }
}

/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
float getValidFloat(char* mensaje,char* mensajeError, int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxInt;
    while(1)
    {
        if (!getStringNumerosFlotantes(mensaje,auxStr))
        {
            printf ("%s\n",mensajeError);
            continue;

        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("\tERROR\nEL NUMERO DEBE SER MAYOR A %d Y MENOR A %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}
/**
 * \brief Solicita un texto solo de letras al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el string
 * \return Void
 *
 */
void getValidString(char* mensaje,char* mensajeError,char* input)
{
    while(1)
    {
        if(!getStringLetras(mensaje,input))
           {
                printf("%s\n",mensajeError);
                continue;
           }
           fflush(stdin);
           break;
    }
}

/**
 * \brief Solicita un texto alfanumerico al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargara el string
 * \return Void
 *
 */
 void getValidStringAlfaNumerico(char* mensaje,char* mensajeError, char* input)
{
    char auxStr[250];

    if(input!= NULL)
    {
        getString(mensaje,auxStr);
        if(!validarStringAlfaNumerico(auxStr))
        {
            printf("%s",mensajeError);

        }
        else
        {
            strcpy(input,auxStr);
        }
    }
}

 /**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
 char getNumeroAleatorio(int desde, int hasta, int iniciar)
 {
     if(iniciar)
        srand(time(NULL));
     return desde + (rand()%(hasta + 1 - desde));
 }


  /**
 * \brief valida un caracter de genero
 * \param mensaje, mensaje a ser mostrado al pedir dato
 * \param mensajeError, error al no cumplirse
 * \param input, array de char donde se guardara el caracter
 * \return void
 */
 void getCaracterSexo(char* mensaje,char* mensajeError,char* input)
 {
    char sexo[13];

    do
    {
        getValidString(mensaje,mensajeError,sexo);

        if(sexo[0]!= 'f' && sexo[0] != 'm' && sexo[0]!= 'F' && sexo[0] != 'M')
        {
            system("cls");
            printf(mensajeError);
        }
        else
        {
            strcpy(input,sexo);
        }
    }while(sexo[0]!= 'f' && sexo[0] != 'm' && sexo[0]!= 'F' && sexo[0] != 'M');
 }


/**
 * \brief valida un numero int
 * \param input, cadena que evaluara que sea int
 * \return -1ERROR - 0 OK
 */
int validarInt(char *input)
{
    int retorno=-1;
    int i=0;

    do
    {
        if(*(input+i)<48||*(input+i)>57)
        {
            break;
        }
        i++;
    }while(i<strlen(input));


        if(i==strlen(input))
        {
            retorno=0;
        }

    return retorno;
}


/**
 * \brief valida una cadena de caracteres
 * \param input, cadena que evaluara que sea solo cadena de caracteres
 * \return -1ERROR - 0 OK
 */
int validarString(char*input)
{
    int retorno=-1;
    int i=0;

    if(input!=NULL)
    {
        do
        {
            if(*(input+i)==' '||*(input+i)=='-')
            {
                i++;
                continue;
            }
            if((*(input+i)<65||*(input+i)>90) && (*(input+i)<97||*(input+i)>122))
            {
                break;
            }
            i++;
        }while(i<strlen(input));

        if(i==strlen(input))
        {
            retorno=0;
        }
    }
    return retorno;
}

