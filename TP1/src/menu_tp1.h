/*
 * menu_tp1.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Lucas
 */

#ifndef MENU_TP1_H_
#define MENU_TP1_H_

#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calculos_tp1.h"

	/// @fn int llamarMenu(float, float, float)
	/// @brief Imprime el men� en la pantalla y pide el ingreso de una opci�n del men�.
	///
	/// @param kilometrosIngresados : Imprime los kil�metros ingresados dentro del men�.
	/// @param precioAerolineas : Imprime el precio de Aerolineas dentro del men�.
	/// @param precioLatam : Imprime el precio de Latam dentro del men�.
	/// @return : Retorna la opcion del men� ingresada.
	int llamarMenu(float kilometrosIngresados, float precioAerolineas, float precioLatam);

	/// @fn int llamarSubMenu()
	/// @brief Imprime un submen� en pantalla en caso de tener que ingresar a que aerolinea le vas a asignar un precio.
	///
	/// @return retorna la opci�n del men� ingresada
	int llamarSubMenu();

	/// @fn int validarDatos(int, int, float, float, float, int, int)
	/// @brief Realiza todas las validaciones correspondientes para el correcto funcionamiento del programa.
	///
	/// @param menu : Switch para saber que tiene que validar.
	/// @param subMenuPasajes : Valida si se ingres� una opci�n correcta.
	/// @param kilometrosIngresados : Par�metro necesario para realizar las validaciones.
	/// @param precioLatam : Par�metro necesario para realizar las validaciones.
	/// @param precioAerolineas : Par�metro necesario para realizar las validaciones.
	/// @param flagCalculos : Bandera necesaria para validar si se realizaron los c�lculos antes de mostrar los datos.
	/// @param flagCambioDeParametros : Bandera necesaria para validar si se modificaron los par�metros antes de mostrar los datos.
	/// @return : Retorna 1 en caso de que se haya validado correctamente, 0 en caso de error.
	int validarDatos(int menu, int subMenuPasajes, float kilometrosIngresados, float precioLatam, float precioAerolineas, int flagCalculos, int flagCambioDeParametros);

	/// @fn void mostrarResultados(float, float, float, float, float, float, float, float, float, float, float, float)
	/// @brief 	Muestra Los resultados de todos los c�lculos realizados.
	///
	/// @param kilometrosIngresados : Muestra los kil�metros ingresados.
	///
	/// @param precioAerolineas : Muestra el precio de Aerolineas ingresado.
	/// @param precioConDebitoAerolineas : Muestra el precio de Aerolineas pagando con d�bito.
	/// @param precioConCreditoAerolineas : Muestra el precio de Aerolineas pagando con cr�dito.
	/// @param precioEnBitcoinAerolineas : Muestra el precio de Aerolineas pagando con bitcoin.
	/// @param precioPorKilometroAerolineas : Muestra el precio unitario por kil�metro de Aerolineas.
	///
	/// @param precioLatam : Muestra el precio de Latam ingresado.
	/// @param precioConDebitoLatam : Muestra el precio de Latam pagando con d�bitoi.
	/// @param precioConCreditoLatam : Muestra el precio de Latam pagando con cr�dito.
	/// @param precioEnBitcoinLatam : Muestra el precio de Latam pagando con bitcoin.
	/// @param precioPorKilometroLatam : Muestra el precio unitario por kil�metro de Latam.
	/// @param diferenciaDePrecio : Muestra la diferencia de precio entre las dos compan�as de viaje.
	void mostrarResultados(float kilometrosIngresados, float precioAerolineas, float precioConDebitoAerolineas, float precioConCreditoAerolineas, float precioEnBitcoinAerolineas, float precioPorKilometroAerolineas, float precioLatam, float precioConDebitoLatam, float precioConCreditoLatam, float precioEnBitcoinLatam, float precioPorKilometroLatam, float diferenciaDePrecio);

	/// @fn void cargarDatosForzados()
	/// @brief Se realiza una carga de datos hardcodeados, la funcion se encarga de realizar los c�lculos y mostrar los resultados.
	///
	///
	void cargarDatosForzados();

	/// @fn int funcionSalir()
	/// @brief Funci�n encargada de preguntar si se desea salir del programa.
	///
	/// @return retorna 0 en caso de querer salir y 1 en caso de querer quedarse.
	int funcionSalir(void);



#endif /* MENU_TP1_H_ */
