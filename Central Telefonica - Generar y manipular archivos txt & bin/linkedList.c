#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "entidad.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}


/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux= this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i,lenght;

    if(this!=NULL)
    {
        lenght= ll_len(this);

        if(nodeIndex>=0 && nodeIndex< lenght)           //retorna un nodo que se encuentra en el indice especifico
        {
            pNode= this->pFirstNode;                    //le asigno el primer nodo a la estructura si es ==0 retorno el primer elemento

            if(pNode!=NULL)
            {
                for(i=0;i<lenght;i++)                   //iterara hasta que encuentre la coincidencia
                {
                    if(nodeIndex== i)
                    {
                        break;
                    }
                    else
                    {
                        pNode= pNode->pNextNode;       // si no la encuentra retornara la direccion del siguiente nodo
                    }
                }
            }
        }
    }
    return pNode;
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode;
    Node* pNode;
    int lenght;

    pNewNode=malloc(sizeof(Node));
    pNewNode->pElement=pElement;
    lenght= ll_len(this);

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=lenght)
    {
        if(nodeIndex==0)
        {
            pNewNode->pNextNode=this->pFirstNode;       //al ser el primer elemento, el auxiliar,pNextNode tendra la direccion del primer elemento de ll
            this->pFirstNode=pNewNode;                  //el primer nodo de ll sera el nuevo auxiliar
            this->size++;                               //incremento el tamaño del ll
            returnAux=0;
        }
        else
        {
            pNode=getNode(this,nodeIndex-1);            //al no ser el primero,obtengo la direccion del nodo anterior del indice especificado
            pNewNode->pNextNode=pNode->pNextNode;       //pNewNode nextNode tendra la direccion del pNode- nextNode para corrarlo uno hacia atras y asi teneer espacio para el siguiente node
            pNode->pNextNode=pNewNode;                  //ahora pNode-nextNode tendra la direccion del pNewNode y se agranda el ll para dar espacio a este
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)                  // agrega un elemento a la lista
    {
        if(addNode(this,this->size,pElement)==0) //agrego nodos para ll, le paso por parametro el tamañao del ll y un elemento que sera el cargado al ll
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodeAux;

    if(this!=NULL)
    {
        if(index>=0 && index<=this->size)       //obtengo un elemento de la ll por el index especifico por
        {
            pNodeAux= getNode(this,index);      //obtengo el nodo especifico por index
            {
                if(pNodeAux!=NULL)
                {
                    returnAux= pNodeAux->pElement; //una vez posicionado en el nodo indicado, retorno el elemento en esa posicion
                }
            }
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodeAux;

    if(this!=NULL)
    {
        if(index>=0 && index<= this->size)
        {
            pNodeAux= getNode(this,index);  //obtengo el nodo del indicde
            if(pNodeAux!=NULL)
            {
               pNodeAux->pElement= pElement;//seteo el elemento pasado por parametro al ll
               returnAux=0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int lenght;
    Node* nodePrev;
    Node* nodeActual;


    if(this!=NULL)
    {
        nodeActual=NULL;
        nodePrev=NULL;
        lenght= ll_len(this);

        if(index==0 && index<lenght)
        {
            nodeActual= this->pFirstNode;       //al ser el primer indice el aux nodoActual, tendra la primera posicion del ll
            this->pFirstNode= nodeActual->pNextNode;//el ll firstNode tendra el pNextNode del auxiliar nodoActual
            free(nodeActual);   //libero el espacio en memoria para node
            this->size--; //decremento el tamaño del ll
            returnAux=0;
        }
        else if(index>0 && index<lenght)
        {
            nodeActual= getNode(this,index); // al no ser el indice obtengo el nodo del index
            nodePrev= getNode(this,index-1); //obtengo el nodo previo a ese actual
            nodePrev->pNextNode= nodeActual->pNextNode; //asigno el pNextNode de nodoActual a nodo previo. ahora puedo liberar el nodoActual que sera el dado de baja
            free(nodeActual);//liber espacio en memoria de nodeActual
            this->size--;//decremento el ll
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i,lenght;

    if(this!=NULL)
    {
        lenght= ll_len(this);
        for(i=0;i<lenght;i++)
        {
            ll_remove(this,i);
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lenght,i;
    Node* pNodeAux;

    if(this!=NULL)
    {
        lenght= ll_len(this);
        for(i=0;i<lenght;i++)
        {
            pNodeAux= getNode(this,i);
            if(pNodeAux!=NULL)
            {
                if(pNodeAux->pElement== pElement)
                {
                    returnAux=i;
                }
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux=-1;

    if(this!=NULL)
    {
        if(ll_len(this)>0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int lenght;

    if(this!=NULL)
    {
        lenght= ll_len(this);
        if(index<=lenght&& index>=0)
        {
            if(addNode(this,index,pElement)==0)
            {
                returnAux=0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int lenght;
    void* pElementAux;

    if(this!=NULL)
    {
        lenght=ll_len(this);
        if(index<=lenght && index>=0)
        {
            pElementAux= ll_get(this,index);
            if(ll_remove(this,index)==0)
            {
                returnAux=pElementAux;
            }
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i,lenght,lenght2,contadorCoincidencia=0;
    void* pElementAux;
    void* pElementAux2;


    if(this!=NULL && this2!=NULL)
    {
        lenght= ll_len(this);
        lenght2= ll_len(this2);

        for(i=0;i<lenght;i++)
        {
            pElementAux= ll_get(this,i);
            pElementAux2= ll_get(this2,i);

            if(pElementAux== pElementAux2)
            {
                contadorCoincidencia ++;
            }
        }
        if(lenght==lenght2)
        {
            if(lenght2==contadorCoincidencia)
            {
                returnAux= 1;
            }
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    cloneArray=ll_newLinkedList();
    void* pElement;
    int i;
    int lenght;
    lenght=ll_len(this);

    if(this!=NULL && from>=0 && from<lenght && to>from && to<=lenght)
    {
        for(i=from;i<to;i++)
        {
            pElement=ll_get(this,i);
            if(ll_add(cloneArray,pElement)==0)
            {
                continue;
            }
            else
            {
                free(cloneArray);
                cloneArray=NULL;
                break;
            }
        }
    }
    else
    {
        free(cloneArray);
        cloneArray=NULL;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void* pElementAux;
    int i,lenght;

    if(this!=NULL)
    {
        cloneArray= ll_newLinkedList();
        lenght= ll_len(this);

        for(i=0;i<lenght;i++)
        {
            pElementAux= ll_get(this,i);
            if(ll_add(cloneArray,pElementAux)==0)
            {
                continue;
            }
            else
            {
                free(cloneArray);
                cloneArray= NULL;
            }
        }
    }
    return cloneArray;
}

/** \brief ordena por criterios
 *
 * \param pElementB
 * \param pElementA
 * \return int
 *
*/
 int compareString_entidad(void* pElementA,void* pElementB)
 {
     int retorno;

     if(strcmp(((Llamadas*)pElementA)->fecha,((Llamadas*)pElementB)->fecha)>0)
     {
         retorno= 1;
     }
     else if(strcmp(((Llamadas*)pElementA)->fecha,((Llamadas*)pElementB)->fecha)<0)
     {
         retorno=-1;
     }
     else
     {
         retorno=0;
     }
     return retorno;
 }


 int compare_criterioNumero(void* thisA,void* thisB)
{
    int retorno=0;
    int numeroA;
    int numeroB;

    llamadas_getIdProblema((Llamadas*)thisA,&numeroA);
    llamadas_getIdProblema((Llamadas*)thisB,&numeroB);

    if(numeroA>numeroB)
    {
        retorno=1;
    }
    else if(numeroA<numeroB)
    {
        retorno=-1;
    }
    return retorno;
}


 int compare_criterioNombre(void* thisA,void* thisB)
{
    int retorno=0;
    char nombreA[1024];
    char nombreB[1024];
    llamadas_getSolucion((Llamadas*)thisA,nombreA);
    llamadas_getSolucion((Llamadas*)thisB,nombreB);

    if(strcmp(nombreA,nombreB)>0)
    {
        retorno=1;
    }
    else if(strcmp(nombreA,nombreB)<0)
    {
        retorno=-1;
    }
    return retorno;
}



/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    int i,j;

    if( this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i=0; i< (ll_len(this)-1) ; i++)
        {
            for(j= i+1; j < ll_len(this); j++)
            {
                if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pAux = ll_get(this,i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}
*/

/** \brief obtiene los elementos de una lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno = -1;
    int i=0;
    void* ptr_elemento;
    Node* ptr_auxNode;

    if(this != NULL && pFunc != NULL)
    {
        do
        {
            ptr_auxNode = getNode(this,i);

            ptr_elemento = ptr_auxNode->pElement;

            if(pFunc(ptr_elemento) == 1)
            {
                retorno = 1;
            }
            i++;

        }
        while(ptr_auxNode->pNextNode != NULL);
    }

    return retorno;
}



LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* new_list = NULL;
    int i;
    void* ptr_elemento;

    if(this != NULL && pFunc != NULL)
    {
        new_list = ll_newLinkedList();

        for(i=0; i < ll_len(this); i++)
        {
            ptr_elemento = ll_get(this,i);

            if(pFunc(ptr_elemento) == 1)
            {
                ll_add(new_list,ptr_elemento);
            }
        }
    }
    return new_list;
}




int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int size=ll_len(this);
    void* thisA;
    void* thisB;
    int flagSwap;
    int returnOrderValue;
    if(this!=NULL && size>0 && pFunc!=NULL && (order==0 || order==1))
    {
        do
        {
            flagSwap=0;
            for(i=0;i<size-1;i++)
            {
                thisA=ll_get(this,i);
                thisB=ll_get(this,i+1);
                if(thisA!=NULL && thisB!=NULL)
                {
                    returnOrderValue=pFunc(thisA,thisB);
                    if((returnOrderValue==-1 && order==0) || (returnOrderValue==1 && order==1))
                    {
                        flagSwap=1;
                        ll_set(this,i,thisB);
                        ll_set(this,i+1,thisA);
                    }
                }
            }
        }while(flagSwap==1);
        returnAux=0;
    }
    return returnAux;

}


