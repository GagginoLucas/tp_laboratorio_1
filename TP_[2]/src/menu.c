#include "menu.h"


void callMainMenu(	Passenger* listPassengers, int len_ListPassengers,
					sStatusFlight* statusFlight, int len_StatusFlight,
					Passenger* passengersHardcodeList, int len_PassengerHardcode) {
	int opcionInformar;
	int rtn;
	int cantidadDatos = 0;
	int flagHardcode = 1;
	int menu;
	int confirmExit;
	do {
		menu = printMainMenu();
		system("cls");
		switch(menu) {

			case 1: rtn = sPassenger_LoadPassenger(listPassengers, len_ListPassengers);
						if(rtn == 1) {
							system("cls");
							printf("Los datos se cargaron correctamente!\n\n");
							cantidadDatos++;
						}else {
							printf("No se cargaron nuevos datos.\n");
							system("pause");
						}
			break;
			case 2:	if( cantidadDatos > 0) {

						rtn = sPassenger_ModifyPassengers(listPassengers, len_ListPassengers);
						if(rtn == 0) {
							printf("No se modifico ningun dato.\n");
							system("pause");
						}
						else {
							printf("Los datos se modificaron correctamente!\n");
							system("pause");
						}
					}else {
						printf("No hay pasajeros cargados.\n");
					}

			break;
			case 3: if(cantidadDatos > 0) {

						rtn = removePassenger(listPassengers, len_ListPassengers);
						if(rtn == 0) {
							printf("\nNo se elimino a ningun pasajero del sistema.\n");
							system("pause");
						}else {
							printf("\nLos datos del pasajero han sido correctamente eliminados.\n");
							cantidadDatos--;
							system("pause");
						}
					}else {
						printf("No hay pasajeros cargados.\n");
					}
			break;
			case 4: if( cantidadDatos > 0 ) {
						do
						{
							opcionInformar = printReportMenu();
							system("cls");
							switch(opcionInformar) {
								case 1:	sPassenger_DisplayPassengersByOrder(listPassengers, len_ListPassengers);
								break;
								case 2: sPassenger_DisplayAverage(listPassengers, len_ListPassengers, cantidadDatos);
								break;
								case 3: sPassenger_DisplayPassengersByCode(listPassengers, len_ListPassengers ,statusFlight, len_StatusFlight);
								break;
							}
						}while(opcionInformar != 4);

					}else
					{
						printf("No hay pasajeros cargados.\n");
						system("pause");
					}
			break;
			case 5: if(flagHardcode == 1) {
						sPassenger_HardcodePassengers(listPassengers, len_ListPassengers, passengersHardcodeList, len_PassengerHardcode);
						cantidadDatos+= len_PassengerHardcode;
						flagHardcode = 0;
						printf("LA CARGA FORZADA DE PASAJEROS SE REALIZO CORRECTAMENTE.\n");
						system("pause");
					}else {
						printf("Los datos ya han sido cargados.\n");
						system("pause");
					}
			break;
			case 6: confirmExit = askToConfirm("Esta seguro que desea salir? S|N\n");
			break;
		}
	}while(confirmExit != 1);
}

int printMainMenu() {
	int menu;
	printf("************************MENU PRINCIPAL************************\n");
	printf("1. ALTAS\n");
	printf("2. MODIFICACIONES\n");
	printf("3. BAJAS\n");
	printf("4. INFORMAR\n");
	printf("5. REALIZAR CARGA FORZADA DE PASAJERXS\n");
	printf("6. SALIR");
	menu = getEntero("Seleccione una opcion del menu: ", 1, 6);
	system("cls");
	return menu;
}



int printReportMenu() {
	int option;
	printf("******************INFORMES******************\n");
	printf("1. Listado de pasajeros.\n");
	printf("2. Total y promedio de los precios.\n");
	printf("3. Listado de pasajeros con estado de vuelo ‘ACTIVO’.\n");
	printf("4. Volver atras\n");
	option = getEntero("Ingrese opcion", 1, 4);
	system("cls");
	return option;
}




