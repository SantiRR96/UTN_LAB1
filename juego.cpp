#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;

// Opcion 1 = JUGAR
void juego(){
	
	
	
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
	
	int turnoJugador; // Variable para controlar el turno del jugador
	
	bool jugador1Comienza = false; // Declaradas aca para que sean visibles en todo el ámbito del switch
	
	bool jugador2Comienza = false;
	
	srand(time(0));
	system("color 3f");
	
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
		string palo;
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
	
	mostrar_ronda(ronda);

	
	do {
		for (const string &carta : cartas_a_comparar) {
			int resultado = comparar_cartas(valores_jugador1, valores_jugador2, carta);
			cout <<endl<<endl<<endl;
			if (resultado == 1) {
				rlutil::locate(50, 23);
				cout << " TURNO DE :" << player1 << endl<< endl;
				jugador1Comienza = true;
				turnoJugador = 1;
				break;
			} else if (resultado == -1) {
				rlutil::locate(50, 23); 
				cout <<" TURNO DE :"  << player2 << endl;
				jugador2Comienza = true;
				turnoJugador = 2;
				break;
			}
		}
		
		
		rlutil::locate(48, 3);
		cout  << player1 << endl<< endl;
		cout<< "------------------------------------------------------------------------------------------------------------------------";
		for (int i = 0; i < CARTAS_POR_JUGADOR; i++) {
			cout << setw(50)  << valores_jugador1[i] << " "  << palos_jugador1[i] << endl;
			
		}
		cout << endl << endl << endl;
		cout<< "------------------------------------------------------------------------------------------------------------------------";
		rlutil::locate(48, 15);
		cout <<  player2 << endl<< endl;
		
		for (int i = 0; i < CARTAS_POR_JUGADOR; i++) {
			cout << setw(50) << valores_jugador2[i] << " " << palos_jugador2[i] << endl;
		}
		
		if (jugador1Comienza || jugador2Comienza) {
			const int tam = 6;
			int dado = tirardados(tam);
			rlutil::locate(48,25);
			cout << "LANZAMIENTO DE DADO #" << dado << endl;
			cambiar_ronda(ronda);
			accion_dado(dado, turnoJugador, valores, palos, valores_jugador1, valores_jugador2, palos_jugador1, palos_jugador2);
			cout << endl;
		}
		
		
		cout<< "------------------------------------------------------------------------------------------------------------------------";
		
		rlutil::locate(48,27);
		
		cout << "presione enter para tirar dados" << endl;
		
		cin.ignore();
		cin.get();
		rlutil::cls();
		
		if (!cartas_en_orden(valores_jugador1) || !cartas_en_orden(valores_jugador2)) {
			
			mostrar_ronda(ronda);
			cout << endl;
		}
		
		
	} while (!cartas_en_orden(valores_jugador1) || !cartas_en_orden(valores_jugador2));
}	
//}

// Opcion 3 - CREDITOS	
void creditos(){
	
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
	rlutil::locate(50, 15);
	cout << "Legajo 27982 - Aguirregabiria, Martin Alejandro" << endl;
}
