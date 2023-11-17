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
	
	setlocale(LC_CTYPE, "Spanish");
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
		case 1:
			juego(); 
			break;
		
		case 2:
			//estadisticas();
		break;
		
		case 3: 
			creditos();
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
			case 2: op = 3; break; 
			case 4: op = 0; break;
			}
			break;
		default: break;
		}
	} while (op != 0);
	
	return 0;
}
