/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#define NAMESIZE 50
#define FLYCODESIZE 8
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


int Passenger_getID();
int Passenger_GetMaxID(LinkedList* pArrayListPassenger);

int Passenger_GetValidatePassengerData(Passenger* pOnePassenger,int* auxID, char* auxName,
		char* auxLastName, float* auxPrice,int* auxTypePassenger,
		char* auxFlyCode, int* auxStatusFlight);

int Passenger_SetValidatePassengerData(Passenger* pOnePassenger,int auxID, char* auxName, char* auxLastName,
									   float auxPrice, char* auxFlyCode, int auxTypePassenger,
									   int auxStatusFlight);

int Passenger_SetValidatePassengerDataFromFile(Passenger* pOnePassenger, char* idStr,char* nameStr,
		char* lastNameStr,char* priceStr,char* flyCodeStr,
		int typePassenger, int statusFlight);

int loadPassengerData(LinkedList* pArrayListPassenger);

Passenger* Passenger_newPararameters(int auxID, char* auxName, char* auxLastName,
		float auxPrice, char* auxFlyCode, int auxTypePassenger,
		int auxStatusFlight);

Passenger* Passenger_new();

Passenger* Passenger_newParametros(char* idStr,char* nameStr,char* lastNameStr,
		char* priceStr,char* flyCodeStr,char* typePassengerStr,
		char* statusFlightStr);

void Passenger_delete(Passenger* this);
int Passenger_RemovePassenger(LinkedList* pArrayListPassenger);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this, int* ID);

int Passenger_setName(Passenger* this,char* name);
int Passenger_getName(Passenger* this,char* name);

int Passenger_setLastName(Passenger* this,char* lastName);
int Passenger_getLastName(Passenger* this,char* lastName);

int Passenger_setFlyCode(Passenger* this,char* flyCode);
int Passenger_getFlyCode(Passenger* this,char* flyCode);

int Passenger_setTypePassenger(Passenger* this,int typePassenger);
int Passenger_getTypePassenger(Passenger* this,int* typePassenger);

int Passenger_setPrice(Passenger* this,float price);
int Passenger_getPrice(Passenger* this,float* price);

int Passenger_setStatusFlight(Passenger* this, int statusFlight);
int Passenger_getStatusFlight(Passenger* this, int* statusFlight);

int statusFlightToInt(char* statusFlightStr);
int typePassengerToInt(char* typePassengerStr);

void typePassengerToChar(int typeInt, char* typeStr);
void statusFlightToChar(int statusInt, char* statusStr);

int Passenger_ModifyPassengers(LinkedList* pArrayListPassenger);
void printModifyMenu(Passenger aux, int* option);

int Passenger_FindPassengerById(LinkedList* pArrayListPassenger, int id);
int Passenger_ModifyOnePassenger(LinkedList* pArrayListPassenger, int index);

void printHeader();
int Passenger_printOnePassenger(Passenger* this);
int Passenger_listPassengers(LinkedList* pArrayListPassenger);

#endif /* PASSENGER_H_ */
