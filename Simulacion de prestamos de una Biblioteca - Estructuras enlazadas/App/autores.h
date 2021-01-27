#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct{
        char nombreAutor[31];
        char apellidoAutor[31];
        int idAutor;
        int isEmpty;
}eAutor;

#endif // AUTORES_H_INCLUDED
#define ESTADO_OCUPADO 1
#define ESTADO_LIBRE 0

int autor_array_generarProximoId(void);
int autor_init(eAutor* ,int cantidad);
int autor_findById(eAutor* ,int cantidad,int id);
int autor_findIsEmpty(eAutor* ,int cantidad);
int autor_remove(eAutor* ,int cantidad,int id);
int autor_add(eAutor* ,int cantidad);
void autor_hardcodearDatos(eAutor* , int cantidad);
int autor_modificar(eAutor* , int cantidad,int idAux);
void autor_listar(eAutor* ,int cantidad);
void autor_admin(eAutor* autores,int cantidad);
void autores_ordenar(eAutor* autores,int cantidad);
