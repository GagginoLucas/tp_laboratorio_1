/*
 * ArrayPassenger.h
 * Author: Lucas Gaggino
 */

#include "utn.h"
#include "StatusFlight.h"


#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

///DEFINES
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define MAX_CHARS_NOMBRE 32
#define MAX_CHARS_FLYCODE 10


/// DECLARO ESTRUCTURA
typedef struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int isEmpty;
int idStatusFlight;
}Passenger;



///CABECERAS DE FUNCIONES PARA EL ABM

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);


/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (1) if Ok

*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int idStatusFlight);


/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int len);


/// @brief  print the content of passenger array
///
/// @param list Passenger
void sPassenger_PrintOnePassenger(Passenger list);


/// @brief remove an existing passenger of the list by putting the isEmpty in -1
///
/// @param list Passenger*
/// @param len lenght of array passenger
/// @return [0] in case of error, [1] in case of the logic low was done right
int removePassenger(Passenger* list, int len);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [2] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengersByCode(Passenger* list, int len, int order);


/// @brief Look for a free index position in the Passenger list array
///
/// @param list Passenger*
/// @param LEN lenght array
/// @return the free index position
int sPassenger_GetFreeIndex(Passenger* list	, int LEN);


/// @brief find a passenger by ID
///
/// @param list Passenger*
/// @param LEN lenght array
/// @param ID Id you are looking for in the passenger list
/// @return return the index position where the ID is
int findPassengerById(Passenger* list, int LEN,int ID);


/// @brief charge the passenger data to add it to a list
///
/// @param list Passenger*
/// @param len lenght array
/// @return  Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sPassenger_LoadPassenger(Passenger* list, int len);


/// @brief print the Type passengers
///
/// @param idType id TypePassenger that you want to print
void displayTypePassenger(int idType);


/// @brief modify in an existing list of passengers the values received as parameters
///
/// @param list Passenger*
/// @param len lenght array
/// @return [0] in case of error, [1] if the modification was done right
int sPassenger_ModifyPassengers(Passenger* list, int len);


/// @brief modify the parameters of one index position
///
/// @param list Passenger
/// @return return the modified passenger list
Passenger sPassenger_ModifyOnePassenger(Passenger list);


/// @brief calculate the passengers over the average price
///
/// @param list Passenger*
/// @param len lenght array
/// @param promedio total promedy of prices
/// @return the amount of passengers over the average price
int sPassenger_CalculatePassengersOverAverage(Passenger* list, int len, int promedio);


/// @brief calculate the total passenger prices
///
/// @param list Passenger*
/// @param len lenght array
/// @return the amount of total passenger prices
float sPassenger_CalculateTotal(Passenger* list, int len);


/// @brief calculate the average prices
///
/// @param total total prices
/// @param cantidadDatos amount of passengers loaded
/// @return return the average price
float sPassenger_CalculateAverage(int total, int cantidadDatos);


/// @brief print the passengers ordered by the FLYCODE and the status flight
///
/// @param status statusFlight*
/// @param lenStatus lenght of Status array
/// @param list Passenger*
/// @param len lenght of Passenger array
/// @return [0] in case of error  [1] if you have passengers to print
int sPassenger_DisplayPassengersByStatusFlight(sStatusFlight* status,int lenStatus, Passenger* list, int len);


/// @brief print the status flight
///
/// @param idStatus id status that you want to print
void displayStatusFlight(int idStatus);

/// @brief print the columns to show the list of passengers
///
void sPassenger_printColumnList();


/// @brief print the passengers sorting by FLYCODE by chosing the order
///
/// @param list PassengeR*
/// @param len lenght passenger array
/// @param status sStatusFlight*
/// @param len_status lenght status array
void sPassenger_DisplayPassengersByCode(Passenger* list, int len, sStatusFlight* status, int len_status);


/// @brief print the passengers list sorting by Last name and the type passenger
///
/// @param list Passenger*
/// @param len lenght passenger array
void sPassenger_DisplayPassengersByOrder(Passenger* list, int len);


/// @brief harcode the passengers in the existing passenger list
///
/// @param list Passenger*
/// @param len lenght passenger array
/// @param hardcodeList Passenger*
/// @param len_hardcodeList lenght hardcode passenger list array
void sPassenger_HardcodePassengers(Passenger* list, int len, Passenger* hardcodeList, int len_hardcodeList);

/// @brief print the total price, the average prices, and the amount of passengers over the average
///
/// @param list Passeger*
/// @param len lenght passenger array
/// @param cantidadDatos amount of charged passengers
void sPassenger_DisplayAverage(Passenger* list, int len, int cantidadDatos);


#endif /* ARRAYPASSENGER_H_ */
