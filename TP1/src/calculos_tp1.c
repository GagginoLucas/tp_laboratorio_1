/*
 * calculos_tp1.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Lucas
 */


#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu_tp1.h"


	int pedirEntero(char mensaje[],char mensajeError[], int inferior, int superior)
	{
		setbuf(stdout, NULL);
		int numero;
		    printf("%s", mensaje);
		    scanf("%d", &numero);

		    while(numero<inferior||numero>superior){
		        printf("%s", mensajeError);
		        scanf("%d", &numero);
		    }

		return numero;
	}

	float pedirFlotante(char mensaje[],char mensajeError[], int inferior, int superior)
	{
		setbuf(stdout, NULL);
		float numero;
		    printf("%s", mensaje);
		    scanf("%f", &numero);

		    while(numero<inferior||numero>superior){
		        printf("%s", mensajeError);
		        scanf("%f", &numero);
		    }

		return numero;
	}


	float realizarCalculo(float numero, int tipoDeCalculo)
	{
		float resultado;

		double valorBitcoin = 4461765.83;

		switch(tipoDeCalculo)
		{
		case 1: 	resultado = numero - (numero*0.10); //Calcular Debito
		break;
		case 2:		resultado = numero + (numero*0.25);//Calcular Credito
		break;
		case 3:		resultado = numero/valorBitcoin;//Calcular Bitcoin
		break;
		}
		return resultado;


	}


	float calcularPrecioUnitario(float precioTotal, float Km)
	{

		float resultado;
		resultado = precioTotal/Km;
		return resultado;
	}


	float calcularDiferenciaDePrecio(float numero1, float numero2)
	{
		float resultado;
		if(numero1 > numero2)
		{
			resultado = numero1 - numero2;

		}else
		{
			if(numero2 > numero1)
			{
				resultado = numero2 - numero1;
			}else
			{
				if(numero1  == numero2)
				{
					resultado = 0;
				}
			}
		}

		return resultado;
	}
