

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"
#include "utn.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return [-1] en caso de error, [1] en caso de que se haya cargado correctamente.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return [-1] en caso de error, [1] en caso de que se haya cargado correctamente.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief Realiza el alta de un pasajero
///
/// @param pArrayListPassenger linkedlist donde se guardará el alta realizada.
/// @return [-1] en caso de error, [1] en caso de que se haya realizado el alta correctamente.
int controller_addPassenger(LinkedList* pArrayListPassenger);

/// @brief Realiza la modificacion de un pasajero
///
/// @param pArrayListPassenger linkedlist donde se encuentra el pasajero a modificar
/// @return  [-1] en caso de error, [1] en caso de que se haya realizado la modificacion correctamente.
int controller_editPassenger(LinkedList* pArrayListPassenger);

/// @brief Realiza la baja de un pasajero
///
/// @param pArrayListPassenger linkedlist donde se encuentra el pasajero a dar de baja
/// @return [-1] en caso de error, [1] en caso de que se haya realizado la baja correctamente.
int controller_removePassenger(LinkedList* pArrayListPassenger);

/// @brief Imprime una lista de pasajeros
///
/// @param pArrayListPassenger linkedlist que será imprimida
/// @return [-1] en caso de error, [1] en caso de que se haya realizado el listar correctamente.
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/// @brief Ordena la lista de pasajeros
///
/// @param pArrayListPassenger linkedlist a ordenar
/// @return [-1] en caso de error, [1] en caso de que se haya realizado el sort correctamente.
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// @brief Imprime el submenu del sort, aparecen las opciones disponibles para ordenar
///
/// @return retorna la opción elegida por el usuario
int controller_printSortMenu();

/// @brief Imprime el orden de ordenamiento(ascendente, descendente)
///
/// @return retorna la opción elegida por el usuario
int controller_printSortOrder();


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return [-1] en caso de error, [1] en caso de que se haya guardado correctamente.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);


/** \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return [-1] en caso de error, [1] en caso de que se haya guardado correctamente.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/// @brief Lee el último id ingresado del archivo lastID.txt
///
/// @return retorne el ID leido
int cotroller_ReadFileLastID();

/// @brief En caso de un alta, escribe en el archivo LastID.txt el nuevo ID
///
/// @param newLastID nuevo id a escribir en lastID.txt
void cotroller_WriteFileLastID(int newLastID);

/// @brief Imprime el menú principal del main
///
/// @return la opción elegida por el usuario
int controller_PrintMainMenu();

#endif /* CONTROLLER_H_ */
