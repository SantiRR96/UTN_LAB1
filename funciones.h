#ifndef FUNCIONES_H
#define FUNCIONES_H

//Funciones principales de opciones del juego
void juego();
void creditos();
void estadisticas();

//Funciones generales 
void ingresarNombres(std::string &nombre1, std::string &nombre2);
bool confirmarNombres(std::string player1, std::string player2);
void mostrar_ronda(int ronda);
void cambiar_ronda(int &ronda);

//Funciones del modulo de cartas
void inicializarMazo(std::string mazo[5][4], const std::string valores[], const std::string palos[]);
void barajarMazo(std::string mazo[5][4]);
void repartirCartas(std::string mazo[5][4], std::string jugador1[5], std::string jugador2[5]);
void mostrarCartasJ1(const std::string jugador[], const std::string& nombre, int size);
void mostrarCartasJ2(const std::string jugador[], const std::string& nombre, int size);
void mazoCartasRestantes(std::string mazo[5][4]);
bool cartas_en_orden(const std::string jugador[], int size);
	
//Funciones del modulo de dados
int tirardados (int tam); 
void accion_dado(int dado, int turnoJugador, std::string mazo[5][4], std::string jugador1[], std::string jugador2[]);


#endif
