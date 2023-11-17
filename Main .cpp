#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
	
	int op = 0;
	
	int y = 0;
	
	string player1, player2;
	
	const int tam_mazo = 20;
	
	const int CARTAS_POR_JUGADOR = 5;
	
	const string cartas_a_comparar[] = {"A", "K", "Q", "J", "10"};
	
	string valores[tam_mazo], palos[tam_mazo];
	// Vectores para almacenar las cartas de cada jugador
	string valores_jugador1[CARTAS_POR_JUGADOR];
	
	string palos_jugador1[CARTAS_POR_JUGADOR];
	
	string valores_jugador2[CARTAS_POR_JUGADOR];
	
	string palos_jugador2[CARTAS_POR_JUGADOR];
	
	//char cartasPlayer1[5], cartasPlayer2[5];
	
	int ronda = 1; // Comenzar en la ronda 1
	
	int turnoJugador = 0; // Variable para controlar el turno del jugador
	
	bool jugador1Comienza = false; // Declaradas aca para que sean visibles en todo el ámbito del switch
	
	bool jugador2Comienza = false;
	
	srand(time(0));
	system("color 3f");
	
	do {
		rlutil::hidecursor();
		rlutil::cls();
		
		rlutil::locate(50, 10);
		cout << "\tCLUTCH" << endl;
		rlutil::locate(50, 11);
		cout << "---------------------" << endl;
		rlutil::locate(50, 12);
		cout << "1- JUGAR" << endl;
		rlutil::locate(50, 13);
		cout << "2- ESTADISTICAS" << endl;
		rlutil::locate(50, 14);
		cout << "3- CREDITOS " << endl;
		rlutil::locate(50, 15);
		cout << "---------------------" << endl;
		rlutil::locate(50, 16);
		cout << "0- SALIR " << endl;
		rlutil::locate(48, 12 + y);
		cout << (char)175 << endl;
		
		switch (op) {
		case 1: {
			
			setlocale(LC_ALL, "spanish");
			
			rlutil::cls();
			rlutil::locate(50, 8);
			cout << "CLUTCH" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			rlutil::locate(40, 10);
			cout << "Antes de comenzar deben registrar sus nombres:" << endl;
			ingresarNombres(player1, player2);
			if (confirmarNombres(player1, player2)) {
				rlutil::locate(50, 18);
				cout << "Nombres confirmados." << endl;
			} else {
				rlutil::locate(45, 17);
				cout << "Vuelve a ingresar los nombres." << endl << endl;
			}
			
			//while(true){
			
			// Llenar los vectores con cartas aleatorias para ambos jugadores
			for (int i = 0; i < CARTAS_POR_JUGADOR; i++) {
				char palo;
				string valor;
				
				// Cartas para el jugador 1
				informar_carta(valor, palo);
				valores_jugador1[i] = valor;
				palos_jugador1[i] = palo;
				
				// Cartas para el jugador 2
				informar_carta(valor, palo);
				valores_jugador2[i] = valor;
				palos_jugador2[i] = palo;
			}
			
			// Verificar si las cartas están en orden y barajar nuevamente si es necesario
			if (cartas_en_orden(valores_jugador1)) {
				cout << "Las cartas del Jugador 1 salieron ordenadas. Barajar nuevamente...\n";
				barajar_cartas(valores_jugador1, palos_jugador1, CARTAS_POR_JUGADOR);
			}
			
			if (cartas_en_orden(valores_jugador2)) {
				cout << "Las cartas del Jugador 2 salieron ordenadas. Barajar nuevamente...\n";
				barajar_cartas(valores_jugador2, palos_jugador2, CARTAS_POR_JUGADOR);
			}
			
		rlutil::cls();
			
			
			// Mostrar las cartas repartidas a ambos jugadores
			rlutil::locate(50, 3);
			cout  << player1 << endl<< endl;
			cout<< "------------------------------------------------------------------------------------------------------------------------";
			for (int i = 0; i < CARTAS_POR_JUGADOR; i++) {
				cout << setw(50)  << valores_jugador1[i] << " "  << palos_jugador1[i] << endl;
				
			}
			cout <<endl<<endl<<endl;
			cout<< "------------------------------------------------------------------------------------------------------------------------";
			cout << "\t\t\t\t\t\t\t"<< player2 << endl<< endl;
			
			for (int i = 0; i < CARTAS_POR_JUGADOR; i++) {
				cout << setw(50) << valores_jugador2[i] << " " << palos_jugador2[i] << endl;
			}
			
		cout<< "------------------------------------------------------------------------------------------------------------------------";
		
			// Determinar qué jugador comienza primero
			for (const string &carta : cartas_a_comparar) {
				int resultado = comparar_cartas(valores_jugador1, valores_jugador2, carta);
				cout <<endl<<endl<<endl;
				if (resultado == 1) {
					cout << " \t\t\t\t\tTURNO DE :" << player1 << endl<< endl;
					jugador1Comienza = true;
				/*	turnoJugador=1;*/
					break;
				} else if (resultado == -1) {
					cout <<" \t\t\t\t\tTURNO DE :"  << player2 << endl<< endl;
					jugador2Comienza = true;
					/*turnoJugador=2;*/
					break;
				}
			}
		}
		if (jugador1Comienza || jugador2Comienza) {
			const int tam = 6;
			int dado = tirardados(tam);
			cout << "\t\t\t\t\tLANZAMIENTO DE DADO #" << dado << endl;
		}
		break;
		
		case 2: {
			cout << "ESTADISTICAS" << endl;
			break;
		}
		
		case 3: {
			rlutil::cls();
			rlutil::locate(50, 8);
			cout << "CREDITOS" << endl;
			rlutil::locate(50, 9);
			cout << " ------------------------------------ " << endl;
			rlutil::locate(50, 10);
			cout << "Laboratorio de Computación I - Grupo 64" << endl;
			rlutil::locate(50, 11);
			cout << "Integrantes: " << endl;
			rlutil::locate(50, 13);
			cout << "Legajo 27990 - Rossi, Santiago Rodrigo" << endl;
			rlutil::locate(50, 14);
			cout << "Legajo 27975 - Diaz, Leonardo Sebastián" << endl;
			
			break;
		}
		
		default: {
			break;
		}
		}
		
		int key = rlutil::getkey();
		
		switch (key) {
		case 14: // Arriba
			rlutil::locate(48, 12 + y);
			cout << " " << endl;
			y--;
			if (y < 0) { y = 0; }
			break;
		case 15: // Abajo
			rlutil::locate(48, 12 + y);
			cout << " " << endl;
			y++;
			if (y > 4) { y = 4; }
			break;
		case 1: // Enter
			switch (y) {
			case 0:
				op = 1;
				break;
			case 2:
				op = 3;
				break;
			case 4:
				op = 0;
				break;
			}
			break;
		default:
			break;
		}
	} while (op != 0);
	
	return 0;
}

			
