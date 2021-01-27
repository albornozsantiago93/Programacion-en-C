#define ESTADO_LIBRE 0
#define ESTADO_OCUPADO 1

typedef struct{
            int idSector;
            char descripcion[31];
}eSector;

typedef struct{
            int id;
            char name[51];
            char lastName[51];
            float salary;
            int sector;
            int isEmpty;
}eEmployee;

int array_generarProximoId(void);
int initEmployees(eEmployee* empleados,int cantidad);
int addEmployee(eEmployee* empleados,int cantidad);
int findEmployeeById(eEmployee* empleados,int cantidad,int id);
int findIsEmpty(eEmployee* empleados,int cantidad);
int removeEmployee(eEmployee* empleados,int cantidad,int id);
void printEmployee(eEmployee empleado,eSector* sectores,int cantidad);
int modificarEmployee(eEmployee* empleados, int cantidad,int id);
void printListEmployee(eEmployee* empleados,int cantidadEmpleados, eSector* sectores,int cantidadSectores);
void ordenarArrayPorNombre(eEmployee* empleados,int cantidadEmpleados);
void ordenarLetras(eEmployee* empleados,int cantidadEmpleados);
float getSalaryMinimo(eEmployee* empleados,int cantidad);
float getSalaryMaximo(eEmployee* empleados,int cantidad);
float getPromedio(eEmployee* empleados,int cantidad);


