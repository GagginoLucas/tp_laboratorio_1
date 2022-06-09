#include "Controller.h"




/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
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

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int rtn = -1;

	if (loadPassengerData(pArrayListPassenger) == 1) {

		printf("Los datos se cargaron correctamente.");
		rtn = 1;
		system("pause");

	}else {

		printf("No se pudo realizar la carga del pasajero.");
		system("pause");

	}
	return rtn;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
		printf("No hay datos cargados.\n");
		system("pause");
	}
	return rtn;
}
/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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
	}
	return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger) {
	int rtn = -1;
	if(ll_len(pArrayListPassenger) > 0) {
		Passenger_listPassengers(pArrayListPassenger);
		rtn = 1;
		system("pause");
	}else {
		printf("No hay datos cargados.\n");
		system("pause");
	}
	return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
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

					if((Passenger_GetValidatePassengerData(aux,&auxID,auxName,auxLastName,
							&auxPrice,&auxTypePassenger,auxFlyCode,
							&auxStatusFlight))==1) {

						typePassengerToChar(auxTypePassenger, auxTypePassengerStr);
						statusFlightToChar(auxStatusFlight, auxStatusFlightStr);

						fprintf(pFile,"%d,%s,%s,%.0f,%s,%s,%s\n",auxID,auxName,auxLastName,
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

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
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

