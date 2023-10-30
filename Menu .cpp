#include <iostream>
#include "rlutil.h"
#include "funciones.h" 
#include <string> 





using namespace std;




int main() {
	
	
	
	int op;
	int y = 0; //Se crea la variable "y" para cambiar la posicion del cursor.
    string player1,player2;
	
	system("color 3f");  //color de fondo y texto.
	
	do {
		
		rlutil::hidecursor(); //oculta el cursor.
	
		
		
	    rlutil::locate(50,10);
		cout << "\tCLUTCH" << endl;	
		rlutil::locate(50,11);
		cout << "---------------------" << endl;
		rlutil::locate(50,12);
		cout << "1- JUGAR" << endl;
		rlutil::locate(50,13);
		cout << "2- ESTADISTICAS" <<endl;
		rlutil::locate(50,14) ;
		cout << "3- CREDITOS " << endl;
		rlutil::locate(50,15);
		cout << "---------------------" << endl;
		rlutil::locate(50,16);
		cout << "0- SALIR " << endl;
		rlutil::locate(48,12 + y);
		cout << (char)175 << endl;
		
		
		
		switch (op)
			
		{
		case 1:
			
			rlutil::cls();
			rlutil::locate(50,8);
			cout << "CLUTCH" << endl;
			
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			rlutil::locate(40,10);
			cout << "Antes de comenzar deber registrar sus nombres:" << endl;
			
			
			ingresarNombres(player1, player2);
			
			if (confirmarNombres(player1, player2)) {
				cout << "Nombres confirmados." << endl;
				// Continuar con la siguientes intrucciones.
				rlutil::cls();
				cout << "test de que aceeda al siguiente paso " << endl;
			} else {
				rlutil::locate(49,14);
				cout << "Vuelve a ingresar los nombres." << endl;
			}
			
			
			break;
		case 2: cout << "ESTADISTICAS" << endl; break;
		case 3: cout << "CREDITOS" << endl; break;
		default:
			break;
			
		}
		
		//SELECTOR
		int key = rlutil ::getkey();
		
		switch (key)
			
		{
		case 14: //Arriba
			
			rlutil::locate(48,12 + y);
			cout << " " << endl;
			
			y--;
			if(y<0)
			{y = 0;} 
			break;
			
		case 15: //Abajo   
			rlutil::locate(48,12 + y);
			cout << " " << endl;
			
			y++;
			if(y>4)
			{y = 4;} 
			break;
			
		case 1: //Enter
			
			switch (y)
			{
			case 0: 
				op = 1;
				
					break;
			case 4:
				
				op = 0;
			}
			break;
			
		default: 
			break;
			
		}
		
		
		
		
		
		
		
		
	} while(op!= 0);
	
	
	
	return 0;
}
