#include "Passenger.h"

int main()
{
	setbuf(stdout,NULL);
	int option;
	int flagCsvFileLoaded = 0;
	int flagBinFileLoaded = 0;
	int flagFileSaved = 0;
	int flagNewChanges = 0;
	LinkedList* PassengerList = ll_newLinkedList();
	do{

		option = controller_PrintMainMenu();
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
			case 3:	if(controller_addPassenger(PassengerList)==1)
						flagNewChanges = 1;
			break;
			case 4: if(controller_editPassenger(PassengerList)==1)
						flagNewChanges = 1;
			break;
			case 5: if(controller_removePassenger(PassengerList)==1)
						flagNewChanges = 1;
			break;
			case 6: controller_ListPassenger(PassengerList);
			break;
			case 7: if(controller_sortPassenger(PassengerList) == 1){
						printf("La lista se ordeno correctamente.\n");
						system("pause");
					}else{
						printf("La lista no ha sido ordenada.\n");
					}
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

			case 10:if(flagFileSaved == 0 && (flagBinFileLoaded == 1 || flagCsvFileLoaded == 1)){
						if(flagNewChanges == 1) {
							if(askToConfirm("Estas seguro que deseas salir sin guardar? los datos modificados se perderan.\n"
											"Ingrese 1 para salir, o cualquier otro numero para volver al menu.\n"
											"Opcion:")==1) {
								printf("\nHasta la proxima!!!\n");
								ll_deleteLinkedList(PassengerList);
								option = 10;

							}else
								{
									option = 0;
								}
						}else {
							printf("No se realizaron modificaciones en el archivo.\n"
								   "Hasta la proxima!!!\n");
						}
					}else
						{
							printf("\nHasta la proxima!!!\n");
							ll_deleteLinkedList(PassengerList);
						}
			break;
		}

	}while(option != 10);

	return  EXIT_SUCCESS;
}

