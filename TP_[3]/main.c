#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/

int cotroller_ReadFileLastID();

int main()
{
	setbuf(stdout,NULL);
	int option;
	int flagCsvFileLoaded = 0;
	int flagBinFileLoaded = 0;
	int flagFileSaved = 0;
	cotroller_ReadFileLastID();
	LinkedList* PassengerList = ll_newLinkedList();
	do{
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

		switch(option){
		case 1:
			if(flagCsvFileLoaded == 0){
				if(flagBinFileLoaded == 0) {
					if((controller_loadFromText("data.csv",PassengerList)) == 1) {
					flagCsvFileLoaded = 1;
					}
				}else {
					printf("El archivo ya fue abierto en modo binario.\n");
					system("pause");
				}
			}else {

				printf("No se puede abrir el archivo dos veces.\n");
				system("pause");

			}
			break;
		case 2:
			if(flagBinFileLoaded == 0){
				if(flagCsvFileLoaded == 0) {

					if((controller_loadFromBinary("data.bin",PassengerList)) == 1) {
						flagBinFileLoaded = 1;
					}
				}else {
					printf("El archivo ya fue abierto en modo texto.\n");
					system("pause");
				}
			}else {
				printf("No se puede abrir el archivo dos veces.\n");
				system("pause");
			}
			break;
		case 3:	controller_addPassenger(PassengerList);
		break;
		case 4: controller_editPassenger(PassengerList);
		break;
		case 5: controller_removePassenger(PassengerList);
		break;
		case 6: controller_ListPassenger(PassengerList);
		break;
		case 8: if(flagCsvFileLoaded == 1) {

			if((controller_saveAsText("data.csv" , PassengerList)) == 1) {

				printf("El archivo se guardo correctamente.\n");
				flagFileSaved = 1;
				system("pause");

			}else {

				printf("No se pudo guardar el archivo.\n");
				system("pause");
			}
		}else {
			printf("No se puede guardar el archivo sin antes cargarlo.\n");
			system("pause");
		}


		break;
		case 9: if( flagBinFileLoaded == 1) {
			if((controller_saveAsBinary("data.bin" , PassengerList)) == 1) {

				printf("El archivo se guardo correctamente.\n");
				flagFileSaved = 1;
				system("pause");

			}else {
				printf("No se pudo guardar el archivo.\n");
				system("pause");
			}
		}else {

			printf("No se puede guardar el archivo sin antes cargarlo.\n");
			system("pause");
		}
		break;

		case 10: if(flagFileSaved == 0){

			printf("Debes guardar el archivo que abriste antes de salir.\n");
			system("pause");
			option = 0;

		}else{
			printf("\nHasta la proxima!!!\n");
		}
		break;
	}

	}while(flagFileSaved == 0 || option != 10);

	return  0;
}

