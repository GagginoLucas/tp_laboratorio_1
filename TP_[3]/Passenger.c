/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"


Passenger* Passenger_new() {

	return (Passenger*)malloc(sizeof(Passenger));
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

	if(pOnePassenger != NULL) {

		if(Passenger_SetValidatePassengerDataFromFile(pOnePassenger, idStr, nameStr,
													  lastNameStr, priceStr, flyCodeStr,
													  auxTypePassenger, auxStatusFlight)!=1) {

			Passenger_delete(pOnePassenger);
		}
	}

	return pOnePassenger;
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



void Passenger_delete(Passenger* this) {

	if(this!=NULL) {

		free(this);
		this=NULL;
	}
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





int Passenger_GetValidatePassengerData(	Passenger* pOnePassenger,int* auxID, char* auxName,
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





int Passenger_RemovePassenger(LinkedList* pArrayListPassenger) {

	int rtn = -1;
	int idPassenger;
	int index;
	Passenger* pAuxPassenger = NULL;

	if(pArrayListPassenger!= NULL) {

		Passenger_listPassengers(pArrayListPassenger);
		do
		{
			get_Int(&idPassenger, "Ingresar ID del pasajerx que desea remover: ");
			index = Passenger_FindPassengerById(pArrayListPassenger,idPassenger);
			if(index != -1) {
				pAuxPassenger = ll_get(pArrayListPassenger, index);
				printHeader();
				Passenger_printOnePassenger(pAuxPassenger);
				if(askToConfirm("Esta segurx que desea continuar? Los datos se perderan.\n"
								"Ingrese 1 para continuar, o cualquier otra numero para cancelar.\n"
						 	 	"Opcion:")==1) {

					pAuxPassenger  = ll_pop(pArrayListPassenger, index);
					Passenger_delete(pAuxPassenger);
					rtn = 1;
				}
			}
		}while( index == -1  && askToConfirm("No se encontro un pasajerx con esa id, desea volver a buscar?\n"
											 "Ingrese 1 para volver a buscar, o cualquier otra numero para cancelar.\n"
											 "Opcion:")==1);

	}

	return rtn;
}

void printModifyMenu(Passenger aux, int* option) {

	char typePassengerAux[50];
	typePassengerToChar(aux.typePassenger,typePassengerAux);
	printf("SELECCIONE QUE OPCION DESEA MODIFICAR\n");
	printf("1. Nombre: %s\n", aux.name);
	printf("2. Apellido: %s\n", aux.lastName);
	printf("3. Precio: $ %.2f\n", aux.price);
	printf("4. Codigo de vuelo:  %s\n", aux.flyCode);
	printf("5. Tipo de pasajero: %s\n", typePassengerAux);
	printf("6. Modificar datos\n");
	printf("7. Ir atras.\n");
	get_IntInRange(option, "Opcion: ",1, 7);
}

int Passenger_ModifyOnePassenger(LinkedList* pArrayListPassenger, int index) {

	int rtn = -1;
	Passenger* aux = NULL;
	Passenger auxToModify;
	int option;
	if(pArrayListPassenger!= NULL) {

		aux = ll_get(pArrayListPassenger, index);
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
					case 6: if(askToConfirm("Esta seguro que desea Modificar los datos?\n"
											"Ingrese 1 para continuar, o cualquier otro numero cancelar.\n"
											"Opcion:") == 1) {
								*aux = auxToModify;
								rtn = 1;
								option = 7;
					}
				}
			}while(option!=7);
		}
	}
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
		}while( index == -1  && askToConfirm("No se encontro un pasajero con esa id, desea volver a buscar?\n"
											 "Ingrese 1 para volver a buscar, o cualquier otra numero para cancelar.\n"
											 "Opcion:")==1);

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
	if(askToConfirm("Esta segurx que desea cargar los datos ingresados?\n"
					"Ingrese 1 para continuar, o cualquier otra numero para cancelar la carga.\n"
					"Opcion:")==1) {
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
	case 3: strcpy(typeStr, "EconomyClass");
	break;
	}
}


void statusFlightToChar(int statusInt, char* statusStr) {

	switch(statusInt) {
	case 1: strcpy(statusStr, "Demorado");
	break;
	case 2: strcpy(statusStr, "Aterrizado");
	break;
	case 3: strcpy(statusStr, "En Horario");
	break;
	}
}


void printHeader() {

	printf("%5s | %15s | %15s | %10s | %10s | %15s | %15s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "FLYCODE", "TYPEPASSENGER", "STATUSFLIGHT");
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
	char auxTypePassengerStr[20];
	char auxFlyCode[FLYCODESIZE];
	int auxStatusFlight;
	char auxStatusFlightStr[20];

	if(this!=NULL)
	{
		if(Passenger_GetValidatePassengerData(this, &auxID, auxName, auxLastName,&auxPrice,
											 &auxTypePassenger,auxFlyCode,&auxStatusFlight)==1) {

			typePassengerToChar(auxTypePassenger, auxTypePassengerStr);
			statusFlightToChar(auxStatusFlight, auxStatusFlightStr);
			printf("%5d | %15s | %15s | %10.2f | %10s | %15s | %15s\n", auxID,
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
	if(this != NULL && flyCode != NULL) {

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

	if(this != NULL && id > 0) {

		this->id = id;
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
	if(this != NULL && lastName != NULL) {

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
	if(this != NULL && price > 0) {

		this->price = price;
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

int Passenger_sortByID(void* firstID, void* secondID) {

	int rtn = 0;
	Passenger* auxPassengerOne = (Passenger*) firstID;
	Passenger* auxPassengerTwo = (Passenger*) secondID;
	int idOne;
	int idTwo;
	if(auxPassengerOne != NULL && auxPassengerTwo != NULL) {

		if(Passenger_getId(auxPassengerOne, &idOne) == 1 &&
		   Passenger_getId(auxPassengerTwo, &idTwo) == 1) {

			if(idOne > idTwo) {

				rtn = 1;
			}else {
				if(idOne < idTwo) {

					rtn = -1;
				}
			}

		}
	}

	return rtn;
}


int Passenger_sortByName(void* firstName, void* secondName) {

	int rtn = 0;
	Passenger* auxPassengerOne = (Passenger*) firstName;
	Passenger* auxPassengerTwo = (Passenger*) secondName;
	char nameOne[NAMESIZE];
	char nameTwo[NAMESIZE];

	if(auxPassengerOne != NULL && auxPassengerTwo != NULL) {

		if(Passenger_getName(auxPassengerOne, nameOne) == 1 && Passenger_getName(auxPassengerTwo, nameTwo) == 1) {

			rtn = strcmp(nameOne, nameTwo);
		}
	}

	return rtn;
}

int Passenger_sortByLastName(void* firstLastName, void* secondLastName) {

	int rtn = 0;
	Passenger* auxPassengerOne = (Passenger*) firstLastName;
	Passenger* auxPassengerTwo = (Passenger*) secondLastName;
	char LastNameOne[NAMESIZE];
	char LastNameTwo[NAMESIZE];

	if(auxPassengerOne != NULL && auxPassengerTwo != NULL) {

		if(Passenger_getLastName(auxPassengerOne, LastNameOne) == 1 && Passenger_getLastName(auxPassengerTwo, LastNameTwo) == 1) {

		rtn = strcmp(LastNameOne, LastNameTwo);
		}
	}

	return rtn;
}

int Passenger_sortByPrice(void* firstPrice, void* secondPrice) {

	int rtn = 0;
	Passenger* auxPassengerOne = (Passenger*) firstPrice;
	Passenger* auxPassengerTwo = (Passenger*) secondPrice;
	float PriceOne;
	float PriceTwo;

	if(auxPassengerOne != NULL && auxPassengerTwo != NULL) {

		if(Passenger_getPrice(auxPassengerOne, &PriceOne) == 1 &&
		   Passenger_getPrice(auxPassengerTwo, &PriceTwo) == 1) {

			if(PriceOne > PriceTwo) {

				rtn = 1;
			}else {

				if(PriceOne < PriceTwo) {

					rtn = -1;
				}
			}
		}
	}

	return rtn;
}

int Passenger_sortByFlyCode(void* firstFlyCode, void* secondFlyCode) {

	int rtn = -1;
	Passenger* auxPassengerOne = (Passenger*) firstFlyCode;
	Passenger* auxPassengerTwo = (Passenger*) secondFlyCode;
	char FlyCodeOne[FLYCODESIZE];
	char FlyCodeTwo[FLYCODESIZE];

	if(auxPassengerOne != NULL && auxPassengerTwo != NULL) {

		if(Passenger_getFlyCode(auxPassengerOne, FlyCodeOne) == 1 && Passenger_getFlyCode(auxPassengerTwo, FlyCodeTwo) == 1) {

		rtn = strcmp(FlyCodeOne, FlyCodeTwo);
		}
	}

	return rtn;
}


int Passenger_sortByStatusFlight(void* firstStatusFlight, void* secondStatusFlight) {

	int rtn = 0;
	Passenger* auxPassengerOne = (Passenger*) firstStatusFlight;
	Passenger* auxPassengerTwo = (Passenger*) secondStatusFlight;
	int StatusFlightOne;
	int StatusFlightTwo;

	if(auxPassengerOne != NULL && auxPassengerTwo != NULL) {

		if(Passenger_getStatusFlight(auxPassengerOne, &StatusFlightOne) == 1 &&
		   Passenger_getStatusFlight(auxPassengerTwo, &StatusFlightTwo) == 1) {

			if(StatusFlightOne > StatusFlightTwo) {
				rtn = 1;
			}else {

				if(StatusFlightOne < StatusFlightTwo) {
					rtn = -1;
				}
			}

		}
	}

	return rtn;
}

int Passenger_sortByTypePassenger(void* firstTypePassenger, void* secondTypePassenger) {

	int rtn = 0;
	Passenger* auxPassengerOne = (Passenger*) firstTypePassenger;
	Passenger* auxPassengerTwo = (Passenger*) secondTypePassenger;
	int TypePassengerOne;
	int TypePassengerTwo;

	if(auxPassengerOne != NULL && auxPassengerTwo != NULL) {

		if(Passenger_getTypePassenger(auxPassengerOne, &TypePassengerOne) == 1 &&
		   Passenger_getTypePassenger(auxPassengerTwo, &TypePassengerTwo) == 1) {

			if(TypePassengerOne > TypePassengerTwo) {

				rtn = 1;
			}else {

				if(TypePassengerOne < TypePassengerTwo) {

					rtn = -1;
				}
			}

		}
	}
	return rtn;
}



// Esta no la uso porque al trabajar con archivos necesito guardar el último id cargado aparte.
/*
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
				Passenger_getId(aux,&id);

				if(i==0 || (idMax<id))
				{
					idMax=id;
				}
			}
		}
	}

	return idMax;
}
*/

