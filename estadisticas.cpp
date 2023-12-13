#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

//Opcion 2 - Estadisticas

void estadisticas(){
	
	int puntos_partida = 0, puntos_robo = 0, puntos_Malubicadas = 0, puntos_Sinturno = 0, puntos_Sinrobo = 0;
	
	rlutil::cls();
	rlutil::locate(45, 8);
	cout << "ESTADISTICAS" << endl; 
	rlutil::locate(45, 9);
	cout << "---------------------------------------------------------------------- " << endl;
	rlutil::locate(45, 10);
	cout << "DETALLE" << endl;
	rlutil::locate(100, 10);
	cout << "PUNTOS" << endl; 
	rlutil::locate(45, 11);
	cout << "---------------------------------------------------------------------- " << endl;
	rlutil::locate(45, 12);
	cout << "Ganar la partida" << endl;
	rlutil::locate(100, 12);
	cout << puntos_partida << "puntos." << endl;
	rlutil::locate(45, 13);
	cout << "Robo última carta al jugador rival" << endl;
	rlutil::locate(100, 13);
	cout << puntos_robo << "puntos." << endl;
	rlutil::locate(45, 14);
	cout << "Cartas mal ubicadas del rival x 4" << endl;
	rlutil::locate(100, 14);
	cout << puntos_Malubicadas << "puntos." << endl;
	rlutil::locate(45, 15);
	cout << "Sin pasar de turno" << endl;
	rlutil::locate(100, 15);
	cout << puntos_Sinturno << "puntos." << endl;
	rlutil::locate(45, 16);
	cout << "Sin haber sufrido un robo del rival " << endl;
	rlutil::locate(100, 16);
	cout << puntos_Sinrobo << "puntos." << endl;
	rlutil::locate(45, 17);
	cout << "---------------------------------------------------------------------- " << endl;
	rlutil::locate(45, 18);
	cout << "TOTAL" << endl;
	
}
