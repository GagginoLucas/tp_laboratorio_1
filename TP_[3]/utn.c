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


int get_Int(int* pResult, char* msj) {

	char auxNumber[50];
	int auxValidation;
	int rtn = -1;;

	do
	{
		printf("\n%s ", msj);
		fflush(stdin);
		if(!myGets(auxNumber, sizeof(auxNumber)))
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
			if(!myGets(auxNumber, sizeof(auxNumber)))
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
		if(!myGets(auxNumber, sizeof(auxNumber)))
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
			if(!myGets(auxNumber, sizeof(auxNumber)))
			auxValidation = validateNumbers(auxNumber);
		}while(auxValidation == 0);

		*pResult = atof(auxNumber);

	}while(*pResult<min||*pResult>max);
	rtn = 1;
	return rtn;
}


void get_String(char* msj, char* pArray, int len_MaxCharacters) {
	int auxValidation = 0;
	char aux[4096];

	do
	{
		printf("\n%s: ", msj);
		fflush(stdin);
		if(!myGets(aux, len_MaxCharacters))
		auxValidation = validateString(aux, len_MaxCharacters);

	}while(auxValidation == 0);
	strncpy(pArray, aux, len_MaxCharacters);
}


void get_AlphaNum(char* msj, char* pArray, int len_MaxCharacters) {

	int auxValidation = 0;
	char aux[4096];
	do
	{
		printf("\n%s: ", msj);
		fflush(stdin);
		if(!myGets(aux, sizeof(aux))) {
			auxValidation = isAlphaNum(aux, len_MaxCharacters);
		}
	}while(auxValidation == 0);
	strupr(aux);
	strncpy(pArray, aux, len_MaxCharacters);
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


int validateString(char* str,  int len_MaxCharacters) {
	int rtn = 1;
	int len = strlen(str);
	if (strspn(str, LEGAL_STRING_CHARS) < len ||
			str[0] == ' ' || str[0] == '\0' || len>len_MaxCharacters)
	{
		printf("\nError, ingresar nuevamente\n");
		rtn = 0;
	}

	return rtn;
}


int isAlphaNum(char* str, int len_MaxCharacters) {

	int rtn = 1;
	int len;
	len = strlen(str);
	if (strspn(str, LEGAL_ALPHANUM_CHARS) < len ||
			str[0] == ' ' || str[0] == '\0' ||len > len_MaxCharacters )
	{
		printf("\nError, ingresar nuevamente\n");
		rtn = 0;
	}
	return rtn;
}


void sortString(char* str) {
	int i;
	int len;

	strlwr(str);
	str[0] = toupper(str[0]);
	len = strlen(str);
	for(i=0; i<len; i++)
	{
		if(str[i] == ' ')
		{
			str[i+1] = toupper(str[i+1]);
		}
	}

}


int askToConfirm(char* msj) {
	int rtn = -1;
	int option;

	get_Int(&option, msj);

	if(option == 1) {
		rtn = 1;
	}

	return rtn;
}











