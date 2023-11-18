#include <iostream>
#include "rlutil.h"
#include "funciones.h" 
#include <string> 
#include <cstdlib>
#include <ctime>
#include <algorithm> 

using namespace std;


void ingresarNombres(string &nombre1, string &nombre2) {
	rlutil::locate(49,12);
	cout << "Nombre jugador N° 1: ";
	getline(std::cin, nombre1);
	rlutil::locate(49,13);
	cout << "Nombre jugador N° 2: ";
	getline(std::cin, nombre2);
}


bool confirmarNombres(string player1, string player2) {
	rlutil::cls();
	
	rlutil::locate(49,10);
	
	cout << "Nombres ingresados:" << endl;
	rlutil::locate(49,12);
	
	cout << "Jugador 1: " << player1 << endl;
	rlutil::locate(49,13);
	
	cout << "Jugador 2: " << player2 << endl;
	
	char confirm;
	rlutil::locate(47,15);
	
	cout << "¿Confirmar nombres? (S/N): ";
	cin >> confirm; 
	
	return (confirm == 'S' || confirm == 's');
	
}

int tirardados (int limite){
	
	return (rand() % limite)+1;
}
	
	/// Aca hago el mazo de cartas y reparte 
	
void informar_carta(string &valor, string &palo) {
		const int total_cartas = 20;
		static int cartas_restantes = total_cartas;
		static bool numeros_generados[total_cartas] = {false};
		
		if (cartas_restantes == 0) {
			// Todas las cartas han sido generadas, reiniciar para un nuevo mazo
			cartas_restantes = total_cartas;
			fill(begin(numeros_generados), end(numeros_generados), false); 
		}
		
		int carta;
		do {
			carta = rand() % total_cartas;
		} while (numeros_generados[carta]);
		
		numeros_generados[carta] = true;
		cartas_restantes--;
		
		switch (carta) {
			
			
		case 0:
			valor = "10";
			palo = "PICA";
			break;
		case 1:
			valor = "J";
			palo = "PICA";
			break;
		case 2:
			valor = "K";
			palo = "PICA";
			break;
		case 3:
			valor = "Q";
			palo = "PICA";
			break;
		case 4:
			valor = "A";
			palo = "PICA";
			break;
		case 5:
			valor = "10";
			palo = "CORAZON";
			break;
		case 6:
			valor = "J";
			palo = "CORAZON";
			break;
		case 7:
			valor = "K";
			palo = "CORAZON";
			break;
		case 8:
			valor = "Q";
			palo = "CORAZON";
			break;
		case 9:
			valor = "A";
			palo = "CORAZON";
			break;
		case 10:
			valor = "10";
			palo = "TREBOL";
			break;
		case 11:
			valor = "J";
			palo = "TREBOL";
			break;
		case 12:
			valor = "K";
			palo = "TREBOL";
			break;
		case 13:
			valor = "Q";
			palo = "TREBOL";
			break;
		case 14:
			valor = "A";
			palo = "TREBOL";
			break;
		case 15:
			valor = "10";
			palo = "DIAMANTE";
			break;
		case 16:
			valor = "J";
			palo = "DIAMANTE";
			break;
		case 17:
			valor = "K";
			palo = "DIAMANTE";
			break;
		case 18:
			valor = "Q";
			palo = "DIAMANTE";
			break;
		case 19:
			valor = "A";
			palo = "DIAMANTE";
			break;
		default:;
		}
	}
	
void barajar_cartas(string valores[], string palos[], int tam) {
	for (int i = 0; i < tam; i++) {
		int j = rand() % tam;
			
		swap(valores[i], valores[j]);
		swap(palos[i], palos[j]);
	}
}


int obtener_indice_carta(const std::string &valor) {
	if (valor == "10") {
		return 10;
	} else if (valor == "J") {
		return 11;
	} else if (valor == "Q") {
		return 12;
	} else if (valor == "K") {
		return 13;
	} else {
		return 14;
	}
}


bool cartas_en_orden(const string valores[]) {
	const int CARTAS_POR_JUGADOR = 5;
	for (int i = 0; i < CARTAS_POR_JUGADOR - 1; ++i) {
		if (valores[i] > valores[i + 1]) {
			return false; // Las cartas no están en orden
		}
	}
	return true; // Las cartas están en orden
}	

int contar_cartas(const string valores[], const string &carta) {
	int contador = 0;
	const int CARTAS_POR_JUGADOR = 5;
	for (int i = 0; i < CARTAS_POR_JUGADOR; ++i) {
		if (valores[i] == carta) {
			contador++;
		}
	}
	return contador;
}

int comparar_cartas(const string valores_jugador1[], const string valores_jugador2[], const string &carta) {
	int cantidad_jugador1 = contar_cartas(valores_jugador1, carta);
	int cantidad_jugador2 = contar_cartas(valores_jugador2, carta);
	
	if (cantidad_jugador1 > cantidad_jugador2) {
		return 1; // Jugador 1 tiene más cartas de la carta especificada
	} else {
		return -1; // Jugador 2 tiene más cartas de la carta especificada
	} 
}

void mostrar_ronda(int ronda) {
	
	
	cout << "\tRONDA #" << ronda << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

void cambiar_ronda(int &ronda) {
	
	
	ronda ++;
}


void restar_cartas_mazo(std::string valores[], std::string palos[], int tam, const std::string valores_jugador[], const std::string palos_jugador[]) {
	// Creo un nuevo mazo que contenga todas las cartas
	string mazo_valores[tam];
	string mazo_palos[tam];
	int CARTAS_POR_JUGADOR = 5;
	
	for (int i = 0; i < tam; i++) {
		mazo_valores[i] = valores[i];
		mazo_palos[i] = palos[i];
	}
	
	// Remover las cartas que se han dado a los jugadores del nuevo mazo
	for (int i = 0; i < CARTAS_POR_JUGADOR; i++) {
		// Encontrar la posición de la carta en el nuevo mazo
		auto it = std::find(mazo_valores, mazo_valores + tam, valores_jugador[i]);
		
		// Eliminar la carta del nuevo mazo
		if (it != mazo_valores + tam) {
			int index = std::distance(mazo_valores, it);
			mazo_valores[index] = "";
			mazo_palos[index] = "";
		}
	}
	
	// Actualizar el mazo original con las cartas restantes
	int indice = 0;
	for (int i = 0; i < tam; i++) {
		if (mazo_valores[i] != "") {
			valores[indice] = mazo_valores[i];
			palos[indice] = mazo_palos[i];
			indice++;
		}
	}
}



//Acciones del dado

void accion_dado(int dado, int turnoJugador, std::string valores[], std::string palos[], std::string valores_jugador1[], std::string valores_jugador2[], std::string palos_jugador1[], std::string palos_jugador2[]) {
	int carta_propia, carta_contrario, carta_propia2, opcion;
	std::string valores_propios;
	std::string valores_contrario;
	const int tam_mazo = 20;
	
	if (turnoJugador == 1){
		switch (dado) {
		case 1:
			
			restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
			restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
			cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << endl << endl;
			cin >> carta_propia;
			
			if(turnoJugador == 1){
			swap(valores_jugador1[carta_propia - 1], valores[carta_propia - 1]);
			swap(palos_jugador1[carta_propia - 1], palos[carta_propia - 1]);
			}
//			AV = valores_jugador1[A + 1];
//			AP = palos_jugador1[A + 1];
//			valores_jugador1[A + 1] = valores[0];
//			palos_jugador1[A + 1] = palos[0];
//			valores[0] = AV;
//			palos[0] = AP;
			break;
			
			
			case 2: {
				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
				restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
				std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
				std::cin >> carta_contrario;
				
				if(turnoJugador == 1){
				swap(valores_jugador2[carta_contrario - 1], valores[carta_contrario - 1]);
				swap(palos_jugador2[carta_contrario - 1], palos[carta_contrario - 1]);
				}
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
				if(turnoJugador == 1){
					swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
					swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
				}
				else{
					swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
					swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
				}
			
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
				// Validar la entrada del usuario
				swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
				swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
				
				break;
			}
			case 5: {
				cout << "A continuacion elige una carta de tu corral" << endl;
				cin >> carta_propia;
				cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
				break;
			}
			case 6: {
				cout << "Puedes elegir cualquier accion anterior o pasar turno con el 6" << endl;
				cin >> opcion;
				switch (opcion) {
				case 1:
					cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << endl << endl;
					cin >> carta_propia;
					
					if(turnoJugador == 1){
						swap(valores_jugador1[carta_propia - 1], valores[1]);
						swap(palos_jugador1[carta_propia - 1], palos[1]);
					}
					//			AV = valores_jugador1[A + 1];
					//			AP = palos_jugador1[A + 1];
					//			valores_jugador1[A + 1] = valores[0];
					//			palos_jugador1[A + 1] = palos[0];
					//			valores[0] = AV;
					//			palos[0] = AP;
					break;
					
					
				case 2: {
					std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
					std::cin >> carta_contrario;
					
					if(turnoJugador == 1){
						swap(valores_jugador2[carta_contrario - 1], valores[1]);
						swap(palos_jugador2[carta_contrario - 1], palos[1]);
					}
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
						if(turnoJugador == 1){
							swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
							swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
						}
						else{
							swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
							swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
						}
						
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
					// Validar la entrada del usuario
					swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
					swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
					
					break;
				}
				case 5: {
					cout << "A continuacion elige una carta de tu corral" << endl;
					cin >> carta_propia;
					cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
					break;
				}
				
				case 6:
					// Salir del bucle si elige pasar turno
					std::cout << "Pasando turno..." << std::endl;
					break;
					break;
				}
			}
		}
	}
	else{
		switch (dado) {
		case 1: {
			restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
			restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
			std::cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << std::endl;
			std::cin >> carta_propia;
			
			if(turnoJugador == 2){
			swap(valores_jugador2[carta_propia - 1], valores[carta_propia - 1]);
			swap(palos_jugador2[carta_propia - 1], palos[carta_propia - 1]);
			}
//			std::string AV = valores_jugador2[A];
//			std::string AP = palos_jugador2[A];
//			valores_jugador2[A] = valores[1];
//			palos_jugador2[A] = palos[1];
//			valores[1] = AV;
//			palos[1] = AP;
		break;
		}
		case 2: {
			restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador1, palos_jugador1);
			restar_cartas_mazo(valores, palos, tam_mazo, valores_jugador2, palos_jugador2);
			std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
			std::cin >> carta_contrario;
			
			if(turnoJugador == 2){
			swap(valores_jugador1[carta_contrario - 1], valores[carta_propia - 1]);
			swap(palos_jugador1[carta_contrario - 1], palos[carta_propia - 1]);
			}
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
			if(turnoJugador == 2){
				swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
				swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
			}
			else{
				swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
				swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
			}
			
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
			// Validar la entrada del usuario
			swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
			swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
		}
		break;
		
		case 5:
			cout << "A continuacion elige una carta de tu corral" << endl;
			cin >> carta_propia;
			cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
		break;
			
		case 6:
			cout << "Puedes elegir cualquier accion anterior o pasar turno con el 6" << endl;
			cin >> opcion;
			switch (opcion) {
			case 1: {
				std::cout << "A continuacion elige una carta de tu propio corral (1-5), esta carta se intercambiara con una del mazo." << std::endl;
				std::cin >> carta_propia;
				
				if(turnoJugador == 2){
					swap(valores_jugador2[carta_propia - 1], valores[1]);
					swap(palos_jugador2[carta_propia - 1], palos[1]);
				}
				//			std::string AV = valores_jugador2[A];
				//			std::string AP = palos_jugador2[A];
				//			valores_jugador2[A] = valores[1];
				//			palos_jugador2[A] = palos[1];
				//			valores[1] = AV;
				//			palos[1] = AP;
				break;
			}
			case 2: {
				std::cout << "A continuacion elige una carta del corral contrario (1-5), esta carta se intercambiara con una del mazo." << std::endl;
				std::cin >> carta_contrario;
				
				if(turnoJugador == 2){
					swap(valores_jugador1[carta_contrario - 1], valores[1]);
					swap(palos_jugador1[carta_contrario - 1], palos[1]);
				}
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
				if(turnoJugador == 2){
					swap(valores_jugador2[carta_propia - 1], valores_jugador1[carta_contrario - 1]);
					swap(palos_jugador2[carta_propia - 1], palos_jugador1[carta_contrario - 1]);
				}
				else{
					swap(valores_jugador1[carta_propia - 1], valores_jugador2[carta_contrario - 1]);
					swap(palos_jugador1[carta_propia - 1], palos_jugador2[carta_contrario - 1]);
				}
				
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
				// Validar la entrada del usuario
				swap(valores_jugador1[carta_propia - 1], valores_jugador1[carta_propia2 - 1]);
				swap(palos_jugador1[carta_propia - 1], palos_jugador1[carta_propia2 - 1]);	
			}
			break;
			
			case 5: {
				cout << "A continuacion elige una carta de tu corral" << endl;
				cin >> carta_propia;
				cout << "Esta carta estara BLOQUEADA y no puede ser elegida por el contrario para intercambiar pero si por ti mismo" << endl;
				break;
			}
			
			case 6:
				// Salir del bucle si elige pasar turno
				std::cout << "Pasando turno..." << std::endl;
				break;
				
			}
		}
	}

}
