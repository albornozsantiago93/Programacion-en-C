
int controller_generateArchive(char* path);
int controller_loadFromText(char* path, LinkedList* pArrayListEntidad);
int controller_saveAsText(char* path, LinkedList* pArrayListEntidad);

int controller_loadFromBinary(char* path, LinkedList* pArrayListEntidad);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntidad);

void controller_printEntidad(Llamadas* this);
void controller_listEntidad(LinkedList* pArrayListEntidad);
