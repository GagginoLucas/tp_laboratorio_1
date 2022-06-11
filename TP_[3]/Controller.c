#include "Controller.h"



int controller_loadFromText(char* path , LinkedList* pArrayListPassenger) {

	int rtn = -1;
	FILE* pFile = NULL;
	if(path!=NULL && pArrayListPassenger != NULL) {

		if((pFile = fopen(path,"r")) != NULL){

			if((parser_PassengerFromText(pFile , pArrayListPassenger)) == 1) {

				system("cls");
				printf("Los datos se cargaron correctamente.\n");
				rtn = 1;
				system("pause");
			}else {

				printf("Los datos no se pudieron leer correctamente.\n");
				system("pause");
			}
		}
	}else {

		printf("Error, no se pudo abrir el archivo\n");
	}

	return rtn;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger) {

	int rtn = -1;
	FILE* pFile = NULL;

	if(path!=NULL && pArrayListPassenger != NULL) {

		if((pFile = fopen(path,"rb")) != NULL) {

			if( (parser_PassengerFromBinary(pFile , pArrayListPassenger)) == 1) {

				system("cls");
				printf("Los datos se cargaron correctamente.\n");
				rtn = 1;
				system("pause");
			}else {

				printf("Los datos no se pudieron leer correctamente.\n");
				system("pause");
			}
		}
	}else {

		printf("Error, no se pudo abrir el archivo\n");
		system("pause");
	}

	return rtn;
}


int controller_addPassenger(LinkedList* pArrayListPassenger) {

	int rtn = -1;
	if (loadPassengerData(pArrayListPassenger) == 1) {

		printf("Los datos se cargaron correctamente.\n");
		rtn = 1;
		system("pause");
	}else {

		printf("No se pudo realizar la carga del pasajero.\n");
		system("pause");
	}
	return rtn;
}


int controller_editPassenger(LinkedList* pArrayListPassenger) {

	int rtn = -1;
	if(ll_len(pArrayListPassenger) > 0){

		if(Passenger_ModifyPassengers(pArrayListPassenger) == 1) {

			printf("El pasajero se modificó correctamente\n");
			rtn = 1;
			system("pause");
		}else{

			printf("No se realizaron modificaciones.\n");
			system("pause");
		}
	}else {

		printf("No hay pasajerxs cargados.\n");
		system("pause");
	}
	return rtn;
}


int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	if(ll_len(pArrayListPassenger) > 0) {

		if(Passenger_RemovePassenger(pArrayListPassenger)==1) {

			printf("Los datos se eliminaron correctamente.\n");
			rtn = 1;
			system("pause");
		}else{

			printf("No se elimino a ningun pasajerx.\n");
			system("pause");

		}
	}else {

		printf("No hay pasajerxs cargados.\n");
		system("pause");
	}
	return rtn;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger) {

	int rtn = -1;
	if(ll_len(pArrayListPassenger) > 0) {

		Passenger_listPassengers(pArrayListPassenger);
		rtn = 1;
		system("pause");
	}else {

		printf("No hay pasajerxs cargados.\n");
		system("pause");
	}
	return rtn;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger) {

	int rtn = -1;
	int option;
	int optionOrder;
	option = controller_printSortMenu();
	if(option!=8) {

		optionOrder = controller_printSortOrder();
	}
	switch(option) {

	case 1: printf("La lista se esta ordenando......\n");
			ll_sort(pArrayListPassenger, Passenger_sortByID, optionOrder);
			rtn = 1;
	break;
	case 2: printf("La lista se esta ordenando......\n");
			ll_sort(pArrayListPassenger, Passenger_sortByName, optionOrder);
			rtn = 1;
	break;
	case 3: printf("La lista se esta ordenando......\n");
			ll_sort(pArrayListPassenger, Passenger_sortByLastName, optionOrder);
			rtn = 1;
	break;
	case 4: printf("La lista se esta ordenando......\n");
			ll_sort(pArrayListPassenger, Passenger_sortByPrice, optionOrder);
			rtn = 1;
	break;
	case 5: printf("La lista se esta ordenando......\n");
			ll_sort(pArrayListPassenger, Passenger_sortByTypePassenger, optionOrder);
			rtn = 1;
	break;
	case 6: printf("La lista se esta ordenando......\n");
			ll_sort(pArrayListPassenger, Passenger_sortByStatusFlight, optionOrder);
			rtn = 1;
	break;
	case 7: printf("La lista se esta ordenando......\n");
			ll_sort(pArrayListPassenger, Passenger_sortByFlyCode, optionOrder);
			rtn = 1;
	break;
	case 8:
	break;
	}

	return rtn;
}


int controller_printSortMenu() {

	int option;
	get_IntInRange(&option,"SUBMENU SORT\n"
					"1. Ordenar por ID.\n"
					"2. Ordenar por nombre.\n"
					"3. Ordenar por apellido.\n"
					"4. Ordenar por precio\n"
					"5. Ordenar por tipo de pasajero.\n"
					"6. Ordenar por estado de vuelo.\n"
					"7. Ordenar por codigo de vuelo.\n"
					"8. Ir atras.\n"
					"Opcion: ",1,8);

	return option;
}

int controller_printSortOrder() {
	int option;
	get_IntInRange(&option,"De que manera desea ordenar?\n"
					"0. Descendente.\n"
					"1. Ascendente.\n"
					"Opcion: ",0,1);

	return option;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger) {

	int rtn = -1;
	int i;
	int auxID;
	char auxName[NAMESIZE];
	char auxLastName[NAMESIZE];
	float auxPrice;
	char auxFlyCode[FLYCODESIZE];
	int auxTypePassenger;
	char auxTypePassengerStr[50];
	char auxStatusFlightStr[50];
	int auxStatusFlight;
	FILE* pFile;
	Passenger* aux = NULL;

	if(path!=NULL && pArrayListPassenger!=NULL) {

		pFile = fopen(path,"w");
		if(pFile!= NULL) {

			fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(i=0; i<ll_len(pArrayListPassenger) ;i++) {

				aux = ll_get(pArrayListPassenger,i);
				if(aux!=NULL) {

					if((Passenger_GetValidatePassengerData(	aux,&auxID,auxName,auxLastName,
															&auxPrice,&auxTypePassenger,auxFlyCode,
															&auxStatusFlight))==1) {

						typePassengerToChar(auxTypePassenger, auxTypePassengerStr);
						statusFlightToChar(auxStatusFlight, auxStatusFlightStr);
						fprintf(pFile,"%d,%s,%s,%.0f,%s,%s,%s\n",	auxID,auxName,auxLastName,
																	auxPrice,auxFlyCode,auxTypePassengerStr,
																	auxStatusFlightStr);
						rtn=1;

					}else {

						Passenger_delete(aux);
					}
				}
			}
		}

		fclose(pFile);
	}
	return rtn;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger) {

	int rtn = -1;
	int i;
	FILE* pFile;
	Passenger* aux = NULL;
	if(path!=NULL && pArrayListPassenger!=NULL) {

		pFile = fopen(path,"wb");
		if(pFile!= NULL) {

			for(i=0; i<ll_len(pArrayListPassenger) ;i++) {

				aux = ll_get(pArrayListPassenger,i);
				if(aux != NULL) {

					fwrite(aux, sizeof(Passenger) , 1 , pFile);
					rtn=1;
				}
			}
		}
		fclose(pFile);
	}

	return rtn;
}

int cotroller_ReadFileLastID() {

	char lastIDstr[FILESIZE];
	int lastID;
	FILE* file_LastID = NULL;
	file_LastID = fopen("LastID.txt", "r");
	if(file_LastID != NULL) {

		fgets(lastIDstr, FILESIZE, file_LastID);
	}
	lastID = atoi(lastIDstr);
	fclose(file_LastID);
	return lastID;
}

void cotroller_WriteFileLastID(int newLastID) {

	FILE* file_LastID = NULL;
	file_LastID = fopen("LastID.txt", "w");
	if(file_LastID != NULL) {

		fprintf(file_LastID,"%d",newLastID);
	}
	fclose(file_LastID);
}

int controller_PrintMainMenu() {

	int option;
	get_IntInRange(&option, "\nOPCIONES \n1. Cargar los datos en modo texto."
					"							\n2. Cargar los datos en modo binario."
					"                         	\n3. Alta de pasajero."
					"                        	\n4. Modificar datos de pasajero."
					"							\n5. Baja de pasajero."
					"                         	\n6. Listar pasajeros."
					"							\n7. Ordenar pasajeros."
					"							\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
					"							\n9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)."
					"							\n10. Salir."
					"							\n\nOpcion: ",
					1, 10);
	return option;
}
