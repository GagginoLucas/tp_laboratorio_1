/*
 ============================================================================
 Name        : Trabajo pr�ctico n�mero 1
 Author      : Lucas Javier Gaggino Division 1-F
 Version     :
 Copyright   : Libre
 Consigna    : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
 			   para ofrecerlos a sus clientes.
			   Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
			   El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.

 ============================================================================
 */

#include "calculos_tp1.h"
#include "menu_tp1.h"

	int main(void)
	{
		setbuf(stdout, NULL);

		//Precios de variables inicializados
		float kilometrosIngresados;
		float precioLatam;
		float precioAerolineas;

		int menu;
		int subMenuPasajes;

		//Precios de los calculos
		float precioConDebitoLatam;
		float precioConCreditoLatam;
		float precioConDebitoAerolineas;
		float precioConCreditoAerolineas;
		float precioEnBitcoinLatam;
		float precioEnBitcoinAerolineas;
		float precioPorKilometroLatam;
		float precioPorKilometroAerolineas;
		float diferenciaDePrecio;

		//Banderas para validar
		int flagCalculos;
		int flagCambioDeParametros;


		kilometrosIngresados = 0;
		precioAerolineas = 0;
		precioLatam = 0;

		flagCambioDeParametros = 0;
		flagCalculos = 0;

		do
		{
			menu = llamarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
			switch(menu)
			{
				case 1: kilometrosIngresados = pedirFlotante("Ingresar kilometros: ", "Error, ingrese una cantidad de kilometros valida(): ", 1, 9999999);
						flagCambioDeParametros = 1;
				break;

				case 2:	subMenuPasajes = llamarSubMenu();
						if(validarDatos(menu, subMenuPasajes, kilometrosIngresados, precioLatam, precioAerolineas, flagCalculos, flagCambioDeParametros) == 1)
						{
							switch(subMenuPasajes)
							{
								case 1: precioLatam = pedirFlotante("Ingresar el precio de latam: ", "Error, ingrese un precio valido: ",0, 99999999);
								flagCambioDeParametros = 1;
								break;
								case 2: precioAerolineas = pedirFlotante("Ingresar el precio de Aerolineas: ", "Error, ingrese un precio valido: ",0, 99999999);
								flagCambioDeParametros = 1;
								break;
							}
						}
				break;

				case 5:
						printf("\nSe cargaron los datos de manera exitosa!\n\n");
						cargarDatosForzados();
						precioLatam = 159339;
						precioAerolineas = 162965;
						kilometrosIngresados = 7090;
						menu = 3;
						/* no break */

				case 3:	if(validarDatos(menu, subMenuPasajes, kilometrosIngresados, precioLatam, precioAerolineas, flagCalculos, flagCambioDeParametros) == 1)
						{
							precioConDebitoLatam = realizarCalculo(precioLatam, 1);
							precioConDebitoAerolineas = realizarCalculo(precioAerolineas, 1);
							precioConCreditoLatam = realizarCalculo(precioLatam, 2);
							precioConCreditoAerolineas = realizarCalculo(precioAerolineas, 2);
							precioEnBitcoinLatam = realizarCalculo(precioLatam, 3);
							precioEnBitcoinAerolineas = realizarCalculo(precioAerolineas, 3);
							precioPorKilometroLatam = calcularPrecioUnitario(precioLatam, kilometrosIngresados);
							precioPorKilometroAerolineas = calcularPrecioUnitario(precioAerolineas, kilometrosIngresados);
							diferenciaDePrecio = calcularDiferenciaDePrecio(precioLatam, precioAerolineas);
							flagCalculos = 1;
							flagCambioDeParametros = 0;
							printf("\n\nLos calculos se realizaron correctamente!\n\n");
							system("pause");
						}
				break;

				case 4: if(validarDatos(menu, subMenuPasajes, kilometrosIngresados, precioLatam, precioAerolineas, flagCalculos, flagCambioDeParametros) == 1)
						{
						  mostrarResultados(kilometrosIngresados, precioAerolineas, precioConDebitoAerolineas, precioConCreditoAerolineas, precioEnBitcoinAerolineas, precioPorKilometroAerolineas, precioLatam, precioConDebitoLatam, precioConCreditoLatam, precioEnBitcoinLatam, precioPorKilometroLatam, diferenciaDePrecio);
						}
				break;

				case 6: if(funcionSalir() == 0)
						{
							return EXIT_SUCCESS;
						}
				break;

				default: printf("\nLa opcion %d no es valida\n\n", menu);
				break;
			}

		}while(menu);
	}

