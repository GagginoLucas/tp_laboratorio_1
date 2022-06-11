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
#define LEGAL_ALPHANUM_CHARS "ABCDEFGHIJLKMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"
#define LEGAL_STRING_CHARS "' 'ABCDEFGHIJLKMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"


/// @brief Lee el stdin mientras no encuentre un '\n'(ENTER)
/// y mientras no se pase de la longitud máxima de caracteres pasadas por el len
///
/// @param pStr puntero a string donde se guardará  lo ingresado por el fgets
/// @param len Tamaño máximo de la cadena a ingresar
/// @return [-1] en caso de error,[0] si se pudo copiar el buffer en pStr
int myGets(char* pStr, int len);


/// @brief Solicita un número entero al usuario
///
/// @param pResult puntero donde se guardará el resultado obtenido
/// @param msj Mensaje a ser mostrado
/// @return retorna [-1] en caso de error, [1] si esta todo ok
int get_Int(int* pResult, char* msj);



/// @brief Solicita un número entero en rango al usuario
///
/// @param pResult Puntero donde se guardará el resultado obtenido
/// @param msj  Mensaje a ser mostrado
/// @param min mínimo número a ser ingresado
/// @param max máximo número a ser ingresado
/// @return retorna [-1] en caso de error, [1] si esta todo ok
int get_IntInRange(int* pResult, char* msj, float min, float max);


/// @brief Solicita un número flotante al usuario
///
/// @param pResult Puntero donde se guardará el resultado obtenido
/// @param msj Mensaje a ser mostrado
/// @return retorna [-1] en caso de error, [1] si esta todo ok
int get_Float(float* pResult, char* msj);


/**
 * \brief Solicita un número flotante en rango al usuario
 * /// @param pResult Puntero donde se guardará el resultado obtenido
 * \param msj Mensaje a ser mostrado
 * \param min mínimo número a ser ingresado
 * \param max máximo número a ser ingresado
 * \return retorna [-1] en caso de error, [1] si esta todo ok
 */
int get_FloatInRange(float* pResult, char* msj, float min, float max);



/// @brief Solicita un string alfanumérico al usuario.
///
/// @param msj Mensaje a ser mostrado.
/// @param pArray Puntero a char donde se guardará el dato obtenido.
/// @param len_MaxCharacters cantidad máxima de caracteres permitidos.
void get_AlphaNum(char* msj, char* pArray, int len_MaxCharacters);


/// @brief Solicita una string al usuario.
/// @param Mensaje a ser mostrado.
/// @param pArray Puntero a char donde se guardará el dato obtenido.
/// @param len_MaxCharacters cantidad máxima de caracteres permitidos.
void get_String(char* msj, char* pArray, int len_MaxCharacters);


/// @brief Valida que el dato ingresado sean solo números
///
/// @param nro array a validar
/// @return retorna [0] en caso de error y [1] en caso de que sean solo números
int validateNumbers(char* nro);


/// @brief Validate if the str is a Name and validate the max amount of characters
/// @param str where to charge the array
/// @param len_MaxCharacters max permited lenght in the array
/// @return  [0] if error, [1] if its ok
int validateString(char* str,  int len_MaxCharacters);

/// @brief Validate if the str is a alphanum and validate the max amount of characters
///
/// @param str
/// @param len_MaxCharacters
/// @return [0] if error, [1] if its ok
int isAlphaNum(char* str, int len_MaxCharacters);


/// @brief Put the first letter uppercase and the rest in lowercase
///
/// @param str*
void sortString(char* str);


/// @brief muestra un mensaje de confirmación
///
/// @param msj* mensaje a ser mostrado
/// @return [1] en caso de que se ingrese 1  [-1] si se ingresa cualquier otro número
int askToConfirm(char* msj);



#endif /* UTN_H_ */
