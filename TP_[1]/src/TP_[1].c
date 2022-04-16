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
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"

	int main(void)
	{
		setbuf(stdout, NULL);

		float kilometrosIngresados;
		float precioLatam;
		float precioAerolineas;

		int menu;
		int subMenuPasajes;

		float precioConDebitoLatam;
		float precioConCreditoLatam;
		float precioConDebitoAerolineas;
		float precioConCreditoAerolineas;
		float precioEnBitcoinLatam;
		float precioEnBitcoinAerolineas;
		float precioPorKilometroLatam;
		float precioPorKilometroAerolineas;
		float diferenciaDePrecio;

		int flagCalculos;
		int flagCambioDeParametros;


		kilometrosIngresados = 0;
		precioAerolineas = 0;
		precioLatam = 0;

		flagCambioDeParametros = 0;
		flagCalculos = 0;

		do
		{
			system("cls");
			menu = llamarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
			switch(menu)
			{
				case 1: kilometrosIngresados = pedirNumero("Ingresar kilometros: ", 1 , 99999999);
						flagCambioDeParametros = 1;

				break;

				case 2:	subMenuPasajes = llamarSubMenu();
						if(validarDatos(menu, subMenuPasajes, kilometrosIngresados, precioLatam, precioAerolineas, flagCalculos, flagCambioDeParametros) == 1)
						{
							switch(subMenuPasajes)
							{
								case 1: precioLatam = pedirNumero("Ingresar el precio de latam: ", 0 , 99999999);
								flagCambioDeParametros = 1;
								break;
								case 2: precioAerolineas = pedirNumero("Ingresar el precio de Aerolineas: " , 0 , 99999999);
								flagCambioDeParametros = 1;
								break;
							}
						}
				break;

				case 5:
						printf(GREEN"\nSe cargaron los datos de manera exitosa!\n\n"RESET);
						cargarDatosForzados(); //Carga los datos forzados, calcula y muestra dentro de la funci�n
						precioLatam = 159339;  //Deja cargado los datos en el men�
						precioAerolineas = 162965;  //Deja cargado los datos en el men�
						kilometrosIngresados = 7090; //Deja cargado los datos en el men�
						menu = 3; //pasa al case 3 sin break as� los datos cargados quedan calculados y validados, para que no haya problemas
								  //en caso de querer volver a mostrar los resultados.
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
							printf(GREEN"\nLos calculos se realizaron correctamente!\n\n"RESET);
							system("pause");
						}
				break;

				case 4: if(validarDatos(menu, subMenuPasajes, kilometrosIngresados, precioLatam, precioAerolineas, flagCalculos, flagCambioDeParametros) == 1)
						{
						  mostrarResultados(kilometrosIngresados, precioAerolineas, precioConDebitoAerolineas, precioConCreditoAerolineas, precioEnBitcoinAerolineas, precioPorKilometroAerolineas, precioLatam, precioConDebitoLatam, precioConCreditoLatam, precioEnBitcoinLatam, precioPorKilometroLatam, diferenciaDePrecio);
						  system("pause");
						}
				break;

				case 6: if(funcionSalir() == 0)
						{
							return EXIT_SUCCESS;
						}
				break;

				default: printf(RED"\nLa opcion %d no es valida\n\n"RESET, menu);
				break;
			}

		}while(menu);
	}

