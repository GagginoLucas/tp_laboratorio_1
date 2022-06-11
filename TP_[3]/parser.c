#include "parser.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn = -1;
	Passenger* aux = NULL;
	char idAux[FILESIZE];
	char nameAux[FILESIZE];
	char lastNameAux[FILESIZE];
	char priceAux[FILESIZE];
	char flyCodeAux[FILESIZE];
	char typePassengerAux[FILESIZE];
	char statusFlightAux[FILESIZE];
	if(pFile != NULL && pArrayListPassenger != NULL) {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",  idAux, nameAux, lastNameAux,
																	priceAux, flyCodeAux, typePassengerAux,
																	statusFlightAux);

		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", idAux, nameAux, lastNameAux,
																		  priceAux, flyCodeAux, typePassengerAux,
																		  statusFlightAux)==7) {
				aux = Passenger_newParametros(idAux, nameAux, lastNameAux, priceAux, flyCodeAux, typePassengerAux, statusFlightAux);
				if(aux!=NULL) {
					ll_add(pArrayListPassenger, aux);
					rtn = 1;
				}
			}
		}while(feof(pFile)==0);
	}
    return rtn;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger) {

	int rtn = -1;
	Passenger* aux = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL) {

		do
		{
			aux = Passenger_new();
			if(aux != NULL) {

				if(fread(aux, sizeof(Passenger),1, pFile)) {

					ll_add(pArrayListPassenger, aux);
					rtn = 1;

				}else {

					Passenger_delete(aux);

				}
			}

		}while(feof(pFile)==0);

	}

	return rtn;
}











