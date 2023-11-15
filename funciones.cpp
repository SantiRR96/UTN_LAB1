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

