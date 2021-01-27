#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED

/**
 * \brief Solicita espacio en memoria para crear una estructura de employee
 * \return Espacio de memoria para tipo de dato employee
 */
Employee* employee_new();

/**
 * \brief Parsea y asigna los datos por parametro a employee
 * \param char* idStr, id unico de employee
 * \param char* nombreStr, nombre de employee
 * \param char* horasTrabajadasStr, cantidad de horas trabajadas employee
 * \param char* sueldo, sueldo de employee
 * \return Employee* puntero de estructura cargada con datos
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);

/**
 * \brief Borra en espacio de memoria reservado
 * \param Employee*, this
 */
void employee_delete(Employee* this);

/**
 * \brief setea id unico para employee*
 * \param Employee*, this
 * \return int, -1 error / 0 ok
 * \param int id
 */
int employee_setId(Employee* this,int id);

/**
 * \brief get id unico de employee*
 * \param Employee*, this
 * \param int id auxiliar
 * \return int, -1 error / 0 ok
 */
int employee_getId(Employee* this,int* id);

/**
 * \brief setea un nombre para employee*
 * \param Employee*, this
 * \param char* nombre que se cargara en employee*
 * \return int, -1 error / 0 ok
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * \brief get get nombre de employee*
 * \param Employee*, this
 * \param char* nombre, auxiliar
 * \return int, -1 error / 0 ok
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * \brief set horas trabajadas de employee*
 * \param Employee*, this
 * \param int horas trabajadas
 * \return int, -1 error / 0 ok
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * \brief get horas trabajadas de employee*
 * \param Employee*, this
 * \param int* horas trabajadas, auxiliar
 * \return int, -1 error / 0 ok
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * \brief set sueldo de employee*
 * \param Employee*, this
 * \param int sueldo
 * \return int, -1 error / 0 ok
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * \brief get sueldo de employee*
 * \param Employee*, this
 * \param int* sueldo, auxiliar
 * \return int, -1 error / 0 ok
 */
int employee_getSueldo(Employee* this,int* sueldo);

