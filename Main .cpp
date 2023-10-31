#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
	int op;
	int y = 0;
	string player1, player2;
	char cartasValidas[] = {'1', '0', 'J', 'Q', 'K', 'A'};
	char cartasPlayer1[5];
	char cartasPlayer2[5];
	srand(time(0));
	system("color 3f");
	int ronda = 1; // Comenzar en la ronda 1
	
	// Variable para controlar el turno del jugador
	int turnoJugador = 1;
	
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
		case 1:
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
				// Continuar con las siguientes instrucciones.
				
			} else { 
					rlutil::locate(45, 17);
					cout << "Vuelve a ingresar los nombres." << endl;
				}
				break;
			case 2: cout << "ESTADISTICAS" << endl; break;
			case 3: cout << "CREDITOS" << endl; 
				cout << " ------------------------------------ " << endl;
				cout << "Laboratorio de Computación I - Grupo 64" << endl;
				cout << "Integrantes: " << endl;
				cout << "Legajo 27990 - Rossi, Santiago Rodrigo" << endl;
				cout << "Legajo 27975 - Diaz, Leonardo Sebastián" << endl;	
				
				// Faltaria agregar los numero de legajo y tambien dice "que hay que poner nombre al grupo"
						
				break;
		
			default: break;
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
				case 0: op = 1; break;
				case 4: op = 0; break;
				}
				break;
			default: break;
			}
		} while (op != 0);
		
		return 0;
	}

