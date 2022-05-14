/*
 * ArrayPassenger.c
 * Author: Lucas Gaggino
 */

#include "ArrayPassenger.h"

// ID AUTOINCREMENTAL CON VARIABLE ESTÁTICA
static int sPassenger_getID();
static int myID = 0;  //*  <- SETEAR EL VALOR EN EL QUE COMIENZA EL ID
static int sPassenger_getID() {
	return myID+=1;
}



int initPassengers(Passenger* list, int len) //INICIALIZO LOS
{
	int i;
	int rtn = -1;
	// SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL  && len >= 0) {
		rtn = 0;
		// RECORRO TODO EL ARRAY
		for (i = 0 ; i < len ; i++) {
			//SET PONGO LOS ESTADOS EN "LIBRE"
			list[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}


Passenger sPassenger_ModifyOnePassenger(Passenger list) {
	Passenger aux = list;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	int option;
	int confirm;
	do
	{
		printf("SELECCIONE QUE OPCIÓN DESEA MODIFICAR\n");
		printf("1. Nombre (%s)\n", aux.name);
		printf("2. Apellido (%s)\n", aux.lastName);
		printf("3. Precio ($ %.2f)\n", aux.price);
		printf("4. Codigo de vuelo (%s)\n", aux.flycode);
		printf("5. Tipo de pasajero: ");
		displayTypePassenger(aux.typePassenger);
		printf("\n6. Finalizar modificacion\n");
		option = getEntero("Opcion: ",1, 6);
		switch(option) {
		case 1 :getValidName("Ingrese nombre: ", aux.name, MAX_CHARS_NOMBRE);
				ordenarCaracteres(aux.name);
		break;
		case 2:getValidName("Ingrese apellido: ", aux.lastName, MAX_CHARS_NOMBRE);
		   	   ordenarCaracteres(aux.lastName);
		break;
		case 3: aux.price = getFlotante("Ingrese precio: ", 1 , 99999999);
		break;
		case 4: getValidAlphaNum("Ingresar codigo de vuelo: ", aux.flycode, MAX_CHARS_FLYCODE);
		break;
		case 5: aux.typePassenger = getEntero("Ingrese tipo de pasajero\n"
												"1.Primera clase\n"
												"2.Clase ejecutiva\n"
												"3.Clase turista\n"
												"OPCION: ", 1, 3);
		break;
		case 6: confirm = askToConfirm("Esta seguro que desea salir? (S|N)");
				if(confirm == 1) {
					option = 7;
				}

		}
	}while(option!=7);




	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return aux;
}

int sPassenger_ModifyPassengers(Passenger* list, int len) {
	int rtn = 0;
	int idPassenger;
	int index;
	int flag = 0;
	int confirm;
	Passenger aux;

	//LISTO TODOS LOS Producto
	if (printPassenger(list, len)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Producto PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idPassenger = getEntero("Ingresar ID a modificar: ", 1, 3100);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(list, len, idPassenger) == -1) {
			printf("El ID ingresado no existe.\n");
			idPassenger = getEntero("Ingresar ID a modificar: ", 1, 3100);
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A MODIFICAR
		index = findPassengerById(list, len, idPassenger);

		//LLAMO A FUNCION QUE MODIFICA Producto
		aux = sPassenger_ModifyOnePassenger(list[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		confirm = askToConfirm("Esta seguro que desea realizar la modificacion? S/N");
		if(confirm == 1) {
		//MODIFICACION ACEPTADA
		list[index] = aux;
		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
		}
	}

	return rtn;
}

void displayTypePassenger(int idType)
{
	switch(idType)
	{
	case 1: printf("\t\tPrimera clase\t\t");
	break;
	case 2: printf("\t\tClase ejecutiva\t\t");
	break;
	case 3: printf("\t\tClase turista\t\t");
	break;
	}
}

void displayStatusFlight(int idStatus)
{
	switch(idStatus)
	{
	case 1: printf("\tACTIVO\n");
	break;
	case 2: printf("\tDEMORADO\n");
	break;
	case 3: printf("\tINACTIVO\n");
	break;
	}
}

int sPassenger_LoadPassenger(Passenger* list, int len) {
	int rtn = -1;
	char auxName[32];
	char auxLastName[32];
	float auxPrice;
	char auxFlyCode[10];
	int auxTypePassenger = 0;
	int auxIDStatusFlight;
	int auxIDPassenger;

	if(list!= NULL && len>= 0) {
		getValidName("Ingrese nombre: ", auxName, MAX_CHARS_NOMBRE);
		ordenarCaracteres(auxName);

		getValidName("Ingrese apellido: ", auxLastName, MAX_CHARS_NOMBRE);
		ordenarCaracteres(auxLastName);

		auxPrice = getFlotante("Ingrese precio: ", 1 , 99999999);
		getValidAlphaNum("Ingresar codigo de vuelo: ", auxFlyCode, MAX_CHARS_FLYCODE);
		auxTypePassenger = getEntero("Ingrese tipo de pasajero\n"
										"1.Primera clase\n"
										"2.Clase ejecutiva\n"
										"3.Clase turista\n"
										"OPCION: ", 1, 3);
		auxIDStatusFlight = getEntero("Ingresar estado del vuelo\n"
										"1.ACTIVO\n"
										"2.DEMORADO\n"
										"3.INACTIVO\n"
										"OPCION: ", 1, 3);
		auxIDPassenger = sPassenger_getID();

	rtn = addPassenger( list, len, auxIDPassenger, auxName, auxLastName,
						auxPrice, auxTypePassenger,  auxFlyCode, auxIDStatusFlight);
	}

	return rtn;
}


int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int idStatusFlight) {
	int rtn = -1;
	int index;
	Passenger aux;

	//BUSCO ESPACIO EN ARRAY
	index = sPassenger_GetFreeIndex(list, len);
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Producto AUXILIAR
		strncpy(aux.name , name, MAX_CHARS_NOMBRE);
		strncpy(aux.lastName , lastName, MAX_CHARS_NOMBRE);
		aux.price = price;
		aux.typePassenger = typePassenger;
		strncpy(aux.flycode , flycode, MAX_CHARS_FLYCODE);
		aux.idStatusFlight = idStatusFlight;
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		aux.id = id;
		//CAMBIO SU ESTADO A "OCUPADO"
		aux.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		list[index] = aux;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn; //RETORNA [0] EN CASO DE ERROR. RETORNA [1] EN CASO DE QUE SE HAYA CARGADO CORRECTAMENTE AL USUARIO
}



void sPassenger_PrintOnePassenger(Passenger list) {

	//MUESTRA UNA SOLA POSICIÓN DEL ARRAY
	printf("%5d    %20s    %20s     $ %10.2f     %20s",	list.id,
														list.name,
														list.lastName,
								 						list.price,
														list.flycode);
	displayTypePassenger(list.typePassenger);
	displayStatusFlight(list.idStatusFlight);
}

void sPassenger_printColumnList() {

	printf("\n*************************************************************LISTADO*****************************************************************************\n"); //CABECERA
	printf("%5s    %20s    %20s      %10s      %20s     %20s     %20s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "FLYCODE", "TIPO DE PASAJERO","ESTADO DE VUELO");  //TITULOS DE COLUMNA

}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int LEN) {
	int i;
	int rtn;
	rtn = 0;

	sPassenger_printColumnList();
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && LEN > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0 ; i < LEN ; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (list[i].isEmpty == OCUPADO) {
				//MUESTRO PASAJEROS UNO POR UNO
				sPassenger_PrintOnePassenger(list[i]);
				//CONTADOR DE PASAJEROS
				rtn++;
			}
		}
	}

	return rtn;
}

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int LEN,int ID) {
	int i;
	int rtn;
	rtn = -1;

	// SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL  && LEN >= 0) {
		// RECORRO TODO EL ARRAY
		for (i = 0 ; i < LEN ; i++) {
			//PREGUNTO SI EL ARRAY EN ESA POSICIÓN ESTÁ OCUPADO Y CARGADO CON EL ID QUE PASARON POR PARAMETRO
			if(list[i].isEmpty == OCUPADO && list[i].id == ID) {
				rtn = i; //RETORNO LA POSICIÓN DE i DONDE SE ENCUENTRA ESE ID
				break;
			}
		}
	}

	return rtn; //RETORNA [-1] EN CASO DE ERROR./ LA POSICION DE [i] EN CASO DE QUE SE HAYA ENCONTRADO EL ID
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in -1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len)
{
	int rtn = 0;
	int idProduct;
	int index;
	int confirm;
	int flag = 0;

	//LISTO TODOS LOS Productos
	if (printPassenger(list, len)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}
	//SI HAY Producto PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idProduct =  getEntero("\nIngrese el ID del usuario desea eliminar: ", 1, 5000);

		//BUSCO INDEX POR ID EN ARRAY
		while (findPassengerById(list, len, idProduct) == -1) {
			printf("NO EXISTE EL ID\n");
		idProduct =  getEntero("\nIngrese el ID del usuario desea eliminar: ", 1, 5000);
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A DAR DE BAJA
		index = findPassengerById(list, len, idProduct);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		confirm = askToConfirm("Esta segurx que desea eliminar los datos del pasajero? S/N");
		if(confirm == 1) {
			list[index].isEmpty = BAJA;	//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			rtn = 1; //RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		}

	}

	return rtn;
}


int sortPassengers(Passenger* list, int len, int order)
{

	int i, j;
	Passenger buffer;
	int rtn = -1;
	///SI EL ARRAY NO ES NULO Y EL LEN ES VÁLIDO
	if(list != NULL && len>= 0) {
		switch(order) //SE ELIJE EL ORDEN (1 Ascendente, 2 Descendente)
		{
		case 1:
			for (i = 0; i<len-1 ; i++) {

				for(j = i+1; j<len; j++) {

					if(strcmpi(list[i].lastName , list[j].lastName) > 0 ) { // ORDENO DE MANERA ASCENDENTE
						buffer = list[i];
						list[i] = list[j];
						list[j] = buffer;
					} else if	(strcmpi(list[i].lastName , list[j].lastName) > 0  &&
								list[i].typePassenger > list[j].typePassenger ) {
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
						}

				}

			}
		break;
		case 2:
			for (i = 0; i<len-1 ; i++) {

							for(j = i+1; j<len; j++) {

								if(strcmpi(list[i].lastName , list[j].lastName) < 0 ) { // ORDENO DESCENDENTEMENTE
									buffer = list[i];
									list[i] = list[j];
									list[j] = buffer;
								} else if	(strcmpi(list[i].lastName , list[j].lastName) > 0  &&
											list[i].typePassenger < list[j].typePassenger ) {
											buffer = list[i];
											list[i] = list[j];
											list[j] = buffer;
									}

							}

						}
		}
}

	return rtn;
}


int sortPassengersByCode(Passenger* list, int len, int order) {

	int i, j;
	Passenger buffer;
	int rtn = -1;
	///SI EL ARRAY NO ES NULO Y EL LEN ES VÁLIDO
	if(list != NULL && len>= 0) {
		switch(order) //SE ELIJE EL ORDEN (1 Ascendente, 2 Descendente)
		{
			case 1:	for (i = 0; i<len-1 ; i++) {

						for(j = i+1; j<len; j++) {

							if(strcmpi(list[i].flycode , list[j].flycode) > 0 ) { // ORDENO DE MANERA ASCENDENTE
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
							}
						}
					}
			break;
			case 2:	for (i = 0; i<len-1 ; i++) {
						for(j = i+1; j<len; j++) {
							if(strcmpi(list[i].flycode , list[j].flycode) < 0 ) { // ORDENO DE MANERA DESCENDENTE
								buffer = list[i];
								list[i] = list[j];
								list[j] = buffer;
							}
						}
					}
			break;
		}
	}

return rtn;

}


int sPassenger_GetFreeIndex(Passenger* list, int LEN) {
	int i;
	int rtn;
	rtn = -1; /// DEVUELVE -1 EN CASO DE ERROR

	// SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL  && LEN >= 0) {
		// RECORRO TODO EL ARRAY
		for (i = 0 ; i < LEN ; i++) {
			//PREGUNTO POR EL ESTADO LIBRE EN LA POSICIÓN DE [i]
			if(list[i].isEmpty == LIBRE) {
				rtn = i;  //DEVUELVE LA POSICIÓN LIBRE DEL ARRAY DONDE SE CARGARAN LOS DATOS
				break;
			}

		}
	}
	return rtn; //<- RETORNA [-1] EN CASO DE ERROR, O [i] EN CASO DE HABER ENCONTRADO UN INDEX VACÍO
}


int sPassenger_CalculatePassengersOverAverage(Passenger* list, int len, int promedio) {
	int rtn = -1;
	int i;
	int contadorSuperioresAlPromedio = 0;
	if(list != NULL && len>=0) {
		for(i = 0; i<len ; i++) {
			if(list[i].isEmpty == OCUPADO && list[i].price > promedio) {
				contadorSuperioresAlPromedio++;
			}

		}
		rtn = contadorSuperioresAlPromedio;
	}
	return rtn;
}


float sPassenger_CalculateTotal(Passenger* list, int len) {
	int rtn = -1;
	int i;
	float auxAcumulador = 0;

	if(list != NULL && len>=0) {
		for(i = 0; i<len ; i++) {
			if(list[i].isEmpty == OCUPADO)	{
				auxAcumulador+= list[i].price;
			}
			rtn = auxAcumulador;
		}
	}
	return rtn;
}


float sPassenger_CalculateAverage(int total, int cantidadDatos) {
	float promedio;
	promedio = (float)(total/cantidadDatos);
	return promedio;
}

int sPassenger_DisplayPassengersByStatusFlight(sStatusFlight* status,int lenStatus, Passenger* list, int len) {
	int rtn = 0;
	int i, j;
	printf("\n********** LISTADO DE PASAJEROS CON ESTADO DE VUELO ACTIVO*******\n");
	sPassenger_printColumnList();
	// SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL  && len >= 0) {
		// RECORRO TODO EL ARRAY
		for (i = 0 ; i < len ; i++) { //RECORRO LISTA DE PASAJEROS
			for (j = 0; j < lenStatus ; j++) { //RECORRO EL STATUSFLIGHT
				if(status[j].idStatusFlight == list[i].idStatusFlight) //MATCHEO STATUS CON PASAJERO
				{
					if(status[j].idStatusFlight == 1 && list[i].isEmpty == OCUPADO) //SI EL STATUS ES "ACTIVO"
					{
						sPassenger_PrintOnePassenger(list[i]); //MUESTRO LOS PASAJEROS
						rtn = 1;  //RETORNA 1 EN CASO DE QUE HAYA PASAJEROS QUE MOSTRAR
					}
				}
			}
		}
	}

	return rtn;
}

void sPassenger_DisplayPassengersByOrder(Passenger* list, int len) {
	int opcionSubMenuInformar;
	do{
		printf("Ordenar listado de manera: \n");
		printf("1. Ascendente\n");
		printf("2. Descendente\n");
		printf("3. Volver atras");
		opcionSubMenuInformar = getEntero("Ingrese opcion", 1, 3);
		switch(opcionSubMenuInformar) {
			case 1:  	sortPassengers(list, len, 1);
						printPassenger(list, len);
						system("pause");
			break;
			case 2:		sortPassengers(list, len, 2);
						printPassenger(list, len);
						system("pause");
			break;
			case 3:
			break;
		}
	}while(0);
}

void sPassenger_DisplayPassengersByCode(Passenger* list, int len, sStatusFlight* status, int len_status) {
	int opcionSubMenuInformar;
	do{
		printf("Ordenar listado de manera: \n");
		printf("1. Ascendente\n");
		printf("2. Descendente\n");
		printf("3. Volver atras");
		opcionSubMenuInformar = getEntero("Ingrese opcion", 1, 3);
		switch(opcionSubMenuInformar) {
			case 1:  	sortPassengersByCode(list, len, 1);
						sPassenger_DisplayPassengersByStatusFlight(status, len_status ,list, len);
						system("pause");
			break;
			case 2:		sortPassengersByCode(list, len, 2);
						sPassenger_DisplayPassengersByStatusFlight(status, len_status ,list, len);
						system("pause");
			break;
			case 3:
			break;
		}
	}while(0);
}

void sPassenger_HardcodePassengers(Passenger* list, int len, Passenger* hardcodeList, int len_hardcodeList) {
	int i;
	int index;
	if(list != NULL && len>= 0 && hardcodeList!= NULL && len_hardcodeList>= 0){
		for(i = 0; i<len_hardcodeList ; i++)
		{
			index = sPassenger_GetFreeIndex(list, len);
			if(list[index].isEmpty == LIBRE && hardcodeList[index].isEmpty == OCUPADO) {
				if(index>=0) {
					list[index] = hardcodeList[index];
				}
			}
		}
	}
}

void sPassenger_DisplayAverage(Passenger* list, int len, int cantidadDatos) {
	float precioTotal;
	float promedioTotal;
	int pasajerosArribaDelPromedio;
	precioTotal = sPassenger_CalculateTotal(list, len);
	promedioTotal = sPassenger_CalculateAverage(precioTotal, cantidadDatos);
	pasajerosArribaDelPromedio = sPassenger_CalculatePassengersOverAverage(list, len , promedioTotal);
	printf("\nTotal en pasajes: $ %.2f\n", precioTotal);
	printf("Promedio Total: $ %.2f\n", promedioTotal);
	printf("Cantidad de pasajeros por encima del promedio de precios: %d\n", pasajerosArribaDelPromedio);
	system("pause");
}
