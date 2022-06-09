/*
 * array.h
 *
 *  Created on: 28 may. 2022
 *      Author: Lucas
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include "Passenger.h"

int alumno_initArray(Passenger* arrayPunteros[],int limite);
int alumno_buscarLibreArray(Passenger* arrayPunteros[],int limite);
int alumno_imprimirArray(Passenger* arrayPunteros[],int limite);

#endif /* ARRAY_H_ */
