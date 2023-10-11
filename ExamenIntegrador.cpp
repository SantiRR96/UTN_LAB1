#include <iostream>
using namespace std;

int main() {
	
	int opcionInicial;
	
	cout << "CLUNCH" << endl;
	cout << "-----------------" << endl;
	cout << "1 - JUGAR" << endl;
	cout << "2 - ESTADISTICAS" << endl;
	cout << "3 - CREDITOS" << endl;
	cout << "-----------------" << endl;
	cout << "0 - SALIR" << endl << endl;
	
	cout << "Ingrese un opción: ";
	cin >> opcionInicial;
	cout << endl;
	
	// Elegi en switch para cada opcion, me parecio mejor para luego en cada caso poner el codigo correspondiente.
	
	switch (opcionInicial) {
		case 1:
			cout << "Has elegido jugar!" << endl;
			// Aquí iría el código para la opción "jugar"
			break;
		
		case 2:
			cout << "Has elegido ver estadísticas!" << endl;
			// Aquí iría el código para la opción "estadísticas"
			break;
		
		case 3:
			cout << " CRÉDITOS " << endl;
			cout << " ------------------------------------ " << endl;
			cout << "Laboratorio de Computación I" << endl;
			cout << "Integrantes: " << endl;
			cout << "Legajo XXXXXX - Rossi, Santiago Rodrigo" << endl;
			cout << "Legajo XXXXXX - Diaz, Leonardo Sebastián" << endl;
			cout << "Legajo XXXXXX - Aguirregabiria, Martín Alejandro" << endl;	
				
			// Faltaria agregar los numero de legajo y tambien dice "que hay que poner nombre al grupo"
			break;
		
		case 0:
			cout << "¡Hasta luego!" << endl;
			break;
		
		default:
			cout << "Opción inválida. Por favor, elija una opción válida." << endl;
			break;
	}
	
	return 0;
}

