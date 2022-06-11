
#ifndef PARSER_H_
#define PARSER_H_
#include "Passenger.h"
#define FILESIZE 50


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path Puntero al ARCHIVO
 * \param pArrayListPassenger LinkedList* donde se guardaran los datos
 * \return [-1] en caso de error, [1] en caso de que se haya parseado correctamente.
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);



/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param pFile Puntero al ARCHIVO
 * \param pArrayListPassenger LinkedList* donde se guardaran los datos
 * \return [-1] en caso de error, [1] en caso de que se haya parseado correctamente.
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);



#endif /* PARSER_H_ */
