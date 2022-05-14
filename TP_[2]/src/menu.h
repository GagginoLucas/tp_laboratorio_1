/*
 * menu.h
 * Author: Lucas Gaggino
 */
#include "ArrayPassenger.h"
#include "StatusFlight.h"
#include "utn.h"


#ifndef MENU_H_
#define MENU_H_


/// @brief Call the main menu where the ABM functions will be used
///
/// @param listPassengers Pointer to array of Passenger
/// @param len_ListPassengers Array Passenger lenght
/// @param statusFlight	Pointer to array of status flight
/// @param len_StatusFlight Array statusFlight  lenght
/// @param passengersHardcodeList Pointer to array of a hardcode list of passengers
/// @param len_PassengerHardcode Array hardcode list lenght
void callMainMenu(Passenger* listPassengers, int len_ListPassengers,
				sStatusFlight* statusFlight, int len_StatusFlight,
				Passenger* passengersHardcodeList, int len_PassengerHardcode);


/// @brief Print the main menu and ask for an option
///
/// @return Returns the choosen option
int printMainMenu();


/// @brief Print the report menu and ask for an option
///
/// @return Returns the choosen option
int printReportMenu();

#endif /* MENU_H_ */
