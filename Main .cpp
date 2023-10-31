#include <iostream>
#include "rlutil.h"
#include "funciones.h"
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
	
	
	
	int op;
	
	int y = 0;
	
	string player1, player2;
	
	srand(time(0));
	system("color 9f");
	
	
	
	do {
		
		rlutil::hidecursor(); //oculta el cursor.
		
	        rlutil::locate(50, 10);cout << "\tCLUTCH" << endl;
		rlutil::locate(50, 11);cout << "---------------------" << endl;
		rlutil::locate(50, 12);cout << "1- JUGAR" << endl;
	        rlutil::locate(50, 13);cout << "2- ESTADISTICAS" << endl;
		rlutil::locate(50, 14);cout << "3- CREDITOS " << endl;
		rlutil::locate(50, 15);cout << "---------------------" << endl;
		rlutil::locate(50, 16);cout << "0- SALIR " << endl;
		
		rlutil::locate(48, 12 + y);cout << (char) 175 << endl; //Llamado a la flecha desde la tabla ASCII con el ID 175
		
		
		
		switch (op) {
		case 1:
			
			setlocale(LC_CTYPE, "Spanish"); // Para que se vea correctamente el texto en la consola.
			
			rlutil::cls();
			
			rlutil::locate(50, 8);
			
			cout << "CLUTCH" << endl;
			
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			
			rlutil::locate(40, 10);
			cout << "Antes de comenzar deben registrar sus nombres:" << endl;
			
			ingresar_nombres(player1, player2);
			
			if (confirmar_nombres(player1, player2)) {
				
				rlutil::locate(50, 18);
				
				cout << "Nombres confirmados."  << endl;
			
			
				int ronda = 1; // Comenzar en la ronda 1
				
			}
			
			else{ 
					rlutil::locate(45, 17);
					
					cout << "Vuelve a ingresar los nombres." << endl ;} break;
			

			case 2: 
				
				rlutil::cls();
				rlutil::locate(50, 8);cout << "ESTADISTICAS" << endl; break;
				
			
		    case 3: 
				
			      rlutil::cls();
				  rlutil::locate(50, 8);cout << "CREDITOS" << endl; 
			      cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			      rlutil::locate(45, 11);cout << "Laboratorio de Computación I - Grupo 64" << endl;
			      rlutil::locate(45, 13);cout << "Integrantes: " << endl;
			      rlutil::locate(45, 15);cout << "Legajo 27990 - Rossi, Santiago Rodrigo" << endl;
			      rlutil::locate(45, 17);cout << "Legajo 27975 - Diaz, Leonardo Sebastián" << endl;	
				  
				  break; 
			
			// Faltaria agregar los numero de legajo y tambien dice "que hay que poner nombre al grupo"
			
			default: break;
			}
		
		
		
		//Con esto controlamos la direccion de la flecha y la entrada a cada opcion al tocar "enter".
			
			int key = rlutil::getkey();
			
			switch (key) {
				
			case 14: // Arriba
				
				rlutil::locate(48, 12 + y)
				;cout << " " << endl;
				
				y--;
				
				if (y < 0)
					
				{ y = 0; }
				
				break;
				
			case 15: // Abajo
				
				rlutil::locate(48, 12 + y);
				cout << " " << endl;
				
				y++;
				
				if (y > 4) 
				
				{ y = 4; }
				
				break;
				
			case 1: // Enter
				switch (y) {
				case 0: op = 1; break;
				case 1: op = 2; break;
				case 2: op = 3; break;
				case 4: op = 0; break;
				}
				break;
				
			default: break;
			}
		} while (op != 0);
		
		return 0;
	}


