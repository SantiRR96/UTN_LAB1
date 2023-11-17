#include <iostream>
#include "rlutil.h"
#include "funciones.h" 
#include <string> 
#include <cstdlib>



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
			palo = "CORAZONES";
			break;
		case 6:
			valor = "J";
			palo = "CORAZONES";
			break;
		case 7:
			valor = "K";
			palo = "CORAZONES";
			break;
		case 8:
			valor = "Q";
			palo = "CORAZONES";
			break;
		case 9:
			valor = "A";
			palo = "CORAZONES";
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
	} else if (cantidad_jugador1 < cantidad_jugador2) {
		return -1; // Jugador 2 tiene más cartas de la carta especificada
	} else {
		return 0; // Ambos jugadores tienen la misma cantidad de cartas de la carta especificada
	}
}

void dados_accion(int resultado_dado, std::string valores_propios[], std::string valores_contrario[], std::string mazo[]){
	switch (resultado_dado) {
	case 1:
		// Elegir una carta propia y robar del mazo
		// Intercambiar las dos cartas
		// La carta robada se incorpora al corral propio y la seleccionada al mazo
	{
		int carta_propia;
		std::cout << "Elige una carta de tu propio corral (1-5): ";
		std::cin >> carta_propia;
		
		// Intercambiar las cartas
		std::swap(valores_propios[carta_propia - 1], mazo[0]);
	}
	break;
	case 2:
		// Elegir una carta del corral contrario y robar del mazo
		// Intercambiar las dos cartas
		// La carta robada se incorpora al corral contrario y la seleccionada al mazo
	{
		int carta_contrario;
		std::cout << "Elige una carta del corral contrario (1-5): ";
		std::cin >> carta_contrario;
	
		// Intercambiar las cartas
		std::swap(valores_contrario[carta_contrario - 1], mazo[0]);
	}
	break;
	case 3:
		// Elegir una carta propia e intercambiarla con una del corral contrario
	{
		int carta_propia, carta_contrario;
		std::cout << "Elige una carta de tu propio corral (1-5): ";
		std::cin >> carta_propia;
		
		// Validar la entrada del usuario
		if (carta_propia < 1 || carta_propia > 5) {
			std::cout << "Entrada inválida. Debes elegir un número entre 1 y 5." << std::endl;
			return;
		}
		
		std::cout << "Elige una carta del corral contrario (1-5): ";
		std::cin >> carta_contrario;
		
		// Validar la entrada del usuario
		if (carta_contrario < 1 || carta_contrario > 5) {
			std::cout << "Entrada inválida. Debes elegir un número entre 1 y 5." << std::endl;
			return;
		}
		
		// Intercambiar las cartas
		std::swap(valores_propios[carta_propia - 1], valores_contrario[carta_contrario - 1]);
	}
	break;
	case 4:
		// Intercambiar dos cartas propias
		break;
	case 5:
		std::cout << "Acción 5: Bloquear una carta del corral.\n";
		// Lógica para la acción 5
		// ...
		break;
		
	case 6:
		int opcion;
		std::cout << "Acción 6: Elegir cualquiera de las acciones anteriores o bien pasar el turno.\n";
		std::cout << "Selecciona la acción (1-6, 0 para pasar el turno): ";
		std::cin >> opcion;
		
		switch (opcion) {
		case 1:
			// Lógica para la acción 1
			// ...
			break;
		case 2:
			// Lógica para la acción 2
			// ...
			break;
		case 3:
			// Lógica para la acción 3
			// ...
			break;
		case 4:
			// Lógica para la acción 4
			// ...
			break;
		case 5:
			// Lógica para la acción 5
			// ...
			break;
		default:
			std::cout << "Turno pasado.\n";
			break;
		}
		
		break;
		
	default:
		std::cout << "Resultado del dado inválido.\n";
		break;
	}
}
