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
	/// @brief Imprime el menú en la pantalla y pide el ingreso de una opción del menú.
	///
	/// @param kilometrosIngresados : Imprime los kilómetros ingresados dentro del menú.
	/// @param precioAerolineas : Imprime el precio de Aerolineas dentro del menú.
	/// @param precioLatam : Imprime el precio de Latam dentro del menú.
	/// @return : Retorna la opcion del menú ingresada.
	int llamarMenu(float kilometrosIngresados, float precioAerolineas, float precioLatam);

	/// @fn int llamarSubMenu()
	/// @brief Imprime un submenú en pantalla en caso de tener que ingresar a que aerolinea le vas a asignar un precio.
	///
	/// @return retorna la opción del menú ingresada
	int llamarSubMenu();

	/// @fn int validarDatos(int, int, float, float, float, int, int)
	/// @brief Realiza todas las validaciones correspondientes para el correcto funcionamiento del programa.
	///
	/// @param menu : Switch para saber que tiene que validar.
	/// @param subMenuPasajes : Valida si se ingresó una opción correcta.
	/// @param kilometrosIngresados : Parámetro necesario para realizar las validaciones.
	/// @param precioLatam : Parámetro necesario para realizar las validaciones.
	/// @param precioAerolineas : Parámetro necesario para realizar las validaciones.
	/// @param flagCalculos : Bandera necesaria para validar si se realizaron los cálculos antes de mostrar los datos.
	/// @param flagCambioDeParametros : Bandera necesaria para validar si se modificaron los parámetros antes de mostrar los datos.
	/// @return : Retorna 1 en caso de que se haya validado correctamente, 0 en caso de error.
	int validarDatos(int menu, int subMenuPasajes, float kilometrosIngresados, float precioLatam, float precioAerolineas, int flagCalculos, int flagCambioDeParametros);

	/// @fn void mostrarResultados(float, float, float, float, float, float, float, float, float, float, float, float)
	/// @brief 	Muestra Los resultados de todos los cálculos realizados.
	///
	/// @param kilometrosIngresados : Muestra los kilómetros ingresados.
	///
	/// @param precioAerolineas : Muestra el precio de Aerolineas ingresado.
	/// @param precioConDebitoAerolineas : Muestra el precio de Aerolineas pagando con débito.
	/// @param precioConCreditoAerolineas : Muestra el precio de Aerolineas pagando con crédito.
	/// @param precioEnBitcoinAerolineas : Muestra el precio de Aerolineas pagando con bitcoin.
	/// @param precioPorKilometroAerolineas : Muestra el precio unitario por kilómetro de Aerolineas.
	///
	/// @param precioLatam : Muestra el precio de Latam ingresado.
	/// @param precioConDebitoLatam : Muestra el precio de Latam pagando con débitoi.
	/// @param precioConCreditoLatam : Muestra el precio de Latam pagando con crédito.
	/// @param precioEnBitcoinLatam : Muestra el precio de Latam pagando con bitcoin.
	/// @param precioPorKilometroLatam : Muestra el precio unitario por kilómetro de Latam.
	/// @param diferenciaDePrecio : Muestra la diferencia de precio entre las dos companías de viaje.
	void mostrarResultados(float kilometrosIngresados, float precioAerolineas, float precioConDebitoAerolineas, float precioConCreditoAerolineas, float precioEnBitcoinAerolineas, float precioPorKilometroAerolineas, float precioLatam, float precioConDebitoLatam, float precioConCreditoLatam, float precioEnBitcoinLatam, float precioPorKilometroLatam, float diferenciaDePrecio);

	/// @fn void cargarDatosForzados()
	/// @brief Se realiza una carga de datos hardcodeados, la funcion se encarga de realizar los cálculos y mostrar los resultados.
	///
	///
	void cargarDatosForzados();

	/// @fn int funcionSalir()
	/// @brief Función encargada de preguntar si se desea salir del programa.
	///
	/// @return retorna 0 en caso de querer salir y 1 en caso de querer quedarse.
	int funcionSalir(void);



#endif /* MENU_TP1_H_ */
