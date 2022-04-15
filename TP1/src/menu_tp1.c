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


int llamarMenu(float kilometrosIngresados, float precioAerolineas, float precioLatam)
	{
		int menu;

		printf("1. Ingresar kilometros (Kilometros ingresados: %.2f)\n", kilometrosIngresados);
		printf("2. Ingresar precio de los vuelos (Latam: $ %.2f, Aerolineas: $ %.2f)\n", precioLatam, precioAerolineas);
		printf("3. Calcular costos\n");
		printf("4. Mostrar informe\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Para salir del menu\n");
		printf("Seleccione una opcion del menu: ");
		scanf("%d", &menu);
		system("cls");
		return menu;

	}

void mostrarResultados(float kilometrosIngresados, float precioAerolineas, float precioConDebitoAerolineas, float precioConCreditoAerolineas, float precioEnBitcoinAerolineas, float precioPorKilometroAerolineas, float precioLatam, float precioConDebitoLatam, float precioConCreditoLatam, float precioEnBitcoinLatam, float precioPorKilometroLatam, float diferenciaDePrecio)
	{
			printf ("Kilometros ingresados: %.2f\n\n", kilometrosIngresados);


			if(precioAerolineas == 0)
			{
				printf("No se ha ingresado el costo de Aerolineas.\n\n");
			}else
			{
				printf("Precio Aerolineas: $ %.2f\n", precioAerolineas);
				printf(" a) Precio con tarjeta de debito: $ %.2f\n", precioConDebitoAerolineas);
				printf(" b) Precio con tarjeta de credito: $ %.2f\n",precioConCreditoAerolineas);
				printf(" c) Precio pagando con bitcoin: %.6f BTC\n", precioEnBitcoinAerolineas);
				printf(" d) Precio unitario: $ %.2f\n\n", precioPorKilometroAerolineas);
			}

			if(precioLatam == 0)
			{
				printf("No se ha ingresado el costo de Latam.\n\n");
			}else
			{
				printf ("Precio Latam: $ %.2f\n", precioLatam);
				printf(" a) Precio con tarjeta de debito: $ %.2f\n", precioConDebitoLatam);
				printf(" b) Precio con tarjeta de credito: $ %.2f\n",precioConCreditoLatam);
				printf(" c) Precio pagando con bitcoin: %.6f BTC\n", precioEnBitcoinLatam);
				printf(" d) Precio unitario: $ %.2f\n\n\n", precioPorKilometroLatam);
			}

			printf("La diferencia de precio es de: $ %.2f\n\n", diferenciaDePrecio);

			system("pause");


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
						printf("ERROR, no se han ingresado los kilometros!.\n");
						system("pause");
						retorno = 0;
					}else
					{
						if(precioAerolineas == 0 && precioLatam == 0)
						{
							printf("No se ha ingresado el precio de ninguna agencia de viaje, no hay calculos para realizar.\n");
							system("pause");
							retorno = 0;
						}else
					{
					retorno = 1;
					}
		break;
		case 4:		if(flagCalculos == 0)
					{
						printf("Debes calcular los costos antes de continuar.\n");
						system("pause");

					}else
					{
						if(flagCambioDeParametros == 1)
						{
							printf("Debes calcular los costos nuevamente antes de continuar.\n");
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
		 if(salir == 'S' || salir == 's')
		 {
			 printf("Hasta la pr%cxima!",162);
			 sleep(3);
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

void cargarDatosForzados()  //Realicé esta función que se encarga de Hardcodear los datos, calcular e imprimir,
							//todo dentro de la misma función, la dejé sin uso porque nuestros ayudantes de cátedra
							//nos dijeron que carguemos los datos para que haya que calcularlos y mostrarlos presionando el 3 y el 4.
							//en caso de querer usar la función sacar el comentario del Main.
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

		printf ("Kil%cmetros ingresados: %.2f\n\n",162, kilometrosIngresadosHC);

		printf ("Precio Latam: $ %.2f\n", precioLatamHC);
		printf(" a) Precio con tarjeta de d%cbito: $ %.2f\n",130 , precioConDebitoLatam);
		printf(" b) Precio con tarjeta de cr%cdito: $ %.2f\n",130 , precioConCreditoLatam);
		printf(" c) Precio pagando con bitcoin: %.6f BTC\n", precioEnBitcoinLatam);
		printf(" d) Precio unitario: $ %.2f\n\n\n", precioPorKilometroLatam);
		printf("Precio Aerolineas: $ %.2f\n", precioAerolineasHC);
		printf(" a) Precio con tarjeta de d%cbito: $ %.2f\n",130 , precioConDebitoAerolineas);
		printf(" b) Precio con tarjeta de cr%cdito: $ %.2f\n",130 , precioConCreditoAerolineas);
		printf(" c) Precio pagando con bitcoin: %.6f BTC\n", precioEnBitcoinAerolineas);
		printf(" d) Precio unitario: $ %.2f\n\n", precioPorKilometroAerolineas);
		printf("La diferencia de precio es de: $ %.2f\n\n", diferenciaDePrecio);



	system("pause");

}

