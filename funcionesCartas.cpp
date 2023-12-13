#include <iostream>
#include <algorithm>
#include <ctime>
#include "funciones.h"
#include "rlutil.h"

using namespace std;


void inicializarMazo(string mazo[5][4], const string valores[], const string palos[]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			mazo[i][j] = valores[i] + " " + palos[j];
		}
	}
}

void barajarMazo(string mazo[5][4]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			int random_i = rand() % 5;
			int random_j = rand() % 4;
			swap(mazo[i][j], mazo[random_i][random_j]);
		}
	}
}

void repartirCartas(string mazo[5][4], string jugador1[5], string jugador2[5]) {
	for (int i = 0; i < 5; i++) {
		jugador1[i] = mazo[i][0];
		jugador2[i] = mazo[i][1];
	}
}

void mostrarCartasJ1(const string jugador[], const string& nombre, int size) {
	rlutil::locate(48, 3);
	cout << nombre << ":" << endl;
	cout<< "------------------------------------------------------------------------------------------------------------------------";
	for (int i = 0; i < size; i++) {
		cout << jugador[i] << endl;
	}
	cout << endl;
}

void mostrarCartasJ2(const string jugador[], const string& nombre, int size) {
	rlutil::locate(48, 15);
	cout << nombre << ":" << endl;
	for (int i = 0; i < size; i++) {
		cout << jugador[i] << endl;
	}
	cout << endl;
}

void mazoCartasRestantes(string mazo[5][4]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 2; j < 4; j++) {
			string nuevoMazo = mazo[i][j];
		}
	}
}

bool cartas_en_orden(const string jugador[], int size) {
	string orden_esperado[] = {"10", "J", "Q", "K", "A"};
	for (int i = 0; i < size; i++) {
		if (jugador[i] != orden_esperado[i]) {
			return false; // Las cartas no están ordenadas
		}
	}
	return true; // Las cartas están ordenadas
}
