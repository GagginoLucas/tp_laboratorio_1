/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"


// ID AUTOINCREMENTAL CON VARIABLE EST�TICA






int Passenger_GetMaxID(LinkedList* pArrayListPassenger) {

	int idMax = 1000;
	int id;
	int len;
	int i;
	Passenger* aux;

	if(pArrayListPassenger!=NULL) {

		len = ll_len(pArrayListPassenger);

		if(len>0)
		{
			for(i=0;i<len;i++)
			{
				aux = ll_get(pArrayListPassenger ,i); //Me va a dar el último ID cargado
				Passenger_getId(aux,&id); //

				if(i==0 || (idMax<id))
				{
					idMax=id;
				}
			}
		}
	}

	return idMax;
}

int Passenger_GetValidatePassengerData(Passenger* pOnePassenger,int* auxID, char* auxName,
		char* auxLastName, float* auxPrice,int* auxTypePassenger,
		char* auxFlyCode, int* auxStatusFlight) {

	int rtn = -1;
	if(pOnePassenger != NULL) {

		if(  	(Passenger_getId(pOnePassenger, auxID) == 1) &&
				(Passenger_getName(pOnePassenger, auxName) == 1) &&
				(Passenger_getLastName(pOnePassenger, auxLastName) == 1) &&
				(Passenger_getPrice(pOnePassenger, auxPrice) == 1) &&
				(Passenger_getFlyCode(pOnePassenger, auxFlyCode) == 1) &&
				(Passenger_getTypePassenger(pOnePassenger,auxTypePassenger) == 1) &&
				(Passenger_getStatusFlight(pOnePassenger,auxStatusFlight) == 1)) {

			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_SetValidatePassengerData(Passenger* pOnePassenger,int auxID, char* auxName, char* auxLastName,
									   float auxPrice, char* auxFlyCode, int auxTypePassenger,
									   int auxStatusFlight) {

	int rtn = -1;
	if(pOnePassenger != NULL) {

		if(  	(Passenger_setId(pOnePassenger, auxID) == 1) &&
				(Passenger_setName(pOnePassenger, auxName) == 1) &&
				(Passenger_setLastName(pOnePassenger, auxLastName) == 1) &&
				(Passenger_setPrice(pOnePassenger, auxPrice) == 1) &&
				(Passenger_setFlyCode(pOnePassenger, auxFlyCode) == 1) &&
				(Passenger_setTypePassenger(pOnePassenger,auxTypePassenger) == 1) &&
				(Passenger_setStatusFlight(pOnePassenger,auxStatusFlight) == 1)) {

			rtn = 1;
		}
	}
	return rtn;
}

int Passenger_SetValidatePassengerDataFromFile(Passenger* pOnePassenger, char* idStr,char* nameStr,
												char* lastNameStr,char* priceStr,char* flyCodeStr,
												int typePassenger, int statusFlight) {
	int rtn = -1;
	if(pOnePassenger != NULL) {
		if(  	(Passenger_setId(pOnePassenger, atoi(idStr)) == 1) &&
				(Passenger_setName(pOnePassenger, nameStr) == 1) &&
				(Passenger_setLastName(pOnePassenger, lastNameStr) == 1) &&
				(Passenger_setPrice(pOnePassenger, atof(priceStr)) == 1) &&
				(Passenger_setFlyCode(pOnePassenger, flyCodeStr) == 1) &&
				(Passenger_setTypePassenger(pOnePassenger,typePassenger) == 1) &&
				(Passenger_setStatusFlight(pOnePassenger,statusFlight) == 1)) {

			rtn = 1;
		}
	}
	return rtn;

}

int Passenger_RemovePassenger(LinkedList* pArrayListPassenger) {

	int rtn = -1;
	int idPassenger;
	int index;
	Passenger* pAuxPassenger = NULL;

	//LISTO TODOS LOS Producto
	if(pArrayListPassenger!= NULL) {
		controller_ListPassenger(pArrayListPassenger);
		do
		{
			get_Int(&idPassenger, "Ingresar ID del pasajerx que desea remover: ");
			index = Passenger_FindPassengerById(pArrayListPassenger,idPassenger);
			if(index != -1) {
				pAuxPassenger = ll_get(pArrayListPassenger, index);
				Passenger_printOnePassenger(pAuxPassenger);
				if(askToConfirm("Esta segurx que desea continuar? Los datos se perderan. S|N")==1){
					pAuxPassenger  = ll_pop(pArrayListPassenger, index);
					Passenger_delete(pAuxPassenger);
					rtn = 1;
				}

			}
		}while( index == -1  && askToConfirm("No se encontro un pasajerx con esa id, desea volver a buscar? S|N")==1);

	}

	return rtn;
}

void printModifyMenu(Passenger aux, int* option) {

	printf("SELECCIONE QUE OPCION DESEA MODIFICAR\n");
	printf("1. Nombre (%s)\n", aux.name);
	printf("2. Apellido (%s)\n", aux.lastName);
	printf("3. Precio ($ %.2f)\n", aux.price);
	printf("4. Codigo de vuelo (%s)\n", aux.flyCode);
	printf("5. Tipo de pasajero: %d\n", aux.typePassenger);
	printf("6. Finalizar modificacion\n");
	get_IntInRange(option, "Opcion: ",1, 6);
}

int Passenger_ModifyOnePassenger(LinkedList* pArrayListPassenger, int index) {
	int rtn = -1;
	Passenger* aux = NULL;
	Passenger auxToModify;
	int option;
	int confirm;
	if(pArrayListPassenger!= NULL) {

		aux = ll_get(pArrayListPassenger, index);
		Passenger_printOnePassenger(aux);
		if(aux != NULL) {

			auxToModify = *aux;
			do
			{
				printModifyMenu(auxToModify, &option);
				switch(option) {
				case 1 :get_String("Ingrese nombre: ", auxToModify.name, NAMESIZE);
				sortString(auxToModify.name);
				break;
				case 2:get_String("Ingrese apellido: ", auxToModify.lastName, NAMESIZE);
				sortString(auxToModify.lastName);
				break;
				case 3: get_FloatInRange(&auxToModify.price,"Ingrese precio: ", 1 , 99999999);
				break;
				case 4: get_AlphaNum("Ingresar codigo de vuelo: ", auxToModify.flyCode, FLYCODESIZE);
				break;
				case 5: get_IntInRange(&auxToModify.typePassenger,"Ingrese tipo de pasajero\n"
						"1.Primera clase\n"
						"2.Clase ejecutiva\n"
						"3.Clase turista\n"
						"OPCION: ", 1, 3);
				break;
				case 6: confirm = askToConfirm("Esta seguro que desea salir? (S|N)");
				if(confirm == 1) {
					confirm = askToConfirm("Esta seguro que desea Modificar los datos? (S|N)");
					if(confirm == 1) {
						*aux = auxToModify;
						rtn = 1;
					}
					option = 7;
				}

				}
			}while(option!=7);
		}
	}	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return rtn;
}

int Passenger_FindPassengerById(LinkedList* pArrayListPassenger, int id) {

	int i;
	int len;
	int index = -1;
	Passenger* pauxPassenger;
	int auxId;

	if(pArrayListPassenger!=NULL) {

		len = ll_len(pArrayListPassenger);
		if(len>0) {

			for(i=0; i<len ;i++) {

				pauxPassenger = ll_get(pArrayListPassenger,i);
				Passenger_getId(pauxPassenger, &auxId);
				if(auxId==id) {
					index=i;
					break;
				}
			}
		}
	}

	return index;

}



int Passenger_ModifyPassengers(LinkedList* pArrayListPassenger) {

	int rtn = -1;
	int idPassenger;
	int index;

	//LISTO TODOS LOS Producto
	if(pArrayListPassenger!= NULL) {
		Passenger_listPassengers(pArrayListPassenger);
		do
		{
			get_Int(&idPassenger, "\nIngresar ID a modificar: ");
			index = Passenger_FindPassengerById(pArrayListPassenger,idPassenger);
			if(index != -1) {

				if(Passenger_ModifyOnePassenger(pArrayListPassenger, index)==1) {
					rtn = 1;
				}

			}
		}while( index == -1  && askToConfirm("No se encontro un pasajero con esa id, desea volver a buscar? S|N")==1);

	}
	return rtn;
}

int loadPassengerData(LinkedList* pArrayListPassenger) {
	int rtn = -1;
	char auxName[NAMESIZE];
	char auxLastName[NAMESIZE];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[FLYCODESIZE];
	int auxStatusFlight;
	int auxID = cotroller_ReadFileLastID();
	auxID+=1;
	cotroller_WriteFileLastID(auxID);

	Passenger* aux = NULL;

	get_String("Ingresar nombre: ",auxName,NAMESIZE);
	sortString(auxName);
	get_String("Ingresar apellido: ",auxLastName,NAMESIZE);
	sortString(auxLastName);
	get_Float(&auxPrice,"Ingresar precio: ");
	get_AlphaNum("Ingresar codigo de vuelo: ",auxFlyCode, FLYCODESIZE);
	get_IntInRange(&auxTypePassenger,"Ingresar el tipo de pasajerx\n"
			"1.Primera clase.\n"
			"2.Clase ejecutiva.\n"
			"3.Clase turista.\n"
			"Opción: ",1,3);
	get_IntInRange(&auxStatusFlight,"Ingresar el estado del vuelo\n"
			"1.Demorado.\n"
			"2.Aterrizado.\n"
			"3.En horario.\n"
			"Opción: ",1,3);
	if(askToConfirm("\nEsta segurx que desea cargar los datos ingresados? S/N \n")==1){
		aux = Passenger_newPararameters(auxID, auxName, auxLastName, auxPrice,auxFlyCode, auxTypePassenger, auxStatusFlight);
		if(aux!=NULL) {

			ll_add(pArrayListPassenger, aux);
			rtn = 1;
		}else
		{
			Passenger_delete(aux);
		}
	}

	return rtn;
}

int typePassengerToInt(char* typePassengerStr) {
	int aux;
	if (strcmp(typePassengerStr, "FirstClass") == 0) {

		aux = 1;

	} else if (strcmp(typePassengerStr, "ExecutiveClass") == 0) {

		aux = 2;

	}else if (strcmp(typePassengerStr, "EconomyClass") == 0) {

		aux = 3;
	}

	return aux;
}
int StatusFlightToInt(char* statusFlightStr) {

	int aux;
	if (strcmp(statusFlightStr, "Demorado") == 0) {

		aux = 1;

	} else if (strcmp(statusFlightStr, "Aterrizado") == 0) {

		aux = 2;

	}else if (strcmp(statusFlightStr, "En Horario") == 0) {

		aux = 3;
	}

	return aux;
}

void typePassengerToChar(int typeInt, char* typeStr) {

	switch(typeInt) {
	case 1: strcpy(typeStr, "FirstClass");
	break;
	case 2: strcpy(typeStr, "ExecutiveClass");
	break;
	case 3: strcpy(typeStr, "En Horario");
	break;
	}
}


void statusFlightToChar(int statusInt, char* statusStr) {

	switch(statusInt) {
	case 1: strcpy(statusStr, "Demorado");
	break;
	case 2: strcpy(statusStr, "Aterrizado");
	break;
	case 3: strcpy(statusStr, "EconomyClass");
	break;
	}
}

Passenger* Passenger_new() {
	return (Passenger*)malloc(sizeof(Passenger));
}

void Passenger_delete(Passenger* this) {

	if(this!=NULL) {

		free(this);
		this=NULL;
	}
}

Passenger* Passenger_newPararameters(int auxID, char* auxName, char* auxLastName,
		float auxPrice, char* auxFlyCode, int auxTypePassenger,
		int auxStatusFlight) {
	Passenger* pOnePassenger = NULL;
	pOnePassenger = Passenger_new();
	if(pOnePassenger != NULL){
		if(Passenger_SetValidatePassengerData(pOnePassenger,auxID, auxName, auxLastName,
				auxPrice, auxFlyCode, auxTypePassenger,
				auxStatusFlight) !=1) {

			Passenger_delete(pOnePassenger);
		}
	}
	return pOnePassenger;

}




Passenger* Passenger_newParametros( char* idStr,char* nameStr,char* lastNameStr,
		char* priceStr,char* flyCodeStr,char* typePassengerStr,
		char* statusFlightStr) {
	Passenger* pOnePassenger = NULL;
	int auxTypePassenger;
	int auxStatusFlight;
	auxTypePassenger = typePassengerToInt(typePassengerStr);
	auxStatusFlight = StatusFlightToInt(statusFlightStr);
	pOnePassenger = Passenger_new();
	if(pOnePassenger != NULL){
		if(Passenger_SetValidatePassengerDataFromFile(pOnePassenger, idStr, nameStr,
				lastNameStr, priceStr, flyCodeStr,
				auxTypePassenger, auxStatusFlight)!=1) {

			Passenger_delete(pOnePassenger);
		}
	}
	return pOnePassenger;
}



void printHeader() {

	printf("%10s %20s %20s %10s %20s %20s %20s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "TIPO DE PASAJERO", "FLYCODE", "STATUS");
}

int Passenger_listPassengers(LinkedList* pArrayListPassenger) {
	int rtn;
	rtn = -1;
	int i;
	Passenger* pPassenger = NULL;
	if(pArrayListPassenger != NULL){
		printHeader();
		for(i = 0; i<ll_len(pArrayListPassenger); i++) {
			pPassenger = ll_get(pArrayListPassenger, i);
			if(pPassenger != NULL) {

				Passenger_printOnePassenger(pPassenger);
				rtn = 1;
			}
		}
	}
	return rtn;
}


int Passenger_printOnePassenger(Passenger* this) {
	int rtn = -1;
	int auxID;
	char auxName[NAMESIZE];
	char auxLastName[NAMESIZE];
	float auxPrice;
	int auxTypePassenger;
	char auxTypePassengerStr[15];
	char auxFlyCode[FLYCODESIZE];
	int auxStatusFlight;
	char auxStatusFlightStr[15];

	if(this!=NULL)
	{
		if(Passenger_GetValidatePassengerData(this, &auxID, auxName, auxLastName,&auxPrice,
				&auxTypePassenger,auxFlyCode,&auxStatusFlight)==1) {

			typePassengerToChar(auxTypePassenger, auxTypePassengerStr);
			statusFlightToChar(auxStatusFlight, auxStatusFlightStr);

			printf("%10d %20s %20s %10.2f %20s %20s %20s\n", auxID,
					auxName,
					auxLastName,
					auxPrice,
					auxFlyCode,
					auxTypePassengerStr,
					auxStatusFlightStr);
			rtn = 1;
		}

	}
	return rtn;
}


int Passenger_setStatusFlight(Passenger* this, int statusFlight) {
	int rtn = -1;
	if(this != NULL && statusFlight > 0) {
		this->statusFlight = statusFlight;
		rtn = 1;
	}

	return rtn;
}

int Passenger_getStatusFlight(Passenger* this, int* statusFlight) {

	int rtn = -1;

	if(this!= NULL) {

		*statusFlight = this->statusFlight;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setTypePassenger(Passenger* this, int typePassenger) {
	int rtn = -1;
	if(this != NULL && typePassenger > 0) {
		this->typePassenger = typePassenger;
		rtn = 1;
	}

	return rtn;
}

int Passenger_getTypePassenger(Passenger* this, int* typePassenger) {

	int rtn = -1;

	if(this!= NULL) {

		*typePassenger = this->typePassenger;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setFlyCode(Passenger* this, char* flyCode) {
	int rtn = -1;
	if(this != NULL && flyCode != NULL)
	{
		strcpy(this->flyCode, flyCode);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getFlyCode(Passenger* this,char* flyCode) {
	int rtn = -1;

	if(this!=NULL && flyCode!=NULL) {

		strcpy(flyCode,this->flyCode);
		rtn=1;
	}

	return rtn;
}

int Passenger_setId(Passenger* this, int id) {
	int rtn = -1;

	if(this != NULL && id > 0) //SI LA ESTRUCTURA NO ES NULA Y EL ID ES MAYOR A 0
	{
		this->id = id; //LE ASIGNO EL ID A LA ESTRUCTURA
		rtn = 1;
	}
	return rtn;
}

int Passenger_getId(Passenger* this, int* ID) {

	int rtn = -1;

	if(this!= NULL) {

		*ID = this->id;
		rtn = 1;
	}
	return rtn;
}

int Passenger_setName(Passenger* this, char* name) {
	int rtn = -1;
	if(this != NULL && name != NULL)
	{
		strcpy(this->name, name);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getName(Passenger* this,char* name) {
	int rtn = -1;

	if(this!=NULL && name!=NULL) {

		strcpy(name,this->name);
		rtn=1;
	}

	return rtn;
}



int Passenger_setLastName(Passenger* this,char* lastName) {

	int rtn = -1;
	if(this != NULL && lastName != NULL)
	{
		strcpy(this->lastName, lastName);
		rtn = 1;
	}
	return rtn;
}

int Passenger_getLastName(Passenger* this,char* lastName) {
	int rtn = -1;

	if(this!=NULL && lastName!=NULL) {

		strcpy(lastName,this->lastName);
		rtn=1;
	}
	return rtn;
}


int Passenger_setPrice(Passenger* this, float price) {
	int rtn = -1;

	if(this != NULL && price > 0) //SI LA ESTRUCTURA NO ES NULA Y EL PRECIO ES MAYOR A 0
			{
		this->price = price; //LE ASIGNO EL PRECIO A LA ESTRUCTURA
		rtn = 1;
			}
	return rtn;
}

int Passenger_getPrice(Passenger* this, float* price) {

	int rtn = -1;

	if(this!= NULL) {

		*price = this->price;
		rtn = 1;
	}
	return rtn;
}

