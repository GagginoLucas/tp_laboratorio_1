/*
 * utn.c
 * Author: Lucas Gaggino
 */


#include "utn.h"


int myGets(char* pStr, int len) {

	int rtn= -1;
	char bufferString [4096];
	if(pStr != NULL && len > 0) {

		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL) {

			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n') {

				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len) {

				strncpy(pStr, bufferString, len);
				rtn = 0;
			}
		}
	}
	return rtn;
}

void sortString(char* str) {
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


int askToConfirm(char* msj) {
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


void get_AlphaNum(char* msj, char* pArray, int len_MaxCharacters) {

	int auxValidation = 0;
	char aux[10];
	do
	{
		printf("\n%s: ", msj);
		fflush(stdin);
		myGets(aux, sizeof(aux));
		auxValidation = isAlphaNum(aux, len_MaxCharacters);
	}while(auxValidation == 0);
	strncpy(pArray, aux, len_MaxCharacters);
	strupr(pArray);
}

int isAlphaNum(char* str, int len_MaxCharacters) {

	int rtn = 1;
	int len;
	len = strlen(str);
	if (strspn(str, LEGAL_ALPHANUM_CHARS) < len|| str[0] == ' ' || str[0] == '\0' ||len > len_MaxCharacters )
	{
		printf("\nError, ingresar nuevamente\n");
		rtn = 0;
	}
	return rtn;
}


void get_String(char* msj, char* pArray, int len_MaxCharacters) {
	int auxValidation = 0;
	char aux[4096];

	do
	{
		printf("\n%s: ", msj);
		fflush(stdin);
		myGets(aux, len_MaxCharacters);
		auxValidation = validateString(aux, len_MaxCharacters);

	}while(auxValidation == 0);
	strncpy(pArray, aux, len_MaxCharacters);
}



int validateString(char* str,  int len_MaxCharacters) {
	int rtn = 1;
	int len = strlen(str);
	if (strspn(str, LEGAL_STRING_CHARS) < strlen(str) ||
			str[0] == ' ' || str[0] == '\0' || len>len_MaxCharacters)
	{
		printf("\nError, ingresar nuevamente\n");
		rtn = 0;
	}

	return rtn;
}

int get_Int(int* pResult, char* msj) {

	char auxNumber[50];
	int auxValidation;
	int rtn = -1;;

	do
	{
		printf("\n%s ", msj);
		fflush(stdin);
		myGets(auxNumber, sizeof(auxNumber));
		auxValidation = validateNumbers(auxNumber);

	}while(auxValidation == 0);

	*pResult = atoi(auxNumber);
	rtn = 1;

	return rtn;
}


int get_IntInRange(int* pResult, char* msj, float min, float max) {

	char auxNumber[50];
	int auxValidation;
	int rtn = -1;;
	do
	{
		do
		{
			printf("\n%s ", msj);
			fflush(stdin);
			myGets(auxNumber, sizeof(auxNumber));
			auxValidation = validateNumbers(auxNumber);

		}while(auxValidation == 0);

		*pResult = atoi(auxNumber);
		rtn = 1;

	}while(*pResult<min||*pResult>max);

	return rtn;
}

int get_Float(float* pResult, char* msj) {
	char auxNumber[50];
	int auxValidation;
	int rtn = -1;

	do
	{
		printf("\n%s ", msj);
		fflush(stdin);
		myGets(auxNumber, sizeof(auxNumber));
		auxValidation = validateNumbers(auxNumber);
	}while(auxValidation == 0);

	*pResult = atof(auxNumber);
	rtn = 1;

	return rtn;
}

int get_FloatInRange(float* pResult, char* msj, float min, float max) {
	char auxNumber[50];
	int auxValidation;
	int rtn = -1;
	do
	{
		do
		{
			printf("\n%s ", msj);
			fflush(stdin);
			myGets(auxNumber, sizeof(auxNumber));
			auxValidation = validateNumbers(auxNumber);
		}while(auxValidation == 0);

		*pResult = atof(auxNumber);

	}while(*pResult<min||*pResult>max);
	rtn = 1;
	return rtn;
}


int validateNumbers(char* nro) {
	int rtn;
	rtn = 1;

	for(int i=0; i < strlen(nro); i++) {

		if(!isdigit(nro[i]))
		{
			printf("\nError, ingrese un numero positivo\n");
			rtn = 0;
			break;
		}
	}

	return rtn;
}
