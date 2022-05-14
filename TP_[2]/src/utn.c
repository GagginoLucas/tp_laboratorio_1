/*
 * utn.c
 * Author: Lucas Gaggino
 */


#include "utn.h"


void ordenarCaracteres(char str[]) {
	int i;
	int len;

	strlwr(str);
	str[0] = toupper(str[0]);
	len = strlen(str);//declaro una variable cantidad para que recorra hasta encontrar el espacio
	for(i=0; i<len; i++)//yo tengo que buscar el espacio
	{
		if(str[i] == ' ')
		{
			str[i+1] = toupper(str[i+1]);//uan vez que lo encuentro, le sumo 1, llego a la primera inicial y la paso a mayusculas
		}
	}

}


int askToConfirm(char msj[]) {
	int rtn = -1;
	char option;
	do {
	  printf("\n%10s\n", msj);
	  fflush(stdin);
	  scanf("%c", &option);
	} while (tolower(option) != 's' && tolower(option) != 'n');

	if(option == 's') {
		rtn = 1;
	}

	return rtn;
}


void getValidAlphaNum(char msj[], char imput[], int len_MaxCharacters) {

	int auxValidacion = 0;
	char aux[4096];
	do
	{
		printf("\n%s: ", msj);
		fflush(stdin);
		gets(aux);
		auxValidacion = isAlphaNum(aux, len_MaxCharacters);
		}while(auxValidacion == 0);
	strncpy(imput, aux, len_MaxCharacters);
	strupr(imput);
}

int isAlphaNum(char str[], int len_MaxCharacters) {

	int retorno = 1;
	int longitud;
	longitud = strlen(str);
	if (strspn(str, LEGAL_ALPHANUM_CHARS) < strlen(str) ||
			longitud > len_MaxCharacters ||
			str[0] == ' ' || str[0] == '\0')
	{
		printf("\nError, ingresar nuevamente\n");
		retorno = 0;
	}
	return retorno;
}


void getValidName(char msj[], char imput[], int len_MaxCharacters) {
	int auxValidacion = 0;
	char aux[4096];

		do
		{
			printf("\n%s: ", msj);
			fflush(stdin);
			gets(aux);
			auxValidacion = isName(aux, len_MaxCharacters);

		}while(auxValidacion == 0);
	strncpy(imput, aux, len_MaxCharacters);
}



int isName(char str[],  int len_MaxCharacters) {
	int retorno = 1;
	int longitud = strlen(str);
	if (strspn(str, LEGAL_NAME_CHARS) < strlen(str) ||
		str[0] == ' ' || str[0] == '\0' || longitud>len_MaxCharacters)
	{
		printf("\nError, ingresar nuevamente\n");
		retorno = 0;
	}

	return retorno;
}



int getEntero(char mensaje[], float min, float max)
	{
		char cadena[50];
		int auxValidacion;
		int resultado;


		do
		{
			do
			{
				printf("\n%s: ", mensaje);
				scanf("%s", cadena);
				auxValidacion = validarIngresoNumeros(cadena);

			}while(auxValidacion == 0);

			resultado = atoi(cadena);

		}while(resultado<min||resultado>max);

		return resultado;

	}


float getFlotante(char mensaje[], float min, float max) {
	char cadena[50];
	int auxValidacion;
	float resultado;
	do
	{
		do
		{
			printf("\n%s: ", mensaje);
			scanf("%s", cadena);
			auxValidacion = validarIngresoNumeros(cadena);
		}while(auxValidacion == 0);

		resultado = atof(cadena);

	}while(resultado<min||resultado>max);

	return resultado;
}


int validarIngresoNumeros(char numero[])
	{
		for(int i=0; i < strlen(numero); i++)
		{
			if(!isdigit(numero[i]))
			{
				printf("\nError, ingrese un numero positivo\n");
				return 0;
			}
		}

		return 1;
	}

