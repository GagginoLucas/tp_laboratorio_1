/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Lucas Javier Gaggino 1-F
 Description :
 Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que no puede tener más de 2000 pasajeros.
 El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 ============================================================================
 */


#include "menu.h"
#define LEN_LISTPASSENGERS 2000 //TAMAÑO LISTA DE PASAJEROS
#define LEN_STATUSFLIGHT 3  //TAMAÑO LISTA DE ESTADOS DE VUELO
#define LEN_PASSENGERHARDCODE 15 //CANTIDAD DE PASAJEROS HARDCODEADOS

int main(void) {

	setbuf(stdout, NULL);
	Passenger listPassengers[LEN_LISTPASSENGERS];
	sStatusFlight statusFlight[LEN_STATUSFLIGHT]={{1, "ACTIVO"},{2,"DEMORADO"},{3,"INACTIVO"}};
											//ID     NOMBRE     APELLIDO    PRECIO   FLYCODE  TIPO  ISEMPTY  ESTADO
	Passenger passengersHardcodeList[LEN_PASSENGERHARDCODE] ={{3000, "Lucas Javier", "Gaggino", 120000, "AB11Z2", 3, OCUPADO, 1 },
											{3001, "Mathias", "Bustamante", 290000, "BBN12Z", 1, OCUPADO, 1 },
											{3002, "Gianni", "Maggiori", 175000, "BBN12Z", 2, OCUPADO, 1 },
								 			{3003, "Lionel", "Messi", 420000, "AB11Z2", 1, OCUPADO, 1 },
											{3004, "David", "Fernandez", 52000, "XX21ZV", 3, OCUPADO, 2 },
											{3005, "Alejo Rodrigo", "Calvi", 225000, "H21ZB2", 3, OCUPADO, 1 },
											{3006, "Ignacio", "Calvi", 225000, "H21ZB2", 2, OCUPADO, 1 },
											{3007, "Juan Cruz", "DiNardo", 180000, "F1PAAB", 3, OCUPADO, 3 },
											{3008, "Sol", "Graciano", 180000, "F1PAAB", 3, OCUPADO, 3 },
											{3009, "Maximiliano", "Sokolovski", 190000, "AB11Z2", 2, OCUPADO, 1 },
											{3010, "Stephanie", "Caffiareli", 190000, "AB11Z2", 2, OCUPADO, 1 },
											{3011, "Juan", "Perez", 39500, "BA22A1", 3, OCUPADO, 2 },
											{3012, "Pepe", "Perez", 52000, "BA22A1", 2, OCUPADO, 2 },
											{3013, "Maria", "Perez", 98000, "BA22A1", 1, OCUPADO, 2 },
											{3014, "Joaquin", "Perez", 39500, "BA22A1", 3, OCUPADO, 2 },};

	initPassengers(listPassengers, LEN_LISTPASSENGERS);
	callMainMenu(listPassengers, LEN_LISTPASSENGERS,
				 statusFlight, LEN_STATUSFLIGHT,
				 passengersHardcodeList, LEN_PASSENGERHARDCODE);
}
