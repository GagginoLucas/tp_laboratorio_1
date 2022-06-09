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

//CREA LISTA EN MEMORIA
LinkedList* ll_newLinkedList(void);


//CUANTOS PASAJEROS VA A HABER ADENTRO DE LA LISTA
int ll_len(LinkedList* this);





//AGREGAR PASAJERO A LA LISTA
int ll_add(LinkedList* this, void* pElement);

//DEVUELVE UN GENERICO
void* ll_get(LinkedList* this, int index);

//SETEA UNA POSICION EN OTRA, PARA DESPUÉS VOLVER---REMPLAZA ELEMENTO EN EL INDICE QUE YO ESPECIFIQUE
int ll_set(LinkedList* this, int index,void* pElement);

//SE COLA O SE METE EN EL MEDIO EN EL INDICE QUE YO ESPECIFICO
int ll_push(LinkedList* this, int index, void* pElement);

//SACO UN ELEMENTO DE LA LISTA
int ll_remove(LinkedList* this,int index);

//LIMPIA LA LISTA, INICIALIZA TODO EN 0 PARA PODER VOLVER A CARGAR
int ll_clear(LinkedList* this);

//ELIMINA LA LISTA DE LA MEMORIA
int ll_deleteLinkedList(LinkedList* this);

//BUSCA INDICE ESPECÍFICO QUE PASO POR PALAMETRO(SIMILAR A BUSCAR POR ID)
int ll_indexOf(LinkedList* this, void* pElement);

//SI ESTA VACÍA O NO
int ll_isEmpty(LinkedList* this);

//SACA UN ELEMENTO DE LA LISTA Y LO DEVUELVE
void* ll_pop(LinkedList* this,int index);

//
int ll_contains(LinkedList* this, void* pElement);

int ll_containsAll(LinkedList* this,LinkedList* this2);


//ME DEVUELVE UN PEDDAZO DE LA LISTA 		desde hasta
LinkedList* ll_subList(LinkedList* this,int from,int to);

//DEVUELVE UNA NUEVA LISTA CLONADA
LinkedList* ll_clone(LinkedList* this);

//ORDENA LA LISTA
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
