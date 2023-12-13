#include <iostream>
#include "rlutil.h"
#include "funciones.h" 
#include <string> 
#include <cstdlib>
#include <ctime>
#include <algorithm> 

using namespace std;

int tirardados (int limite){
	return 1;
	//return (rand() % limite) + 1;
}
	
//Acciones del dado
	
	void accion_dado(int dado, int turnoJugador, std::string mazo[5][4], std::string jugador1[], std::string jugador2[]) {
		int carta_propia, carta_contrario, carta_propia2, opcion;
		std::string valores_propios;
		std::string valores_contrario;
		//const int tam_mazo = 20;
		
		if (turnoJugador == 1){
			switch (dado) {
			case 1:
				
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
				cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << endl << endl;
				cin >> carta_propia;
				
				if(turnoJugador == 1){
					swap(jugador1[carta_propia - 1], mazo[carta_propia - 1][2]);
					//swap(palos_jugador1[carta_propia - 1], palos[posicion_mazo]);
				}
				//			AV = valores_jugador1[A + 1];
				//			AP = palos_jugador1[A + 1];
				//			valores_jugador1[A + 1] = valores[0];
				//			palos_jugador1[A + 1] = palos[0];
				//			valores[0] = AV;
				//			palos[0] = AP;
				break;
				
				
			case 2: {
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
				std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
				std::cin >> carta_contrario;
				
//				if(turnoJugador == 1){
//					swap(valores_jugador2[carta_contrario - 1], valores[carta_contrario - 1]);
//					swap(palos_jugador2[carta_contrario - 1], palos[carta_contrario - 1]);
//				}
				//				AV = valores_jugador2[A + 1];
				//				AP = palos_jugador2[A + 1];
				//				valores_jugador2[A] = valores[1];
				//				palos_jugador2[A] = palos[1];
				//				valores[1] = AV;
				//				palos[1] = AP;
				break;
			}
			case 3: {
				cout << "Elegir una carta propia e intercambiarla con una del corral contrario" << endl;
				{
					std::cout << "Elige una carta de tu propio corral (1-5): ";
					std::cin >> carta_propia;
					
					std::cout << "Elige una carta del corral contrario (1-5): ";
					std::cin >> carta_contrario;
					
					// Intercambiar las cartas
//					if(turnoJugador == 1){
//						swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
//						swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
//					}
//					else{
//						swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
//						swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
//					}
					
				}
				break;
			}
			case 4: {
				cout << "A continuacion elige una carta de tu propio corral (1-5), acto seguido elige otra carta de tu propio corral (1-5) y estas se intercambiaran." << endl;
				cout << "Ingrese la primer carta: ";
				cin >> carta_propia;
				cout << endl;
				cout << "Ingrese la segunda carta: ";
				cin >> carta_propia2;
				cout << endl;
//				// Validar la entrada del usuario
//				swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
//				swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
				
				break;
			}
			case 5: {
				cout << "A continuacion elige una carta de tu corral" << endl;
				cin >> carta_propia;
				cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
				break;
			}
			case 6: {
				cout << "Puedes elegir cualquier accion anterior o pasar turno con el 0" << endl;
				cin >> opcion;
//				switch (opcion) {
//				case 1:
//					cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << endl << endl;
//					cin >> carta_propia;
//					
//					if(turnoJugador == 1){
//						swap(valores_jugador1[carta_propia - 1], valores[1]);
//						swap(palos_jugador1[carta_propia - 1], palos[1]);
//					}
//					//			AV = valores_jugador1[A + 1];
//					//			AP = palos_jugador1[A + 1];
//					//			valores_jugador1[A + 1] = valores[0];
//					//			palos_jugador1[A + 1] = palos[0];
//					//			valores[0] = AV;
//					//			palos[0] = AP;
//					break;
//					
//					
//				case 2: {
//					std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
//					std::cin >> carta_contrario;
//					
//					if(turnoJugador == 1){
//						swap(valores_jugador2[carta_contrario - 1], valores[1]);
//						swap(palos_jugador2[carta_contrario - 1], palos[1]);
//					}
//					//				AV = valores_jugador2[A + 1];
//					//				AP = palos_jugador2[A + 1];
//					//				valores_jugador2[A] = valores[1];
//					//				palos_jugador2[A] = palos[1];
//					//				valores[1] = AV;
//					//				palos[1] = AP;
//					break;
//				}
//				case 3: {
//					cout << "Elegir una carta propia e intercambiarla con una del corral contrario" << endl;
//					{
//						std::cout << "Elige una carta de tu propio corral (1-5): ";
//						std::cin >> carta_propia;
//						
//						std::cout << "Elige una carta del corral contrario (1-5): ";
//						std::cin >> carta_contrario;
//						
//						// Intercambiar las cartas
//						if(turnoJugador == 1){
//							swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
//							swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
//						}
//						else{
//							swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
//							swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
//						}
//						
//					}
//					break;
//				}
//				case 4: {
//					cout << "A continuacion elige una carta de tu propio corral (1-5), acto seguido elige otra carta de tu propio corral (1-5) y estas se intercambiaran." << endl;
//					cout << "Ingrese la primer carta: ";
//					cin >> carta_propia;
//					cout << endl;
//					cout << "Ingrese la segunda carta: ";
//					cin >> carta_propia2;
//					cout << endl;
//					// Validar la entrada del usuario
//					swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
//					swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
//					
//					break;
//				}
//				case 5: {
//					cout << "A continuacion elige una carta de tu corral" << endl;
//					cin >> carta_propia;
//					cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
//					break;
//				}
//				
//				case 0:
//					// Salir del bucle si elige pasar turno
//					std::cout << "Pasando turno..." << std::endl;
//					break;
//					break;
//					}
				}
			}
		}
		else{
			switch (dado) {
			case 1: {
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
				std::cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << std::endl;
				std::cin >> carta_propia;
				
//				if(turnoJugador == 2){
//					swap(valores_jugador2[carta_propia - 1], valores[carta_propia - 1]);
//					swap(palos_jugador2[carta_propia - 1], palos[carta_propia - 1]);
//				}
				//			std::string AV = valores_jugador2[A];
				//			std::string AP = palos_jugador2[A];
				//			valores_jugador2[A] = valores[1];
				//			palos_jugador2[A] = palos[1];
				//			valores[1] = AV;
				//			palos[1] = AP;
				break;
			}
			case 2: {
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
				//				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
				std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
				std::cin >> carta_contrario;
				
//				if(turnoJugador == 2){
//					swap(valores_jugador1[carta_contrario - 1], valores[carta_propia - 1]);
//					swap(palos_jugador1[carta_contrario - 1], palos[carta_propia - 1]);
//				}
				//			AV = valores_jugador1[A];
				//			AP = palos_jugador1[A];
				//			valores_jugador1[A] = valores[1];
				//			palos_jugador1[A] = palos[1];
				//			valores[1] = AV;
				//			palos[1] = AP;
				break;
			}
			
			case 3:
			{
				// Elegir una carta propia e intercambiarla con una del corral contrario
				{
				int carta_propia, carta_contrario;
				std::cout << "Elige una carta de tu propio corral (1-5): ";
				std::cin >> carta_propia;
				
				std::cout << "Elige una carta del corral contrario (1-5): ";
				std::cin >> carta_contrario;
				
				// Intercambiar las cartas
//				if(turnoJugador == 2){
//					swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
//					swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
//				}
//				else{
//					swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
//					swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
//				}
				
			}
			break;
			}
			
			case 4: {
				cout << "A continuacion elige una carta de tu propio corral (1-5), acto seguido elige otra carta de tu propio corral (1-5) y estas se intercambiaran." << endl;
				cout << "Ingrese la primer carta: ";
				cin >> carta_propia;
				cout << endl;
				cout << "Ingrese la segunda carta: ";
				cin >> carta_propia2;
				cout << endl;
//				// Validar la entrada del usuario
//				swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
//				swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
			}
			break;
			
			case 5:
				cout << "A continuacion elige una carta de tu corral" << endl;
				cin >> carta_propia;
				cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
				break;
				
			case 6:
				cout << "Puedes elegir cualquier accion anterior o pasar turno con el 0" << endl;
				cin >> opcion;
//				switch (opcion) {
//				case 1: {
//					std::cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << std::endl;
//					std::cin >> carta_propia;
//					
//					if(turnoJugador == 2){
//						swap(valores_jugador2[carta_propia - 1], valores[1]);
//						swap(palos_jugador2[carta_propia - 1], palos[1]);
//					}
//					//			std::string AV = valores_jugador2[A];
//					//			std::string AP = palos_jugador2[A];
//					//			valores_jugador2[A] = valores[1];
//					//			palos_jugador2[A] = palos[1];
//					//			valores[1] = AV;
//					//			palos[1] = AP;
//					break;
//				}
//				case 2: {
//					std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
//					std::cin >> carta_contrario;
//					
//					if(turnoJugador == 2){
//						swap(valores_jugador1[carta_contrario - 1], valores[1]);
//						swap(palos_jugador1[carta_contrario - 1], palos[1]);
//					}
//					//			AV = valores_jugador1[A];
//					//			AP = palos_jugador1[A];
//					//			valores_jugador1[A] = valores[1];
//					//			palos_jugador1[A] = palos[1];
//					//			valores[1] = AV;
//					//			palos[1] = AP;
//					break;
//				}
//				
//				case 3:
//				{
//					// Elegir una carta propia e intercambiarla con una del corral contrario
//					{
//					int carta_propia, carta_contrario;
//					std::cout << "Elige una carta de tu propio corral (1-5): ";
//					std::cin >> carta_propia;
//					
//					std::cout << "Elige una carta del corral contrario (1-5): ";
//					std::cin >> carta_contrario;
//					
//					// Intercambiar las cartas
//					if(turnoJugador == 2){
//						swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
//						swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
//					}
//					else{
//						swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
//						swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
//					}
					
//				}
//				break;
//				}
//				
//				case 4: {
//					cout << "A continuacion elige una carta de tu propio corral (1-5), acto seguido elige otra carta de tu propio corral (1-5) y estas se intercambiaran." << endl;
//					cout << "Ingrese la primer carta: ";
//					cin >> carta_propia;
//					cout << endl;
//					cout << "Ingrese la segunda carta: ";
//					cin >> carta_propia2;
//					cout << endl;
//					// Validar la entrada del usuario
//					swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
//					swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
//				}
//				break;
//				
//				case 5: {
//					cout << "A continuacion elige una carta de tu corral" << endl;
//					cin >> carta_propia;
//					cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
//					break;
//				}
//				
//				case 0:
//					// Salir del bucle si elige pasar turno
//					std::cout << "Pasando turno..." << std::endl;
//					break;
//					
//				}
				
			}
		}
		
	}
	
