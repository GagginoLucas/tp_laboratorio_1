#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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
	LinkedList* this = NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if(this != NULL) {

		this->pFirstNode = NULL;
		this->size = 0;
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

	if(this != NULL) {

		returnAux = this->size;
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
static Node* getNode(LinkedList* this, int nodeIndex) {

	Node* pGetNode = NULL;
	int llLen;
	int i;

	llLen = ll_len(this);
	if(this != NULL && nodeIndex < llLen && nodeIndex>=0) {

		pGetNode= this->pFirstNode;

		for(i=0 ; i < nodeIndex ; i++) {

			pGetNode = pGetNode->pNextNode;

		}
	}

	return pGetNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement) {

	int rtn = -1;
	Node* pAuxNode = NULL;
	Node* pNewNode = NULL;
	int llLen = ll_len(this);

	int flagNewNode = -1;
	if (this != NULL && nodeIndex <= llLen && nodeIndex >= 0) {

		pNewNode = (Node*)malloc(sizeof(Node));
		if(pNewNode!=NULL) {

			if(nodeIndex == 0) { //SI ES EL PRIMER NODO

				pAuxNode = getNode(this, nodeIndex);
				pNewNode->pNextNode = pAuxNode;
				this->pFirstNode = pNewNode;
				flagNewNode = 0;
			} else {

				pAuxNode = getNode(this, nodeIndex-1);
				pNewNode->pNextNode = pAuxNode->pNextNode;
				pAuxNode->pNextNode=pNewNode;
				flagNewNode = 0;
			}

			if(!flagNewNode) {

				pNewNode->pElement = pElement;
				llLen++;
				this->size=llLen;
				rtn = 0;
			}
		}
	}

	return rtn;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) {

	int llLen;
	llLen = ll_len(this);

	return addNode(this, llLen, pElement);
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) {

	void* pElement = NULL;
	Node* pNode = NULL;
	int llLen;
	llLen = ll_len(this);

	if(this != NULL && index >= 0 && index < llLen) {

		pNode = getNode(this, index);
		if(pNode != NULL) {

			pElement = pNode->pElement;
		}
	}

	return pElement;
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

	int rtn = -1;
	Node* pNode = NULL;
	int llLen;
	llLen = ll_len(this);

	if(this != NULL && index >= 0 && index <= llLen) {

		pNode = getNode(this, index);
		if(pNode != NULL) {

			pNode->pElement = pElement;
			rtn = 0;
		}
	}

	return rtn;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) {

	int rtn = -1;
	Node* pNode = NULL;
	Node* pAuxToRemove = NULL;
	int llLen;
	llLen = ll_len(this);

	if(this != NULL && index >= 0 && index < llLen) {

		if(index == 0) {
			pNode = getNode(this, index);

			if(pNode != NULL) {

				this->pFirstNode = pNode->pNextNode;
				pAuxToRemove = pNode;
			}

		}else
		{
			pNode = getNode(this, index-1);
			if(pNode != NULL) {

				pAuxToRemove = pNode->pNextNode;
				if(index == llLen-1) {

					pNode->pNextNode = NULL;
				}else{

					pNode->pNextNode = pAuxToRemove->pNextNode;
				}
			}
		}

		this->size--;
		free(pAuxToRemove);
		rtn = 0;
	}

	return rtn;
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
	int rtn = -1;
	int llLen;
	llLen = ll_len(this);
	int i;

	if(this != NULL && llLen>=0) {

		for(i = 0 ; i<llLen ; i++) {

			ll_remove(this, i);
		}
	}
	if(ll_len(this) == 0)
		rtn = 0;

	return rtn;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this) {

	int rtn = -1;
	if(this != NULL) {

		ll_clear(this);
		free(this);
		rtn = 0;
	}

	return rtn;
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

	int index = -1;
	int i;
	Node* pNode = NULL;
	int llLen = ll_len(this);
	if(this != NULL) {

		for(i = 0 ; i < llLen ; i++) {

			pNode = getNode(this, i);
			if(pNode != NULL) {

				if(pElement == pNode->pElement) {   //SI *VOID MATCHEA CON EL ELEMENTO GUARDADO EN EL NODO

					index = i;    //I ME DA LA POSICIÓN DEL ÍNDICE
					break;
				}
			}
		}
	}

	return index;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this) {

	int rtn = -1;
	int llLen = ll_len(this);
	if(this != NULL) { // (-1) Error: si el puntero a la lista es NULL

		if(llLen>0) {  // ( 0) Si la lista NO esta vacia

			rtn = 0;
		} else {

			rtn = 1; // ( 1) Si la lista esta vacia
		}
	}

	return rtn;
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
int ll_push(LinkedList* this, int index, void* pElement) {

	int rtn = -1;
	int llLen = ll_len(this);
	if(this != NULL && index <= llLen ) {

		rtn = addNode(this, index, pElement);
	}

	return rtn;
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
	int llLen = ll_len(this);
	if(this != NULL && llLen >= 0 && index <= llLen) {

		returnAux = ll_get(this, index);
		ll_remove(this, index);
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
	int rtn = -1;
	int aux;
	if(this != NULL) {

		aux = ll_indexOf(this, pElement);
		if(aux >= 0) {

			rtn = 1;
		}else {

			rtn = 0;
		}


	}

	return rtn;
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
	int rtn = -1;
	void* pElement = NULL;
	int i;
	int llLen = ll_len(this);
	if(  this != NULL && this2 != NULL) {

		rtn = 0;
		for(i = 0 ; i<llLen ; i++) {

			pElement = ll_get(this2, i);
			rtn = ll_contains(this, pElement);
			if(rtn == 0) {

				rtn = 0;
				break;
			}
		}

	}

	return rtn;
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
	void* pElement;
	int i;
	int llLen = ll_len(this);

	if(this != NULL && from >= 0 && from <= to && to <= llLen) {

		cloneArray = ll_newLinkedList();

			for(i = from; i<to; i++) {

				pElement = ll_get(this, i);
				if(pElement != NULL) {

					ll_add(cloneArray, pElement);
				}
			}
	}

	return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList* this) {

	int i;
	int llLen = ll_len(this);
	LinkedList* cloneArray = NULL;
	void* pElement = NULL;
	if(this != NULL) {

		cloneArray = ll_newLinkedList();

		for(i = 0; i<llLen; i++) {

			pElement = ll_get(this, i);
			if(pElement != NULL) {

				ll_add(cloneArray, pElement);
			}
		}
	}

	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;

	return returnAux;

}

