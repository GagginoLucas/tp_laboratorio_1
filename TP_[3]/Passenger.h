/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#define NAMESIZE 50
#define FLYCODESIZE 20
#define MAXPRICE 9999999

typedef struct
{
	int id;
	char name[NAMESIZE];
	char lastName[NAMESIZE];
	float price;
	int typePassenger;
	char flyCode[FLYCODESIZE];
	int statusFlight;

}Passenger;


/// @brief Crea espacio de memoria para un nuevo pasajero.
///
/// @return Retorna NULL si no encontro espacio de memoria para un nuevo pasajero
/// 		o la dirección de memoria de un *Passenger si encontró memoria en el heap.
Passenger* Passenger_new();


/// @brief Crea un pasajero en memoria y setea los campos recibidos que sera todo texto(data.csv)
///
/// @param idStr ID a setear
/// @param nameStr Nombre a setear
/// @param lastNameStr Apellido a setear
/// @param priceStr  Precio a setear
/// @param flyCodeStr Codigo de vuelo a setear
/// @param typePassengerStr tipo de pasajero a setear
/// @param statusFlightStr Estado de vuelo a setear
/// @return Retorna NULL si no se pudo crear el pasajero, o retorna un *Passenger si todo se seteo correctamente.
Passenger* Passenger_newParametros(char* idStr,char* nameStr,char* lastNameStr,
		char* priceStr,char* flyCodeStr,char* typePassengerStr,
		char* statusFlightStr);


/// @brief Crea un pasajero en memoria y setea los campos recibidos(Lo utilizo para el alta)
///
/// @param auxID ID a setear
/// @param auxName  Nombre a setear
/// @param auxLastName Apellido a setear
/// @param auxPrice Precio a setear
/// @param auxFlyCode Codigo de vuelo a setear
/// @param auxTypePassenger tipo de pasajero a setear
/// @param auxStatusFlight Estado de vuelo a setear
/// @return Retorna NULL si no se pudo crear el pasajero, o retorna un *Passenger si todo se seteo correctamente.
Passenger* Passenger_newPararameters(int auxID, char* auxName, char* auxLastName,
		float auxPrice, char* auxFlyCode, int auxTypePassenger,
		int auxStatusFlight);

/// @brief Elimina un pasajero de la memoria
///
/// @param this *Passenger a eliminar
void Passenger_delete(Passenger* this);

/// @brief Remueve un pasajero de la linkedlist
///
/// @param pArrayListPassenger Lista de pasajeros en la que se encuentra el pasajero a remover
/// @return [-1] en caso de error, [1] en caso de que se haya podido eliminar al pasajero de la lista correctamente.
int Passenger_RemovePassenger(LinkedList* pArrayListPassenger);

/// @brief Setea y Valida que los set hayan sido correctamente realizados
///
/// @param pOnePassenger Puntero a pasajero al que se le setearan los datos.
/// @param auxID ID a setear y validar
/// @param auxName Nombre a setear y validar
/// @param auxLastName Apellido a setear y validar
/// @param auxPrice Precio a setear y validar
/// @param auxFlyCode Codigo de vuelo a setear y validar
/// @param auxTypePassenger Tipo de pasajero a setear y validar
/// @param auxStatusFlight Estado de vuelo a setear y validar
/// @return retorna [-1] en caso de error, [1] en caso de se haya seteado correctamente.
int Passenger_SetValidatePassengerData( Passenger* pOnePassenger,int auxID, char* auxName, char* auxLastName,
									   	float auxPrice, char* auxFlyCode, int auxTypePassenger,
									    int auxStatusFlight);



/// @brief  Setea y Valida que los set hayan sido correctamente realizados(Para el modo texto)
///
/// @param pOnePassenger Puntero a pasajero al que se le setearan los datos.
/// @param idStr ID a setear y validar
/// @param nameStr Nombre a setear y validar
/// @param lastNameStr Apellido a setear y validar
/// @param priceStr Precio a setear y validar
/// @param flyCodeStr Codigo de vuelo a setear y validar
/// @param typePassenger Tipo de pasajero a setear y validar
/// @param statusFlight Estado de vuelo a setear y validar
/// @return retorna [-1] en caso de error, [1] en caso de se haya seteado correctamente.
int Passenger_SetValidatePassengerDataFromFile( Passenger* pOnePassenger, char* idStr,char* nameStr,
												char* lastNameStr,char* priceStr,char* flyCodeStr,
												int typePassenger, int statusFlight);



/// @brief Realiza el Get de un pasajero y valida que haya sido correctamente realizado
///
/// @param pOnePassenger *Passenger a relizarle el get
/// @param auxID Donde se guardará el ID traido con el get
/// @param auxName donde se guardará el NOMBRE traido con el get
/// @param auxLastName donde se guardará el APELLIDO traido con el get
/// @param auxPrice donde se guardará el Precio traido con el get
/// @param auxTypePassenger donde se guardará el TIPO DE PASAJERO traido con el get
/// @param auxFlyCode donde se guardará el FLYCODE traido con el get
/// @param auxStatusFlight donde se guardará el STATUSFLIGHT traido con el get
/// @return retorna [-1] en caso de error, [1] en caso de se haya echo el get correctamente.
int Passenger_GetValidatePassengerData( Passenger* pOnePassenger,int* auxID, char* auxName,
										char* auxLastName, float* auxPrice,int* auxTypePassenger,
										char* auxFlyCode, int* auxStatusFlight);


/// @brief Se encargará de realizar la carga de los datos del pasajero para el ALTA
///
/// @param pArrayListPassenger Linkedlist en la que se guardará el nuevo pasajero
/// @return [-1] en caso de error, [1] en caso de que el pasajero se haya cargado correctamente a la ll.
int loadPassengerData(LinkedList* pArrayListPassenger);


/// @brief Setea el id de un pasajero
///
/// @param this Pasajero al que se le realizará el set
/// @param id ID a setear
/// @return [-1] en caso de error, [1] en caso de que se haya seteado correctamente.
int Passenger_setId(Passenger* this,int id);

/// @brief Obtener el id de un pasajero
///
/// @param this Pasajero a obtener el ID
/// @param ID Puntero en donde se guardará el ID obtenido
/// @return [-1] en caso de error, [1] en caso de que se haya obtenido correctamente.
int Passenger_getId(Passenger* this, int* ID);


/// @brief Setea el nombre de un pasajero
///
/// @param this Pasajero al que se le realizará el set
/// @param name NOMBRE a setear
/// @return [-1] en caso de error, [1] en caso de que se haya seteado correctamente.
int Passenger_setName(Passenger* this,char* name);

/// @brief Obtener el nombre de un pasajero
///
/// @param this Pasajero a obtener el NOMBRE
/// @param name Puntero en donde se guardará el Nombre obtenido
/// @return [-1] en caso de error, [1] en caso de que se haya obtenido correctamente.
int Passenger_getName(Passenger* this,char* name);


/// @brief Setea el apellido de un pasajero
///
/// @param this Pasajero al que se le realizará el set
/// @param lastName APELLIDO a setear
/// @return [-1] en caso de error, [1] en caso de que se haya seteado correctamente.
int Passenger_setLastName(Passenger* this,char* lastName);

/// @brief Obtener el apellido de un pasajero
///
/// @param this Pasajero a obtener el APELLIDO
/// @param lastName Puntero en donde se guardará el apellido obtenido
/// @return [-1] en caso de error, [1] en caso de que se haya obtenido correctamente.
int Passenger_getLastName(Passenger* this,char* lastName);


/// @brief Setea el flyCode de un pasajero
///
/// @param this Pasajero al que se le realizará el set
/// @param flyCode flyCode a setear
/// @return [-1] en caso de error, [1] en caso de que se haya seteado correctamente.
int Passenger_setFlyCode(Passenger* this,char* flyCode);

/// @brief Obtener el flyCode de un pasajero
///
/// @param this Pasajero a obtener el flyCode
/// @param flyCode Puntero en donde se guardará el flyCode obtenido
/// @return [-1] en caso de error, [1] en caso de que se haya obtenido correctamente.
int Passenger_getFlyCode(Passenger* this,char* flyCode);


/// @brief Setea el typePassenger de un pasajero
///
/// @param this Pasajero al que se le realizará el set
/// @param typePassenger typePassenger a setear
/// @return [-1] en caso de error, [1] en caso de que se haya seteado correctamente.
int Passenger_setTypePassenger(Passenger* this,int typePassenger);

/// @brief Obtener el typePassenger de un pasajero
///
/// @param this Pasajero a obtener el typePassenger
/// @param typePassenger Puntero en donde se guardará el typePassenger obtenido
/// @return [-1] en caso de error, [1] en caso de que se haya obtenido correctamente.
int Passenger_getTypePassenger(Passenger* this,int* typePassenger);


/// @brief Setea el precio de un pasajero
///
/// @param this Pasajero al que se le realizará el set
/// @param typePassenger precio a setear
/// @return [-1] en caso de error, [1] en caso de que se haya seteado correctamente.
int Passenger_setPrice(Passenger* this,float price);

/// @brief Obtener el precio de un pasajero
///
/// @param this Pasajero a obtener el precio
/// @param price Puntero en donde se guardará el precio obtenido
/// @return [-1] en caso de error, [1] en caso de que se haya obtenido correctamente.
int Passenger_getPrice(Passenger* this,float* price);


/// @brief Setea el statusFlight de un pasajero
///
/// @param this Pasajero al que se le realizará el set
/// @param statusFlight statusFlight a setear
/// @return [-1] en caso de error, [1] en caso de que se haya seteado correctamente.
int Passenger_setStatusFlight(Passenger* this, int statusFlight);

/// @brief Obtener el statusFlight de un pasajero
///
/// @param this Pasajero a obtener el statusFlight
/// @param statusFlight Puntero en donde se guardará el statusFlight obtenido
/// @return [-1] en caso de error, [1] en caso de que se haya obtenido correctamente.
int Passenger_getStatusFlight(Passenger* this, int* statusFlight);


/// @brief  le Asigna un entero al statusFlightStr ingresado
///
/// @param statusFlightStr estado de vuelo a convertir en entero
/// @return retorna [1] si statusFlightStr es [DEMORADO]
/// 		retorna [2] si statusFlightStr es [ATERRIZANDO]
/// 		retorna [3] si statusFlightStr es [EN HORARIO]
int StatusFlightToInt(char* statusFlightStr);

/// @brief  le Asigna un entero al typePassengerStr ingresado
///
/// @param typePassengerStr tipo de pasajero a convertir en entero
/// @return retorna [1] si typePassengerStr es [FirstClass]
/// 		retorna [2] si typePassengerStr es [ExecutiveClass]
/// 		retorna [3] si typePassengerStr es [EconomyClass]
int typePassengerToInt(char* typePassengerStr);

/// @brief le asigna el string correspondiente al typePassengerInt ingresado
///
/// @param typeInt int de type passenger
/// @param typeStr puntero donde se guardará la cadena
void typePassengerToChar(int typeInt, char* typeStr);

/// @brief le asigna el string correspondiente al statusInt ingresado
///
/// @param statusInt int de estado devuelo
/// @param statusStr puntero donde se guardará la cadena
void statusFlightToChar(int statusInt, char* statusStr);

/// @brief Realiza la modificación de un pasajero que se encuentra en la ll
///
/// @param pArrayListPassenger linkedlist
/// @return [-1] en caso de error, [1] en caso de que se haya realizado la modificación.
int Passenger_ModifyPassengers(LinkedList* pArrayListPassenger);

/// @brief imprime el menú de modificaciones
///
/// @param aux mostrará los datos del pasajero a modificar
/// @param option puntero donde se guardará la opción ingresada del menú.
void printModifyMenu(Passenger aux, int* option);

/// @brief Busca un pasajero por ID en la linkedlist
///
/// @param pArrayListPassenger linkedlist
/// @param id ID a buscar
/// @return [-1] en caso de error, o el [index] en el que se encuentra el pasajero buscado en la linkedlist
int Passenger_FindPassengerById(LinkedList* pArrayListPassenger, int id);

/// @brief Modifica los datos de un pasajero
///
/// @param pArrayListPassenger Linkedlist
/// @param index indice en el que se encuentra el pasajero en la linkedlist
/// @return [-1] en caso de error, [1] en caso de que se haya realizado la modificación.
int Passenger_ModifyOnePassenger(LinkedList* pArrayListPassenger, int index);


/// @brief Imprime el header
void printHeader();

/// @brief Imprime un pasajero
///
/// @param this pasajero a imprimir
/// @return [-1] en caso de error, [1] si se pudo imprimir correctamente
int Passenger_printOnePassenger(Passenger* this);

/// @brief Imprime la lista de pasajeros completa
///
/// @param pArrayListPassenger Lista de pasajeros a imprimir
/// @return [-1] en caso de error, [1] si se pudo imprimir correctamente
int Passenger_listPassengers(LinkedList* pArrayListPassenger);


/// @brief Recibe dos punteros a void, los castea a tipo Passenger, y los compara por ID
/// @param firstID Puntero que se comparará
/// @param secondID puntero con el que se comparará
/// @return [-1] si el primero es menor que el segundo
/// 		[0] si son iguales
/// 		[1] si el primero es mayor que el segundo
int Passenger_sortByID(void* firstID, void* secondID);


/// @brief Recibe dos punteros a void, los castea a tipo Passenger, y los compara por NOMBRE
/// @param firstName Puntero que se comparará
/// @param secondName puntero con el que se comparará
/// @return [-1] si el primero es menor que el segundo
/// 		[0] si son iguales
/// 		[1] si el primero es mayor que el segundo
int Passenger_sortByName(void* firstName, void* secondName);

/// @brief Recibe dos punteros a void, los castea a tipo Passenger, y los compara por APELLIDO
/// @param FirstLastName Puntero que se comparará
/// @param secondLastName puntero con el que se comparará
/// @return [-1] si el primero es menor que el segundo
/// 		[0] si son iguales
/// 		[1] si el primero es mayor que el segundo
int Passenger_sortByLastName(void* FirstLastName, void* secondLastName);

/// @brief Recibe dos punteros a void, los castea a tipo Passenger, y los compara por PRECIO
/// @param firstPrice Puntero que se comparará
/// @param secondPrice puntero con el que se comparará
/// @return [-1] si el primero es menor que el segundo
/// 		[0] si son iguales
/// 		[1] si el primero es mayor que el segundo
int Passenger_sortByPrice(void* firstPrice, void* secondPrice);


/// @brief Recibe dos punteros a void, los castea a tipo Passenger, y los compara por FLYCODE
/// @param firstFlyCode Puntero que se comparará
/// @param secondFlyCode puntero con el que se comparará
/// @return [-1] si el primero es menor que el segundo
/// 		[0] si son iguales
/// 		[1] si el primero es mayor que el segundo
int Passenger_sortByFlyCode(void* firstFlyCode, void* secondFlyCode);

/// @brief Recibe dos punteros a void, los castea a tipo Passenger, y los compara por ESTADO DE VUELO
/// @param firstStatusFlight Puntero que se comparará
/// @param secondStatusFlight puntero con el que se comparará
/// @return [-1] si el primero es menor que el segundo
/// 		[0] si son iguales
/// 		[1] si el primero es mayor que el segundo
int Passenger_sortByStatusFlight(void* firstStatusFlight, void* secondStatusFlight);

/// @brief Recibe dos punteros a void, los castea a tipo Passenger, y los compara por TIPO DE PASAJERO
/// @param firstTypePassenger Puntero que se comparará
/// @param secondTypePassenger puntero con el que se comparará
/// @return [-1] si el primero es menor que el segundo
/// 		[0] si son iguales
/// 		[1] si el primero es mayor que el segundo
int Passenger_sortByTypePassenger(void* firstTypePassenger, void* secondTypePassenger);

///
//int Passenger_GetMaxID(LinkedList* pArrayListPassenger);


#endif /* PASSENGER_H_ */
