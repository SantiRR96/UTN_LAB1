#include <iostream>
#include "rlutil.h"
#include "funciones.h" 
#include <string> 
#include <cstdlib>



using namespace std;


void ingresarNombres(string &nombre1, string &nombre2) {
	rlutil::locate(49,12);
	cout << "Nombre jugador N° 1: ";
	cin >> nombre1;
	rlutil::locate(49,13);
	cout << "Nombre jugador N° 2: ";
	cin >> nombre2;
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
