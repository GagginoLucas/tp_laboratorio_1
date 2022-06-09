/*
 * array.c
 *
 *  Created on: 26 may. 2022
 *      Author: Lucas
 */
#include "array.h"

int alumno_initArray(Passenger* arrayPunteros[],int limite){
    int retorno=-1;
    int i;
    if(arrayPunteros!= NULL && limite>0) {
        retorno=-2;
        for(i=0;i<limite;i++)
        {
            if(arrayPunteros[i] == NULL)
            {
                 retorno=1;
                 break;
            }
        }
    }
    return retorno;
  }

int alumno_buscarLibreArray(Passenger* arrayPunteros[],int limite) {
    int retorno=-1;
    int i;
    if(arrayPunteros!=NULL && limite>0)
    {
        retorno=-2;
        for(i=0;i<limite;i++)
        {
            if(arrayPunteros[i]== NULL)
            {
                retorno=1;
                break;
           }
        }
    }
    return retorno;
}

int alumno_imprimirArray(Passenger* arrayPunteros[],int limite) {
	int retorno=-1;
	int i;
	if(arrayPunteros!=NULL && limite>0) {
		for(i=0;i<limite;i++) {
			if(arrayPunteros[i]!=NULL) {
				printf("Nombre:%s- ID:%d\n",arrayPunteros[i]->name,arrayPunteros[i]->id);
			}
		}
	}
return retorno;
}
