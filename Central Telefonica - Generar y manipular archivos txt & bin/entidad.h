#ifndef llamadas_H_INCLUDED
#define llamadas_H_INCLUDED

typedef struct
{
    int idLlamada;
    int idCliente;
    int idProblema;
    char fecha[20];
    char solucionado[10];
}Llamadas;
#endif // llamadas_H_INCLUDED

Llamadas* llamadas_new();
void llamadas_delete(Llamadas* this);
int llamadas_setIdLlamada(Llamadas* this, int numeroAux);
int llamadas_getIdLlamada(Llamadas* this, int* idLlamadaAux);
int llamadas_setSolucion(Llamadas* this, char* solucionAux);
int llamadas_getSolucion(Llamadas* this, char* solucionAux);
int llamadas_setFecha(Llamadas* this, char* fechaAux);
int llamadas_getFecha(Llamadas* this, char* fechaAux);

int llamadas_setIdCliente(Llamadas* this, int idAux);
int llamadas_getIdCliente(Llamadas* this, int* idAux);
int llamadas_setIdProblema(Llamadas* this, int idAux);
int llamadas_getIdProblema(Llamadas* this, int* idAux);
int llamadas_noEnciendePc(void *this);
int llamadas_noFuncionaMouse(void* this);
int llamadas_noFuncionaTeclado(void* this);
int llamadas_noHayInternet(void* this);
int llamadas_noFuncionaTelefono(void* this);




