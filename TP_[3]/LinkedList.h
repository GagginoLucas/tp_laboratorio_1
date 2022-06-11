/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);


//Publicas

/// @brief Crea una nueva lista en memoria
///
/// @return retorna dirección de memoria de la nueva lista
LinkedList* ll_newLinkedList(void);

/// @brief Calcula tamaño de la lista
///
/// @param this lista a calcualr tamaño
/// @return retorna el tamaño de la lista
int ll_len(LinkedList* this);


/// @brief Agrega genérico a la linkedlist
///
/// @param this lista donde se agregará
/// @param pElement puntero que se va a agregar
/// @return
int ll_add(LinkedList* this, void* pElement);

/// @brief Devuelve un generico de la linkedlist
///
/// @param this lista de donde se obtendrá
/// @param index posición index donde se encuentra el genérico
void* ll_get(LinkedList* this, int index);

/// @brief Setea un genérico en linkedlist
/// @param this lista donde se seteara el genérico
/// @param index posición index donde se seteará
/// @param pElement genérico que se va a setear en la lista
/// @return
int ll_set(LinkedList* this, int index,void* pElement);

int ll_push(LinkedList* this, int index, void* pElement);

/// @brief Remueve un elemento de la linkedlist
///
/// @param this lista donde se encuentra el elemento a remover
/// @param index posición en la que se encuentra el elemento
/// @return
int ll_remove(LinkedList* this,int index);

int ll_clear(LinkedList* this);

///ELIMINA LA LISTA DE LA MEMORIA
int ll_deleteLinkedList(LinkedList* this);

///BUSCA INDICE ESPECÍFICO QUE PASO POR PALAMETRO(SIMILAR A BUSCAR POR ID)
int ll_indexOf(LinkedList* this, void* pElement);

///SI ESTA VACÍA O NO
int ll_isEmpty(LinkedList* this);

/// @brief Remueve un elemento de la lista y lo retorna como genérico
///
/// @param this lista donde se encuentra el elemento a remover
/// @param index posición en la que se encuentra el elemento
void* ll_pop(LinkedList* this,int index);

int ll_contains(LinkedList* this, void* pElement);

int ll_containsAll(LinkedList* this,LinkedList* this2);


LinkedList* ll_subList(LinkedList* this,int from,int to);

///DEVUELVE UNA NUEVA LISTA CLONADA
LinkedList* ll_clone(LinkedList* this);

/// @brief Realiza el ordenamiento de la linkedlist
///
/// @param this lista a ordenar
/// @param pFunc función que comparará dos *void
/// @param order orden en el que se realizará el ordenamiento [0] descendente [1] ascendente
/// @return
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
