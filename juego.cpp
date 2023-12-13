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
	
		srand(time(0));
		
		string valores[] = {"10", "J", "Q", "K", "A"};
		string palos[] = {"Corazon", "Pica", "Diamante", "Trebol"};
		string mazo[5][4];
		string jugador1[5], jugador2[5];
		string player1, player2;
		int ronda = 1;
		int turnoJugador;
		
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
		// Funciones para crear el mazo, barajarlo y luego repartir a los dos jugadores
		inicializarMazo(mazo, valores, palos);
		barajarMazo(mazo);
		repartirCartas(mazo, jugador1, jugador2);
		
		if (cartas_en_orden(jugador1, 5) || cartas_en_orden(jugador2, 5)) {
			cout << "¡Las cartas de un jugador salieron ordenadas! Volviendo a repartir..." << endl << endl;
			barajarMazo(mazo);
			repartirCartas(mazo, jugador1, jugador2);
		}
		
		do{
			rlutil::cls();
			barajarMazo(mazo);
			//Funcion de ronda de la partida
			mostrar_ronda(ronda);
			
			// Establecer el turno del jugador al comienzo de cada ronda
			if (ronda % 2 == 1) {
				turnoJugador = 1;
				rlutil::locate(50, 23); 
				cout <<" TURNO DE :"  << player1 << endl;
			} else {
				turnoJugador = 2;
				rlutil::locate(50, 23); 
				cout <<" TURNO DE :"  << player2 << endl;
			}
			// Funciones que muestran las cartas de los jugadores
			mostrarCartasJ1(jugador1, player1, 5);
			cout << endl << endl << endl;
			cout<< "------------------------------------------------------------------------------------------------------------------------";
			mostrarCartasJ2(jugador2, player2, 5);
			
			//Indica el dado que sale y muestra la accion del mismo, luego pasa al siguiente turno.
			if (turnoJugador == 1 || turnoJugador == 2) {
				const int tam = 6;
				int dado = tirardados(tam);
				rlutil::locate(48,25);
				cout << "LANZAMIENTO DE DADO #" << dado << endl;
				cout << endl;
				cambiar_ronda(ronda);
				accion_dado(dado, turnoJugador, mazo, jugador1, jugador2);
			}
			
			
			cout<< "------------------------------------------------------------------------------------------------------------------------" << endl;
			
			rlutil::locate(48,27);
			
			cout << " Presione enter para tirar dados " << endl;
			
			cin.ignore();
			cin.get();
			rlutil::cls();
			
		} while(cartas_en_orden(jugador1, 5) != true || cartas_en_orden(jugador2, 5) != true); 
		
		
				
}
