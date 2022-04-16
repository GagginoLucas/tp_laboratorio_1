/*
 * menu_tp1.c
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
#include "calculos_tp1.h"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"

int llamarMenu(float kilometrosIngresados, float precioAerolineas, float precioLatam)
	{
		int menu;

		printf("1. Ingresar kilometros (Kilometros ingresados: "GREEN"%.2f"RESET")\n", kilometrosIngresados);
		printf("2. Ingresar precio de los vuelos (Latam: "GREEN "$ %.2f" RESET", Aerolineas: "GREEN"$ %.2f"RESET")\n", precioLatam, precioAerolineas);
		printf("3. Calcular costos\n");
		printf("4. Mostrar informe\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Para salir del menu\n");
		menu = pedirNumero("Seleccione una opcion del menu: " , 1, 6);
		system("cls");
		return menu;

	}

void mostrarResultados(float kilometrosIngresados, float precioAerolineas, float precioConDebitoAerolineas, float precioConCreditoAerolineas, float precioEnBitcoinAerolineas, float precioPorKilometroAerolineas, float precioLatam, float precioConDebitoLatam, float precioConCreditoLatam, float precioEnBitcoinLatam, float precioPorKilometroLatam, float diferenciaDePrecio)
	{
			printf ("Kilometros ingresados:"GREEN"$ %.2f\n\n"RESET, kilometrosIngresados);


			if(precioAerolineas == 0)
			{
				printf("No se ha ingresado el costo de Aerolineas.\n\n");
			}else
			{
				printf("Precio Aerolineas: "GREEN"$ %.2f\n"RESET, precioAerolineas);
				printf(" a) Precio con tarjeta de debito: "GREEN"$ %.2f\n"RESET, precioConDebitoAerolineas);
				printf(" b) Precio con tarjeta de credito: "GREEN"$ %.2f\n"RESET,precioConCreditoAerolineas);
				printf(" c) Precio pagando con bitcoin: " GREEN"%.6f BTC\n"RESET, precioEnBitcoinAerolineas);
				printf(" d) Precio unitario:"GREEN" $ %.2f\n\n"RESET, precioPorKilometroAerolineas);
			}

			if(precioLatam == 0)
			{
				printf("No se ha ingresado el costo de Latam.\n\n");
			}else
			{
				printf ("Precio Latam: "GREEN"$ %.2f\n"RESET, precioLatam);
				printf(" a) Precio con tarjeta de debito: "GREEN"$ %.2f\n"RESET, precioConDebitoLatam);
				printf(" b) Precio con tarjeta de credito: "GREEN"$ %.2f\n"RESET,precioConCreditoLatam);
				printf(" c) Precio pagando con bitcoin: "GREEN"%.6f BTC\n"RESET, precioEnBitcoinLatam);
				printf(" d) Precio unitario: "GREEN"$ %.2f\n\n\n"RESET, precioPorKilometroLatam);
			}

			printf("La diferencia de precio es de: "GREEN"$ %.2f\n\n"RESET, diferenciaDePrecio);

	}


int validarDatos(int menu, int subMenuPasajes, float kilometrosIngresados, float precioLatam, float precioAerolineas, int flagCalculos, int flagCambioDeParametros)
	{
		int retorno = 0;
		switch(menu)
		{

		case 2: 	while(subMenuPasajes!=1 && subMenuPasajes!=2 && subMenuPasajes!=0)
					{
						printf("1. Para ingresar el precio de Latam\n");
						printf("2. Para ingresar el precio de Aerolineas\n");
						printf("0. Para salir\n");
						scanf("%d", &subMenuPasajes);
					}
		retorno = 1;
		break;
		case 3:   if(kilometrosIngresados <= 0)
					{
						printf(RED"ERROR, no se han ingresado los kilometros!\n"RESET);
						system("pause");
						retorno = 0;
					}else
					{
						if(precioAerolineas == 0 && precioLatam == 0)
						{
							printf(RED"No se ha ingresado el precio de ninguna agencia de viaje, no hay calculos para realizar.\n"RESET);
							system("pause");
							retorno = 0;
						}else
					{
					retorno = 1;
					}
		break;
		case 4:		if(flagCalculos == 0)
					{
						printf(RED"Debes calcular los costos antes de continuar.\n"RESET);
						system("pause");

					}else
					{
						if(flagCambioDeParametros == 1)
						{
							printf(RED"Debes calcular los costos nuevamente antes de continuar.\n"RESET);
							system("pause");
						}else
						{
							retorno =1;
						}
					}
				}
		break;
	}
		return retorno;
	}


int funcionSalir()
	{
		int retorno = 1;
		char salir;
		 printf("¿Esta seguro que desea salir? S/N \n");
		 fflush(stdin);
		 scanf("%c", &salir);
		 while(salir != 'S' && salir != 's' && salir != 'N' && salir != 'n')
		 {
			 printf("¿Esta seguro que desea salir? S/N \n");
			 fflush(stdin);
			 scanf("%c", &salir);
		 }
		 if(salir == 'S' || salir == 's')
		 {
			 printf("Hasta la pr%cxima!",162);
			 sleep(2);
			 retorno = 0;
		}
		 return retorno;
	}


int llamarSubMenu()
	{
		int subMenuPasajes;
		printf("1. Para ingresar el precio de Latam\n");
		printf("2. Para ingresar el precio de Aerolineas\n");
		printf("0. Para salir\n");
		scanf("%d", &subMenuPasajes);
		return subMenuPasajes;
	}

void cargarDatosForzados()
{


	float precioLatamHC;
	float precioAerolineasHC;
	float kilometrosIngresadosHC;
	precioLatamHC = 159339;
	precioAerolineasHC = 162965;
	kilometrosIngresadosHC = 7090;



	float precioConDebitoLatam = realizarCalculo(precioLatamHC, 1);
	float precioConDebitoAerolineas = realizarCalculo(precioAerolineasHC, 1);
	float precioConCreditoLatam = realizarCalculo(precioLatamHC, 2);
	float precioConCreditoAerolineas = realizarCalculo(precioAerolineasHC, 2);
	float precioEnBitcoinLatam = realizarCalculo(precioLatamHC, 3);
	float precioEnBitcoinAerolineas = realizarCalculo(precioAerolineasHC, 3);
	float precioPorKilometroLatam = calcularPrecioUnitario(precioLatamHC, kilometrosIngresadosHC);
	float precioPorKilometroAerolineas = calcularPrecioUnitario(precioAerolineasHC, kilometrosIngresadosHC);
	float diferenciaDePrecio = calcularDiferenciaDePrecio(precioLatamHC, precioAerolineasHC);


	mostrarResultados(kilometrosIngresadosHC, precioAerolineasHC, precioConDebitoAerolineas, precioConCreditoAerolineas, precioEnBitcoinAerolineas, precioPorKilometroAerolineas, precioLatamHC, precioConDebitoLatam, precioConCreditoLatam, precioEnBitcoinLatam, precioPorKilometroLatam, diferenciaDePrecio);




}

