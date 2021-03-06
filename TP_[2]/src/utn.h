/*
 * utn.h
 * Author: Lucas Gaggino
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define LEGAL_ALPHANUM_CHARS "ABCDEFGHIJLKMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789"
#define LEGAL_NAME_CHARS "' 'ABCDEFGHIJLKMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

/**
 * \brief Solicita un n?mero flotante al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param min Valida el m?nimo n?mero que acepta
 * \param max valida el m?ximo n?mero que acepta
 * \return El n?mero ingresado por el usuario
 */
float getFlotante(char mensaje[], float min, float max);


/// @brief Valida que el dato ingresado sean solo n?meros
///
/// @param numero array a validar
/// @return retorna [0] en caso de error y [1] en caso de que sean solo n?meros
int validarIngresoNumeros(char numero[]);

/**
 * \brief Solicita un n?mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n?mero ingresado por el usuario
 */
int getEntero(char mensaje[], float min, float max);


/// @brief printea un mensaje y espera un S o un N
///
/// @param msj*
/// @return [0] en caso de N, [1] en caso de S
int askToConfirm(char msj[]);


/// @brief Put the first letter uppercase and the rest in lowercase
///
/// @param str*
void ordenarCaracteres(char str[]);

/// @brief Validate if the str is a alphanum and validate the max amount of characters
///
/// @param str
/// @param len_MaxCharacters
/// @return [0] if error, [1] if its ok
int isAlphaNum(char str[], int len_MaxCharacters);

/// @brief ask for a alphanum str
///
/// @param msj msj to show
/// @param imput where to charge the array
/// @param len_MaxCharacters max permited lenght in the array
void getValidAlphaNum(char msj[], char imput[], int len_MaxCharacters);


/// @brief Validate if the str is a Name and validate the max amount of characters
/// @param str where to charge the array
/// @param len_MaxCharacters max permited lenght in the array
/// @return  [0] if error, [1] if its ok
int isName(char str[],  int len_MaxCharacters);


/// @brief ask for a name
///
/// @param msj msj to show
/// @param imput where to charge the array
/// @param len_MaxCharacters max permited lenght in the array
void getValidName(char msj[], char imput[], int len_MaxCharacters);



#endif /* UTN_H_ */
