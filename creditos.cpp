#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Opcion 3 - CREDITOS	
void creditos(){
	
	rlutil::cls();
	rlutil::locate(45, 8);
	cout << "CREDITOS" << endl; 
	rlutil::locate(45, 9);
	cout << " ------------------------------------ " << endl;
	rlutil::locate(45, 10);
	cout << "Laboratorio de Computación I - Grupo 64" << endl;
	rlutil::locate(45, 11);
	cout << "Integrantes: " << endl;
	rlutil::locate(45, 13);
	cout << "Legajo 27990 - Rossi, Santiago Rodrigo" << endl;
	rlutil::locate(45, 14);
	cout << "Legajo 27975 - Diaz, Leonardo Sebastián" << endl;
	rlutil::locate(45, 15);
	cout << "Legajo 27982 - Aguirregabiria, Martin Alejandro" << endl;
}
