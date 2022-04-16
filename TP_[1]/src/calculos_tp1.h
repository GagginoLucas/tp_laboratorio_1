/*
 * calculos_tp1.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Lucas
 */

#ifndef CALCULOS_TP1_H_
#define CALCULOS_TP1_H_

#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu_tp1.h"

	/// @fn double pedirNumero(char[], int, int)
	/// @brief Función utilizada para pedir números.
	///
	/// @param mensaje
	/// @param min : numero mínimo para validar rango
	/// @param max : numero máximo para validar rango
	/// @return : retorna el número ingresado
	float pedirNumero(char mensaje[], float inferior, float superior);

	/// @fn int validarIngresoNumeros(char[])
	/// @brief Recorre mediante un for la cadena ingresada para verificar si se ingresaron solo números
	///
	/// @param numero
	/// @return 0 en caso de que haya letras, 1 en caso de que haya solo números
	int validarIngresoNumeros(char numero[]);



	/// @fn int pedirEntero(char[], char[], int, int)
	/// @brief Le pide al usuario el ingreso de un número entero.
	///
	/// @param mensaje : Le muestra un mensaje al usuario.
	/// @param mensajeError : Le muestra un mensaje al usuario en caso de que no se haya podido validar el número.
	/// @param inferior : Valida cual es el número mínimo a ingresar.
	/// @param superior : Valida cual es el número máximo a ingresar.
	/// @return Retorna el número ingresado por el usuario.
	int pedirEntero(char mensaje[],char mensajeError[], int inferior, int superior);

	/// @fn int pedirFlotante(char[], char[], int, int)
	/// @brief Le pide al usuario el ingreso de un número flotante.
	///
	/// @param mensaje : Le muestra un mensaje al usuario.
	/// @param mensajeError : Le muestra un mensaje al usuario en caso de que no se haya podido validar el número.
	/// @param inferior : Valida cual es el número mínimo a ingresar.
	/// @param superior : Valida cual es el número máximo a ingresar.
	/// @return Retorna el número ingresado por el usuario.
	float pedirFlotante(char mensaje[],char mensajeError[], int inferior, int superior);

/// @fn float realizarCalculo(float, int)
	/// @brief Función encarga de realizar 3 tipos de cálculos que seran: el precio con DÉBITO, el precio con CRÉDITO, y el precio con BITCOIN.
	///
	/// @param numero : Será un numero ingresado anteriormente por el usuario, que hace referencia al precio del Vuelo Latam/Aerolineas.
	/// @param tipoDeCalculo : Será un número hardcodeado para indicar el tipo de calculo a realizar. 1. CALCULAR DEBITO. 2.CALCULAR CREDITO. 3.CALCULAR BITCOIN.
	/// @return Retorna el resultado de la operación.
	float realizarCalculo(float numero, int tipoDeCalculo);


	/// @fn float calcularPrecioUnitario(float, float)
	/// @brief Calcula el precio por kilómetro.
	///
	/// @param precioTotal :Será el precio ingresado de la agencia de viajes.
	/// @param Km : Serán los kilometros ingresados.
	/// @return Retorna el resultado de la operación.
	float calcularPrecioUnitario(float precioTotal, float Km);


	/// @fn int calcularDiferenciaDePrecio(float, float)
	/// @brief 	Calcula la diferencia de precio de las dos agencias de viaje
	///
	/// @param numero1 : Precio de la primer Agencia.
	/// @param numero2 : Precio de la segunda Agencia.
	/// @return Retorna el resultado de la operacion.
	float calcularDiferenciaDePrecio(float numero1, float numero2);


#endif /* CALCULOS_TP1_H_ */


